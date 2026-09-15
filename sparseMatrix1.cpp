#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROWS 3
#define COLS 3

void add_ver1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            C[i][j] = A[i][j] +B[i][j];
        }
    }
}

int main(void){
int array_A[ROWS][COLS];
int array_B[ROWS][COLS];
int array_C[ROWS][COLS];

for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLS; j++){
        scanf("%d", &array_A[i][j]);
    }
}

for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLS; j++){
        scanf("%d", &array_B[i][j]);
    }
}

add_ver1(array_A, array_B, array_C);
for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLS; j++){
        printf("%d ",array_C[i][j]);

    }
    printf("\n");
}
    
}