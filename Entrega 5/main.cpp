#include <iostream>
#include <vector>
#include <direct.h>

#include "InsertionSort.h"
#include "selectionsort.h"
#include "bubblesort.h"
#include "shellsort.h"
#include "mergesort.h"
#include "quicksort.h"

#include "GeradorCrescente.h"
#include "GeradorDecrescente.h"
#include "GeradorRandom.h"

#include "heapsortmin.h"
#include "filaprioridademinima.h"

using namespace std;

void criarPastas(int escolha)
{
    if (escolha == 1) {
        _mkdir("InsertionSort");
        _mkdir("InsertionSort/Arquivos de Entrada");
        _mkdir("InsertionSort/Arquivos de Entrada/Crescente");
        _mkdir("InsertionSort/Arquivos de Entrada/Decrescente");
        _mkdir("InsertionSort/Arquivos de Entrada/Random");
        _mkdir("InsertionSort/Arquivos de Saida");
        _mkdir("InsertionSort/Arquivos de Saida/Crescente");
        _mkdir("InsertionSort/Arquivos de Saida/Decrescente");
        _mkdir("InsertionSort/Arquivos de Saida/Random");
        _mkdir("InsertionSort/Arquivos de Tempo");
        _mkdir("InsertionSort/Arquivos de Tempo/Crescente");
        _mkdir("InsertionSort/Arquivos de Tempo/Decrescente");
        _mkdir("InsertionSort/Arquivos de Tempo/Random");
    }

    if (escolha == 2) {
        _mkdir("SelectionSort");
        _mkdir("SelectionSort/Arquivos de Entrada");
        _mkdir("SelectionSort/Arquivos de Entrada/Crescente");
        _mkdir("SelectionSort/Arquivos de Entrada/Decrescente");
        _mkdir("SelectionSort/Arquivos de Entrada/Random");
        _mkdir("SelectionSort/Arquivos de Saida");
        _mkdir("SelectionSort/Arquivos de Saida/Crescente");
        _mkdir("SelectionSort/Arquivos de Saida/Decrescente");
        _mkdir("SelectionSort/Arquivos de Saida/Random");
        _mkdir("SelectionSort/Arquivos de Tempo");
        _mkdir("SelectionSort/Arquivos de Tempo/Crescente");
        _mkdir("SelectionSort/Arquivos de Tempo/Decrescente");
        _mkdir("SelectionSort/Arquivos de Tempo/Random");
    }

    if (escolha == 3) {
        _mkdir("BubbleSort");
        _mkdir("BubbleSort/Arquivos de Entrada");
        _mkdir("BubbleSort/Arquivos de Entrada/Crescente");
        _mkdir("BubbleSort/Arquivos de Entrada/Decrescente");
        _mkdir("BubbleSort/Arquivos de Entrada/Random");
        _mkdir("BubbleSort/Arquivos de Saida");
        _mkdir("BubbleSort/Arquivos de Saida/Crescente");
        _mkdir("BubbleSort/Arquivos de Saida/Decrescente");
        _mkdir("BubbleSort/Arquivos de Saida/Random");
        _mkdir("BubbleSort/Arquivos de Tempo");
        _mkdir("BubbleSort/Arquivos de Tempo/Crescente");
        _mkdir("BubbleSort/Arquivos de Tempo/Decrescente");
        _mkdir("BubbleSort/Arquivos de Tempo/Random");
    }

    if (escolha == 4) {
        _mkdir("ShellSort");
        _mkdir("ShellSort/Arquivos de Entrada");
        _mkdir("ShellSort/Arquivos de Entrada/Crescente");
        _mkdir("ShellSort/Arquivos de Entrada/Decrescente");
        _mkdir("ShellSort/Arquivos de Entrada/Random");
        _mkdir("ShellSort/Arquivos de Saida");
        _mkdir("ShellSort/Arquivos de Saida/Crescente");
        _mkdir("ShellSort/Arquivos de Saida/Decrescente");
        _mkdir("ShellSort/Arquivos de Saida/Random");
        _mkdir("ShellSort/Arquivos de Tempo");
        _mkdir("ShellSort/Arquivos de Tempo/Crescente");
        _mkdir("ShellSort/Arquivos de Tempo/Decrescente");
        _mkdir("ShellSort/Arquivos de Tempo/Random");
    }

    if (escolha == 5) {
        _mkdir("MergeSort");
        _mkdir("MergeSort/Arquivos de Entrada");
        _mkdir("MergeSort/Arquivos de Entrada/Crescente");
        _mkdir("MergeSort/Arquivos de Entrada/Decrescente");
        _mkdir("MergeSort/Arquivos de Entrada/Random");
        _mkdir("MergeSort/Arquivos de Saida");
        _mkdir("MergeSort/Arquivos de Saida/Crescente");
        _mkdir("MergeSort/Arquivos de Saida/Decrescente");
        _mkdir("MergeSort/Arquivos de Saida/Random");
        _mkdir("MergeSort/Arquivos de Tempo");
        _mkdir("MergeSort/Arquivos de Tempo/Crescente");
        _mkdir("MergeSort/Arquivos de Tempo/Decrescente");
        _mkdir("MergeSort/Arquivos de Tempo/Random");
    }

    if (escolha == 6) {
        _mkdir("QuickSort_Versao1");
        _mkdir("QuickSort_Versao1/Arquivos de Entrada");
        _mkdir("QuickSort_Versao1/Arquivos de Entrada/Crescente");
        _mkdir("QuickSort_Versao1/Arquivos de Entrada/Decrescente");
        _mkdir("QuickSort_Versao1/Arquivos de Entrada/Random");
        _mkdir("QuickSort_Versao1/Arquivos de Saida");
        _mkdir("QuickSort_Versao1/Arquivos de Saida/Crescente");
        _mkdir("QuickSort_Versao1/Arquivos de Saida/Decrescente");
        _mkdir("QuickSort_Versao1/Arquivos de Saida/Random");
        _mkdir("QuickSort_Versao1/Arquivos de Tempo");
        _mkdir("QuickSort_Versao1/Arquivos de Tempo/Crescente");
        _mkdir("QuickSort_Versao1/Arquivos de Tempo/Decrescente");
        _mkdir("QuickSort_Versao1/Arquivos de Tempo/Random");
    }

    if (escolha == 7) {
        _mkdir("QuickSort_Versao2");
        _mkdir("QuickSort_Versao2/Arquivos de Entrada");
        _mkdir("QuickSort_Versao2/Arquivos de Entrada/Crescente");
        _mkdir("QuickSort_Versao2/Arquivos de Entrada/Decrescente");
        _mkdir("QuickSort_Versao2/Arquivos de Entrada/Random");
        _mkdir("QuickSort_Versao2/Arquivos de Saida");
        _mkdir("QuickSort_Versao2/Arquivos de Saida/Crescente");
        _mkdir("QuickSort_Versao2/Arquivos de Saida/Decrescente");
        _mkdir("QuickSort_Versao2/Arquivos de Saida/Random");
        _mkdir("QuickSort_Versao2/Arquivos de Tempo");
        _mkdir("QuickSort_Versao2/Arquivos de Tempo/Crescente");
        _mkdir("QuickSort_Versao2/Arquivos de Tempo/Decrescente");
        _mkdir("QuickSort_Versao2/Arquivos de Tempo/Random");
    }

    if (escolha == 8) {
        _mkdir("QuickSort_Versao3");
        _mkdir("QuickSort_Versao3/Arquivos de Entrada");
        _mkdir("QuickSort_Versao3/Arquivos de Entrada/Crescente");
        _mkdir("QuickSort_Versao3/Arquivos de Entrada/Decrescente");
        _mkdir("QuickSort_Versao3/Arquivos de Entrada/Random");
        _mkdir("QuickSort_Versao3/Arquivos de Saida");
        _mkdir("QuickSort_Versao3/Arquivos de Saida/Crescente");
        _mkdir("QuickSort_Versao3/Arquivos de Saida/Decrescente");
        _mkdir("QuickSort_Versao3/Arquivos de Saida/Random");
        _mkdir("QuickSort_Versao3/Arquivos de Tempo");
        _mkdir("QuickSort_Versao3/Arquivos de Tempo/Crescente");
        _mkdir("QuickSort_Versao3/Arquivos de Tempo/Decrescente");
        _mkdir("QuickSort_Versao3/Arquivos de Tempo/Random");
    }

    if (escolha == 9) {
        _mkdir("HeapSortMin");
        _mkdir("HeapSortMin/Arquivos de Entrada");
        _mkdir("HeapSortMin/Arquivos de Entrada/Crescente");
        _mkdir("HeapSortMin/Arquivos de Entrada/Decrescente");
        _mkdir("HeapSortMin/Arquivos de Entrada/Random");
        _mkdir("HeapSortMin/Arquivos de Saida");
        _mkdir("HeapSortMin/Arquivos de Saida/Crescente");
        _mkdir("HeapSortMin/Arquivos de Saida/Decrescente");
        _mkdir("HeapSortMin/Arquivos de Saida/Random");
        _mkdir("HeapSortMin/Arquivos de Tempo");
        _mkdir("HeapSortMin/Arquivos de Tempo/Crescente");
        _mkdir("HeapSortMin/Arquivos de Tempo/Decrescente");
        _mkdir("HeapSortMin/Arquivos de Tempo/Random");
    }

    if (escolha == 10) {
        _mkdir("FilaPrioridadeMinima");
    }
}

int escolherTamanho() {
    cout << "\nEscolha o tamanho:\n1 - 10\n2 - 100\n3 - 1000\n4 - 10000\n5 - 100000\n6 - 1000000\nOpcao: ";
    int x;
    cin >> x;
    int t[6] = {10, 100, 1000, 10000, 100000, 1000000};
    if (x < 1 || x > 6) return -1;
    return t[x - 1];
}

void gerarVetor(vector<int>& v, char tipo, int tamanho, int escolha) {
    v.clear();
    if (tipo == 'C' || tipo == 'c')
        GeradorCrescente::gerarcrescente(v, tamanho, escolha);
    else if (tipo == 'D' || tipo == 'd')
        GeradorDecrescente::gerardecrescente(v, tamanho, escolha);
    else if (tipo == 'R' || tipo == 'r') {
        GeradorRandom g;
        g.gerarrandom(v, tamanho, escolha);
    }
}

void executarAlgoritmo(vector<int>& v, int escolha, char tipo) {
    if (escolha == 1) InsertionSort::sort(v, tipo);
    else if (escolha == 2) SelectionSort::sort(v, tipo);
    else if (escolha == 3) BubbleSort::sort(v, tipo);
    else if (escolha == 4) ShellSort::sort(v, tipo);
    else if (escolha == 5) MergeSort::sort(v, tipo);
    else if (escolha >= 6 && escolha <= 8) QuickSort::sort(v, tipo, escolha);
}

void menuFilaPrioridade() {

    vector<int> vetor(10000);
    int tamanho = 0;
    int opcao = -1;

    while (opcao != 0) {
        cout << "\n===== FILA DE PRIORIDADE MINIMA =====\n";
        cout << "1 - Inserir\n";
        cout << "2 - Extrair minimo\n";
        cout << "3 - Mostrar minimo\n";
        cout << "4 - Aumentar chave\n";
        cout << "5 - Imprimir heap\n";
        cout << "0 - Voltar\nOpcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int chave;
            cout << "Valor: ";
            cin >> chave;
            if (tamanho == 10000) cout << "Fila cheia!\n";
            else {
                FilaPrioridadeMinima::max_heap_insert(vetor, tamanho, chave);
                FilaPrioridadeMinima::salvar_fila(vetor, tamanho);
            }
        }

        if (opcao == 2) {
            if (tamanho == 0) cout << "Fila vazia!\n";
            else {
                int m = FilaPrioridadeMinima::heap_extract_min(vetor, tamanho);
                FilaPrioridadeMinima::salvar_fila(vetor, tamanho);
                cout << "Minimo removido: " << m << endl;
            }
        }

        if (opcao == 3) {
            if (tamanho == 0) cout << "Fila vazia!\n";
            else cout << "Minimo: " << FilaPrioridadeMinima::heap_minimum(vetor, tamanho) << endl;
        }

        if (opcao == 4) {
            int indice, chave;
            cout << "Indice: ";
            cin >> indice;
            cout << "Nova chave: ";
            cin >> chave;
            if (indice < 0 || indice >= tamanho) cout << "Indice invalido!\n";
            else {
                FilaPrioridadeMinima::heap_increase_key(vetor, tamanho, indice, chave);
                FilaPrioridadeMinima::salvar_fila(vetor, tamanho);
            }
        }

        if (opcao == 5) {
            FilaPrioridadeMinima::imprimir_heap(vetor, tamanho);
        }
    }
}

int main() {

    vector<int> v;
    int escolha;
    char tipo;

    cout << "======================================================\n";
    cout << "          MENU DE ALGORITMOS DE ORDENACAO\n";
    cout << "======================================================\n";
    cout << "1 - Insertion Sort\n";
    cout << "2 - Selection Sort\n";
    cout << "3 - Bubble Sort\n";
    cout << "4 - Shell Sort\n";
    cout << "5 - Merge Sort\n";
    cout << "6 - Quick Sort Versao 1\n";
    cout << "7 - Quick Sort Versao 2\n";
    cout << "8 - Quick Sort Versao 3\n";
    cout << "9 - Heap Sort Minimo\n";
    cout << "10 - Fila de Prioridade Minima\n";
    cout << "0 - Sair\n";
    cout << "Opcao: ";
    cin >> escolha;

    if (escolha == 0) return 0;

    if (escolha == 10) {
        criarPastas(10);
        menuFilaPrioridade();
        return 0;
    }

    criarPastas(escolha);

    cout << "\nTipo (C/D/R): ";
    cin >> tipo;

    int tamanho = escolherTamanho();
    if (tamanho <= 0) return 0;

    gerarVetor(v, tipo, tamanho, escolha);

    if (escolha == 9) {
        HeapSortMin::sort(v, tipo);
    } else {
        executarAlgoritmo(v, escolha, tipo);
    }

    system("pause");
    return 0;
}
