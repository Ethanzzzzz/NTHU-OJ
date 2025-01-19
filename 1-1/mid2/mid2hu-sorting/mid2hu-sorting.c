#include <stdio.h>
#include "function.h"

int min(int x, int y) {return x < y ? x : y;}

void array2d_sort(int row, int col, long long arr[][500]){
    for(int start=0;start<row;start++){
        for(int r=0;r<min(row, col)-start-1;r++){
            for(int c=0;c<min(row, col)-start-1-r;c++){
                if(arr[c+start][c] > arr[c+start+1][c+1]){
                    int temp = arr[c+start][c];
                    arr[c+start][c] = arr[c+start+1][c+1];
                    arr[c+start+1][c+1] = temp;
                }
            }
        }
    }
    for(int start=1;start<col;start++){
        for(int r=0;r<min(row, col)-start-1;r++){
            for(int c=0;c<min(row, col)-start-1-r;c++){
                if(arr[c][c+start] > arr[c+1][c+start+1]){
                    int temp = arr[c][c+start];
                    arr[c][c+start] = arr[c+1][c+start+1];
                    arr[c+1][c+start+1] = temp;
                }
            }
        }
    }
}