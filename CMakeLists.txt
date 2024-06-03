# cmake -DCMAKE_C_COMPILER=/opt/homebrew/bin/gcc-14 -DCMAKE_CXX_COMPILER=/opt/homebrew/bin/g++-14 -DOpenCV_DIR=/opt/homebrew/Cellar/opencv/4.9.0_8 ..

# g++-14 -fopenmp testing.cpp -o MyProject $(pkg-config --cflags --libs /opt/homebrew/Cellar/opencv/4.9.0_8/lib/pkgconfig/opencv4.pc)

# arch -arch x86_64 gcc -fopenmp omptest.cpp -o MyProject $(pkg-config --cflags --libs /opt/homebrew/Cellar/opencv/4.9.0_8/lib/pkgconfig/opencv4.pc)


cmake_minimum_required(VERSION 3.10)
project(MyProject)

find_package(OpenCV REQUIRED)
# find_package(OpenMP REQUIRED)


set(OpenMP_C_FLAGS "-Xclang -fopenmp")
set(OpenMP_C_LIB_NAMES "omp")
set(OpenMP_omp_LIBRARY /opt/homebrew/opt/libomp/lib/libomp.dylib)
set(OpenMP_omp_INCLUDE_DIR /opt/homebrew/opt/libomp/include)

add_executable(MyProject testing.cpp)
target_compile_options(MyProject PRIVATE ${OpenMP_C_FLAGS})
target_include_directories(MyProject PRIVATE ${OpenMP_omp_INCLUDE_DIR})
target_link_libraries(MyProject PRIVATE ${OpenMP_omp_LIBRARY})


target_link_libraries(MyProject PRIVATE ${OpenCV_LIBS})


# # find_package(MPI REQUIRED)
# # include_directories(${MPI_INCLUDE_PATH})


# # target_link_libraries(MyProject PRIVATE ${MPI_CXX_LIBRARIES})


# cmake_minimum_required(VERSION 3.10)
# project(MyProject)

# find_package(OpenCV REQUIRED)

# find_package(OpenMP REQUIRED)

# set(CMAKE_CXX_COMPILER "g++-14")

# target_link_libraries(MyProject PRIVATE OpenMP::OpenMP_CXX)

# target_link_libraries(MyProject PRIVATE ${OpenCV_LIBS})




