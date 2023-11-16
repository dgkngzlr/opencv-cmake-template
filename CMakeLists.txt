cmake_minimum_required(VERSION 3.20)
project(Project5 VERSION 1.0 DESCRIPTION "Example project" LANGUAGES CXX)

set(OpenCV_DIR "C:/dev/libraries/opencv/build")
file(GLOB OpenCV_DLLS "${OpenCV_DIR}/x64/vc16/bin/*.dll")
find_package(OpenCV REQUIRED)

# MagicIsp lib
add_library(MagicIsp STATIC "${CMAKE_SOURCE_DIR}/src/MagicIsp/MagicIsp.cpp")
target_include_directories(MagicIsp PUBLIC "${CMAKE_SOURCE_DIR}/include/MagicIsp")
target_link_libraries(MagicIsp PRIVATE "${OpenCV_LIBS}")
set_target_properties(MagicIsp PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/lib/MagicIsp")

# Executable
add_executable(Project5 "${CMAKE_SOURCE_DIR}/src/Main.cpp")
target_link_libraries(Project5 PRIVATE MagicIsp)
target_link_libraries(Project5 PRIVATE "${OpenCV_LIBS}")

# Copy OpenCV DLLs
foreach(OpenCV_DLL IN ITEMS ${OpenCV_DLLS})
add_custom_command(TARGET Project5 POST_BUILD                     # Adds a post-build event to MyTest
                COMMAND ${CMAKE_COMMAND} -E copy_if_different     # which executes "cmake - E copy_if_different..."
                "${OpenCV_DLL}"                                   # <--this is in-file
                $<TARGET_FILE_DIR:Project5>)                      # <--this is out-file path
endforeach()


