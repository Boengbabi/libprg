//
// Created by Babi on 24/09/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

ListaEncadeada *lenc_criar(void) {
    ListaEncadeada *l = malloc(sizeof(ListaEncadeada));
    if (l == NULL) return NULL;
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

int lenc_inserir(ListaEncadeada *l, int valor) {
    if (l == NULL) return -1;
    NoLE *novo = malloc(sizeof(NoLE));
    if (novo == NULL) return -1;
    novo->valor = valor;
    novo->proximo = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        NoLE *atual = l->inicio;
        while (atual->proximo != NULL) atual = atual->proximo;
        atual->proximo = novo;
    }
    l->tamanho++;
    return 0;
}

int lenc_remover(ListaEncadeada *l, int *valor) {
    if (l == NULL || l->inicio == NULL) return -1;
    NoLE *remover = l->inicio;
    if (valor != NULL) *valor = remover->valor;
    l->inicio = remover->proximo;
    free(remover);
    l->tamanho--;
    return 0;
}

int lenc_primeiro(const ListaEncadeada *l, int *valor) {
    if (l == NULL || l->inicio == NULL) return -1;
    *valor = l->inicio->valor;
    return 0;
}

int lenc_tamanho(const ListaEncadeada *l) {
    return l == NULL ? 0 : l->tamanho;
}

void lenc_imprimir(const ListaEncadeada *l) {
    if (l == NULL) return;
    for (NoLE *n = l->inicio; n != NULL; n = n->proximo)
        printf("%d ", n->valor);
    printf("\n");
}

void lenc_destruir(ListaEncadeada *l) {
    if (l == NULL) return;
    NoLE *atual = l->inicio;
    while (atual != NULL) {
        NoLE *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(l);
}