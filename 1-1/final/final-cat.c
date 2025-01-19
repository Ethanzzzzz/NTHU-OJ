#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y) {return x < y ? x : y;}

typedef struct{
    char name[35];
    char occupation[35];
    int order;
    int age;
} Cat;

Cat cat[10005];

char table[8][20] = {{"elder"},{"nursy"},{"kitty"},{"warrior"},{"apprentice"},{"medicent"},{"deputy"},{"leader"}};

int cmp(const void* pa, const void* pb){
    Cat *a = (Cat*) pa, *b = (Cat*) pb;

    if(a->order < b->order) return -1; // order小的，排序較前
    else if(a->order > b->order) return 1;
    else{ // the same order
        if(a->order == 5 && b->order == 5){ // order == 5，age小的先
            if(a->age < b->age) return -1;
            else if(a->age > b->age) return 1;
            else{ // the same age
                return strcmp(a->name, b->name);
            }
        }
        else{ // order != 5
            if(a->age > b->age) return -1;
            else if(a->age < b->age) return 1;
            else{ // the same age
                return strcmp(a->name, b->name);
            }
        }
    }
}

void convert_occupation(int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<8;j++){
            if(strcmp(cat[i].occupation, table[j]) == 0){
                cat[i].order = j + 1;
                break;
            }
        }
    }
}

int main(){
    // freopen("final-cat.txt", "r", stdin);
    int N, food;
    while(scanf("%d %d", &N, &food) != EOF){
        for(int i=0;i<N;i++){
            memset(cat[i].name, 0, sizeof(cat[i].name));
            memset(cat[i].occupation, 0, sizeof(cat[i].occupation));
        }
        for(int i=0;i<N;i++) scanf("%s %s %d", cat[i].name, cat[i].occupation, &cat[i].age);
        convert_occupation(N);
        qsort(cat, N, sizeof(Cat), cmp);
        for(int i=0;i<min(N, food);i++) printf("%s\n", cat[i].name);
    }
}