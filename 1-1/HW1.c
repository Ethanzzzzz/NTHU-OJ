#include <stdio.h>
int multipy(){
    int int1,int2,int3,int4;
    scanf("%d.%2d %d.%2d",&int1,&int2,&int3,&int4);
    int a = 100*int1+int2;
    int b = 100*int3+int4;
    int ans = a*b;
    printf("%d.%4d\n",ans/10000,ans%10000);
    return 0;
}

int cat(){
    printf(" ^   ^      \n(=-w-=)----?\n  \" \"   \" \" \n");
    return 0;
}

int anyacoin(){
    int P,A,B,C,D;
    int count = 0;
    scanf("%d %d %d %d %d",&P,&A,&B,&C,&D);
    if(P <= A+5*B+10*C+50*D){
        while(P >= 50 && D > 0){
            P = P-50;
            D--;
            count++;
        }
        while(P >= 10 && C > 0){
            P = P-10;
            C--;
            count++;
        }
        while(P >= 5 && B > 0){
            P = P-5;
            B--;
            count++;
        }
        while(P >= 1 && A > 0){
            P = P-1;
            A--;
            count++;
        }
        if(P == 0){
            printf("%d\n",count);
        }
        else{
            printf("-1\n");
        }
    }
    else{
        printf("-1\n");
    }
    return 0;
}

int main(){
    cat();
    return 0;
}