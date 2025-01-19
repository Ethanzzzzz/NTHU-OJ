#include <stdio.h>
#include <stdlib.h>

char expr[31];
int idx = 0, array[4];

int output(int, int, int, int);
// char op();

int main(){
    scanf(" %s", expr);
    for(int A=0; A<2; A++)
        for(int B=0; B<2; B++)
            for(int C=0; C<2; C++)
                for(int D=0; D<2; D++){
                    idx = 0; // initialize
                    printf("%d %d %d %d %d\n", A, B, C, D, output(A, B, C, D));
                }

    // for(int i=0; i<16; i++){ // use 0 ~ 16 in binary form to show the truth table
    //     idx = 0;
    //     // bitwise comparison
    //     for(int  j=0; j<4; j++){ // j == 0 represents A ... 
    //         if(1<<(3-j) & i) array[j] = 1;
    //         else array[j] = 0;

    //         printf("%d ", array[j]);
    //     }
    //     printf("%d\n", op());
    // }
}

int output(int A, int B, int C, int D){
    char c = expr[idx++];
    if (c == '|') return output(A, B, C ,D) | output(A, B, C ,D);
    if (c == '&') return output(A, B, C ,D) & output(A, B, C ,D);
    if (c == 'A') return A;
    if (c == 'B') return B;
    if (c == 'C') return C;
    return D;
}

// char op(){
//     char c = expr[idx];
//     idx += 1;
//     if (c == '|') return op() | op();
//     if (c == '&') return op() & op();
//     return array[c - 'A'];
// }