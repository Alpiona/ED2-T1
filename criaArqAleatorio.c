#include   <limits.h>
#include   <stdio.h>
#include   <stdlib.h>
#include   <sys/time.h>

// Gerador de números aleatórios

// Tipos 

typedef long TipoChave;
typedef struct TipoItem {
  TipoChave Chave;
  // ----- TipoChave outroasChaves[9]; // item C exercicio 1
  /* outros componentes */
} TipoItem;

// variaveis para comparacoes e movimentacoes globais
long int comp, mov;
double tMiliSec;

// funcoes auxiliares das variaveis globais
void printVariables(double miliSec) {
	printf("\nComparacoes = %li\n", comp/3);
	printf("Movimentacoes = %li\n", mov/3);
	printf("Tempo(miliSec) = %f\n\n", miliSec / 3.0);
}

typedef int TipoIndice;
typedef TipoItem TipoVetor[MAXTAM + 1]; 
/* MAXTAM+1 por causa da sentinela em Insercao */
TipoVetor A;
TipoIndice i, n;

//  --------------------------------------------
//	Criadores de arquivos com números aleatórios
//  -------------------------------------------- 


void Copia(TipoItem *Fonte, TipoItem *Destino, TipoIndice n)
{ for (i = 1; i <= n; i++)
    Destino[i] = Fonte[i];
}

double rand0a1() 
{ double resultado=  (double) rand()/ INT_MAX; /* Dividir pelo maior inteiro */
  if(resultado>1.0) resultado= 1.0;
  return resultado;
}

void Permut( TipoItem *A, int n) 
{ int i,j;
  TipoItem b;

  for(i = n-1; i>0; i --) 
  { j = (i * rand0a1()) +1 ;
    b = A[i];
    A[i] = A[j];
    A[j] = b;
  }
}

int criaVetor(TipoIndice n) {
	TipoVetor A;
	for (int i = 0; i <= n; i++) {
		A[i].Chave = i;
	}

	Permut(A, n);
	return A;
}

void criaArquivoVetor(TipoItem *A) {
	// pegando o vetor, criar o arquivo
	
}

