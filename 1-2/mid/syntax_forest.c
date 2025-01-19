#include <stdio.h> // 1(4/4) 2(4/4) 3(0/2)TLE
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node{
    char data;
    struct _node *left, *right;
} btnode;

int n, q;
int f_pos[26] = {0};
char function[26][205];
char func_name[26];
int func_call[26][26] = {0};
int error[26] = {0};

btnode* makeNode(char c);
btnode* pre_parser(int idx);
btnode *list[26];
btnode nodehole[5205]; // substitution of malloc
long long ans(btnode* root, long long int X, long long int A, long long int B, long long int C, long long int D);
long long Mod(long long num);

void find_error(){
    for(int i=0; i<n; i++){
        char func_1 = func_name[i];
        if(error[func_1 - 'a']) continue;
        for(int j=0; j<26; j++){
            if(func_call[func_1 - 'a'][j] == 1){ // func_1 will call this function
                char func_2 = 'a' + j;
                if(error[func_2 - 'a']) continue;
                if(func_call[func_2 - 'a'][func_1 - 'a'] == 1) error[func_1 - 'a'] = error[func_2 - 'a'] = 1;
            }
        }
    }
}

void printNode(btnode* root){
    printf("%c", root->data);
    if(root->left) printNode(root->left);
    if(root->right) printNode(root->right);
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++){
        char alpha ,str[205];
        scanf(" %c %s", &alpha, str);
        strcpy(function[alpha - 'a'], str);
        func_name[i] = alpha;
    }
    for(int i=0; i<n; i++) list[func_name[i] - 'a'] = pre_parser(func_name[i] - 'a');
    // for(int i=0; i<n; i++) for(int j=0; j<26; j++) if(func_call[func_name[i] - 'a'][j] != 0) printf("%c ", 'a' + j); 
    // putchar('\n');
    find_error();
    // for(int i=0; i<26; i++) printf("%d ", error[i]);
    // putchar('\n');
    for(int Q=0; Q<q; Q++){
        char func;
        long long A, B, C, D, X;
        scanf(" %c", &func);
        scanf("%lld %lld %lld %lld %lld", &X, &A, &B, &C, &D);
        if(!error[func - 'a']) printf("%lld\n", Mod(ans(list[func - 'a'], X, A, B, C, D)));
        else puts("Error");
    }

}

btnode* makeNode(char c){
    static int used = 0;
    btnode* node = &nodehole[used++];
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

btnode* pre_parser(int idx){
    btnode* node;
    char c = function[idx][f_pos[idx]++];
    if(isalpha(c)){
        node = makeNode(c);
        if(islower(c)) func_call[idx][c - 'a'] = 1; // record calling which function
        return node;
    }
    else{
        node = makeNode(c);
        if(c == '-'){
            node->left = makeNode('0');
            node->right = pre_parser(idx);
        }
        else{
            node->left = pre_parser(idx);
            node->right = pre_parser(idx);
        }
    }
    return node;
}

long long ans(btnode* root, long long int X, long long int A, long long int B, long long int C, long long int D){
    if(root->data == '+') return Mod(ans(root->left, X, A, B, C, D) + ans(root->right, X, A, B, C, D));
    else if(root->data == '-') return Mod(ans(root->left, X, A, B, C, D) - ans(root->right, X, A, B, C, D));
    else if(root->data == '*') return Mod(ans(root->left, X, A, B, C, D) * ans(root->right, X, A, B, C, D));
    else if(root->data == '@') return Mod(ans(list[root->left->data - 'a'], ans(root->right, X, A, B, C, D), A, B, C, D));
    else if(root->data == 'A') return Mod(A);
    else if(root->data == 'B') return Mod(B);
    else if(root->data == 'C') return Mod(C);
    else if(root->data == 'D') return Mod(D);
    else if(root->data == 'X') return Mod(X);
    else return 0;
}

long long Mod(long long num){
    num %= 998244353;
    if(num < 0) num += 998244353;
    return num;
}
