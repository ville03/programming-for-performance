#include <iostream>
#include <cassert>
#include <chrono>

#include "include/VByte.hpp"

template <bool debug = false>
void run_ops(std::istream& in) {
    if constexpr (debug) std::cout << "Enter values to add" << std::endl;
    uint64_t n = 0;
    uint64_t val = 0;
    uint64_t read = std::fread(&n, sizeof(uint64_t), 1, in);
    pfp::VB vb();
    assert(read == 1);
    if constexpr (debug) std::cout << "n = " << n << std::endl;
    for (int i = 0; i < n; i++) {
        uint64_t read = std::fread(&val, sizeof(uint64_t), 1, in);
        assert(read == 1);
        if constexpr (debug) std::cout << "val = " << val << std::endl;
        vb.append(val)
        
    }
    read = std::fread(&n, sizeof(uint64_t), 1, in);
    assert(read == 1);
    if constexpr (debug) std::cout << "n = " << n << std::endl;
    for (int i = 0; i < n; i++) {
        uint64_t read = std::fread(&val, sizeof(uint64_t), 1, in);
        assert(read == 1);
        if constexpr (debug) std::cout << "val = " << val << std::endl;
        vb.at()
        
    }
}

int main(int argc, char const* argv[]) {
    int input_file = 0;
    bool debug = false;
    while (i < argc) {
        std::string s(argv[i++]);
        if (s.compare("-k") == 0) {
            debug = true;
        } else if (s.compare("-s") == 0) {
            debug = true;
        } else if (s.compare("-n") == 0) {
            debug = true;
        } else if (s.compare("-l") == 0) {
            debug = true;
        } else if (s.compare("-d") == 0) {
            debug = true;
        } else {
            input_file = i - 1;
        }
    }
    if (debug) {
        std::cerr << "File = " << (file_index ? argv[file_index] : "") << std::endl;
    }
    if (file_index) {
        if (debug) {
            read<true>(std::fopen(argv[file_index], "rb"));
        } else {
            read<false>(std::fopen(argv[file_index], "rb"));
        }
    } else {
        if (debug) {
            read<true>(std::freopen(nullptr, "rb", stdin));
        } else {
            read<false>(std::freopen(nullptr, "rb", stdin));
        }
    }
    return 0;
}