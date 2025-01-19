#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    if(a->order < b->order) return -1;
    else if(a->order > b->order) return 1;
    else{
        if(a->order == 5 && b->order == 5){
            if(a->age < b->age) return -1;
            else if(a->age > b->age) return 1;
            else return strcmp(a->name, b->name);
        }
        else{
            if(a->age < b->age) return 1;
            else if(a->age > b->age) return -1;
            else return strcmp(a->name, b->name);
        }
    }
}

int main(){
    int n, food;
    while(scanf("%d %d", &n, &food) != EOF){
        for(int i=0;i<n;i++){
            scanf("%s %s %d", cat[i].name, cat[i].occupation, &cat[i].age);
            for(int j=0;j<8;j++) if(strcmp(cat[i].occupation, table[j]) == 0) cat[i].order = j + 1;
        }
        qsort(cat, n, sizeof(Cat), cmp);
        for(int i=0;i<min(n, food);i++) printf("%s\n", cat[i].name);
    }
    for(int i=0;i<n;i++){
        memset(cat[i].name, 0, sizeof(cat[i].name));
        memset(cat[i].occupation, 0, sizeof(cat[i].occupation));
    }
}