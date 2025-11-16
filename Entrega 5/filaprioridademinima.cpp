#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <direct.h>

#include "filaprioridademinima.h"

void FilaPrioridadeMinima::trocar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void FilaPrioridadeMinima::min_heapify(std::vector<int> &vetor, int indice, int tamanho) {
    int menor = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if (esq < tamanho && vetor[esq] < vetor[menor]) menor = esq;
    if (dir < tamanho && vetor[dir] < vetor[menor]) menor = dir;

    if (menor != indice) {
        trocar(vetor[indice], vetor[menor]);
        min_heapify(vetor, menor, tamanho);
    }
}

void FilaPrioridadeMinima::build_min_heap(std::vector<int> &vetor, int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        min_heapify(vetor, i, tamanho);
}

int FilaPrioridadeMinima::heap_minimum(std::vector<int> &vetor, int tamanho) {
    build_min_heap(vetor, tamanho);
    return vetor[0];
}

int FilaPrioridadeMinima::heap_extract_min(std::vector<int> &vetor, int &tamanho) {
    if (tamanho < 1) return -1;

    build_min_heap(vetor, tamanho);

    int minimo = vetor[0];
    vetor[0] = vetor[tamanho - 1];
    tamanho--;

    min_heapify(vetor, 0, tamanho);

    return minimo;
}

void FilaPrioridadeMinima::heap_increase_key(std::vector<int> &vetor, int tamanho, int indice, int novaChave) {
    vetor[indice] = novaChave;

    while (indice > 0) {
        int pai = (indice - 1) / 2;
        if (vetor[pai] <= vetor[indice]) break;
        trocar(vetor[pai], vetor[indice]);
        indice = pai;
    }
}

void FilaPrioridadeMinima::max_heap_insert(std::vector<int> &vetor, int &tamanho, int chave) {
    vetor[tamanho] = chave;
    tamanho++;

    int indice = tamanho - 1;
    while (indice > 0) {
        int pai = (indice - 1) / 2;
        if (vetor[pai] <= vetor[indice]) break;
        trocar(vetor[pai], vetor[indice]);
        indice = pai;
    }
}

void FilaPrioridadeMinima::imprimir_heap(std::vector<int> &vetor, int tamanho) {
    std::cout << "Heap: ";
    for (int i = 0; i < tamanho; i++)
        std::cout << vetor[i] << " ";
    std::cout << std::endl;
}

void FilaPrioridadeMinima::salvar_fila(std::vector<int> &vetor, int tamanho) {
    _mkdir("FilaPrioridadeMinima");

    std::ofstream arq("FilaPrioridadeMinima/fila.txt");
    if (!arq) return;

    arq << "Tamanho: " << tamanho << "\n";
    for (int i = 0; i < tamanho; i++)
        arq << vetor[i] << "\n";

    arq.close();
}

