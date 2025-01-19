#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int height[16], jumped[16], color[16], route[16];
int max_energy = 0, max_jump = 0;
int N, start, end;
int energy(int step);
void jump(int current, int end, int step);


int main(){
    scanf("%d %d %d", &N, &start, &end);
    for(int i=1;i<=N;i++) scanf(" %d", &height[i]); // 讀取，從 1 開始
    for(int i=1;i<=N;i++) scanf(" %d", &color[i]);
    for(int i=1;i<=N;i++) jumped[i] = 0;   // 初始化
    for(int i=1;i<=N;i++) route[i] = 0;
    jump(start,end,0);   //開跳
    printf("%d %d\n",max_energy,max_jump);
}

int energy(int step){    // 我是一次算 走到終點的話用route[]一次算出來
    int energy = 0;
    for(int i=0;i<step;i++){
        int a = route[i], b = route[i+1];
        int ha = height[a], hb = height[b];
        energy += abs(a - b) * abs(ha - hb);
    }
    return energy;
}

void jump(int current, int end, int step){
    jumped[current] = 1;     // 目前的這格設成 1 代表走過了
    route[step] = current;   // 記錄第幾步走到哪顆石頭 step 從 0 開始
    if(current == end){      //如果走到 end 開始計算 energy，如果 max 比較小的話，更新、相等的話比較 step，取大的那個
        if(max_energy < energy(step)){
            max_energy = energy(step);
            max_jump = step;
        }
        else if(max_energy == energy(step) && max_jump < step){
            max_jump = step;
        }
    }
    else{
        if(current-1>0 && jumped[current-1] == 0)jump(current-1, end, step+1);    // 判斷能跳的話就跳
        if(current+1<=N && jumped[current+1] == 0)jump(current+1, end, step+1);   // 判斷條件 : 那一格在 0 到 N 之間，以及沒被跳過
        for(int i=1;i<=N;i++){                                                    //相同顏色的話，判斷沒跳過就跳
            if(color[i] == color[current] && jumped[i] == 0) jump(i, end, step+1);
        }
    }
    jumped[current] = 0;
    route[step] = 0;       // 把路徑、有無走過都歸零
}
