// Teste Segunda Parte
#import "criaArqAleatorio.h"
#import "problemaA.h"

typedef FILE* ArqEntradaTipo;

int m, n;
int OrdemIntercalacao;

void OrdeneExternoB() {


}

// se cabem apenas 3 registros na memória e se possui 3 fitas. Esses 3 registros ( se completos ) 
// geram na próxima fita 9 registros por intercalação.

void OrdeneVetor(int n, int m, int OrdemIntercalacao, char *nomeArqEntrada) {
	int NBlocos = 0;
  	ArqEntradaTipo ArqEntrada, ArqSaida;
		ArqEntradaTipo[OrdemIntercalacao] ArrArqEnt;
		short Fim;
		int Low, High, Lim;
		NBlocos = 0;
		ArqEntrada = fopen(nomeArqEntrada, "r"); //abrir arquivo a ser ordenado;
		//do   /*Formacao inicial dos NBlocos ordenados */
		    { 
		NBlocos = criaArquivosOrdenados(ArqEntrada);
		    	// NBlocos++;
		     //  	Fim = EnchePaginas(NBlocos, ArqEntrada);
		     //  	OrdeneInterno;
		     //  	ArqSaida = AbreArqSaida(NBlocos);
		     //  	DescarregaPaginas(ArqSaida);
		     //  	fclose(ArqSaida); 
		    //} while (!Fim);
		//fclose(ArqEntrada);
		Low = 0;
		High = NBlocos-1;
		while (Low < High) /* Intercalacao dos NBlocos ordenados */
		    { Lim = Minimo(Low + OrdemIntercalConst-1, High);
		      AbreArqEntrada(ArrArqEnt, Low, Lim);
		      High++;
		      ArqSaida = AbreArqSaida(High);
		      Intercale(ArrArqEnt, Low, Lim, ArqSaida);
		      fclose(ArqSaida);
		      for(i= Low; i < Lim; i++)
		        { fclose(ArrArqEnt[i]);
		          Apague_Arquivo(ArrArqEnt[i]);
		        }
		      Low += OrdemIntercalConst;
		    }
		//Mudar o nome do arquivo High para o nome fornecido pelo usuario;
} 

int criaArquivosOrdenados(ArqEntradaTipo ArqEntrada) {
	int registros = n / m; int total = 0; int count = 0;
	TipoItem V[registros]; long int chave;
	char novo[20];
	while(!feof(ArqEntrada)) {
		fscanf(ArqEntrada, "%li", &chave);
		TipoItem aux; aux.Chave = chave; strcpy(aux.Peso,"123456789012345678901234");
		V[total] = aux;
		total++;
		if (total == registros) {
			count++;
			sprintf(novo, "Temp%d.txt", count);
			HeapSort(V, total);
			salvaArquivo(novo, V, total, 0);
		}
	}
	if (total > 0) {
		count ++;
		sprintf(novo, "Temp%d.txt", count);
		HeapSort(V, total);
		salvaArquivo(novo, V, total, 0);
	}

	fclose(ArqEntrada);
	return count;
}

void salvaArquivo(char *nome, TipoItem *V, TipoIndice n, int mudaLinhaFinal) {
	FILE *f = fopen(nome, "a");
	for(int i = 0; i < tam - 1; i++) {
		fprintf(f, "%li ", V[i].Chave);
	}

	if (mudaLinhaFinal == 0) {
		fprintf(f, "%li ", V[tam-1]);
	} else {
		fprintf(f, "%li ", V[tam-1]);
	}

	fclose(f);
}

int Minimo(int Lim, int High) {
    if (High <= Lim) {
        return High;
    } else {
        return Lim;
    }
}

void AbreArqEntrada(ArqEntradaTipo* ArrArqEnt, int Low, int Lim) {
    char aux[30];
    for (int i = 0; i <= (Lim - Low); i++) {
        sprintf(aux, "Temp%d.txt", (Low + i));
        ArrArqEnt[i] = fopen(aux, "r");
    }
}

ArqEntradaTipo AbreArqSaida(int NBlocos) {
    char aux[30];
    sprintf(aux, "Temp%d.txt", NBlocos);
    ArqEntradaTipo saida = fopen(aux, "w");
    return saida;
}


void Intercale(ArqEntradaTipo* ArrArqEnt, int Low, int Lim, ArqEntradaTipo ArqSaida) {
    char chaves[Lim - Low + 1];
    char auxChar;
    int auxInt, fim = 0;
    char auxString[40];
    for (int i = 0; i <= (Lim - Low); i++) {
        chaves[i] = fgetc(ArrArqEnt[i]);
    }
    while (fim != 1) {
        auxChar = 'Z';
        auxInt = 999;
        for (int i = 0; i <= (Lim - Low); i++) {
            if ((strcmp(&auxChar, &chaves[i]) > 0)&&(chaves[i] != EOF)) {
                auxChar = chaves[i];
                auxInt = i;
            }
        }
        if (auxInt != 999) {
            fgets(auxString, 40, ArrArqEnt[auxInt]);
            fprintf(ArqSaida, "%c%s", chaves[auxInt], auxString);
            chaves[auxInt] = fgetc(ArrArqEnt[auxInt]);
        } else {
            fim = 1;
        }
    }
}

// HeapSort

void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A)
{ TipoIndice i = Esq;
  int j;
  TipoItem x;
  j = i * 2;
  x = A[i];
  while (j <= Dir) 
    { if (j < Dir) 
      { if (A[j].Chave < A[j+1].Chave) {
        j++;
        }
        comp++;
      }
      comp++;
      if (x.Chave >= A[j].Chave) goto L999;
      A[i] = A[j]; mov++;
      i = j;  j = i * 2;
    }
  L999: A[i] = x; mov += 2;
}

void Constroi(TipoItem *A, TipoIndice n)
{ TipoIndice Esq;
  Esq = n / 2 + 1;
  while (Esq > 1) 
    { Esq--;
      Refaz(Esq, n, A);
    }
}

/*--Entra aqui a funcao Refaz do Programa 4.9 --*/
/*--Entra aqui a funcao Constroi do Programa 4.10--*/

void Heapsort(TipoItem *A, TipoIndice n)
{ TipoIndice Esq, Dir;
  TipoItem x;
  Constroi(A, n);  /* constroi o heap */
  Esq = 1;  Dir = n;
  while (Dir > 1) 
    { /* ordena o vetor */
      x = A[1];  A[1] = A[Dir];  A[Dir] = x;  Dir--; mov += 3; 
      Refaz(Esq, Dir, A);
    }
}


int main() {
	//OrdeneExternoA();
	//n = 33554432;
	//int m = n / 4;
	//criaArquivoAleatorio(n,"primeiro_arquivo.txt");




	return 0;
}