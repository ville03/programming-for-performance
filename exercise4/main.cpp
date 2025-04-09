#include <iostream>
#include <cassert>
#include <chrono>

#include "include/VByte.hpp"

template <bool debug = false>
void read(std::FILE* in) {
    if constexpr (debug) std::cout << "Enter values to add" << std::endl;
    uint64_t n = 0;
    uint64_t val = 0;
    uint64_t read = std::fread(&n, sizeof(uint64_t), 1, in);
    assert(read == 1);
    if constexpr (debug) std::cout << "n = " << n << std::endl;
    pfp::VB vb(n);
    for (uint64_t i = 0; i < n; i++) {
        read = std::fread(&val, sizeof(uint64_t), 1, in);
        assert(read == 1);
        if constexpr (debug) std::cout << "val = " << val << std::endl;
        vb.append(val);
    }

    read = std::fread(&n, sizeof(uint64_t), 1, in);
    assert(read == 1);
    if constexpr (debug) std::cout << "n = " << n << std::endl;
    uint64_t output = 0;
    for (uint64_t i = 0; i < n; i++) {
        read = std::fread(&val, sizeof(uint64_t), 1, in);
        assert(read == 1);
        if constexpr (debug) std::cout << "val = " << val << std::endl;
        output = vb.at(val);
        std::cout << output << std::endl;
    }
}

int main(int argc, char const* argv[]) {
    int file_index = 0;
    int i = 1;
    bool debug = false;
    while (i < argc) {
        std::string s(argv[i++]);
        if (s.compare("-k") == 0) {
            debug = false;
        } else if (s.compare("-s") == 0) {
            debug = false;
        } else if (s.compare("-n") == 0) {
            debug = false;
        } else if (s.compare("-l") == 0) {
            debug = false;
        } else if (s.compare("-d") == 0) {
            debug = true;
        } else {
            file_index = i - 1;
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