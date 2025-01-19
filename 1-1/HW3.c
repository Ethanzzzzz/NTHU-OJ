#include <stdio.h>
int caesar(){
    int n, x, i;
    char array[3];
    scanf("%s %d",&array,&n);
    x = n%26;
    int convert[3] = {array[0]+x,array[1]+x,array[2]+x};
    for(i=0;i<3;i++){
        if(convert[i]<65){
            convert[i] = convert[i] +26;
        }
        if (convert[i]>90){
            convert[i] = convert[i] -26;
        }
    }
    printf("%c%c%c\n", convert[0], convert[1], convert[2]);
}

int rearrange(){
    int N,M;
    int c=1,i,j;
    int a,b;
    int temp;
    scanf("%d %d",&N,&M);
    int seat[N];
    for(i=0;i<N;i++){
        seat[i] = i+1;
    }
    while(c<=M){
        scanf("%d %d",&a,&b);
        temp = seat[a-1];
        seat[a-1] = seat[b-1];
        seat[b-1] = temp;
        c++;
    }
    for(i=1;i<N;i++){
        for(j=0;j<N;j++){
            if(i == seat[j]){
                printf("%d ",j+1);
            }
        }
    }
    for(j=0;j<N;j++){
        if(N == seat[j]){
            printf("%d\n",j+1);
        }
    }

}



int mapping(){
    char letter[10];
    char input[5];
    int i,j;
    scanf("%s",letter);
    scanf(" %s",input);
    for(j=0;j<=3;j++){
        for(i=1;i<=9;i++){
            if(input[j] == i+48){
                printf("%c",letter[i-1]);
            }
            else if(input[j] == letter[i-1]){
                printf("%c",i+48);
            }
        }
    }
}
int main(){
    mapping();
    return 0;
}


