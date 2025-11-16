#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>

void Merge(std::vector<int>& a, int l, int mid, int r);

void MergeSort(std::vector<int>& a, int l, int r, int threshold);

void MergeSort(std::vector<int>& a, int threshold = 15);

#endif  // MERGE_SORT_HPP
