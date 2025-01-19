#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long queue_height[10000010];
int remember_pos[10000010];
int num_people, comfort_level, num_remember = 0;
int flag = 0;

void cal_level(int pos, int num_people, int comfort_level, int level){
    for(int i=pos-1;i>0;i--){
        if(queue_height[i] > queue_height[pos]) break;
        else level++;
    }
    if(level == comfort_level){
        flag = 1;
        remember_pos[num_remember] = pos;
        num_remember++;
    }
    if(pos+1 <= num_people) cal_level(pos+1, num_people, comfort_level, 0);
    else return;
}

int main(){
    scanf("%d %d", &num_people, &comfort_level);
    for(int i=1;i<=num_people;i++) scanf("%lld", &queue_height[i]);
    cal_level(1, num_people, comfort_level, 0);
    if(flag){
        for(int i=0;i<num_remember-1;i++) printf("%d ", remember_pos[i]);
        printf("%d\n", remember_pos[num_remember-1]);
    }
    else puts("ouo");
}