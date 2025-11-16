#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <direct.h>

#include "heapsortmin.h"

// funcao que troca dois valores
void HeapSortMin::trocar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

// funcao que mantem propriedade de heap minimo
void HeapSortMin::min_heapify(std::vector<int> &vetor, int indice, int tamanho) {
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita  = 2 * indice + 2;

    if (esquerda < tamanho && vetor[esquerda] < vetor[menor])
        menor = esquerda;

    if (direita < tamanho && vetor[direita] < vetor[menor])
        menor = direita;

    if (menor != indice) {
        trocar(vetor[indice], vetor[menor]);
        min_heapify(vetor, menor, tamanho);
    }
}

// funcao que constroi o heap minimo
void HeapSortMin::build_min_heap(std::vector<int> &vetor) {
    int tamanho = vetor.size();
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        min_heapify(vetor, i, tamanho);
    }
}

// funcao de ordenacao heapsort minimo
void HeapSortMin::sort(std::vector<int> &vetor, char tipo) {
    clock_t inicio = clock();

    build_min_heap(vetor);

    int tamanho = vetor.size();

    for (int i = tamanho - 1; i > 0; i--) {
        trocar(vetor[0], vetor[i]);
        min_heapify(vetor, 0, i);
    }

    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;

    std::string baseSaida = "HeapSortMin\\Arquivos de Saida\\";
    std::string baseTempo = "HeapSortMin\\Arquivos de Tempo\\";

    std::string nomeArquivo;
    std::string nomeArquivo2;

    std::ofstream arquivo;
    std::ofstream arquivo2;

    switch (tipo) {
    case 'c':
    case 'C':
        nomeArquivo = baseSaida + "Crescente\\SaidaCrescente" + std::to_string(vetor.size()) + ".txt";
        nomeArquivo2 = baseTempo + "Crescente\\TempoCrescente" + std::to_string(vetor.size()) + ".txt";
        break;

    case 'd':
    case 'D':
        nomeArquivo = baseSaida + "Decrescente\\SaidaDecrescente" + std::to_string(vetor.size()) + ".txt";
        nomeArquivo2 = baseTempo + "Decrescente\\TempoDecrescente" + std::to_string(vetor.size()) + ".txt";
        break;

    case 'r':
    case 'R':
        nomeArquivo = baseSaida + "Random\\SaidaRandom" + std::to_string(vetor.size()) + ".txt";
        nomeArquivo2 = baseTempo + "Random\\TempoRandom" + std::to_string(vetor.size()) + ".txt";
        break;
    }

    arquivo.open(nomeArquivo);
    if (arquivo) {
        arquivo << vetor.size() << "\n";
        for (size_t i = 0; i < vetor.size(); i++)
            arquivo << vetor[i] << "\n";
    }

    arquivo2.open(nomeArquivo2);
    if (arquivo2) {
        arquivo2 << "Tempo de Execucao\n";
        arquivo2 << tempo << " segundos";
    }
}

