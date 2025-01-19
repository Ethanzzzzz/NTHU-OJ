#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int start, end;
    scanf("%d %d", &start, &end);
    int ans = 0;
    while(start < end){
        start >>= 1;
        end >>= 1;
        ans++;
        printf("start is %d, end is %d, ans is %d\n", start, end, ans);
    }
    ans = end << ans;
    printf("%d\n", ans);
}

// int main(){
//     int T, start, end;
//     scanf("%d", &T);
//     while(T--){
//         scanf("%d %d", &start, &end);
//         int ans = start;
//         int t;
//         for(int i=0;i<32;i++){
//             if(pow(2, i) > start){
//                 t = pow(2, i);
//                 break;
//             }
//         }
//         printf("t is %d\n", t);
//         if(end < t){
//             for(int i = start + 1; i < end; i++){
//                 ans = ans & i & i+1;
//             }
//         }
//         else ans = 0;
//         printf("%d\n", ans);
//     }
// }