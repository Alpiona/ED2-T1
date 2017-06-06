// #include   <limits.h>
// #include   <stdio.h>
// #include   <stdlib.h>
// #include   <string.h>
// #include   <sys/time.h>

//#define MAXTAM 100

#include "criaArqAleatorio.h"

// Gerador de números aleatórios

// Tipos 

// typedef long int TipoChave;
// typedef char TipoPeso[32];
// typedef struct TipoItem {
//   TipoChave Chave;
//   TipoPeso Peso;

// } TipoItem;

// typedef int TipoIndice;
// TipoIndice i, n;
// typedef TipoItem TipoVetor[MAXTAM + 1]; 
/* MAXTAM+1 por causa da sentinela em Insercao */
//TipoVetor A;

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
{ int j;
  TipoItem b;

  for(i = n-1; i>0; i --) 
  { j = (i * rand0a1()) +1 ;
    b = A[i];
    A[i] = A[j];
    A[j] = b;
  }
}

// void criaVetor(TipoIndice n) {
// 	//if (n == MAXTAM_25) { }
// 	TipoItem Aux[n+1];
// 	TipoItem B[n+1];
// 	for (int i = 0; i <= n; i++) {
// 		A[i].Chave = i;
// 		strcpy(A[i].Peso,"1234567890123456789012345678901");
// 	}
// 	Permut(Aux,n);
// 	Copia(Aux,B,n);
// }

// TipoVetor criaVetor(TipoIndice n) {
// 	TipoVetor B, C;
// 	for (int i = 0; i <= n; i++) {
// 		B[i].Chave = i;
// 		strcpy(B[i].Peso,"1234567890123456789012345678901");
// 	}

// 	Permut(B, n);
// 	Copia(B,C,n);
// 	return B;
// }

void imprimeVetor(TipoItem *V, TipoIndice n) {
	for (i = 1; i <= n; i++)
    printf("%li ", V[i].Chave);  printf("\n");
}

// void criaArquivoVetor(TipoItem *A, TipoIndice n, char nomeArquivo[]) {
// 	FILE *fp = NULL;
// 	fp = fopen(nomeArquivo, "a");
// 	if (fp != NULL) {
// 		printf("\n FILE NOT NULL\n");
// 		for(i=1;i<=n;i++) {
// 			fprintf(fp,"%li ", A[i].Chave);
// 		}
// 		//fwrite(A, sizeof(long), sizeof(A), fp);
// 		fclose(fp);
// 	}
// }

void criaArquivoAleatorio(TipoIndice n, char *nomeArquivo) {
	//criaVetor(n);
	TipoItem Aux[n+1];
	TipoItem B[n+1];
	int auxCount = 0;
	for (i = 1; i <= n; i++) {
		printf("CRIAARQALEATORIO 1\n");
		Aux[i].Chave = i;
		printf("%d", sizeof(i));
		strcpy(Aux[i].Peso,"12345678901234567890123");
		puts(Aux[i].Peso); printf("CRIAARQALEATORIO 2\n"); auxCount++;
		//printf("%s", Aux[i].Peso);
	}
	printf("%d", auxCount);
	Permut(Aux,n);

	Copia(Aux,B,n);

	
	// criando FILE
	FILE *fp = NULL;
	fp = fopen(nomeArquivo, "a");
	if (fp != NULL) {
		printf("\n FILE NOT NULL\n");
		for(i=1;i<=n;i++) {
			if (i == n) {
				fprintf(fp,"%li", Aux[i].Chave);
			} else {
				fprintf(fp,"%li ", Aux[i].Chave);
			}
		}
		//fwrite(A, sizeof(long), sizeof(A), fp);
		fclose(fp);
	}
	//criaArquivoVetor(A,n,nomeArquivo);
}

