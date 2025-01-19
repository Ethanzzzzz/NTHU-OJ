#include <stdio.h>

int middle[8] = {0,1};

int cumulative[8] = {0,1};

void initialize_size(){
    for(int i = 2; i <= 7; i++) {
        middle[i] = 4 * cumulative[i-2] - middle[i-2] + 2;
        cumulative[i] = cumulative[i-1] + middle[i];
    }
}

int snowflake_size(int order){
    return cumulative[order] + cumulative[order - 1];
}

int snow(){

}

int main(){
    initialize_size();
    char snow_flake[snowflake_size(7)][snowflake_size(7)];
    
}