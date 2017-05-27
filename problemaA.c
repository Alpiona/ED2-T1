#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "problemaA.h"

void OrdeneExternoA() {
    int m = 4; //QUANTIDADE DE REGISTROS NA MEMORIA
    int OrdemIntercalacao = 2; //QUANTIDADE DE ARQUIVOS PARA INTERCALAR
    int NBlocos = 0; //IMAGINO QUE SEJA O QUE VAI IDENTIFICAR OS BLOCOS;;
    int ordem[m];
    ArqEntradaTipo ArqEntrada, ArqSaida;
    ArqEntradaTipo arrArqEnt[OrdemIntercalacao];
    TipoRegistroA memoria[m];
    ArqSaida = fopen("teste", "w");
    short Fim;
    int Low, High, Lim;
    NBlocos = 0;
    ArqEntrada = fopen("arquivoentrada.txt", "r");
    do /*Formacao inicial dos NBlocos ordenados */ {
        NBlocos++;
        Fim = EnchePaginas(m, NBlocos, ArqEntrada, memoria); //PEGA A QUANTIDADE DE REGISTROS NÃO USADOS
        m -= Fim; //LIMITE DE REGISTROS MENOS A QUANTIDADE NÃO USADA, PARA NÃO VERIFICAR REGISTROS QUE NÃO ESTÃO SENDO USADOS
        OrdeneInterno(m, ordem, memoria); //ORDENA OS REGISTROS
        ArqSaida = AbreArqSaida(NBlocos);
        DescarregaPaginas(m, ordem, ArqSaida, memoria);
        fclose(ArqSaida);
    } while (!Fim);
    fclose(ArqEntrada);
    Low = 0;
    High = NBlocos - 1;
//    while (Low < High) /* Intercalacao dos NBlocos ordenados */ {
//        Lim = Minimo(Low + OrdemIntercalacao - 1, High);
//        AbreArqEntrada(ArrArqEnt, Low, Lim);
//        High++;
//        ArqSaida = AbreArqSaida(High);
//        Intercale(ArrArqEnt, Low, Lim, ArqSaida);
//        fclose(ArqSaida);
//        for (i = Low; i < Lim; i++) {
//            fclose(ArrArqEnt[i]);
//            Apague_Arquivo(ArrArqEnt[i]);
//        }
//        Low += OrdemIntercalacao;
//    }
//    Mudar o nome do arquivo High para o nome fornecido pelo usuario;
}

short EnchePaginas(int m, int NBlocos, ArqEntradaTipo ArqEntrada, TipoRegistroA* registro) {
    char aux;
    for (short i = 0; i < m; i++) {
        aux = fgetc(ArqEntrada);
        if (aux == '\n') {
            aux = fgetc(ArqEntrada);

        } else if (aux != EOF) {
            registro[i].chave = aux;
            strcpy(registro[i].peso, "1234567890123456789012345678901"); //STRING DE 31 CHARS
        } else {
            return (m - i + 1); //SE ALCANÇAR O FINAL DO ARQUIVO RETORNA A QUANTIDADE DE REGISTRO NA MEMORIA QUE NAO USOU

        }
        char aux = fgetc(ArqEntrada); //PARA TIRAR OS \n DEPOIS DE CADA LETRA
    }
    return 0; //SE NÃO ALCANÇAR, RETORNA 0 PARA CONTINUAR PEGANDO BLOCOS DEPOIS
}

void OrdeneInterno(int m, int ordem[], TipoRegistroA* memoria) {
    char auxChar;
    int usado, auxInt;

    for (int i = 0; i < m; i++) {
        ordem[i] = 999; //TODAS AS POSIÇÕES RECEBEM UM VALOR MAIS ALTO QUE A QUANTIDADE DE REGISTROS NA MEMORIA
    }

    for (int i = 0; i < m; i++) { //PASSA TODAS A POSIÇÕES DO VETOR DE ORDEM
        auxChar = 'z';
        for (int j = 0; j < m; j++) { //PASSA POR TODAS OS REGISTROS NA MÉMORIA
            usado = 0;
            if (strcmp(&auxChar, &memoria[j].chave) >= 0) { //AS CHAVES COM VALOR MAIS BAIXO ENTRAM NESSE 'IF'
                for (int k = 0; k < m; k++) { //OUTRO PARA PASSAR PELAS POSIÇÕES DO VETOR DE ORDEM
                    if (ordem[k] == j) { //CASO O VETOR DE ORDEM JÁ TENHA ESSE REGISTRO, NAO SERA CONSIDERADO A CHAVE MAIS BAIXA
                        usado = 1;
                    }
                }
                if (usado == 0) { //CASO NÃO TENHA AINDA O REGISTRO NO VETOR DE ORDEM, ELE SE TORNA A CHAVE COM VALOR MAIS BAIXO
                    auxChar = memoria[j].chave;
                    auxInt = j;
                }
            }
        }
        ordem[i] = auxInt; //A CHAVE MAIS BAIXA ENTRA PARA O VETOR DE ORDEM
        printf("%c---%c\n", memoria[i].chave, memoria[auxInt].chave);
    } //NO FINAL O VETOR DE ORDEM FICA, POR EXEMPLO, "4132", SIGNIFICA QUE 4ºREGISTRO PRIMEIRO, 1ºREGISTRO EM SEGUNDO,ETC...
    printf("--------PŔOXIMO BLOCO ---------\n");
}

ArqEntradaTipo AbreArqSaida(int NBlocos) {
    char aux[30];
    sprintf(aux, "%d", NBlocos);
    ArqEntradaTipo saida = fopen(aux, "w");
    return saida;
}

void DescarregaPaginas(int m, int ordem[], ArqEntradaTipo ArqSaida, TipoRegistroA* memoria) {
    int aux;
    for (int i = 0; i < m; i++) {
        aux = ordem[i];
        fwrite(&memoria[aux].chave, sizeof (char), sizeof (memoria[aux].chave), ArqSaida);
        fwrite(&memoria[aux].peso, sizeof (char), sizeof (memoria[aux].peso), ArqSaida);
    }
}