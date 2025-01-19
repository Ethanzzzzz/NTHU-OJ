#include <stdio.h>
int math(){
    float G,B,S;
    scanf("%f %f %f",&G,&B,&S);
    long long int x = G*B;
    float y = G/S;
    printf("%lld\n%.2f\n",x,y);
}
int encrypt(){
    char input[5];
    scanf("%s",input);
    char lower[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char upper[] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
    int i;
    int j;
    for (i = 0;i < 4;i++){
        for (j = 0;j < 26;j++){
            if (input[i] == lower[j]){
                printf("%c",upper[j]);
            }
        }
    }
    for (j = 0;j <= 25;j++){
        if (input[4] == lower[j]){
            printf("%c\n",upper[j]);
        }
    }
}
int main(){
    encrypt();
    return 0;
}