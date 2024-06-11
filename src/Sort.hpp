#pragma once

#include <vector>

namespace Sort {
    template <typename T> int partition(std::vector<T> &, int, int);
    template <typename T> void quicksort(std::vector<T> &, int, int);
    template <typename T> void quicksort(std::vector<T> &);
};

template <typename T> int Sort::partition(std::vector<T> &arr, int low, int high) {
    T piv = arr[low];
    int i = low - 1; int j = high + 1;
    while (true) {
        do i++; while (arr[i] < piv);
        do j--; while (arr[j] > piv);

        if (i < j)
            std::swap(arr[i], arr[j]);
        else
            return j;
    }
}

template <typename T> void Sort::quicksort(std::vector<T> &arr, int low, int high) {
    if (high <= low) return;

    int p = partition(arr, low, high);
    quicksort(arr, low, p);
    quicksort(arr, p+1, high);
}

template <typename T> void Sort::quicksort(std::vector<T> &arr) {
    quicksort(arr, 0, arr.size()-1);
}