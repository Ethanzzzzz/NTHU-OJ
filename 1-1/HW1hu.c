#include <stdio.h>
#include <math.h>
int binary(){
    int x;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d",&x);
    while(x - pow(2,3) >= 0){
        x = x-8;
        a++;
    }
    while(x - pow(2,2) >= 0){
        x = x-4;
        b++;
    }
    while(x - pow(2,1) >= 0){
        x = x-2;
        c++;
    }
    while(x - pow(2,0) >= 0){
        x = x-1;
        d++;
    }
    printf("%d%d%d%d\n",a,b,c,d);
}

int oniichan(){
    int A,B,C,D,E,F;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    E = (C-B*D)/(A-B);
    F = D-E;
    printf("%d %d",E,F);
}

int  print(){
    printf(" \\|/ \\|/ \\|/ \n(\"_____\")\n( ^ ^)( ^ ^)\n");
}

int main(){
    print();
    return 0;
}

