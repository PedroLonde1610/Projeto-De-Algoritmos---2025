#ifndef FILAPRIORIDADEMINIMA_H
#define FILAPRIORIDADEMINIMA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class FilaPrioridadeMinima {
public:
    static void trocar(int &a, int &b);
    static void min_heapify(std::vector<int> &vetor, int indice, int tamanho);
    static void build_min_heap(std::vector<int> &vetor, int tamanho);

    static int heap_minimum(std::vector<int> &vetor, int tamanho);
    static int heap_extract_min(std::vector<int> &vetor, int &tamanho);
    static void heap_increase_key(std::vector<int> &vetor, int tamanho, int indice, int novaChave);
    static void max_heap_insert(std::vector<int> &vetor, int &tamanho, int chave);

    static void imprimir_heap(std::vector<int> &vetor, int tamanho);
    static void salvar_fila(std::vector<int> &vetor, int tamanho);
};

#endif

