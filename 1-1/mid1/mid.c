#include <stdio.h>
#include <string.h>

char zip[1000][4000] = {'\0'};
void simple_zip(){
    char input[1000][1000] = {'\0'};
    char chr;
    float compress_rate[1000][2];
    char count = '1';
    int zip_pos = 0;  //要存放在zip[]的哪格
    int line = 0, word = 0;  //讀input會用到的，line可以順便紀錄有幾列
    int len[1000];
    while((chr = getchar()) != EOF){
        if(chr == '\n'){
            ++line;
            word = 0;
            continue;
        }
        input[line][word] = chr;
        word++;
    }
    
    for(int i=0;i<line;i++){
        len[i] = strlen(input[i]);
        zip_pos = 0;
        for(int j=0;j<len[i];j++){
            if(input[i][j] == input[i][j+1]){
                count += 1;
                continue;
            }
            zip[i][zip_pos] = count;
            count = '1';
            ++zip_pos;
            if((input[i][j] > 47) && (input[i][j] < 58) ){
                zip[i][zip_pos] = '\'';
                ++zip_pos;
                zip[i][zip_pos] = input[i][j];
                ++zip_pos;
                zip[i][zip_pos] = '\'';
                ++zip_pos;
            }
            else{
                zip[i][zip_pos] = input[i][j];
                ++zip_pos;
            }
        }
        compress_rate[i][0] = (float)zip_pos / (float)len[i];
    }

 

    for(int i=0;i<line;i++){
        printf("%s\n",zip[i]);
        if(compress_rate[i][0] >= 1){
            printf("the string can't zip\n");
        }
        else{
            printf("compress rate:%6.3f\n",compress_rate[i][0]);
        }
        
    }
}

char array[5001][5001] = {' '};
void spiral(){
    int T;
    scanf("%d",&T);
    int N;
    while(T){
        T--;
        scanf("%d",&N);
        int x = -1, y = 0;
        int direction = 1, step = N, limit = 1;
        while(1){
            if(direction == 1 && step > 0){
                x++;
                step--;
                array[y][x] ='#';
                if(step <= 0){
                    direction = -2;
                    step = N - limit;
                    limit++;
                }
            }
            if(direction == -1 && step > 0){
                x--;
                step--;
                array[y][x] ='#';
                if(step <= 0){
                    direction = 2;
                    step = N - limit;
                    limit++;
                }
            }
            if(direction == 2 && step > 0){
                y--;
                step--;
                array[y][x] ='#';
                if(step <= 0){
                    direction = 1;
                    step = N - limit;
                    limit++;
                }
            }
            if(direction == -2 && step > 0){
                y++;
                step--;
                array[y][x] ='#';
                if(step <= 0){
                    direction = -1;
                    step = N - limit;
                    limit++;
                }
            }
            if(limit > N){
                break;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N-1;j++){
                if(array[i][j] == '#'){
                    printf("%c",array[i][j]);
                    array[i][j] = '\0';
                }
                else{
                    printf(" ");
                }
            }
            if(array[i][N-1] == '#'){
                printf("%c\n",array[i][N-1]);
                array[i][N-1] = '\0';
            }
        }
    }
}

long long prefix[1000001] = {0};
void prefix_sum(){
    int size, times, L, R;
    long long sum = 0;
    int ei = 0;
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        scanf("%d",&ei);
        prefix[i] = prefix[i-1] + ei;
    }
    scanf("%d",&times);
    while(times){
        times--;
        scanf("%d %d",&L,&R);
        sum = prefix[R] - prefix[L-1];
        printf("%lld\n",sum);
        sum = 0;
    }
}

void palindrome(){
    char input[100001];
    int start = 0, end;
    int flag = 1;
    int pos = 0;
    char ch;
    while(1){
        pos = 0;
        start = 0;
        while((ch = getchar()) != EOF && ch != '\n'){
            input[pos] = ch;
            pos++;
        }
        if(ch == EOF){
            break;
        }
        end = strlen(input)-1;
        while(start <= end){
            if(input[start] != input[end]){
                flag = 0;
            }
            start++;
            end--;
        }
        if(flag){
            printf("Yes\n");
            flag = 1;
            memset(input,0,sizeof(input));
        }
        else{
            printf("No\n");
            flag = 1;
            memset(input,0,sizeof(input));
        }
    }
}

char string[1000001] = {'\0'};
int TYPE[100000] = {0};
char A[100001], B[100001], C[100001];
int id[100001];
int sub[1000001];
char alpha[26];
void string_operatoin2(){
    for(int i=0;i<26;i++){
        alpha[i] = 'a' + i;
    }
    
    scanf("%s",string);
    int len = strlen(string);
    int times;
    scanf("%d",&times);
    
    for(int i=0;i<len;i++){
        sub[i] = -1;
    }
    
    for(int i=0;i<times;i++){
        scanf("%d",&TYPE[i]);
        if(TYPE[i] == 1){
            scanf(" %c %c",&A[i],&B[i]);
        }
        else{
            scanf(" %d %c",&id[i],&C[i]);
        }
    }
    
    for(int i=times-1;i>=0;i--){
        if(TYPE[i] == 1){
            alpha[A[i]-'a'] = alpha[B[i]-'a'];
        }
        else if(sub[id[i]] == -1){
                C[i] = alpha[C[i]-'a'];
                sub[id[i]] = i;
        }
    }
    
    for(int i=0;i<len;i++){
        if(sub[i] == -1){
            printf("%c",alpha[string[i]-'a']);
        }
        else{
            printf("%c",C[sub[i]]);
        }
    }
    printf("\n");
}

void indentation(){
    char c, prev;
    int mode = 0;   //mode0:header, mode1:indentation, mode2:one}, mode3:regular code
    while((c = getchar()) != EOF){
        if(mode == 0){
            if(c == '\n'){
                mode = 1;
            }
        }
        else if(mode == 1){
            if(c == '#') mode = 0;
            if(c == '}') mode = 2;
            if(c == ';'){
                putchar(' ');
                prev = ' ';
                continue;
            }
            if(c != '#' && c != '}' && c != ';') mode = 3;
        }
        else if(mode == 2){
            if(c == '\n') mode = 1;
        }
        else if(mode == 3){
            if(c == '\n'){
                if(prev != '{') putchar(';');
                prev = c;
                mode = 1;
            }
        }
        putchar(c);
        prev = c;
    }
}



int main(){
    palindrome();
}