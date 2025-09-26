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

int add_ini(Lista* li, struct aluno al);

int add_fin(Lista* li, struct aluno al);

int rem_ini(Lista* li);

int rem_fim(Lista* li);

int remover(Lista* li, int mat);

int consulta(Lista* li, int mat, char nome[30]);
