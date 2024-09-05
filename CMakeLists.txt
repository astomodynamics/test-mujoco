cmake_minimum_required(VERSION 3.14)
project(test-mujoco)

set(CMAKE_CXX_STANDARD 17)

include_directories(/home/tom/mujoco/include) 

# Explicitly set the MUJOCO_LIBRARY variable
set(MUJOCO_LIBRARY /home/tom/mujoco/build/lib/libmujoco.so)

add_executable(test_mujoco src/main.cpp)
target_link_libraries(test_mujoco ${MUJOCO_LIBRARY})