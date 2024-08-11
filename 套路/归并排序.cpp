//
// Created by victor on 2024/6/5.
//

#include <vector>
#include <iostream>

using namespace std;

void Merge(std::vector<int> &inputs, int start, int mid, int end) {
    std::vector<int> temp;
    int a_index = start, b_index = mid + 1;
    while (a_index <= mid && b_index <= end) {
        if (inputs[a_index] < inputs[b_index]) {
            temp.emplace_back(inputs[a_index]);
            ++a_index;
        } else {
            temp.emplace_back(inputs[b_index]);
            ++b_index;
        }
    }
    while (a_index <= mid) {
        temp.emplace_back(inputs[a_index]);
        ++a_index;
    }
    while (b_index <= end) {
        temp.emplace_back(inputs[b_index]);
        ++b_index;
    }
    int index = start;
    for (const auto &item: temp) {
        inputs[index] = item;
        ++index;
    }
}

void MergeSort(std::vector<int> &inputs, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    MergeSort(inputs, start, mid);
    MergeSort(inputs, mid + 1, end);
    Merge(inputs, start, mid, end);
}

int main() {
    std::vector<int> inputs{324, 1, 243, 3, 54, 44, 564, -3, -213, 3, 12031203, 44, 0, 645, -82138, 6, 5, 235};
    MergeSort(inputs, 0, inputs.size() - 1);
    for (const auto &item: inputs) {
        cout << item << " ";
    }
}