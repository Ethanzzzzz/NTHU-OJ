#include <iostream> // 15_puzzle
#include <cmath>
#include <queue>
using namespace std;


const int goalRow[] = {-1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
const int goalCol[] = {-1, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class State{
    public:
        int puzzle[4][4];
        int heuristic;
        int currentMove;
        int prevMove;
        int ex, ey;

        State(int puzzle[4][4]){
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    this->puzzle[i][j] = puzzle[i][j];
            this->ex = -1;
            this->ey = -1;
            this->currentMove = 0;
            this->prevMove = -1;
            set_heuristic();
        }
        State(const State& rhs){
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    this->puzzle[i][j] = rhs.puzzle[i][j];
            currentMove = rhs.currentMove;
            prevMove = rhs.prevMove;
            ex = rhs.ex;
            ey = rhs.ey;
            heuristic = rhs.heuristic;
        }
        void set_heuristic(){
            int h = 0;
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    if(puzzle[i][j]){
                        int x = goalRow[puzzle[i][j]], y = goalCol[puzzle[i][j]];
                        h += abs(x - i) + abs(y - j);

                        if(i == x)
                            for(int k=j; k<4; k++){
                                if(puzzle[i][k] > 0 && goalRow[puzzle[i][k]] == i && puzzle[i][j] > puzzle[i][k])
                                    h += 2;
                            }
                        if(j == y)
                            for(int k=i; k<4; k++){
                                if(puzzle[k][j] > 0 && goalCol[puzzle[k][j]] == j && puzzle[i][j] > puzzle[k][j])
                                    h += 2;
                            }
                    }
                }
            }
            heuristic = h;
        }
        void update(int i, int newx, int newy){
            prevMove = i;
            swap(puzzle[newx][newy], puzzle[ex][ey]);
            ex = newx;
            ey = newy;
            currentMove++;
            set_heuristic();
        }
        bool operator< (const State& rhs) const{
            return currentMove + heuristic > rhs.currentMove + rhs.heuristic;
        }
};

int main(){
    int puzzle[4][4], ex, ey;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            cin >> puzzle[i][j];
            if(puzzle[i][j] == 0){
                ex = i;
                ey = j;
            }
        }
    
    State s(puzzle);
    s.ex = ex;
    s.ey = ey;

    priority_queue<State> pq;
    pq.push(s);

    while(!pq.empty()){
        State cur = pq.top();
        if(cur.heuristic == 0){
            cout << cur.currentMove << endl;
            break;
        }
        pq.pop();
        if(cur.currentMove + cur.heuristic > 80)
            continue;
        for(int i=0; i<4; i++){
            int newx = cur.ex + dx[i], newy = cur.ey + dy[i];

            if(newx < 0 || newy < 0 || newx > 3 || newy > 3)
                continue;
            // back and forth, 00 ^ 01 = 01, 01 ^ 01 == 00, 10 ^ 01 = 11, 11 ^ 01 == 10
            if(i == (cur.prevMove ^ 1))
                continue;

            State next = cur;
            next.update(i, newx, newy);
            pq.push(next);
        }
    }
    if(pq.empty())
        cout << -1 << endl;


}
