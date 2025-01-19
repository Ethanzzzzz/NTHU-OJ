#include <stdio.h>
#include <stdlib.h>
#include "function.h"

// unsigned*** new_3d_array(unsigned n, unsigned m, unsigned k){           //這個也行 但很慢 因為用超多次malloc()
//     unsigned ***array3D = malloc(n * sizeof(unsigned**));
//     for(int i=0;i<n;i++){
//         array3D[i] = malloc(n * m * sizeof(unsigned*));
//         for(int j=0;j<m;j++){
//             array3D[i][j] = malloc(n * m * k *sizeof(unsigned));
//         }
//     }
//     return array3D;
// }

unsigned*** new_3d_array(unsigned n, unsigned m, unsigned k){
    unsigned ***array3D = malloc(n * sizeof(unsigned**));
    unsigned **pp = malloc(n * m * sizeof(unsigned*));
    unsigned *p = malloc(n * m * k * sizeof(unsigned));
    for(int i=0;i<n;i++){
        array3D[i] = pp + i * m;
        for(int j=0;j<m;j++){
            array3D[i][j] = p + (i * m + j) * k;
        }
    }
    return array3D;
}

void delete_3d_array(unsigned ***arr){
    free(**arr);
    free(*arr);
    free(arr);
}