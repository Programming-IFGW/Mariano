#include <stdio.h>
#include <stdlib.h>

struct vertice {
    int id;
    int connection_number;
    int* connections;
};

void create_connection(struct vertice *grafo, int this_vertice, int this_connection){
    //VERTICE
    int *aux;
    int new_size = 1 + grafo[this_vertice].connection_number;
    aux = malloc(new_size*sizeof(int));
    grafo[this_vertice].connection_number = new_size;

    if(grafo[this_vertice].connections==NULL){
        grafo[this_vertice].connections = malloc(sizeof(int));
        grafo[this_vertice].connections[0] = this_connection;
    }
    else{
        for(int i = 0; i<new_size-1; i++){
            aux[i] = grafo[this_vertice].connections[i];
        };
        aux[new_size] = this_connection;
        free(grafo[this_vertice].connections);
        grafo[this_vertice].connections = &aux[0]; 
    };
    //CONNECTION
    new_size = 1 + grafo[this_connection].connection_number;
    aux = malloc(new_size*sizeof(int));
    grafo[this_connection].connection_number = new_size;

    if(grafo[this_connection].connections==NULL){
        grafo[this_connection].connections = malloc(sizeof(int));
        grafo[this_connection].connections[0] = this_vertice;
    }
    else{
        for(int i = 0; i<new_size-1; i++){
            aux[i] = grafo[this_connection].connections[i];
        };
        aux[new_size] = this_vertice;
        free(grafo[this_connection].connections);
        grafo[this_connection].connections = &aux[0]; 
    };
};

void print_graph(struct vertice *grafo, int size){
    printf("\n\n************ IMPRIMINDO GRAFO **************\n\n");
    for(int i = 0; i<size;i++){
        printf("Vertice:%d\n\n",i);
        int con_num = grafo[i].connection_number;
        if(con_num!=0){
            for(int j=0; j<con_num; j++){
                printf("%d,%d\n",i,grafo[i].connections[j]);
            }
        }
    }

}

int check_conexity(struct vertice *grafo, int size){
    return 0;
}

void app(){
    int this_vertice;
    int this_connection;
    int size_of_graph;

    struct vertice *grafo;
    printf("Insira o número de grafos: ");
    scanf("%d",&size_of_graph);

    //INITIALIZE
    grafo = malloc(size_of_graph*sizeof(struct vertice)); 
    for(int i = 0; i<size_of_graph; i++){
        grafo[i].connections = NULL;
        grafo[i].connection_number = 0;
    }

    //LOOP
    do{
        printf("Use \"-1\" to exit;\n");
        printf("Inserir vértice: ");
        scanf("%d",&this_vertice);
        if(this_vertice==-1) break;
        printf("Inserir ligação: ");
        scanf("%d",&this_connection);

        create_connection(grafo, this_vertice,this_connection);
    }while(this_connection!=-1);
    printf("Aqui: %d", grafo[0].connection_number);

    print_graph(grafo,size_of_graph);
    int is_true = check_conexity(grafo,size_of_graph);
    if(is_true==1) printf("\n\n\t\t É conexo!!\n\n");
    if(is_true==0) printf("\n\n\t\t Não é conexo!!\n\n");
};


void main(){
    app();
}