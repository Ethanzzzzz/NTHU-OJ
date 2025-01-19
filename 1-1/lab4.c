#include <stdio.h>
#include <stdio.h>
void sprinklers(){
    int N;
    scanf("%d",&N);
    int times = 0;                                 //讀取
    int x[N], y[N], r[N];
    for(int i=0;i<N;i++){
        x[i] = 0;
        y[i] = 0;
        r[i] = 0;
    }
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&x[i],&y[i],&r[i]);
    }
    
    
    
    for(int i=0;i<N-1;i++){
        times = 0;
        for(int j=0;j<N;j++){
            if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) < (r[i]+r[j])*(r[i]+r[j])){
                times++;                                                                                   //判斷
            }
            if(times>0){
                printf("%d ",1);
                break;
            }
        }
        if(times == 0){
            printf("%d ",0);
        }
    }
    times = 0;
    for(int j=0;j<N;j++){
            if((x[N-1]-x[j])*(x[N-1]-x[j]) + (y[N-1]-y[j])*(y[N-1]-y[j]) < (r[N-1]+r[j])*(r[N-1]+r[j])){
                times++;
            }
            if(times>0){
                printf("%d\n",1);
                break;
            }
    }
    if(times == 0){
        printf("%d\n",0);
    }
}



void subarray_rotation(){
    int n;
    scanf("%d",&n);
    int A[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    int m, b;    //m = subarray size  ,  b = rotate angle
    scanf("%d %d",&m,&b);
    
    b/=90;
    b%=4;
    
    
    int max=A[0][0], max_i, max_j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(max < A[i][j]){           //find the start of the subarray
                if((i+m-1) < n && (j+m-1) < n){
                    max = A[i][j];
                }  
            }
        }
    }

    
    
    int finish = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(max == A[i][j]){           //find the start of the subarray
                max_i = i;
                max_j = j;
                finish++;
                break;
            }
        }
        if(finish == 1){
            break;
        }
    }
    
    
    
    int temp[m][m];

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            temp[i][j] = A[i+max_i][j+max_j];
        }
    }
    
    int convert[m][m];




    while(b){
        b--;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                convert[i][j] = temp[i][(m-1)-j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                temp[i][j] = convert[j][i];
            }
        }
        for(int i=max_i;i<max_i+m;i++){
            for(int j=max_j;j<max_j+m;j++){
                A[i][j] = temp[i-max_i][j-max_j];
            }
        }
    }
    


    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            printf("%d ",A[i][j]);
        }
        printf("%d\n",A[i][n-1]);
    }
    
}

int main(){
    sprinklers();
}