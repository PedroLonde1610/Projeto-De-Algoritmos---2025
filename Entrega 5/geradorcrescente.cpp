#include <iostream>
#include <vector>
#include "geradorcrescente.h"
#include <fstream>
#include <string>

using namespace std;

void GeradorCrescente::gerarcrescente(std::vector<int> & v, int quantidade, int escolha) {
    v.resize(quantidade);
    for (size_t i = 0; i < v.size(); i++) {
        v[i] = i + 1;
    }

    string basePath;

    if (escolha == 1) {
        basePath = "InsertionSort\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 2) {
        basePath = "SelectionSort\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 3) {
        basePath = "BubbleSort\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 4) {
        basePath = "ShellSort\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 5) {
        basePath = "MergeSort\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 6) {
        basePath = "QuickSort_Versao1\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 7) {
        basePath = "QuickSort_Versao2\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 8) {
        basePath = "QuickSort_Versao3\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 9) {
        basePath = "HeapSortMin\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else if (escolha == 10) {
        basePath = "FilaPrioridadeMinima\\Arquivos de Entrada\\Crescente\\EntradaCrescente";
    } else {
        return;
    }

    string nomeArquivo = basePath + to_string(v.size()) + ".txt";

    ofstream arquivo(nomeArquivo);
    if (arquivo) {
        arquivo << v.size() << "\n";
        for (size_t i = 0; i < v.size(); i++) {
            arquivo << v[i] << '\n';
        }
        arquivo.close();
    }
}

