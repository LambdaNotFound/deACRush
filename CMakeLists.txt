cmake_minimum_required(VERSION 3.17)
project(acrush)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-std=libc++")
## turn on debugging
set(CMAKE_CXX_FLAGS "-g")
## StackOverflow: flags-to-enable-thorough-and-verbose-g-warnings
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Wno-unused -Wundef")
set(CMAKE_CXX_FLAGS "-Wold-style-cast -Wcast-align -Wcast-qual -Wlogical-op")
set(CMAKE_CXX_FLAGS "-Wmissing-declarations -Wctor-dtor-privacy -Woverloaded-virtual")
## make warning into error
set(CMAKE_CXX_FLAGS "-Werror")

include_directories(include)

add_executable(acrush main.cpp)

set(SOURCE_CORE
    include/StandardLibrary.cpp
    # Algorithm/BinarySearch/BinarySearch.cpp
    # Algorithm/ComputationalGeometry/SweepLine.cpp
    # Algorithm/DivideAndConquer/DivideAndConquer.cpp
    # Algorithm/Graph/UnionFind.cpp
    # Algorithm/RandomizedAlgorithm/RandomizedAlgorithm.cpp
    # Algorithm/Sorting/InsertionSort.cpp
    # Algorithm/Sorting/QuickSort.cpp
    # Algorithm/Sorting/TopologicalSort.cpp
    # Algorithm/StringMatching/KMP.cpp
    # Algorithm/Tree/TreeTraversal.cpp
    # DataStructure/BinarySearchTreeIterator.cpp
    # DataStructure/BinaryTree.cpp
    # ModernCpp/Basic.cpp
    # ProblemSet/Array.cpp
    # ProblemSet/Backtracking.cpp
    # ProblemSet/BinarySearch.cpp
    # ProblemSet/BinarySearchTree.cpp
    # ProblemSet/BFS.cpp
    ProblemSet/DivideAndConquer.cpp
    # ProblemSet/DynamicProgramming.cpp
    # ProblemSet/Graph.cpp
    # ProblemSet/Greedy.cpp
    ProblemSet/HashMap.cpp
    ProblemSet/Heap.cpp
    # ProblemSet/Iterator.cpp
    # ProblemSet/LinkedList.cpp
    # ProblemSet/Math.cpp
    # ProblemSet/Matrix.cpp
    # ProblemSet/Merge.cpp
    # ProblemSet/Scheduling.cpp
    # ProblemSet/Set.cpp
    # ProblemSet/Stack.cpp
    # ProblemSet/String.cpp
    # ProblemSet/Tree.cpp
    ProblemSet/TwoPointers.cpp
    # ProblemSet/UnionFind.cpp
)
add_library(Core ${SOURCE_CORE})

add_subdirectory(google_tests)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_TESTS
    # UnitTest/AlgorithmTest/BinarySearchTest.cpp
    # UnitTest/AlgorithmTest/SortingTest.cpp
    # UnitTest/DataStructureTest/BinarySearchTreeIteratorTest.cpp
    # UnitTest/ProblemSetTest/ArrayTest.cpp
    # UnitTest/ProblemSetTest/BFSTest.cpp
    # UnitTest/ProblemSetTest/BinaryTreeTest.cpp
    # UnitTest/ProblemSetTest/BinarySearchTreeTest.cpp
    # UnitTest/ProblemSetTest/DynamicProgrammingTest.cpp
    UnitTest/HashMap.cpp
    UnitTest/Heap.cpp
    UnitTest/MergeSort.cpp
    # UnitTest/ProblemSetTest/LinkedListTest.cpp
    # UnitTest/ProblemSetTest/MatrixTest.cpp
    # UnitTest/ProblemSetTest/StackTest.cpp
    # UnitTest/ProblemSetTest/StringTest.cpp
)
add_executable(UnitTest ${SOURCE_TESTS} ${SOURCE_CORE})
target_link_libraries(UnitTest gtest gtest_main)
