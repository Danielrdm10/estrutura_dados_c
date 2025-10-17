#include <stdio.h>
#include <stdlib.h>

int** criar_matriz(int m, int n){
    int **matriz = (int**) malloc(m * sizeof(int*));
	for (int i = 0; i<n; i++){
        matriz[i] = (int*) malloc(n * sizeof(int));
        for (int j = 0; j<m; j++) matriz[i][j]==0;
    }
return matriz;
}    

void printar(int** mat, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) printf("%d ", mat[i][j]);
    printf("\n");
    }

}


int main(){
    int m,n;
    printf("digite o tamanho da matriz: ");
    scanf("%d %d", &m, &n);
    int** mat = criar_matriz(m,n);
    printar(mat, m, n);
}


