include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES bed_parser_tests.cpp
        ${permutations_SOURCE_DIR}/src/bed_parser.cpp ${permutations_SOURCE_DIR}/include/bed_parser.h
        ${permutations_SOURCE_DIR}/src/bed_entry.cpp ${permutations_SOURCE_DIR}/include/bed_entry.h
        ${permutations_SOURCE_DIR}/src/genome_info.cpp ${permutations_SOURCE_DIR}/include/genome_info.h
        ${permutations_SOURCE_DIR}/src/bed.cpp ${permutations_SOURCE_DIR}/include/bed.h
        ${permutations_SOURCE_DIR}/src/bed_chromosome.cpp ${permutations_SOURCE_DIR}/include/bed_chromosome.h ../../src/split.cpp ../../include/split.h ../../src/str2int.cpp ../../include/str2int.h)
add_executable(bedParserTests ${SOURCE_FILES} )

set(SOURCE_FILES bed_entry_tests.cpp
        ${permutations_SOURCE_DIR}/src/bed_entry.cpp ${permutations_SOURCE_DIR}/include/bed_entry.h
        ${permutations_SOURCE_DIR}/src/genome_info.cpp ${permutations_SOURCE_DIR}/include/genome_info.h ../../src/split.cpp ../../include/split.h ../../src/str2int.cpp ../../include/str2int.h)
add_executable(bedEntryTests ${SOURCE_FILES} )

set(SOURCE_FILES bed_chromosome_tests.cpp
        ${permutations_SOURCE_DIR}/src/bed_parser.cpp ${permutations_SOURCE_DIR}/include/bed_parser.h
        ${permutations_SOURCE_DIR}/src/bed_chromosome.cpp ${permutations_SOURCE_DIR}/include/bed_chromosome.h
        ${permutations_SOURCE_DIR}/src/bed_entry.cpp ${permutations_SOURCE_DIR}/include/bed_entry.h
        ${permutations_SOURCE_DIR}/src/genome_info.cpp ${permutations_SOURCE_DIR}/include/genome_info.h
        ${permutations_SOURCE_DIR}/src/bed.cpp ${permutations_SOURCE_DIR}/include/bed.h ../../src/split.cpp ../../include/split.h ../../src/str2int.cpp ../../include/str2int.h)
add_executable(bedChromosomeTests ${SOURCE_FILES} )

set(SOURCE_FILES genome_info_tests.cpp
        ${permutations_SOURCE_DIR}/src/genome_info.cpp ${permutations_SOURCE_DIR}/include/genome_info.h ../../src/split.cpp ../../include/split.h ../../src/str2int.cpp ../../include/str2int.h)
add_executable(genomeInfoTests ${SOURCE_FILES})

set(SOURCE_FILES bed_tests.cpp
        ${permutations_SOURCE_DIR}/src/bed_parser.cpp ${permutations_SOURCE_DIR}/include/bed_parser.h
        ${permutations_SOURCE_DIR}/src/bed_chromosome.cpp ${permutations_SOURCE_DIR}/include/bed_chromosome.h
        ${permutations_SOURCE_DIR}/src/bed_entry.cpp ${permutations_SOURCE_DIR}/include/bed_entry.h
        ${permutations_SOURCE_DIR}/src/genome_info.cpp ${permutations_SOURCE_DIR}/include/genome_info.h
        ${permutations_SOURCE_DIR}/src/bed.cpp ${permutations_SOURCE_DIR}/include/bed.h ../../src/split.cpp ../../include/split.h ../../src/str2int.cpp ../../include/str2int.h)
add_executable(bedTests ${SOURCE_FILES})

set(SOURCE_FILES bed_randomizer_tests.cpp
        ${permutations_SOURCE_DIR}/src/bed_parser.cpp ${permutations_SOURCE_DIR}/include/bed_parser.h
        ${permutations_SOURCE_DIR}/src/bed_chromosome.cpp ${permutations_SOURCE_DIR}/include/bed_chromosome.h
        ${permutations_SOURCE_DIR}/src/bed_entry.cpp ${permutations_SOURCE_DIR}/include/bed_entry.h
        ${permutations_SOURCE_DIR}/src/genome_info.cpp ${permutations_SOURCE_DIR}/include/genome_info.h
        ${permutations_SOURCE_DIR}/src/bed.cpp ${permutations_SOURCE_DIR}/include/bed.h ../../src/split.cpp ../../include/split.h ../../src/str2int.cpp ../../include/str2int.h
        ${permutations_SOURCE_DIR}/src/bed_randomizer.cpp ${permutations_SOURCE_DIR}/include/bed_randomizer.h)
add_executable(bedRandomizerTests ${SOURCE_FILES})


target_link_libraries(bedParserTests gtest gtest_main)
target_link_libraries(bedEntryTests gtest gtest_main)
target_link_libraries(bedChromosomeTests gtest gtest_main)
target_link_libraries(bedTests gtest gtest_main)
target_link_libraries(genomeInfoTests gtest gtest_main)
target_link_libraries(bedRandomizerTests gtest gtest_main)


