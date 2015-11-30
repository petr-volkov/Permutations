cmake_minimum_required(VERSION 3.3)
project(permutations)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(SOURCE_FILES main.cpp
        src/bed_parser.cpp include/bed_parser.h
        src/bed_entry.cpp include/bed_entry.h
        src/bed.cpp include/bed.h
        src/bed_chromosome.cpp include/bed_chromosome.h
        src/genome_info.cpp include/genome_info.h src/split.cpp include/split.h src/str2int.cpp include/str2int.h src/bed_randomizer.cpp include/bed_randomizer.h)

add_subdirectory(test)

add_executable(permutations ${SOURCE_FILES})