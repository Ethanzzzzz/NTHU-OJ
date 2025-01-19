#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int direction;
    int coordinate;
} Particle;

Particle p[200005];
int time = 0, num, collide = 0, R_flag = 0;

int main(){
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        char dir;
        scanf(" %c", &dir);
        p[i].direction = (dir == 'L') ? -1 : 1;
    }
    for(int i=0;i<num;i++){
        scanf("%d", &p[i].coordinate);
        if(p[i].direction == 1) R_flag = 1;
        if(R_flag == 1 && p[i].direction == -1) collide = 1;
    }
    if(!collide){
        printf("-1\n");
        return 0;
    }
    while(1){
        time++;
        for(int i=0;i<num;i++) p[i].coordinate += p[i].direction;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(p[i].coordinate == p[j].coordinate && i != j){
                    printf("%d\n", time);
                    goto stop;
                }
            }
        }
    }
    stop : return 0;
}