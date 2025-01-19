#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int queue_height[10000001], remember_pos[10000001], level[10000001];
// 這邊如果陣列開太大會TLE

int main(){
    int num_people, comfort_level, num_remember = 0;
    scanf("%d %d", &num_people, &comfort_level);
    for(int i=1;i<=num_people;i++){
        scanf("%d", &queue_height[i]);
        int j;
        for(j=i-1;j>=1;){
            if(queue_height[j] < queue_height[i]){
                j -= level[j] + 1;
            }
            else break;
        }
        level[i] = i - j - 1;
        if(level[i] == comfort_level) remember_pos[num_remember++] = i;
    }
    if(num_remember){
        for(int i=0;i<num_remember-1;i++) printf("%d ", remember_pos[i]);
        printf("%d\n", remember_pos[num_remember-1]);
    }
    else puts("ouo");
}