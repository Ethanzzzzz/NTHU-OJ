#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node{
    char data;
    struct _node *left, *right;
} Tree;

int n, q;
int f_pos[27] = {0};
char function[27][205];
char func_name[27];

Tree* makeNode(char c);
Tree* pre_parser(int idx);
long long ans(Tree* root, long long int X, long long int A, long long int B, long long int C, long long int D);
long long Mod(long long num);
Tree **list;

void printNode(Tree* root){
    printf("%c", root->data);
    if(root->left) printNode(root->left);
    if(root->right) printNode(root->right);
}
void freeNode(Tree* root){
    if(root->left) freeNode(root->left);
    if(root->right) freeNode(root->right);
    free(root);
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++){
        char alpha ,str[205];
        scanf(" %c %s", &alpha, str);
        strcpy(function[alpha - 'a'], str);
        func_name[i] = alpha;
    }
    list = (Tree**) malloc(sizeof(Tree*) * 26);
    for(int i=0; i<n; i++) list[func_name[i] - 'a'] = pre_parser(func_name[i] - 'a');
    for(int Q=0; Q<q; Q++){
        char ch;
        long long A, B, C, D, X;
        scanf(" %c", &ch);
        scanf("%lld %lld %lld %lld %lld", &X, &A, &B, &C, &D);
        printf("%lld\n", Mod(ans(list[ch - 'a'], X, A, B, C, D)));
    }
    // for(int i=0; i<n; i++){
    //     printNode(list[func_name[i] - 'a']);
    //     putchar('\n');
    // }
    for(int i=0; i<n; i++) freeNode(list[func_name[i] - 'a']);

}

Tree* makeNode(char c){
    Tree* node = (Tree*) malloc(sizeof(Tree));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

Tree* pre_parser(int idx){
    Tree* node;
    char c = function[idx][f_pos[idx]++];
    if(isalpha(c)){
        node = makeNode(c);
        return node;
    }
    else{
        node = makeNode(c);
        node->left = pre_parser(idx);
        node->right = pre_parser(idx);
    }
    return node;
}

long long ans(Tree* root, long long int X, long long int A, long long int B, long long int C, long long int D){
    if(root->data == '+') return Mod(ans(root->left, X, A, B, C, D) + ans(root->right, X, A, B, C, D));
    else if(root->data == '-') return Mod(ans(root->left, X, A, B, C, D) - ans(root->right, X, A, B, C, D));
    else if(root->data == '*') return Mod(ans(root->left, X, A, B, C, D) * ans(root->right, X, A, B, C, D));
    else if(root->data == '@') return Mod(ans(list[root->left->data - 'a'], ans(root->right, X, A, B, C, D), A, B, C, D));
    else if(root->data == 'A') return Mod(A);
    else if(root->data == 'B') return Mod(B);
    else if(root->data == 'C') return Mod(C);
    else if(root->data == 'D') return Mod(D);
    else if(root->data == 'X') return Mod(X);
}

long long Mod(long long num){
    num %= 998244353;
    if(num < 0) num += 998244353;
    return num;
}
