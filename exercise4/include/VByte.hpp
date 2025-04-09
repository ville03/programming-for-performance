#pragma once

namespace pfp {

template <class dtype>
class VB {
    private:
        uint64_t * array;
        int filled = 0;
    public:
        VB(dtype n){
            array = new uint64_t [n];
        }
        void scan(){
            return;
        }
        void append(dtype val){
            array[filled] = val;
            filled++;
        }
        int at(dtype val){
            return array[val];
        }

};
}//end namespace pfp