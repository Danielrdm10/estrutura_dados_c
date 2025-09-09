#include "hash.h"
#include <stdio.h>
#include <stdlib.h>


struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash* criarHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i < ha->TABLE_SIZE; i++){
            ha->itens[i] = NULL;
        }
        return ha;
    }

}

void liberaHash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL){
                free(ha->itens[i]);
            }
            free(ha->itens);
            free(ha);
        }
    }
}

//metodos de função hash:
//resto do inteiro, só faz uma operação pra eliminar o bit de sinal.
int chaveDivisao(int chave, int TABLE_SIZE){
    return(chave & 0x7FFFFFFF) % TABLE_SIZE;
}

//metodo da multiplicação
int chaveMulti(int chave, int TABLE_SIZE){
    float A = 0.6180339887; //constante fracionaria, arbitraria.
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

//metodo dobra, dobra e soma os digitos
int chaveDobra(int chave, int TABLE_SIZE){
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE-1);
    return (parte1 ^ parte2);
}

int insereHash_SemColisao(Hash* ha, struct aluno al){
    if(ha==NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = al.matricula;

    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL){
        return 0;
    }
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_SemColisao(Hash* ha, int mat, struct aluno *al){
    if(ha == NULL){
        return 0;
    }

    int pos = chaveDivisao(mat,ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        return 0;
    }
    *al = *(ha->itens[pos]);
    return 1;
}






