add_library(hcparser STATIC html_parser.c)
target_include_directories(hcparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
