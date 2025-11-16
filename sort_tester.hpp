#ifndef SORT_TESTER_HPP
#define SORT_TESTER_HPP

#include <chrono>
#include <fstream>
#include <memory>

#include "array_generator.hpp"
#include "merge_sort.hpp"

class SortTester {
    size_t cnt_runs;

    long long run(std::vector<int> a, int threshold);

   public:
    SortTester(size_t cnt_runs = 10);

    void runs(const std::vector<int>& arr_gen, const std::string& path_csv,
              const std::vector<int>& thresholds);
};

#endif  // SORT_TESTER_HPP
