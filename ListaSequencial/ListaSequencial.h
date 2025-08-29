#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct lista Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho(Lista* li);

int vazia(Lista* li);

int cheia(Lista* li);

int incluir_fim(Lista* li, struct aluno);

int incluir_inicio(Lista* li, struct aluno);

