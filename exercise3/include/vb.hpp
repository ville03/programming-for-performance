#pragma once

namespace pfp {

template <class dtype>
class vb {
    public:
        bool * bitarray;
        ba(dtype limit){bitarray = new bool [limit];}
        void set(dtype i, bool b){
            bitarray[i]=b;
            return;
        }
        bool get(dtype i){
            return bitarray[i];
        }
};
}