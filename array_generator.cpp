#include "array_generator.hpp"

ArrayGenerator::ArrayGenerator(unsigned int sd, int start, int finish, size_t n)
    : rng(sd), n(n), arr1(n), arr2(n), arr3(n) {
    std::uniform_int_distribution<int> i_dist(0, n - 1);
    std::uniform_int_distribution<int> x_dist(start, finish);

    for (size_t i = 0; i < n; ++i) {
        arr1[i] = x_dist(rng);
        arr2[i] = x_dist(rng);
        arr3[i] = x_dist(rng);
    }

    std::sort(arr2.begin(), arr2.end(), std::greater<int>());

    std::sort(arr3.begin(), arr3.end());
    for (size_t i = 0; i < n / 100; ++i) {
        std::swap(arr3[i_dist(rng)], arr3[i_dist(rng)]);
    }
}

const std::vector<int>& ArrayGenerator::getArr1() const {
    return arr1;
}

const std::vector<int>& ArrayGenerator::getArr2() const {
    return arr2;
}

const std::vector<int>& ArrayGenerator::getArr3() const {
    return arr3;
}
