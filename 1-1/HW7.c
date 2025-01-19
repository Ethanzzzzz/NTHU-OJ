#include <stdio.h>
#include <string.h>

int stair_function(int n, int a1, int a2, int a3){
    if(n == 0){
        return a1;
    }
    else{
        a3 = a1 + a2;
        stair_function(n-1, a2, a3, a1);
    }
}

void stair_v1(){
    int N, X;
    int a[41];
    a[0] = 1, a[1] = 1;
    for(int i=2;i<41;i++){
        a[i] = a[i-1] + a[i-2];
    }
    scanf("%d",&N);
    while(N){
        N--;
        scanf("%d",&X);
        printf("%d\n",a[X]);
    }
}

void stair_v2(){
    int N, X;
    int a1 = 1, a2 = 1, a3;
    int ans;
    scanf("%d",&N);
    while(N){
        N--;
        scanf("%d",&X);
        ans = stair_function(X, a1, a2, a3);
        printf("%d\n",ans);
    }
}

//-------------------------------------------------------------

//parameter format ( , , ) = (from, by, to)
int hanoi_function(int n, char A, char B, char C){
    if(n == 0) return 0;
    else{
        hanoi_function(n-1,A,C,B);
        printf("%d\n",n);
        hanoi_function(n-1,B,A,C);
    }
}

void tower_of_hanoi(){
    int n;
    scanf("%d",&n);
    hanoi_function(n,'A','B','C');
}

//-------------------------------------------------------------

long f[50];
long g[50];
long f_function(int i);
long g_function(int i);

long f_function(int i){
    if(i == 0) return f[0];
    else if(i == 1) return f[1];
    else if(i%2 == 0) f[i] = f_function(i-1) + g_function(i/2);
    else f[i] = f_function(i-1) + g_function(i-2);
    return f[i];
}

long g_function(int i){
    if(i == 0) return g[0];
    else if(i == 1) return g[1];
    else if(i%3 == 0) g[i] = g_function(i-1) + f_function(i/3);
    else g[i] = g_function(i-1) + f_function(i-2);
    return g[i];
}

void fibonacci_soup(){
    int n;
    long ans_f, ans_g;
    scanf("%ld %ld %ld %ld %d", &f[0], &f[1], &g[0], &g[1], &n);
    ans_f = f_function(n);
    ans_g = g_function(n);
    printf("%ld %ld\n",ans_f,ans_g);
}

int main(){
    stair_v2();
}