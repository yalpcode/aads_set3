#ifndef ARRAY_GENERATOR_HPP
#define ARRAY_GENERATOR_HPP

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

class ArrayGenerator {
    std::mt19937 rng;
    size_t n;
    std::vector<int> arr1;
    std::vector<int> arr2;
    std::vector<int> arr3;

   public:
    ArrayGenerator(unsigned int sd = 42, int start = 0, int finish = 6000,
                   size_t n = 100000);

    const std::vector<int>& getArr1() const;

    const std::vector<int>& getArr2() const;

    const std::vector<int>& getArr3() const;
};

#endif  // ARRAY_GENERATOR_HPP