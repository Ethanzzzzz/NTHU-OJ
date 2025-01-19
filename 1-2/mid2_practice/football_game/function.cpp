#include <iostream> // AC(6/6)
#include "function.h"
using namespace std;

bool Field::SomeoneIsHere(int x, int y){
    for(int i=0; i<this->p; i++)
        if(player[i]->IsHere(x, y)) return true;

    return false;
}

int Field::GetWho(){
    for(int i=0; i<this->p; i++)
        if(player[i]->IsHoldingBall()) return i;

    return -1;
}

void Field::handleBallKicked(int dx, int dy){
    int xt = ball->GetX(), yt = ball->GetY();
    for(int t=0; ; t++){
        xt += dx;
        yt += dy;
        if(xt < 0 || xt >= this->n || yt < 0 || yt >= this->m){
            xt -= dx;
            yt -= dy;
            break;
        }
        if(SomeoneIsHere(xt, yt)) break;
    }

    ball->SetX(xt);
    ball->SetY(yt);
}