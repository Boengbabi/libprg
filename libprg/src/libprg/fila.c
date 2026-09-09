#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct no_fila {
    int valor;
    struct no_fila* proximo;
} no_fila_t;

struct fila {
    no_fila_t* inicio;
    no_fila_t* fim;
    int tamanho;
};

fila_t* criar_fila(int capacidade)
{
    fila_t* f = malloc(sizeof(struct fila));
    if (f == NULL) {
        exit(EXIT_FAILURE); // não conseguiu alocar memória
    }

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;

    return f;
}

void enfileirar(fila_t* fila, int valor)
{
    no_fila_t* novo = malloc(sizeof(no_fila_t));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila->inicio == NULL) {

        fila->inicio = novo;
        fila->fim = novo;
    } else {

        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    fila->tamanho++;
}

void desenfileirar(fila_t* f)
{
    if (f->inicio == NULL) {
        exit(EXIT_FAILURE); // fila vazia, não tem o que remover
    }

    no_fila_t* removido = f->inicio;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL; // a fila ficou vazia
    }

    free(removido);
    f->tamanho--;
}

int inicio_fila(fila_t* f)
{
    if (f->inicio == NULL) {
        return -1;
    }
    return f->inicio->valor;
}

int fim_fila(fila_t* f)
{
    if (f->fim == NULL) {
        return -1;
    }
    return f->fim->valor;
}

int tamanho_fila(fila_t* f)
{
    return f->tamanho;
}

bool fila_cheia(fila_t* f)
{
    (void)f;
    return false; // lista encadeada não tem limite fixo
}

bool fila_vazia(fila_t* f)
{
    return f->tamanho == 0;
}

void listar_fila(fila_t* f)
{
    no_fila_t* atual = f->inicio;
    while (atual != NULL) {
        printf("\t%d", atual->valor);
        atual = atual->proximo;
    }
}

void destruir_fila(fila_t* f)
{
    no_fila_t* atual = f->inicio;
    while (atual != NULL) {
        no_fila_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(f);
}