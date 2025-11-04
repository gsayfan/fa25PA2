//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size++] = idx;
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int root = data[0];
        data[0] = data[--size];
        downheap(0, weightArr);
        return root;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        // Continues until it reaches the first index of the array, comparing each child with its parent,
        // swapping if it is smaller, then updating the position to its new index
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else
                break;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        // Continues until it reaches the end of the array, swapping each parent with one of it
        // children if it's larger, and updating the position to the child it swapped with if so
        while (pos < size) {
            int lChild = 2 * pos + 1;
            int rChild = 2 * pos + 2;
            int min = pos;

            if (lChild < size && weightArr[data[pos]] > weightArr[data[lChild]])
                min = lChild;
            if (rChild < size && weightArr[data[pos]] > weightArr[data[rChild]])
                min = rChild;

            if (min != pos) {
                swap(data[pos], data[min]);
                pos = min;
            }
            else
                break;
        }
    }
};

#endif