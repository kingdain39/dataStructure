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

SparseMatrix sparse_Matrix_add(SparseMatrix a, SparseMatrix b){
    SparseMatrix c;

    int ca=0; 
    int cb=0;
    int cc=0;

    if(a.rows != b.rows || a.cols != b.cols) {
        printf("Size error");
        exit(1);
    }

    c.rows = a.rows;
    c.cols = a.cols;
    c.terms =0;

    while(ca<a.terms && cb<b.terms){
        int numA = a.data[ca].row * a.cols +a.data[ca].col;
        int numB = b.data[cb].row * b.cols +b.data[cb].col;

        if(numA==numB){
            c.data[cc].row = a.data[ca].row;
            c.data[cc].col = a.data[ca].col;
            c.data[cc].value = a.data[ca].value + b.data[cb].value;
            cc++;
            ca++;
            cb++;
        }
        else if(numA>numB){
            c.data[cc] = b.data[cb];
            cc++;
            cb++;
        }
        else{
            c.data[cc] = a.data[ca];
            cc++;
            ca++;
        }

    }

    while(ca < a.terms){
        c.data[cc] = a.data[ca];
        cc++;
        ca++;
    }

    while(cb < b.terms){
        c.data[cc] = b.data[cb];
        cc++;
        cb++;
    }

    c.terms = cc;
    return c;

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

    return Ta;
}

void print_sparseMatrix(SparseMatrix a){

    for(int i=0; i<a.rows; i++){
        for(int j=0; j<a.cols; j++){
            int found =0;
            for(int k=0; k<a.terms; k++){
                if(a.data[k].row==i && a.data[k].col==j){
                    printf("%d ", a.data[k].value);
                    found =1;
                    break;
                }
            }
            if(found==0) printf("0 ");
            
            
        }
        printf("\n");
    }
    printf("\n");
    return ;
}

int main(void){
    SparseMatrix m1 = {{{1,1,5}, {2,2,9}},3,3,2};
    SparseMatrix m2 = {{{0,0,5},{2,2,9}},3,3,2};
    SparseMatrix m3 = sparse_Matrix_add(m1,m2);
    SparseMatrix m4 = {{{0,0,1},{0,1,2},{1,0,3},{2,0,1},{2,2,7}},3,3,5};

    print_sparseMatrix(m3);
    
    print_sparseMatrix(sparse_matrix_transpose(m4));

}