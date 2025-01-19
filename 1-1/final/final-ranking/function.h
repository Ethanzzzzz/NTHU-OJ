#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct{
    int score;
    char* name;
} Node;

void Insert( Node** Table, int N, int score, char* name );
void Delete( Node** Table, int N, char* name );
int* Top( Node** Table, int N, int x);
#endif
