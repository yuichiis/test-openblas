/*
  for upper compatibility
*/

#include <stdlib.h>
#include <stdio.h>
#include "lapacke.h"

#define LAPACK_dgesvd dgesvd_
#define LAPACK_lsame lsame_

extern lapack_logical lsame_	(	char * 	ca,
char * 	cb,
lapack_int 	lca,
lapack_int 	lcb
);
extern void dgesvd_	(	char const * 	jobu,
char const * 	jobvt,
lapack_int const * 	m,
lapack_int const * 	n,
double * 	A,
lapack_int const * 	lda,
double * 	S,
double * 	U,
lapack_int const * 	ldu,
double * 	VT,
lapack_int const * 	ldvt,
double * 	work,
lapack_int const * 	lwork,
lapack_int * 	info
);

static int nancheck_flag = -1;

lapack_logical LAPACKE_lsame	(	char 	ca,
char 	cb
)
{
    return (lapack_logical) lsame_( &ca, &cb, 1, 1 );
}
void LAPACKE_xerbla	(	const char * 	name,
lapack_int 	info
)
{
    if( info == LAPACK_WORK_MEMORY_ERROR ) {
        printf( "Not enough memory to allocate work array in %s\n", name );
    } else if( info == LAPACK_TRANSPOSE_MEMORY_ERROR ) {
        printf( "Not enough memory to transpose matrix in %s\n", name );
    } else if( info < 0 ) {
        printf( "Wrong parameter %d in %s\n", -(int) info, name );
    }
}


lapack_logical LAPACKE_dge_nancheck	(
int 	matrix_layout,
lapack_int 	m,
lapack_int 	n,
const double * 	a,
lapack_int 	lda
)
{
     lapack_int i, j;

     if( a == NULL ) return (lapack_logical) 0;

     if( matrix_layout == LAPACK_COL_MAJOR ) {
         for( j = 0; j < n; j++ ) {
             for( i = 0; i < MIN( m, lda ); i++ ) {
                 if( LAPACK_DISNAN( a[i+(size_t)j*lda] ) )
                     return (lapack_logical) 1;
             }
         }
     } else if ( matrix_layout == LAPACK_ROW_MAJOR ) {
         for( i = 0; i < m; i++ ) {
             for( j = 0; j < MIN( n, lda ); j++ ) {
                 if( LAPACK_DISNAN( a[(size_t)i*lda+j] ) )
                     return (lapack_logical) 1;
             }
         }
     }
     return (lapack_logical) 0;
}
int LAPACKE_get_nancheck	(		)
{
     char* env;
     if ( nancheck_flag != -1 ) {
         return nancheck_flag;
     }

     /* Check environment variable, once and only once */
     env = getenv( "LAPACKE_NANCHECK" );
     if ( !env ) {
         /* By default, NaN checking is enabled */
         nancheck_flag = 1;
     } else {
         nancheck_flag = atoi( env ) ? 1 : 0;
     }

     return nancheck_flag;
}

void LAPACKE_dge_trans	(	int 	matrix_layout,
lapack_int 	m,
lapack_int 	n,
const double * 	in,
lapack_int 	ldin,
double * 	out,
lapack_int 	ldout
)
{
     lapack_int i, j, x, y;

     if( in == NULL || out == NULL ) return;

     if( matrix_layout == LAPACK_COL_MAJOR ) {
         x = n;
         y = m;
     } else if ( matrix_layout == LAPACK_ROW_MAJOR ) {
         x = m;
         y = n;
     } else {
         /* Unknown input layout */
         return;
     }

     /* In case of incorrect m, n, ldin or ldout the function does nothing */
     for( i = 0; i < MIN( y, ldin ); i++ ) {
         for( j = 0; j < MIN( x, ldout ); j++ ) {
             out[ (size_t)i*ldout + j ] = in[ (size_t)j*ldin + i ];
         }
     }
}

lapack_int LAPACKE_dgesvd_work	(
int 	matrix_layout,
char 	jobu,
char 	jobvt,
lapack_int 	m,
lapack_int 	n,
double * 	a,
lapack_int 	lda,
double * 	s,
double * 	u,
lapack_int 	ldu,
double * 	vt,
lapack_int 	ldvt,
double * 	work,
lapack_int 	lwork
)
{
     lapack_int info = 0;
     if( matrix_layout == LAPACK_COL_MAJOR ) {
         /* Call LAPACK function and adjust info */
         LAPACK_dgesvd( &jobu, &jobvt, &m, &n, a, &lda, s, u, &ldu, vt, &ldvt,
                        work, &lwork, &info );
         if( info < 0 ) {
             info = info - 1;
         }
     } else if( matrix_layout == LAPACK_ROW_MAJOR ) {
         lapack_int nrows_u = ( LAPACKE_lsame( jobu, 'a' ) ||
                              LAPACKE_lsame( jobu, 's' ) ) ? m : 1;
         lapack_int ncols_u = LAPACKE_lsame( jobu, 'a' ) ? m :
                              ( LAPACKE_lsame( jobu, 's' ) ? MIN(m,n) : 1);
         lapack_int nrows_vt = LAPACKE_lsame( jobvt, 'a' ) ? n :
                               ( LAPACKE_lsame( jobvt, 's' ) ? MIN(m,n) : 1);
         lapack_int lda_t = MAX(1,m);
         lapack_int ldu_t = MAX(1,nrows_u);
         lapack_int ldvt_t = MAX(1,nrows_vt);
         double* a_t = NULL;
         double* u_t = NULL;
         double* vt_t = NULL;
         /* Check leading dimension(s) */
         if( lda < n ) {
             info = -7;
             LAPACKE_xerbla( "LAPACKE_dgesvd_work", info );
             return info;
         }
         if( ldu < ncols_u ) {
             info = -10;
             LAPACKE_xerbla( "LAPACKE_dgesvd_work", info );
             return info;
         }
         if( ldvt < n ) {
             info = -12;
             LAPACKE_xerbla( "LAPACKE_dgesvd_work", info );
             return info;
         }
         /* Query optimal working array(s) size if requested */
         if( lwork == -1 ) {
             LAPACK_dgesvd( &jobu, &jobvt, &m, &n, a, &lda_t, s, u, &ldu_t, vt,
                            &ldvt_t, work, &lwork, &info );
             return (info < 0) ? (info - 1) : info;
         }
         /* Allocate memory for temporary array(s) */
         a_t = (double*)LAPACKE_malloc( sizeof(double) * lda_t * MAX(1,n) );
         if( a_t == NULL ) {
             info = LAPACK_TRANSPOSE_MEMORY_ERROR;
             goto exit_level_0;
         }
         if( LAPACKE_lsame( jobu, 'a' ) || LAPACKE_lsame( jobu, 's' ) ) {
             u_t = (double*)
                 LAPACKE_malloc( sizeof(double) * ldu_t * MAX(1,ncols_u) );
             if( u_t == NULL ) {
                 info = LAPACK_TRANSPOSE_MEMORY_ERROR;
                 goto exit_level_1;
             }
         }
         if( LAPACKE_lsame( jobvt, 'a' ) || LAPACKE_lsame( jobvt, 's' ) ) {
             vt_t = (double*)
                 LAPACKE_malloc( sizeof(double) * ldvt_t * MAX(1,n) );
             if( vt_t == NULL ) {
                 info = LAPACK_TRANSPOSE_MEMORY_ERROR;
                 goto exit_level_2;
             }
         }
         /* Transpose input matrices */
         LAPACKE_dge_trans( matrix_layout, m, n, a, lda, a_t, lda_t );
         /* Call LAPACK function and adjust info */
         LAPACK_dgesvd( &jobu, &jobvt, &m, &n, a_t, &lda_t, s, u_t, &ldu_t, vt_t,
                        &ldvt_t, work, &lwork, &info );
         if( info < 0 ) {
             info = info - 1;
         }
         /* Transpose output matrices */
         LAPACKE_dge_trans( LAPACK_COL_MAJOR, m, n, a_t, lda_t, a, lda );
         if( LAPACKE_lsame( jobu, 'a' ) || LAPACKE_lsame( jobu, 's' ) ) {
             LAPACKE_dge_trans( LAPACK_COL_MAJOR, nrows_u, ncols_u, u_t, ldu_t,
                                u, ldu );
         }
         if( LAPACKE_lsame( jobvt, 'a' ) || LAPACKE_lsame( jobvt, 's' ) ) {
             LAPACKE_dge_trans( LAPACK_COL_MAJOR, nrows_vt, n, vt_t, ldvt_t, vt,
                                ldvt );
         }
         /* Release memory and exit */
         if( LAPACKE_lsame( jobvt, 'a' ) || LAPACKE_lsame( jobvt, 's' ) ) {
             LAPACKE_free( vt_t );
         }
 exit_level_2:
         if( LAPACKE_lsame( jobu, 'a' ) || LAPACKE_lsame( jobu, 's' ) ) {
             LAPACKE_free( u_t );
         }
 exit_level_1:
         LAPACKE_free( a_t );
 exit_level_0:
         if( info == LAPACK_TRANSPOSE_MEMORY_ERROR ) {
             LAPACKE_xerbla( "LAPACKE_dgesvd_work", info );
         }
     } else {
         info = -1;
         LAPACKE_xerbla( "LAPACKE_dgesvd_work", info );
     }
     return info;
}

lapack_int LAPACKE_dgesvd	(
    int 	matrix_layout,
    char 	jobu,
    char 	jobvt,
    lapack_int 	m,
    lapack_int 	n,
    double * 	a,
    lapack_int 	lda,
    double * 	s,
    double * 	u,
    lapack_int 	ldu,
    double * 	vt,
    lapack_int 	ldvt,
    double * 	superb
)
{
    lapack_int info = 0;
    lapack_int lwork = -1;
    double* work = NULL;
    double work_query;
    lapack_int i;
    if( matrix_layout != LAPACK_COL_MAJOR && matrix_layout != LAPACK_ROW_MAJOR ) {
        LAPACKE_xerbla( "LAPACKE_dgesvd", -1 );
        return -1;
    }
#ifndef LAPACK_DISABLE_NAN_CHECK
    if( LAPACKE_get_nancheck() ) {
        /* Optionally check input matrices for NaNs */
        if( LAPACKE_dge_nancheck( matrix_layout, m, n, a, lda ) ) {
            return -6;
        }
    }
#endif
    /* Query optimal working array(s) size */
    info = LAPACKE_dgesvd_work( matrix_layout, jobu, jobvt, m, n, a, lda, s, u,
                                ldu, vt, ldvt, &work_query, lwork );
    if( info != 0 ) {
        goto exit_level_0;
    }
    lwork = (lapack_int)work_query;
    /* Allocate memory for work arrays */
    work = (double*)LAPACKE_malloc( sizeof(double) * lwork );
    if( work == NULL ) {
        info = LAPACK_WORK_MEMORY_ERROR;
        goto exit_level_0;
    }
    /* Call middle-level interface */
    info = LAPACKE_dgesvd_work( matrix_layout, jobu, jobvt, m, n, a, lda, s, u,
                                ldu, vt, ldvt, work, lwork );
    /* Backup significant data from working array(s) */
    for( i=0; i<MIN(m,n)-1; i++ ) {
        superb[i] = work[i+1];
    }
    /* Release memory and exit */
    LAPACKE_free( work );
exit_level_0:
    if( info == LAPACK_WORK_MEMORY_ERROR ) {
        LAPACKE_xerbla( "LAPACKE_dgesvd", info );
    }
    return info;
}
