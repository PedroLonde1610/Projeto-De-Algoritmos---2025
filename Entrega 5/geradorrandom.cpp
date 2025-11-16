#include <random>
#include "geradorrandom.h"
#include <fstream>
#include <string>

using namespace std;

void GeradorRandom::gerarrandom(std::vector<int>& v, int max, int escolha) {
    if (max <= 1) return;
    v.resize(max);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, max);

    for (size_t i = 0; i < v.size(); i++) {
        v[i] = dist(gen);
    }

    std::string basePath;

    if (escolha == 1) {
        basePath = "InsertionSort\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 2) {
        basePath = "SelectionSort\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 3) {
        basePath = "BubbleSort\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 4) {
        basePath = "ShellSort\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 5) {
        basePath = "MergeSort\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 6) {
        basePath = "QuickSort_Versao1\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 7) {
        basePath = "QuickSort_Versao2\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 8) {
        basePath = "QuickSort_Versao3\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 9) {
        basePath = "HeapSortMin\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else if (escolha == 10) {
        basePath = "FilaPrioridadeMinima\\Arquivos de Entrada\\Random\\EntradaRandom";
    }
    else {
        return;
    }

    std::string nomeArquivo = basePath + std::to_string(v.size()) + ".txt";

    std::ofstream arquivo(nomeArquivo);
    if (arquivo) {
        arquivo << v.size() << "\n";
        for (size_t i = 0; i < v.size(); i++) {
            arquivo << v[i] << '\n';
        }
        arquivo.close();
    }
}

