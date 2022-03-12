
add_library(TrigLib STATIC Angle.h Angle.cpp Triangle.h Triangle.cpp)

add_executable(Angle main.cpp)
target_link_libraries(Angle TrigLib)
