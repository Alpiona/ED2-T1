#ifndef PROBLEMAA_H
#define PROBLEMAA_H

struct registroA{
    char chave;
    char peso[32];
};

typedef FILE* ArqEntradaTipo;
typedef struct registroA TipoRegistroA;

void OrdeneExternoA();
short EnchePaginas (int m, int NBlocos, ArqEntradaTipo ArqEntrada, TipoRegistroA* registro);
void OrdenaInterno();

#endif /* PROBLEMAA_H */

