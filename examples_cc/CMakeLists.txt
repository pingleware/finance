# examples_cc/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Create the executable for run_all_examples.cc
add_executable(run_all_examples run_all_examples.cc)

# Link the executable with libfinance.a, newmat, and my_library
target_link_libraries(run_all_examples PRIVATE ${FINANCE_LIB_PATH} newmat finance)

# Install the run_all_examples executable
install(TARGETS run_all_examples
        RUNTIME DESTINATION bin)