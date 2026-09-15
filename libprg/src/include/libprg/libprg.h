#ifndef LABORATORIO_LIBPRG_H
#define LABORATORIO_LIBPRG_H
#include <stdbool.h>

// |-- FILA --|

typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
void desenfileirar(fila_t* f);
int inicio_fila(fila_t* f);
int fim_fila(fila_t* f);
int tamanho_fila(fila_t* f);
bool fila_cheia(fila_t* f);
bool fila_vazia(fila_t* f);
void listar_fila(fila_t *f);
void destruir_fila(fila_t* f);

// |-- LISTA -- |

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct lista_linear {
    No *inicio;
    No *fim;
    int tamanho;
} ListaLinear;

ListaLinear* lista_criar(void);
void lista_inserir(ListaLinear *lista, int valor);
int lista_primeiro(ListaLinear *lista);
int lista_tamanho(ListaLinear *lista);
void lista_remover_inicio(ListaLinear *lista);
void lista_imprimir(ListaLinear *lista);

#endif //LABORATORIO_LIBPRG_H
