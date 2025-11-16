#include<iostream>
#include<vector>
#include "mergesort.h"
#include<string>
#include<fstream>
#include<ctime>
#include<direct.h>

using namespace std;

// funcao que junta duas partes do vetor em ordem
void merge(vector<int> & v, int inicio, int meio, int fim){
    // calcula o tamanho das duas metades
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // cria dois vetores temporarios
    vector<int> L(n1), R(n2);

    // copia os elementos da primeira metade para L
    for(int i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    // copia os elementos da segunda metade para R
    for(int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

    // define os indices para percorrer os vetores
    int i = 0, j = 0, k = inicio;

    // compara elementos e coloca o menor de cada vez no vetor original
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // copia o que sobrou de L se tiver
    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    // copia o que sobrou de R se tiver
    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

// funcao que divide o vetor e chama o merge
void mergeSort(vector<int> & v, int inicio, int fim){
    // enquanto ainda puder dividir o vetor
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);   //uma vez executado para cada nivel de divisao
}
}

// funcao principal da classe que executa o algoritmo e salva os resultados
void MergeSort::sort(std::vector<int> & v, char tipo){

    clock_t inicio = clock();

    // executa o merge sort
    mergeSort(v, 0, v.size() - 1);

    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;

    std::string baseSaida = "MergeSort\\Arquivos de Saida\\";
    std::string baseTempo = "MergeSort\\Arquivos de Tempo\\";
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



