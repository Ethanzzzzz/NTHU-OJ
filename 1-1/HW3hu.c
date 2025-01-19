#include <stdio.h>
#include <math.h>
void SAO(){
    int i, j;
    int n;
    int q;
    int l, r;
    scanf("%d",&n);
    int order[n];
    for(i=0;i<n;i++){
        scanf("%d",&order[i]);
    }
    scanf("%d",&q);
    while(q){
        q--;
        scanf("%d %d",&l,&r);
        int count[n];
        for(i=0;i<n;i++){
            count[i] = 0;
        }
        for(i=l-1;i<r;i++){        // l=1,r=3 so for i in order[i] from 0 to 2
            for(j=l-1;j<r;j++){
                if(order[i] == order[j]){
                    count[i]+=1;
                }
            }
        }
        int dish=0,max=0;
        for(int i=l-1;i<r;i++){
            if(max < count[i]){
                max = count[i];
                dish = i;
            }
            if(max == count[i]){
                if(order[i]<order[i-1]){
                    dish = i;
                }
                
            }
        }
        printf("%d\n",order[dish]);
        
    }
        
}

void binary(){
    int decimal_input;
    int to_binary[32];
    scanf("%d",&decimal_input);
    int length = 1;
    if(decimal_input == 0){
        printf("0\n");
    }
    else{
        for(int i=0;decimal_input!=0;i++){
            to_binary[i] = decimal_input%2;
            decimal_input /= 2;
            length++;
        }
        for(int i=length-1;i>=0;i--){
            printf("%d",to_binary[i]);
        }
        printf("\n");
    }
}

int main(){
    binary();
    return 0;
}