#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void max_min(){
    int R, C;
    scanf("%d %d",&R,&C);
    int array[R][C];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&array[i][j]);
        }
    }
    int max=0, min=array[0][0];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(array[i][j] > max){
                max = array[i][j];
            }
            if(array[i][j] < min){
                min = array[i][j];
            }
        }
    }
    int i_max, j_max, i_min, j_min;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(array[i][j] == max){
                i_max = i;
                j_max = j;
            }
            if(array[i][j] == min){
                i_min = i;
                j_min = j;
            }
        }
    }
    int location_difference = abs(i_max - i_min) + abs(j_max - j_min);
    int value_difference = abs(max - min);
    printf("%d %d",location_difference,value_difference);
}


void bingo_rotation(){
    int n;
    scanf("%d",&n);
    int card[n][n];
    int degree;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&card[i][j]);
        }
    }
    scanf("%d",&degree);
    int convert_card[n][n];
    int temp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(degree == 90){
                temp[i][j] = card[i][(n-1)-j];
            }
            if(degree == 180){
                temp[i][j] = card[i][(n-1)-j];
            }
            if(degree == 270){
                temp[i][j] = card[(n-1)-i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(degree == 0){
                convert_card[i][j] = card[i][j];
            }
            if(degree == 90){
                convert_card[i][j] = temp[j][i];
            }
            if(degree == 180){
                convert_card[i][j] = temp[(n-1)-i][j];
            }
            if(degree == 270){
                convert_card[i][j] = temp[j][i];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-1);j++){
            printf("%d ",convert_card[i][j]);
        }
        printf("%d\n",convert_card[i][n-1]);
    }
    
}

int main(){
    bingo_rotation();
}