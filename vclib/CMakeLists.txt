file(GLOB_RECURSE srcfiles.vclib RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

if(MSVC)
    add_library(libopenblas.vclib STATIC ${srcfiles.vclib})
    set_target_properties(libopenblas.vclib PROPERTIES OUTPUT_NAME libopenblas)
    target_compile_options(libopenblas.vclib PRIVATE /Zl)
    target_include_directories(libopenblas.vclib PUBLIC ${OpenBLAS_INCLUDE_DIRS})
endif()

if(MSVC)
    install(
        TARGETS libopenblas.vclib
        ARCHIVE DESTINATION lib
        RENAME libopenblas.lib
        COMPONENT ${PROJECT_NAME}
    )
endif()
