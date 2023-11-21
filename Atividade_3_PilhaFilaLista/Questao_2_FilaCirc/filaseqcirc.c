#include "filaseqcirc.h"
#include <stdio.h>

void criarFila(FilaSeqCir *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
}

int filaVazia(FilaSeqCir *f) {
    if(f->tam == 0) {
        return 1;
    }
    return 0;
}

int filaCheia(FilaSeqCir *f) {
    if((f->fim + 1) % MAX == f->inicio) {
        return 1;
    }
    return 0;
}

int primeiro(FilaSeqCir *f, int *valor) {
    if(filaVazia(f)) {
        return 0;
    }
    *valor = f->elementos[f->inicio];
    return 1;
}

int ultimo(FilaSeqCir *f, int *valor) {
    if(filaVazia(f)) {
        return 0;
    }
    if(f->fim == 0) {
        *valor = f->elementos[f->fim];
        return 1;
    }
    *valor = f->elementos[f->fim - 1];
    return 1;
}

int entrar(FilaSeqCir *f, int elemento) {
    if(filaCheia(f)) {
        return 0;
    }
    f->elementos[f->fim] = elemento;
    f->tam++;
    f->fim = (f -> fim + 1) % MAX;
    return 1;
}

int sair(FilaSeqCir *f, int *valor) {
    if(filaVazia(f)) {
        return 0;
    }
    *valor = f->elementos[f->inicio];
    f->tam--;
    f->inicio = (f->inicio + 1) % MAX;
    return 1;
}

void exibir(FilaSeqCir *f) {
    for(int i = f->inicio; i < f->fim; i++) {
        if(i != f->fim-1) {
            printf("%d, ", f->elementos[i % MAX]);
        }
        else if (i == f->fim-1){
            printf("%d", f->elementos[i % MAX]);
        }
    }
}