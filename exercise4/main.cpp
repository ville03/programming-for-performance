#include <fstream>
#include <iostream>

#include <string>


#include "include/ba.hpp"

void help() {
    std::cout << "empty for now"/*R"(
Program to test set data structures for positive ints. 

usage:
    ./query [options] [input file]

Options:\n
-h             Outputs this message and terminates.
-t <number>    Type. 1 will use std::set, 2 will use std::unordered_set.
               Other options will be implementation dependent.
-l <number>    Limit. Highest number that will be inserted. Defaults to 2^31 - 1.
-s             If given, it will be assumed that all insertions will be done before any queries.
-v             Verify that the datastructure behaves the same way as std::unordered_set (slow).
-d             Debug mode. Run the program in interactive / verbose mode.
<input file>   Specify file to read insertions and queris from.
               If no input file is specified standard input will be used.

Accepted input is a sequence of non-negative integers in the [0..<limit>] range, with negative
integers switching between insertion and query modes. The program  will start in insert mode.

Examples:
   ./query -t 3 -d
         Interactively test the type 3 data structure (unbalanced binary tree by default).

   /usr/bin/time ./query -t 2 data.txt >> /dev/null
         Benchmark std::unordered set with operations from the data.txt file.

   /usr/bin/time ./query -s -l 10000 limited_sorted.txt >> /dev/null
         Benchmark data with guaranteed sorted and limited input sequence.
         Allows program logic to select data structure type.)"*/
              << std::endl;
}

template <bool debug = false>
void run_ops(std::istream& in) {
    // Creats in instance of undordered_set for use with validation.
    // If validation si not used, an optimizing compiler will remove the
    // initialization.
    if constexpr (debug) std::cout << "Enter values to add" << std::endl;
    int val;
    int n;
    int m;
    int i = 0;
    std::string test;
    if constexpr (debug) std::cout << "Enter ammount of insertions" << std::endl; 
    while (i<2) {
        char Buffer[sizeof(long)]

        std::string str(buf);
        in.read(&test, 8);
        std::cout << str << std::endl;
        i++;
    }
    // unsigned long
    if constexpr (debug) std::cout <<  "Enter ammount of allocated memory" << std::endl;
    in >> m;
    std::cout << m << std::endl;
    pfp::ba<int> ba(m);
    if constexpr (debug) std::cout << "Enter insertions" << std::endl; 
    while(i<n){
        in >> val;
        if constexpr (debug) std::cout << val << std::endl;
        ba.set(val, true);
        i++;
    }
    i = 0;
    if constexpr (debug) std::cout << "Enter queries" << std::endl;
    while(i<n){
        in >> val;
        std::cout << ba.get(val) << std::endl;
        i++;
    }
}

int main(int argc, char const* argv[]) {
    int input_file = 0;
    int i = 1;
    bool debug = false;
    int task = 1;
    bool time = false;
    while (i < argc) {
        std::string s(argv[i++]);
        if (s.compare("-t") == 0) {
            time = true;
        } else if (s.compare("-b") == 0) {
            task = 1;
        } else if (s.compare("-h") == 0) {
            help();
            exit(0);
        } else if (s.compare("-d") == 0) {
            debug = true;
        } else {
            input_file = i - 1;
        }
    }
    //if (debug)
    //    std::cerr << "type = " << type << std::endl;
    if (input_file > 0) {
        std::ifstream in(argv[input_file], std::ios::in | std::ios::binary);
        if (debug) {
            std::cerr << "debug file" << std::endl;
            run_ops<true>(std::fopen(argv[input_file], "rb"));
        } else {
            run_ops<false>(in);
        }
    } else {
        if (debug) {
            std::cerr << "debug manual" << std::endl;
            run_ops<true>(std::cin);
        } else {
            run_ops<false>(std::cin);
        }
    }
    return 0;
}