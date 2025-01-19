#include <stdio.h> // AC(10/10)
#include <stdlib.h>
#include <string.h>

int n, count_cmp = 0, count_swap = 0, sorted = 0;
int arr[10001];

void iter_swap(int *pa, int *pb){
    sorted = 0;
    count_swap++;
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void bubble_sort(int *begin, int *end){
    for(; begin < end; end--){
        sorted = 1; // when start a loop, set to 1
        for(int *ptr = begin + 1; ptr < end; ptr++){
            count_cmp++;
            if(*(ptr - 1) > *ptr){
                iter_swap(ptr - 1, ptr);
            }
        } 
        // if after a loop, sorted != 0, means it didn't go into iter_swap() at all
        // which means the array has already been sorted
        if(sorted) break;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    bubble_sort(arr, arr+n);
    printf("%d %d\n", count_cmp, count_swap);
}