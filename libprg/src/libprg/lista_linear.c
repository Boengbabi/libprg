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

void lista_inserir(ListaLinear *lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->fim == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
}

int lista_primeiro(ListaLinear *lista) {
    return lista->inicio->valor;
}