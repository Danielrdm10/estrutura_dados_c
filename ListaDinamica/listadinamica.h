struct node{
    int no;
    int *prox;
};

typedef struct ld{
    struct node *no;
    int tam;
} LinkedL;

LinkedL criar_ld();

int add_node(LinkedL list, struct node no);



