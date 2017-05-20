#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "problemaA.h"

void OrdeneExternoA() {
    int m = 4;  //QUANTIDADE DE REGISTROS NA MEMORIA
    int OrdemIntercalacao = 2;  //QUANTIDADE DE ARQUIVOS PARA INTERCALAR
    int NBlocos = 0; //IMAGINO QUE SEJA O QUE VAI IDENTIFICAR OS BLOCOS
    ArqEntradaTipo ArqEntrada, ArqSaida;
    ArqEntradaTipo arrArqEnt[OrdemIntercalacao];
    TipoRegistroA registro[m];
    short Fim;
    int Low, High, Lim;
    NBlocos = 0;
    ArqEntrada = fopen("arquivoentrada.txt", "r");
    do /*Formacao inicial dos NBlocos ordenados */ {
        NBlocos++;
        Fim = EnchePaginas(m, NBlocos, ArqEntrada, registro);  //PEGA A QUANTIDADE DE REGISTROS
        OrdeneInterno;  //ORDENA OS REGISTROS
        ArqSaida = AbreArqSaida(NBlocos); //CRIA ARQUIVO DE SAIDA 
        DescarregaPaginas(ArqSaida);  //PÕEM OS BLOCOS ORDENADOS
        fclose(ArqSaida);
    } while (!Fim);
    fclose(ArqEntrada);
    Low = 0;
    High = NBlocos - 1;
    while (Low < High) /* Intercalacao dos NBlocos ordenados */ {
        Lim = Minimo(Low + OrdemIntercalacao - 1, High);
        AbreArqEntrada(ArrArqEnt, Low, Lim);
        High++;
        ArqSaida = AbreArqSaida(High);
        Intercale(ArrArqEnt, Low, Lim, ArqSaida);
        fclose(ArqSaida);
        for (i = Low; i < Lim; i++) {
            fclose(ArrArqEnt[i]);
            Apague_Arquivo(ArrArqEnt[i]);
        }
        Low += OrdemIntercalacao;
    }
    Mudar o nome do arquivo High para o nome fornecido pelo usuario;
}

short EnchePaginas(int m, int NBlocos, ArqEntradaTipo ArqEntrada, TipoRegistroA* registro) {
    char aux;
    for (short i = 0; i < m; i++) {
        aux = fgetc(ArqEntrada);
        if (aux != EOF) {
            registro[i].chave = fgetc(ArqEntrada);
            strcpy(registro[i].peso, "12345678901234567890123456789012"); //STRING DE 32 CHARS

        } else {
            return i;       //SE ALCANÇAR O FINAL DO ARQUIVO RETORNA A QUANTIDADE DE RECURSOS Q PEGOU
        }
        char aux = fgetc(ArqEntrada); //PARA TIRAR OS \n DEPOIS DE CADA LETRA
    }
    return 0;   //SE NÃO ALCANÇAR, RETORNA 0 PARA CONTINUAR PEGANDO BLOCOS DEPOIS
}

void OrdenaInterno(){
    
}