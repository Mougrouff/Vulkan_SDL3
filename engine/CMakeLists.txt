
file(GLOB_RECURSE engine_files RELATIVE  ${CMAKE_SOURCE_DIR} "*.cpp")

message("Adding engine files : ${engine_files}")

list(APPEND source_list ${engine_files})

set(source_list ${source_list} PARENT_SCOPE)
