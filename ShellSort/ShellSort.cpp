// ShellSort.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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

void ShellSort(int arr[100])
{
	int contadorTick = 0;
	long tempoTick[5000];
	int f = 0;
	clock_t t;

	int h = 1;
	int n = 100;

	t = clock();

	while (h < n)
	{
		h = h * 3 + 1;
	}

	h = h / 3;
	int c, j;
	while (h > 0)
	{
		for (int i = h; i < n; i++)
		{
			c = arr[i];
			j = i;
			while (j >= h && arr[j - h] > c)
			{
				arr[j] = arr[j - h];
				j = j - h;

				tempoTick[contadorTick] = clock() - t;
				contadorTick++;
			}
			arr[j] = c;
		}
		h = h / 2;
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

	ShellSort(lista);

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
