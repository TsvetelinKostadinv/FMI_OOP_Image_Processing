# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)


# Add source to this project's executable.
add_executable (ImageProcessing "Main.cpp")

target_include_directories(ImageProcessing PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# TODO: Add tests and install targets if needed.

