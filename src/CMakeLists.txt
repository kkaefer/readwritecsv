add_executable(writer writer.cpp)
target_add_mason_package(writer PRIVATE protozero)

add_executable(reader reader.cpp)
target_add_mason_package(reader PRIVATE protozero)
