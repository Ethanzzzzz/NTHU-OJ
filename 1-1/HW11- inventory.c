#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, idx[101];

typedef struct pokemon{
    char name[21];
    int current_hp;
    int max_hp;
};
struct pokemon pokemon[101];

int cmp(int idx1, int idx2){
    if(pokemon[idx1].current_hp < pokemon[idx1].max_hp && pokemon[idx2].current_hp == pokemon[idx2].max_hp){
        return -1;
    }
    else if(pokemon[idx1].current_hp == pokemon[idx1].max_hp && pokemon[idx2].current_hp < pokemon[idx2].max_hp){
        return 1;
    }
    else{ // pokemon[idx1].current_hp < pokemon[idx1].max_hp && pokemon[idx2].current_hp < pokemon[idx2].max_hp
        if(pokemon[idx1].current_hp < pokemon[idx2].current_hp) return -1;
        else if(pokemon[idx1].current_hp > pokemon[idx2].current_hp) return 1;
        else{ // pokemon[idx1].current_hp == pokemon[idx2].current_hp
            if(pokemon[idx1].max_hp < pokemon[idx2].max_hp) return -1;
            else if(pokemon[idx1].max_hp > pokemon[idx2].max_hp) return 1;
            else return 0;
        }
    }
}

void bubble(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(cmp(idx[j], idx[j+1]) > 0){
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }
}

int main(){
    freopen("a.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        idx[i] = i;
        scanf("%s %d %d", pokemon[i].name, &pokemon[i].current_hp, &pokemon[i].max_hp);
    }
    bubble();
    for(int i=0;i<n;i++){
        printf("%s %d %d\n", pokemon[idx[i]].name, pokemon[idx[i]].current_hp, pokemon[idx[i]].max_hp);
    }

}