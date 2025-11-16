#include<iostream>
#include<vector>
#include "shellsort.h"
#include<string>
#include<fstream>
#include<ctime>

void ShellSort::sort(std::vector<int>& v, char forma) {
    clock_t inicio = clock();

    for (size_t gap = v.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < v.size(); i++) {
            int temp = v[i];
            size_t j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }

    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;

    std::string baseSaida = "ShellSort\\Arquivos de Saida\\";
    std::string baseTempo = "ShellSort\\Arquivos de Tempo\\";
    std::string nomeArquivo, nomeArquivo2;
    std::ofstream arquivo;
    std::ofstream arquivo2;

    switch (forma) {
        case 'c':
        case 'C': {
            nomeArquivo = baseSaida + "Crescente\\SaidaCrescente" + std::to_string(v.size()) + ".txt";
            arquivo.open(nomeArquivo);
            if (arquivo) {
                arquivo << v.size() << "\n";
                for (size_t i = 0; i < v.size(); i++) {
                    arquivo << v[i] << '\n';
                }
            }
            nomeArquivo2 = baseTempo + "Crescente\\TempoCrescente" + std::to_string(v.size()) + ".txt";
            arquivo2.open(nomeArquivo2);
            if (arquivo2) {
                arquivo2 << "Tempo de Execucao\n";
                arquivo2 << tempo << " segundos";
            }
            break;
        }

        case 'd':
        case 'D': {
            nomeArquivo = baseSaida + "Decrescente\\SaidaDecrescente" + std::to_string(v.size()) + ".txt";
            arquivo.open(nomeArquivo);
            if (arquivo) {
                arquivo << v.size() << "\n";
                for (size_t i = 0; i < v.size(); i++) {
                    arquivo << v[i] << '\n';
                }
            }
            nomeArquivo2 = baseTempo + "Decrescente\\TempoDecrescente" + std::to_string(v.size()) + ".txt";
            arquivo2.open(nomeArquivo2);
            if (arquivo2) {
                arquivo2 << "Tempo de Execucao\n";
                arquivo2 << tempo << " segundos";
            }
            break;
        }

        case 'r':
        case 'R': {
            nomeArquivo = baseSaida + "Random\\SaidaRandom" + std::to_string(v.size()) + ".txt";
            arquivo.open(nomeArquivo);
            if (arquivo) {
                arquivo << v.size() << "\n";
                for (size_t i = 0; i < v.size(); i++) {
                    arquivo << v[i] << '\n';
                }
            }
            nomeArquivo2 = baseTempo + "Random\\TempoRandom" + std::to_string(v.size()) + ".txt";
            arquivo2.open(nomeArquivo2);
            if (arquivo2) {
                arquivo2 << "Tempo de Execucao\n";
                arquivo2 << tempo << " segundos";
            }
            break;
        }
    }
}




