# Data Structures - Project 4 - Sorting
## Due 12/11/15 at 11:59 pm

With this project you will be sorting using various sorting methods!

I have provided the header file for the Sorter struct, and you MUST implement all neccesary functions.


## Files

I will supply you with these files:

 * README.md - This file contains these instructions
 * Makefile - use 'make' on the linux system to compile the project using this makefile.  The binary file will be named 'sorter.out'.
 * Sorter.hpp - This contains the header file for a Sorter object which contains static sorting functions for the following sorting algorithms:
   * Bubble Sort
   * Insertion Sort
   * Radix Sort
   * Merge Sort
   * Quick Sort
 * test_sorter.cpp - this has various functions to test your sorting methods

You must implement functions found in the Sorter.hpp file

## Functions

Here is the Sorter class you need to implement. You MUST implement these functions without changing the name or arguments.

```c++
struct Sorter {

  // sort a vector using bubble sort
  static std::vector<int> bubblesort(const std::vector<int>&); 

  // sort a vector using insertion sort
  static std::vector<int> insertionsort(const std::vector<int>&); 

  // sort a vector using radix sort
  // this has been implemented for you
  static std::vector<int> radixsort(const std::vector<int>&); 

  // sort a vector using quicksort
  static std::vector<int> quicksort(const std::vector<int>&); 
  
  // sort a vector using mergesort
  static std::vector<int> mergesort(const std::vector<int>&); 

};

```

## General Information

 * Each sort takes a std:vector<int> and returns a sorted std:vector<int>.
 * You can use anything from the standard library that is NOT a sort.

## Rubric

 * [20%] Your program must compile and run on our knuth linux server. TEST THIS! IF IT DOESNT COMPILE YOU LOSE 20% OFF THE TOP AND I CANT TEST FUNCTIONALITY!

 * [60%] Your program must correctly sort using each sorting method and the method must be implemented correctly
   * Bubble Sort [10%]
   * Insertion Sort [10%]
   * Merge Sort [20%]
   * Quick Sort [20%]

 * [10%] You must document all functions in your code (you don't need to go crazy, just document what you are doing)

 * [10%] You must properly handle memory, memory leaks will cost you points
