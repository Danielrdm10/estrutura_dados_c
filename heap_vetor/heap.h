#ifndef ARVORE_BIN
#define ARVORE_BIN

//atributos
typedef struct {
    char nome[20];
    int chave;
    } t_item;

typedef struct{
    t_item *dados;
    int tam, n;
    } PQ;

//funcoes

PQ* pq_criar(int tam);

void pq_destruir(PQ **p);

void pq_adicionar(PQ *p, t_item x);

t_item pq_extrai_maximo(PQ *p);

int pq_vazia(PQ *p);
int pq_cheia(PQ *p);

#endif
