struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* criar_lista();

void libera_lista(Lista* li);

int tamanho(Lista* li);

int add_ini(Lista* li, struct aluno al);

int add_fin(Lista* li, struct aluno al);

int remove_ini(Lista* li);