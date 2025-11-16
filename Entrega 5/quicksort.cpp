#include <iostream>
#include <vector>
#include "quicksort.h"
#include <string>
#include <fstream>
#include <ctime>
#include <direct.h>

using namespace std;

void troca(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Versao 1 - pivo eh o primeiro elemento
int particionaVersao1(vector<int> &v, int inicio, int fim) {
    int pivo = v[inicio];
    int i = inicio + 1;
    int j = fim;

    while (true) {
        while (i <= fim && v[i] <= pivo) i++;
        while (j >= inicio && v[j] > pivo) j--;     //se i nao cruzou ha um maior na esquerda se j nao cruzou ha um menor na direita
        if (i < j)
            troca(v[i], v[j]);                      //troca um com outro
        else
            break;                                  //caso eles tenham se passado quer dizer que ta certo
    }

    troca(v[inicio], v[j]);                         //troca o pivo para dps do primeiro menor igual a ele que j achou
    return j;
}

// Versao 2 - pivo eh a media dos extremos
int particionaVersao2(vector<int> &v, int inicio, int fim) {
    int media = (v[inicio] + v[fim]) / 2;
    int i = inicio;
    int j = fim;

    while (i <= j) {
        while (v[i] < media) i++;                                   //enquanto i nao achar alguem maior continua
        while (v[j] > media) j--;                                   //enquanto j nao achar um menor continua
        if (i <= j) {
            troca(v[i], v[j]);
            i++;
            j--;
        }
    }
    return i;                      //como nao ha indice do pivo retorna os menores que a media i-1 e os maiores i ai faz o quick de novo
}

// Versao 3 - pivo aleatorio
int particionaVersao3(vector<int> &v, int inicio, int fim) {
    int pivoIndex = inicio + rand() % (fim - inicio + 1);     //aleatorio mas que esteja entre o 0 e tamanho do vetor
    int pivo = v[pivoIndex];                                  //pivo = indice do rand
    troca(v[pivoIndex], v[inicio]);                           //troca indice do pivo pelo inicio
    int i = inicio + 1;
    int j = fim;

    while (true) {
        while (i <= fim && v[i] <= pivo) i++;
        while (j >= inicio && v[j] > pivo) j--;               // enquanto i for menor que fim e o os valores de i for menor ou igual a i vai andando e j ao contrario >= e maior que inicio
        if (i < j)                                            //quer dizer que pararam antes de se encontrarem ou seja troca o maior do lado esquerdo pelo menor do lado direito
            troca(v[i], v[j]);
        else
            break;                                            //se encontraram sai do loop
    }

    troca(v[inicio], v[j]);
    return j;
}

// QuickSort recursivo otimizado
void quickSort(vector<int> &v, int inicio, int fim, int escolha) {
    while (inicio < fim) {       //enquanto tiver pelo menos dois elementos continua
        int pivoIndex;

        if (escolha == 6)
            pivoIndex = particionaVersao1(v, inicio, fim); //vai dividindo
        else if (escolha == 7)
            pivoIndex = particionaVersao2(v, inicio, fim); //vai dividindo
        else
            pivoIndex = particionaVersao3(v, inicio, fim); //vai dividindo

        // recursao sempre na menor particao para limitar profundidade
        if ((pivoIndex - inicio) < (fim - pivoIndex)) {   //esquerda < direita
            quickSort(v, inicio, pivoIndex - 1, escolha);
            inicio = pivoIndex + 1;  // continua com a metade maior  (a parte maior e processada sem nova recursao apenas reaproveitando o mesmo stack)(uso o mesmo while)(uma por vez)
        } else {                                         //direita > esquerda
            quickSort(v, pivoIndex + 1, fim, escolha);
            fim = pivoIndex - 1;      // continua com a metade menor
        }
    }
}

void QuickSort::sort(std::vector<int> &v, char tipo, int escolha) {
    clock_t inicio = clock();
    quickSort(v, 0, v.size() - 1, escolha);
    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;

    string baseSaida, baseTempo;
    if (escolha == 6) {
        baseSaida = "QuickSort_Versao1\\Arquivos de Saida\\";
        baseTempo = "QuickSort_Versao1\\Arquivos de Tempo\\";
    } else if (escolha == 7) {
        baseSaida = "QuickSort_Versao2\\Arquivos de Saida\\";
        baseTempo = "QuickSort_Versao2\\Arquivos de Tempo\\";
    } else {
        baseSaida = "QuickSort_Versao3\\Arquivos de Saida\\";
        baseTempo = "QuickSort_Versao3\\Arquivos de Tempo\\";
    }

    string tipoNome;
    switch (tipo) {
        case 'c': case 'C': tipoNome = "Crescente"; break;
        case 'd': case 'D': tipoNome = "Decrescente"; break;
        case 'r': case 'R': tipoNome = "Random"; break;
        default:
            cout << "Tipo invalido\n";
            return;
    }

    string nomeArquivo = baseSaida + tipoNome + "\\Saida" + tipoNome + to_string(v.size()) + ".txt";
    string nomeArquivo2 = baseTempo + tipoNome + "\\Tempo" + tipoNome + to_string(v.size()) + ".txt";

    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao criar arquivo: " << nomeArquivo << endl;      //n conseguiu abrir sai fora
        return;
    }

    arquivo << v.size() << "\n";    //Primeiro grava o tamanho do vetor vsize
    const size_t BLOCO = 100000;    //Usa um buffer uma string temporaria para acumular varios numeros antes de gravar no arquivo
    string buffer;                  //A cada 100000 numeros BLOCO ele grava o conteudo e limpa o buffer  (evita demora)
    buffer.reserve(BLOCO * 8);
    for (size_t i = 0; i < v.size(); i++) {
        buffer += to_string(v[i]) + '\n';
        if (i % BLOCO == 0 && i != 0) {
            arquivo << buffer;
            buffer.clear();
        }
    }
    if (!buffer.empty()) arquivo << buffer;
    arquivo.close();

    ofstream arquivo2(nomeArquivo2);
    arquivo2 << "Tempo de Execucao\n" << tempo << " segundos";
    arquivo2.close();

    cout << "QuickSort versao " << (escolha - 5)
         << " finalizado. Vetor " << v.size()
         << " salvo em " << nomeArquivo << "\nTempo salvo em " << nomeArquivo2
         << "\nTempo total: " << tempo << " segundos\n";
}


