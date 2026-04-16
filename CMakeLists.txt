cmake_minimum_required(VERSION 3.28)

project(html)

# parser lib (html/css)
add_subdirectory(parser)

# add executable
add_executable(${PROJECT_NAME} main.c)

# link the project to the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE hcparser)
