struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
   
};

typedef struct fila Fila;


Fila* cria_fila();

int enqueue(Fila* fi, struct aluno al);

int tamanho(Fila* fi);

int dequeue(Fila* fi);

void show(Fila* fi);