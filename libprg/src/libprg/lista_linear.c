//
// Created by Babi on 15/09/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

ListaLinear* lista_criar(void) {
    ListaLinear *lista = malloc(sizeof(ListaLinear));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

