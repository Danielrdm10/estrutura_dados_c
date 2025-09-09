#include <stdio.h>
#include "fila.h"

int main(){
    Fila *fi;
    fi = cria_fila();
    struct aluno al = {123,"daniel",10,10,8};
    struct aluno al2 = {123,"fulano",10,10,8};
    struct aluno al3 = {123,"cicrano",10,10,8};
    struct aluno al4 = {123,"renato",10,10,8};
    struct aluno al5 = {123,"cassia",10,10,8};
    struct aluno al6 = {123,"edite",10,10,8};
    struct aluno al7 = {123,"Jorge",10,10,8};


    enqueue(fi, al);
    enqueue(fi, al2);
    enqueue(fi, al3);
    enqueue(fi, al4);
    enqueue(fi, al5);

    dequeue(fi);
    dequeue(fi);

    enqueue(fi, al6);
    enqueue(fi, al7);
    dequeue(fi);


    show(fi);
    puts("ola");

    int tam = tamanho(fi);
    printf("Tamanho da fila é %d\n", tam);
    
}