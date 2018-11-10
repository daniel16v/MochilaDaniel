// Problema da mochila programacao dinamica 
// Daniel Vaz de Oliveira Matricula 1420226

#include <iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

int Mochila(int MochilaMax, int PesoItem[], int b[], int NItens)
{
	// criando Tabela para preenchimetno
	int V[NItens + 1][MochilaMax + 1];
	int cont=1;

	// inicializando matriz
	for(int w = 0; w <= MochilaMax; w++)
		V[0][w] = 0;
	for(int i = 1; i <= NItens; i++)
		V[i][0] = 0;

	for(int i = 1; i <= NItens; i++)
	{	
		for(int w = 1; w <= MochilaMax; w++)
		{	
			// Teste se o elemento pode fazer parte da soluÁ„o
			if(PesoItem[i - 1] <= w)
			{
				// max...
				if((b[i - 1] + V[i - 1][w - PesoItem[i - 1]]) > V[i - 1][w]){
				
					V[i][w] = b[i - 1] + V[i - 1][w - PesoItem[i - 1]];
					
					}
				else{
					V[i][w] = V[i - 1][w];
			
				}
			}
			else
				V[i][w] = V[i - 1][w]; // wi > w
		
		} //Tentando exibir elemento 
		printf("\nItem  %i", V[i][cont]);
		cont = cont+1;
	}

	// retorna o valor m√°ximo colocado na mochila
	return V[NItens][MochilaMax];
}

int main(int argc, char *argv[])
{
	int MochilaMax = 10;
	int NItens = 5;
	// vetor com os valores (beneficio) de cada elemento
	int b[] = {3, 5, 8, 4, 10};
	// vetor com os pesos de cada elemento
	int PesoItem[] = {2, 4, 5, 3, 9};

	// obt√©m o m√°ximo valor que pode ser colocado na mochila
	int max_valor = Mochila(MochilaMax, PesoItem, b, NItens);

	printf("\nValor maximo %i", max_valor);

	return 0;
}
