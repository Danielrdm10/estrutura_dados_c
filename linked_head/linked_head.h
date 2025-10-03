#ifndef LINKED_HEAD
#define LINKED_HEAD

typedef struct no{
    int dado;
    struct no *prox;
} No;

No* criar_lista();

void destruir_lista(No **L);

void imprimir_lista(No *L);

//adicionar
void adicionar_inicio(No *L, int x);
void adicionar_final(No *L, int x);

//remover
void remover_inicio(No *L);
void remover_final(No *L);
void remover_valor(No *L, int x);

//buscar
int buscar_valor(No *L, int x);

int tamanho(No *p);

int acessar_primeiro(No *p);

#endif
