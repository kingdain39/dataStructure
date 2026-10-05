#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {
    int row;
    int col;
    int value;
}element;

typedef struct SparseMatrix{
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;



int compare(const void *p1, const void *p2){
    const element *a = (const element *)p1;
    const element *b = (const element *)p2;
    if(a->row==b->row){
        return a->col-b->col;
    }
    return a->row - b->row; 
}

SparseMatrix sparse_matrix_transpose(SparseMatrix a){
    SparseMatrix Ta;
    Ta.rows = a.cols;
    Ta.cols = a.rows;
    Ta.terms = a.terms;


    int ca=0;
    while(ca<a.terms){
        Ta.data[ca].row = a.data[ca].col;
        Ta.data[ca].col = a.data[ca].row;
        Ta.data[ca].value = a.data[ca].value;

        ca++;
    }
    qsort(Ta.data, Ta.terms, 3*sizeof(int), compare); 
    return Ta;
}

void print_sparseMatrix(SparseMatrix a){
    int cursor=0;
    for(int i=0; i<a.rows; i++){
        for(int j=0; j<a.cols; j++){
            if(a.data[cursor].row == i && a.data[cursor].col == j){
                printf("%d ", a.data[cursor].value);
                cursor++;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
    return ;
}

int main(void){

    SparseMatrix m4 = {{{0,0,1},{0,1,2},{1,0,3},{2,0,1},{2,2,7}},3,3,5};
    printf("m4: \n");
    print_sparseMatrix(m4);


    
   
    printf("m4(T): \n");
     print_sparseMatrix(sparse_matrix_transpose(m4));

}