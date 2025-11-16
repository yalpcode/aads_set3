#include "sort_tester.hpp"

int main() {
    ArrayGenerator array_generator;
    SortTester sort_tester;

    std::vector<int> thresholds = {5, 10, 20, 30, 50};

    sort_tester.runs(array_generator.getArr1(), "random.csv", thresholds);
    sort_tester.runs(array_generator.getArr2(), "reverse.csv", thresholds);
    sort_tester.runs(array_generator.getArr3(), "almost_sorted.csv",
                     thresholds);

    return 0;
}