#include <iostream>
#include <cassert>
#include <chrono>

template<bool debug>
void read(std::FILE* in) {
    uint64_t n = 0;
    uint64_t m = 0;
    uint64_t read = std::fread(&n, sizeof(uint64_t), 1, in);
    std::cerr << n << std::endl;
    while (true){
        read = std::fread(&m, sizeof(uint64_t), 1, in);
        assert(read == 1);
        std::cerr << m << std::endl;
        if (feof(in)) {
            return;
        }
    }
}
int main(int argc, char const *argv[]) {
    int file_index = 0;
    int i = 1;
    bool debug = false;
    while (i < argc) {
        std::string s(argv[i++]);
        if (s.compare("-d") == 0) {
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
    }
    return 0;
}