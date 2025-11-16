#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <chrono>
#include <random>
#include <vector>

namespace {
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void heapify(std::vector<int>& a, int i, int n, int l);

void buildMaxHeap(std::vector<int>& a, int l, int r);

void heapSort(std::vector<int>& a, int l, int r);

int partition(std::vector<int>& a, int l, int r, int pivot);
};  // namespace

void quickSort(std::vector<int>& a, int l, int r, int h = 0,
               int threshold = 15);

void quickSort(std::vector<int>& a, int threshold = 15);

#endif
