/*
  for upper compatibility
*/
#ifndef lapack_int
#define lapack_int     int
#endif

#ifndef lapack_logical
#define lapack_logical lapack_int
#endif

#ifndef LAPACKE_malloc
#define LAPACKE_malloc( size ) malloc( size )
#endif
#ifndef LAPACKE_free
#define LAPACKE_free( p )      free( p )
#endif

#define LAPACK_ROW_MAJOR               101
#define LAPACK_COL_MAJOR               102

#define LAPACK_WORK_MEMORY_ERROR       -1010
#define LAPACK_TRANSPOSE_MEMORY_ERROR  -1011

/* NaN checkers */
#define LAPACK_SISNAN( x ) ( x != x )
#define LAPACK_DISNAN( x ) ( x != x )
#define LAPACK_CISNAN( x ) ( LAPACK_SISNAN(*((float*) &x)) || \
                              LAPACK_SISNAN(*(((float*) &x)+1)) )
#define LAPACK_ZISNAN( x ) ( LAPACK_DISNAN(*((double*)&x)) || \
                              LAPACK_DISNAN(*(((double*)&x)+1)) )

#ifndef ABS
#define ABS(x) (((x) < 0) ? -(x) : (x))
#endif
#ifndef MAX
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif
#ifndef MIN
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif
#ifndef MAX3
#define MAX3(x,y,z) (((x) > MAX(y,z)) ? (x) : MAX(y,z))
#endif
#ifndef MIN3
#define MIN3(x,y,z) (((x) < MIN(y,z)) ? (x) : MIN(y,z))
#endif

extern void print_matrix( int matrix_layout, char* desc, int m, int n, double* a, int lda );

extern lapack_logical LAPACKE_lsame	(	char 	ca,
char 	cb
);
extern void LAPACKE_xerbla	(	const char * 	name,
lapack_int 	info
);
extern lapack_logical LAPACKE_dge_nancheck	(int matrix_layout,
lapack_int 	m,
lapack_int 	n,
const double * 	a,
lapack_int 	lda
);
extern int LAPACKE_get_nancheck	();
extern void LAPACKE_dge_trans	(	int 	matrix_layout,
lapack_int 	m,
lapack_int 	n,
const double * 	in,
lapack_int 	ldin,
double * 	out,
lapack_int 	ldout
);
extern lapack_int LAPACKE_dgesvd_work	(	int 	matrix_layout,
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
);
extern lapack_int LAPACKE_dgesvd	(
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
);
