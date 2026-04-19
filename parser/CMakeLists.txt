add_library(hcparser STATIC html_parser.c css_parser.c)

target_include_directories(hcparser
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(
    lexbor
    GIT_REPOSITORY https://github.com/lexbor/lexbor.git
    GIT_TAG master
)

FetchContent_MakeAvailable(lexbor)

target_link_libraries(hcparser PUBLIC lexbor_static)
