#include "merge_sort.hpp"

void Merge(std::vector<int>& a, int l, int mid, int r) {
    std::vector<int> c;
    c.reserve(r - l + 1);
    int i = l;
    int j = mid;
    while (i < mid && j < r) {
        if (a[i] < a[j]) {
            c.push_back(a[i]);
            ++i;
        } else {
            c.push_back(a[j]);
            ++j;
        }
    }
    for (; i < mid; ++i) {
        c.push_back(a[i]);
    }
    for (; j < r; ++j) {
        c.push_back(a[j]);
    }
    for (int i = l; i < r; ++i) {
        a[i] = c[i - l];
    }
}

void MergeSort(std::vector<int>& a, int l, int r, int threshold) {
    if (r - l <= threshold) {
        for (int i = l; i < r - 1; ++i) {
            int j = 0;
            while (i - j >= l && a[i - j] > a[i + 1 - j]) {
                std::swap(a[i - j], a[i + 1 - j]);
                ++j;
            }
        }
        return;
    }

    int mid = l + (r - l) / 2;
    MergeSort(a, l, mid, threshold);
    MergeSort(a, mid, r, threshold);
    Merge(a, l, mid, r);
}

void MergeSort(std::vector<int>& a, int threshold) {
    MergeSort(a, 0, a.size(), threshold);
}
