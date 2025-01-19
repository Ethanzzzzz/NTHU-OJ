#include <stdio.h>
#include <string.h>

char board[501][501];
char ch;
int n, m;
int y = 0, x = 0;
char from = 'u'; // u, l, r
int status = 1;

void initialize(){
    from = 'u';
    status = 1;
    y = 0;
    x = 0;
}

int main(){
    freopen("drop.txt","r",stdin);
    scanf("%d %d",&n,&m);
    int times = n;
    int Q;
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<m;j++){
            ch = getchar();
            board[i][j] = ch;
        }
        board[i][m] = '\0';
        // printf("the %d line is %s\n", i, board[i]);
    }
    scanf(" %d",&Q);
    for(int q=0;q<Q;q++){
        scanf("%d",&x);
        x--; //convert to the index
        while(y<n && y>=0 && x<m && x>=0){
            if(board[y][x] == '/'){
                if(from == 'l'){
                    printf("Stuck QQ\n");
                    break;
                }
                if(from == 'u'){
                    x--;
                    from = 'r';
                }
                if(from == 'r'){
                    y++;
                    from = 'u';
                }
            }
            else if(board[y][x] == '\\'){
                if(from == 'r'){
                    printf("Stuck QQ\n");
                    break;
                }
                if(from == 'u'){
                    x++;
                    from = 'l';
                }
                if(from == 'l'){
                    y++;
                    from = 'u';
                }
            }
        }
        if(x>=m) printf("Right!\n");
        else if(x<0) printf("Left!\n");
        else if(y>=n) printf("Position: %d\n",x);
        initialize();
    }
}