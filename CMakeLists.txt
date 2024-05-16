cmake_minimum_required(VERSION 3.14)

project(tests-openblas VERSION 0.1.0 LANGUAGES CXX C)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    if("$ENV{OpenBLAS_DIR}" STREQUAL "")
        message(FATAL_ERROR "OpenBLAS_DIR not found.\nPlease set the OpenBLAS root path in the environment variable OpenBLAS_DIR.")
    else()
        message(STATUS "OpenBLAS_DIR: $ENV{OpenBLAS_DIR}")
        find_package(OpenBLAS REQUIRED)
        set(OpenBLAS_INCLUDE_DIRS "$ENV{OpenBLAS_DIR}/include")
        set(OpenBLAS_LIBRARIES "$ENV{OpenBLAS_DIR}/lib/libopenblas.lib")
        set(LAPACKE_INCLUDE_DIRS "$ENV{OpenBLAS_DIR}/include")
        set(LAPACKE_LIBRARIES "$ENV{OpenBLAS_DIR}/lib/libopenblas.lib")
        set(LAPACK_LIBRARIES "$ENV{OpenBLAS_DIR}/lib/libopenblas.lib")
    endif()
elseif(APPLE)
    find_library(OpenBLAS_LIBRARIES Accelerate)
    set(LAPACKE_LIBRARIES ${OpenBLAS_LIBRARIES})
    set(LAPACK_LIBRARIES ${OpenBLAS_LIBRARIES})
    #if("$ENV{OpenBLAS_DIR}" STREQUAL "")
    #    message(FATAL_ERROR "OpenBLAS_DIR not found.\nPlease set the OpenBLAS root path in the environment variable OpenBLAS_DIR.")
    #else()
    #    message(STATUS "OpenBLAS_DIR: $ENV{OpenBLAS_DIR}")
    #    find_package(OpenBLAS REQUIRED)
    #    set(LAPACKE_INCLUDE_DIRS ${OpenBLAS_INCLUDE_DIRS})
    #    set(LAPACKE_LIBRARIES ${OpenBLAS_LIBRARIES})
    #endif()
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(OpenBLAS REQUIRED openblas)
    if(NOT OpenBLAS_FOUND)
        message(FATAL_ERROR "OpenBLAS library not found")
    endif()
    pkg_search_module(LAPACKE REQUIRED lapacke)
    if(NOT LAPACKE_FOUND)
        message(FATAL_ERROR "LAPACKE library not found")
    endif()
    pkg_search_module(LAPACK REQUIRED lapack)
    if(NOT LAPACK_FOUND)
        message(FATAL_ERROR "LAPACK library not found")
    endif()
endif()

message(STATUS "OpenBLAS_VERSION: ${OpenBLAS_VERSION}")
message(STATUS "OpenBLAS_LIBRARIES: ${OpenBLAS_LIBRARIES}")
message(STATUS "OpenBLAS_INCLUDE_DIRS: ${OpenBLAS_INCLUDE_DIRS}")
message(STATUS "LAPACKE_LIBRARIES: ${LAPACKE_LIBRARIES}")
message(STATUS "LAPACKE_INCLUDE_DIRS: ${LAPACKE_INCLUDE_DIRS}")
message(STATUS "LAPACK_LIBRARIES: ${LAPACK_LIBRARIES}")

#if(MSVC)
#    add_subdirectory(./vclib)
#endif()

add_executable(bit2 src/bit2.c)
if(NOT APPLE)
    target_include_directories(bit2 PUBLIC ${OpenBLAS_INCLUDE_DIRS})
endif()
#if(MSVC)
#    target_link_libraries(bit2 PUBLIC libopenblas.vclib)
#else()
    target_link_libraries(bit2 PUBLIC ${OpenBLAS_LIBRARIES})
#endif()
if(APPLE)
    target_compile_options(bit2 PRIVATE -DACCELERATE_NEW_LAPACK)
endif()


add_executable(tst_dgesvd src/tst_dgesvd.c)
target_link_libraries(tst_dgesvd PUBLIC ${LAPACK_LIBRARIES})
if(APPLE)
    target_compile_options(tst_dgesvd PRIVATE -DACCELERATE_NEW_LAPACK)
endif()

if(NOT APPLE)
    add_executable(tst_edgesvd src/tst_edgesvd.c)
    target_include_directories(tst_edgesvd PUBLIC ${LAPACKE_INCLUDE_DIRS})
    #if(MSVC)
    #    target_link_libraries(tst_edgesvd PUBLIC libopenblas.vclib)
    #else()
        target_link_libraries(tst_edgesvd PUBLIC ${LAPACKE_LIBRARIES})
    #endif()
endif()

add_test(
  NAME bit2
  COMMAND bit2 sasum 20 1
)
add_test(
  NAME bit2_info
  COMMAND bit2 info
)
add_test(
  NAME tst_dgesvd
  COMMAND tst_dgesvd
)
if(NOT APPLE)
    add_test(
      NAME tst_edgesvd
      COMMAND tst_edgesvd
    )
endif()
