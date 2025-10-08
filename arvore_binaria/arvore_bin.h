#ifndef ARVORE_BIN
#define ARVORE_BIN

//atributos
typedef struct no {
    int dado;
    struct no *esq, *dir;
} No;


//funcoes

No* criar_no(int x, No *l, No *r);

void destruir_arvore(No **raiz);

void imprimir_arvore(No *raiz);

No* procurar_valor(No *raiz, int x);

int numero_nos(No *raiz);

int altura(No *raiz);
#so um teste

#endif
