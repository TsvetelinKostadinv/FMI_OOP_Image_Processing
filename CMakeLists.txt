cmake_minimum_required (VERSION 3.8)

project(ImageProcessing VERSION 1.0)

file(GLOB_RECURSE SRCFILES 
	Main.cpp
	src/*.h
	src/*.cpp
	)

add_compile_definitions(_DEBUG_)

message( "Source files: " ${SRCFILES})
add_executable (ImageProcessing ${SRCFILES})

add_subdirectory(lib/catch2)
# add_subdirectory(lib/rlutil)

list(APPEND EXTRA_LIBS Catch2)

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/catch2")
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/rlutil")
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src")

# Add source to this project's executable.
target_link_libraries(ImageProcessing PUBLIC ${EXTRA_LIBS})

target_include_directories(ImageProcessing PUBLIC
                           "${PROJECT_BINARY_DIR}"
						   "${EXTRA_INCLUDES}"
                           )