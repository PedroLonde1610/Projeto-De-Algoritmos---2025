#ifndef HEAPSORTMIN_H
#define HEAPSORTMIN_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <direct.h>

class HeapSortMin {
public:
    static void sort(std::vector<int> &vetor, char tipo);
    static void min_heapify(std::vector<int> &vetor, int indice, int tamanho);
    static void build_min_heap(std::vector<int> &vetor);
    static void trocar(int &a, int &b);
};

#endif

