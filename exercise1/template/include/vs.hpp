/**
 * You can use this file for programmign task 1 of set 1.
*/

#pragma once
#include <bits/stdc++.h>
namespace pfp {

template <class dtype>
class vs {
  public:
    int test =1;
    std::vector<int> v={};
    void insert(dtype val) { 
      v.push_back(val);
      test=1;
    }

    int count(dtype val) {
      // Sort vector in ascending order
      if(test) [[unlikely]]
        std::sort(v.begin(), v.end()); test=0;
      if (std::binary_search(v.begin(), v.end(), val))
        return 1;
      else
        return 0;

    }
};

}  // namespace pfp
