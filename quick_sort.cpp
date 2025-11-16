#include "quick_sort.hpp"

void heapify(std::vector<int>& a, int i, int n, int l) {
    while (2 * i <= n) {
        int j = 2 * i;
        if ((j < n) && (a[l - 1 + j] < a[l - 1 + j + 1])) {
            ++j;
        }
        if (!(a[l - 1 + i] < a[l - 1 + j])) {
            break;
        }
        std::swap(a[l - 1 + i], a[l - 1 + j]);
        i = j;
    }
}

void buildMaxHeap(std::vector<int>& a, int l, int r) {
    int n = r - l;

    for (int k = n / 2; k >= 1; --k) {
        ::heapify(a, k, n, l);
    }
}

void heapSort(std::vector<int>& a, int l, int r) {
    int n = r - l;
    ::buildMaxHeap(a, l, r);

    while (n > 1) {
        std::swap(a[l], a[l - 1 + n]);
        --n;
        ::heapify(a, 1, n, l);
    }
}

int partition(std::vector<int>& a, int l, int r, int pivot) {
    int i = l, j = r - 1;
    while (i <= j) {
        while (a[i] < pivot) {
            ++i;
        }
        while (a[j] > pivot) {
            --j;
        }
        if (i <= j) {
            std::swap(a[i], a[j]);
            ++i;
            --j;
        }
    }

    return i;
}

void quickSort(std::vector<int>& a, int l, int r, int h, int threshold) {
    if (threshold > 1 && h >= 2 * log(a.size()) - 1) {
        ::heapSort(a, l, r);
        return;
    }

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

    std::uniform_int_distribution<int> i_dist(l, r - 1);

    int pivot = a[i_dist(rng)];
    int p = ::partition(a, l, r, pivot);
    quickSort(a, l, p, h + 1, threshold);
    quickSort(a, p, r, h + 1, threshold);
}

void quickSort(std::vector<int>& a, int threshold) {
    quickSort(a, 0, a.size(), threshold);
}
