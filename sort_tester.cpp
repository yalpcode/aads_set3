#include "sort_tester.hpp"

SortTester::SortTester(size_t cnt_runs) : cnt_runs(cnt_runs) {
}

long long SortTester::run(std::vector<int> a, int threshold) {
    long long msec_all = 0;

    for (size_t i = 0; i < cnt_runs; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(a, threshold);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;

        long long msec =
            std::chrono::duration_cast<std::chrono::milliseconds>(elapsed)
                .count();
        msec_all += msec;
    }

    return msec_all / cnt_runs;
}

void SortTester::runs(const std::vector<int>& arr_gen,
                      const std::string& path_csv,
                      const std::vector<int>& thresholds) {
    std::ofstream fout(path_csv);

    fout << "n,quick";
    for (int th : thresholds) {
        fout << ",thresholds_t" << th;
    }
    fout << "\n";

    for (int n = 500; n <= 100000; n += 100) {
        fout << n << ","
             << run(std::vector<int>(arr_gen.begin(), arr_gen.begin() + n), 1);

        for (int th : thresholds) {
            fout << ","
                 << run(std::vector<int>(arr_gen.begin(), arr_gen.begin() + n),
                        th);
        }
        fout << "\n";
    }

    fout.close();
}