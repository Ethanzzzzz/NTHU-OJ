#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int max(int x, int y) {return x > y ? x : y;}

void level_up(Pokemon *P){ // 1. level < 5, increase by 1.
    if(P->level < 5){
        P->level += 1;
        P->attack += lvup_atk; // 1. increase by lvup_..., respectively.
        P->defense += lvup_dfn;
        P->maxHp += lvup_maxHp;
        P->maxMp += lvup_maxMp;
    }
    P->Hp = P->maxHp; // 1. set Hp to MaxHp, set Mp to MaxMp.
    P->Mp = P->maxMp;
}

void battle(Pokemon *A, Pokemon *B){
    char attacker = 'A';
    while(1){
        int rest = 0;
        
        if(A->Hp == 0 || B->Hp == 0){ // 7. whenever any pokemon Hp == 0, the battle ends directly.
            // 7. if only one of them Hp == 0, print winner and died in vain.
            if(A->Hp > B->Hp) printf( "%s is the winner! %s died in vain...\n", A->name, B->name);
            else if(A->Hp < B->Hp) printf( "%s is the winner! %s died in vain...\n", B->name, A->name);
            // 7. if both of them Hp == 0, print draw.
            else printf("draw\n");
            // 7. print a newline character.
            printf("\n");
            break;
        }

        switch(attacker){ // 1.take turn
            case 'A':
                A->Mp += T; // 2. Mp increases by T before action
                if(A->Mp > A->maxMp) A->Mp = A->maxMp; // avoid from exceeding
                if(A->Mp >= A->costMp){ // 4. if can attack, always choose to attack
                    A->Mp -= A->costMp; // 3. cost Mp
                    B->Hp -= 2 * A->level * max(A->attack - B->defense, 0) / 100; // 3. cause damage on B, Hp decreases by damage
                    if(B->Hp <= 0) B->Hp = 0; // 3. if Hp less than 0, set to 0
                }
                else{ // 4. otherwise choose to rest
                    A->Mp += T; // 4. recover an extra T
                    rest = 1;
                }
                break;
            case 'B':
                B->Mp += T;
                if(B->Mp > B->maxMp) B->Mp = B->maxMp;
                if(B->Mp >= B->costMp){
                    B->Mp -= B->costMp;
                    A->Hp -= 2 * B->level * max(B->attack - A->defense, 0) / 100;
                    if(A->Hp <= 0) A->Hp = 0;
                }
                else{
                    B->Mp += T;
                    rest = 1;
                }
                break;
        }
        if(attacker == 'A'){
            // 6. if rest, print used Rest and Mp.
            rest ? printf("%s used Rest!\n%s now has %d MP.\n", A->name, A->name, A->Mp)
            // 5. if attack, print used Headbutt and Hp. 
                 : printf("%s used Headbutt!\n%s now has %d HP.\n", A->name, B->name, B->Hp);
        }
        else{
            rest ? printf("%s used Rest!\n%s now has %d MP.\n", B->name, B->name, B->Mp)
                 : printf("%s used Headbutt!\n%s now has %d HP.\n", B->name, A->name, A->Hp);
        }

        if(attacker == 'A') attacker = 'B'; // 1. take turn.
        else attacker = 'A';
    }
}