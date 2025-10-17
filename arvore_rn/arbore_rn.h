#ifndef ABB
#define ABB

enum Cor {VERMELHO, PRETO}


//atributos
typedef struct no {
    int chave;
    enum Cor cor;
    struct no *esq, *dir;
} No;


//funcoes

No* criar_arvore();

void destruir_arvore(No **p);

void imprimir_arvore(No *p, int h);

void in_order(No *p);

No* inserir(No *p, int chave);

void remover(No **p, int chave);

#endif

