#include<iostream>
#include<vector>
#include "bubblesort.h"
#include<string>
#include<fstream>
#include<ctime>

void BubbleSort::sort(std::vector<int> & v, char tipo){
    clock_t inicio = clock();
        for (size_t i = 0; i < v.size() - 1; i++) {
            for (size_t j = 0; j < v.size() - 1 - i; j++) {
                if (v[j] > v[j + 1]) {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
        }
    }
}
    clock_t fim = clock();
    double tempo = double(fim - inicio)/ CLOCKS_PER_SEC;
    std::string baseSaida = "BubbleSort\\Arquivos de Saida\\";
    std::string baseTempo = "BubbleSort\\Arquivos de Tempo\\";
    std::string nomeArquivo, nomeArquivo2;
    std::ofstream arquivo;
    std::ofstream arquivo2;

    switch(tipo){
    case 'c':
    case 'C':
        {
            nomeArquivo = baseSaida + "Crescente\\SaidaCrescente" + std::to_string(v.size()) + ".txt";
            arquivo.open(nomeArquivo);

            if(arquivo){
                arquivo << v.size() << "\n";
                for(size_t i = 0; i < v.size(); i++){
                    arquivo << v[i] << '\n';
                }
            }

            nomeArquivo2 = baseTempo + "Crescente\\TempoCrescente" + std::to_string(v.size()) + ".txt";
            arquivo2.open(nomeArquivo2);
            if(arquivo2){
                arquivo2 << "Tempo de Execucao" << "\n";
                arquivo2 << tempo << " segundos";
            }
            break;
        }

        case 'd':
        case 'D':
            {
            nomeArquivo = baseSaida + "Decrescente\\SaidaDecrescente" + std::to_string(v.size()) + ".txt";
            arquivo.open(nomeArquivo);

            if(arquivo){
                arquivo << v.size() << "\n";
                for(size_t i = 0; i < v.size(); i++){
                    arquivo << v[i] << '\n';
                }
            }

            nomeArquivo2 = baseTempo + "Decrescente\\TempoDecrescente" + std::to_string(v.size()) + ".txt";
            arquivo2.open(nomeArquivo2);

            if(arquivo2){
                arquivo2 << "Tempo de Execucao" << "\n";
                arquivo2 << tempo << " segundos";
                }
            break;
        }

        case 'r':
        case 'R':
            {
            nomeArquivo = baseSaida + "Random\\SaidaRandom" + std::to_string(v.size()) + ".txt";
            arquivo.open(nomeArquivo);

            if(arquivo){
                arquivo << v.size() << "\n";
                for(size_t i = 0; i < v.size(); i++){
                    arquivo << v[i] << '\n';
                }
            }

            nomeArquivo2 = baseTempo + "Random\\TempoRandom" + std::to_string(v.size()) + ".txt";
            arquivo2.open(nomeArquivo2);

            if(arquivo2){
                arquivo2 << "Tempo de Execucao" << "\n";
                arquivo2 << tempo << " segundos";
            }
            break;
        }
}
}





