cmake_minimum_required(VERSION 3.10)

# Project name
project(finance VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/all_cc_progs/*.cc)

# Add the Newmat library
add_subdirectory(libs/newmat)

# Create the library
add_library(finance STATIC ${SOURCES})

# Link the Newmat library
target_link_libraries(finance PRIVATE newmat)


# Optionally, specify the library's public header files
target_include_directories(finance PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Add the examples_cc directory
add_subdirectory(examples_cc)

# Install the finance
install(TARGETS finance
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

# Install the header files
install(DIRECTORY include/ DESTINATION include)

# Install the libfinance.a library
install(FILES ${FINANCE_LIB_PATH} DESTINATION lib)

# Configure CPack
include(CPack)
