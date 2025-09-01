struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista *cria_lista();

void libera(Lista* li);

int tamanho(Lista* li);

int vazia(Lista* li);

void add_ini(Lista* li, struct aluno al);

void add_fin(Lista* li, struct aluno al);

