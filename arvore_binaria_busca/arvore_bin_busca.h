#ifndef ABB
#define ABB

//atributos
typedef struct no {
    int chave;
    struct no *esq, *dir, *pai;
} No;


//funcoes

No* criar_arvore();

void destruir_arvore(No **p);

void imprimir_arvore(No *p, int h);

void in_order(No *p);

No* inserir(No *p, int chave);

void remover(No **p, int chave);

No* buscar(No *p, int chave);
#endif

