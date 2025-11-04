add_executable(light light.cpp main.cpp)
target_link_libraries(light ${MP2_LIBRARY})
target_include_directories(light PRIVATE ${MP2_INCLUDE})