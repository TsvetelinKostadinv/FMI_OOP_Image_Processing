cmake_minimum_required (VERSION 3.8)

add_subdirectory(lib/catch2)
# add_subdirectory(lib/rlutil)

list(APPEND EXTRA_LIBS Catch2)

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/catch2")
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/rlutil")

# Add source to this project's executable.
add_executable (ImageProcessing "Main.cpp")

target_link_libraries(ImageProcessing PUBLIC ${EXTRA_LIBS})

target_include_directories(ImageProcessing PUBLIC
                           "${PROJECT_BINARY_DIR}"
						   "${EXTRA_INCLUDES}"
                           )