//
// Created by Babi on 24/09/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

ListaEncadeada *lista_criar(void) {
    ListaEncadeada *l = malloc(sizeof(ListaEncadeada));
    if (l == NULL) return NULL;
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

