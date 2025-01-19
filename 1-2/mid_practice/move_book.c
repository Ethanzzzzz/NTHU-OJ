#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, table[25][25]; // table[which table][ith book] = which book
int book_pos[25]; // book_pos[which book] = 100 * which table + ith book

void init();
void move(int A ,int B, char *detail);
void pile(int A, int B, char *detail);
void put_back(int x);

int main(){
    scanf("%d", &N);
    char cmd[5], detail[5];
    init();
    while(1){
        int A, B;
        scanf(" %s", cmd);
        if(strcmp(cmd, "exit") == 0) break;
        scanf("%d %s %d", &A, detail, &B);
        if(A == B || book_pos[A] / 100 == book_pos[B] / 100) continue;
        if(strcmp(cmd, "move") == 0) move(A, B, detail);
        else if(strcmp(cmd, "pile") == 0) pile(A, B, detail);
    }
    for(int i=0; i<N; i++){
        printf("%d:", i);
        for(int j=0; table[i][j] != -1; j++) printf(" %d", table[i][j]);
        printf("\n");
    }
}

void init(){
    for(int i=0; i<N; i++){
        table[i][0] = i;
        for(int j=1; j<25; j++) table[i][j] = -1;
        book_pos[i] = 100 * i;
    }
}

void move(int A ,int B, char *detail){
    if(strcmp(detail, "over") == 0){ // clean all the books on A, put A on top of B
        put_back(A);
        int atable = book_pos[A] / 100, apos = book_pos[A] % 100, btable = book_pos[B] / 100, top = 0;
        table[atable][apos] = -1;
        while(table[btable][top] != -1) top++;
        table[btable][top] = A;
        book_pos[A] = 100 * btable + top;
    }
    else if(strcmp(detail, "onto") == 0){ // clean all the books upper than A and B, put A on B
        put_back(A);
        put_back(B);
        int atable = book_pos[A] / 100, apos = book_pos[A] % 100;
        int btable = book_pos[B] / 100, bpos = book_pos[B] % 100;
        table[btable][bpos+1] = A;
        table[atable][apos] = -1;
        book_pos[A] = 100 * btable + bpos + 1;

    }
}

void pile(int A, int B, char *detail){
    if(strcmp(detail, "over") == 0){
        int atable = book_pos[A] / 100, apos = book_pos[A] % 100, btable = book_pos[B] / 100, bpos = book_pos[B] % 100, top = bpos;
        while(table[btable][top] != -1) top++;
        for(int i=apos; table[atable][i] != -1; i++){
            int move = table[atable][i];
            table[btable][top] = move;
            book_pos[move] = 100 * btable + top;
            table[atable][i] = -1;
            top++;
        }
    }
    else if(strcmp(detail, "onto") == 0){
        put_back(B);
        int atable = book_pos[A] / 100, apos = book_pos[A] % 100, btable = book_pos[B] / 100, bpos = book_pos[B] % 100, top = bpos + 1;
        for(int i=apos; table[atable][i] != -1; i++){
            int move = table[atable][i];
            table[btable][top] = move;
            book_pos[move] = 100 * btable + top;
            table[atable][i] = -1;
            top++;
        }
    }
}

void put_back(int x){
    int xtable = book_pos[x] / 100;
    int xpos = book_pos[x] % 100;
    for(int i=xpos+1; table[xtable][i] != -1; i++){
        int move = table[xtable][i], top = 0;
        while(table[move][top] != -1) top++;
        table[move][top] = move;
        book_pos[move] = 100 * move + top;
        table[xtable][i] = -1;
    }
     
}
