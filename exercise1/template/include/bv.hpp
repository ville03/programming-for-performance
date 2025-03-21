/**
 * You can use this for programming task 2 of set 1 
*/

#pragma once

namespace pfp {

template <class dtype>
class bv {
  public:
    bool boolarray[1000000]={0};
    bv(dtype limit) { limit++; limit--;}
    
    void insert(dtype value) { boolarray[value]=1; }

    int count(dtype value) const {
        return boolarray[value];
    }
};

} // namespace pfp
//Just an array of booleans, or the BitArray from next week.