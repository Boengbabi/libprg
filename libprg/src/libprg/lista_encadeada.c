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

int lista_inserir(ListaEncadeada *l, int valor) {
    if (l == NULL) return -1;
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return -1;
    novo->valor = valor;
    novo->proximo = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *atual = l->inicio;
        while (atual->proximo != NULL) atual = atual->proximo;
        atual->proximo = novo;
    }
    l->tamanho++;
    return 0;
}

int lista_remover(ListaEncadeada *l, int *valor) {
    if (l == NULL || l->inicio == NULL) return -1;
    No *remover = l->inicio;
    if (valor != NULL) *valor = remover->valor;
    l->inicio = remover->proximo;
    free(remover);
    l->tamanho--;
    return 0;
}

int lista_primeiro(const ListaEncadeada *l, int *valor) {
    if (l == NULL || l->inicio == NULL) return -1;
    *valor = l->inicio->valor;
    return 0;
}

int lista_tamanho(const ListaEncadeada *l) {
    return l == NULL ? 0 : l->tamanho;
}

