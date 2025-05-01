cmake_minimum_required(VERSION 3.28)
project(Data_Structure_Practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_Structure_Practice EffectiveC++/main.cpp EffectiveC++/Item_11.h)
add_executable(Vector Vector/Vector.cpp Vector/Vector.h)
add_executable(MyNamespace Namespace/MyNamespace.cpp Namespace/MyNamespace.h)