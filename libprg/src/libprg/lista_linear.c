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

int lista_tamanho(ListaLinear *lista) {
    return lista->tamanho;
}

void lista_remover_inicio(ListaLinear *lista) {
    if (lista->inicio == NULL) return;

    No *temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
    free(temp);
    lista->tamanho--;
}

void lista_imprimir(ListaLinear *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}
