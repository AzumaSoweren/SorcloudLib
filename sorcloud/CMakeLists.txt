file(GLOB SORCLOUD_SRC SOURCES "src/*.cpp")
file(GLOB SORCLOUD_HEADER_SRC SOURCES "include/*.h")

target_sources(SoLoudLib
    PRIVATE
        ${SORCLOUD_SRC}

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            ${SORCLOUD_HEADER_SRC}
)
