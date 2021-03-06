// BubbleSort.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <math.h> 
#include "pch.h"

using namespace std;

void BubbleSort(int arr[100])
{
	int contadorTick = 0;
	long tempoTick[5000];
	int f = 0;
	clock_t t;

	int repos = 0;
	int length = 100;
	
	/*
	 * Irá percorrer o vetor, comparando cada elemento do vetor com o elemento
	 * seguinte (arr[j] = arr[j + 1];)
	 * O numero maximo de execuções do trecho do algoritmo
	 * p/ que o vetor fique ordenado é de N - 1, onde N é o numero de vezes.
	*/

	// i determina o número de etapas para a ordenação 
	for (int i = 0; i < length - 1; i++)
	{
		// j determina o numero de comparações em cada etapa e os indices a serem 
		//pesquisados para a comparação.
		for (int j = 0; j < length - (i + 1); j++)
		{
			t = clock();

			if (arr[j] > arr[j + 1])
			{
				repos = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = repos;
			}

			tempoTick[contadorTick] = clock() - t;
			contadorTick++;
		}
	}

	long tempoTotal = 0;
	long tempoMedio = 0;

	for (int i = 0; i < contadorTick; i++)
	{
		tempoTotal += tempoTick[i];
	}

	tempoMedio = tempoTotal / contadorTick;

	cout << "Resultados de Performance\n";
	cout << "Número de interações: ......." << contadorTick << "\b";
	cout << "Tempo total de interações: ......." << tempoTotal << "\b";
	cout << "Tempo médio de interações: ......." << tempoMedio << "\b";

	for (int i = 0; i < contadorTick; i++)
	{
		tempoTick[i] = 0;
	}
	contadorTick = 0;	
}

int numeroAleatorio(int menor, int maior)
{
	return rand() % (maior - menor + 1) + menor;
}

int main()
{
	setlocale(LC_ALL, "portuguese");

	int lista[100];
	cout << "Lista original:";
	for (int i = 0; i < 100; i++)
	{
		srand((unsigned)time(0));
		lista[i] = numeroAleatorio(0, 100);
		cout << lista[i] << " ";
	}

	BubbleSort(lista);

	return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
