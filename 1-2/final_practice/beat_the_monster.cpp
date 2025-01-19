#include <iostream> // AC(4/4)
#include <queue>
using namespace std;

int dmg[20], heal[20];
bool vis[20][310][410];
struct state{
    int lv, hp, mhp, round;
    state(int lv, int hp, int mhp, int round): 
        lv(lv), hp(hp), mhp(mhp), round(round) {};
};

int main(){
    
    int max_level, max_hp, monster_hp, monster_dmg;
    cin >> max_level >> max_hp >> monster_hp >> monster_dmg;
    for(int i=1; i<=max_level; i++) cin >> dmg[i] >> heal[i];

    // bfs 好難QQ
    queue<state> q;
    q.push(state(1, max_hp, monster_hp, 0));

    while(!q.empty()){
        state s = q.front();
        if(s.mhp != 0) q.pop();
        else break;
        // level up
        if(s.hp - monster_dmg > 0 && s.lv < max_level){
            state n(s.lv+1, s.hp-monster_dmg, s.mhp, s.round+1);
            if(!vis[n.lv][n.hp][n.mhp]){
                vis[n.lv][n.hp][n.mhp] = true;
                q.push(n);
            }
        }
        // attack
        if(s.hp - monster_dmg > 0 || s.mhp - dmg[s.lv] <= 0){
            state n(s.lv, s.hp-monster_dmg, max(0, s.mhp-dmg[s.lv]), s.round+1);
            if(!vis[n.lv][n.hp][n.mhp]){
                vis[n.lv][n.hp][n.mhp] = true;
                q.push(n);
            }
        }
        // heal
        if(max_hp - monster_dmg > 0 && heal[s.lv] > monster_dmg){
        // if(min(max_hp, s.hp+heal[s.lv])-monster_dmg > 0){
            state n(s.lv, min(max_hp, s.hp+heal[s.lv])-monster_dmg, s.mhp, s.round+1);
            if(!vis[n.lv][n.hp][n.mhp]){
                vis[n.lv][n.hp][n.mhp] = true;
                q.push(n);
            }
        }
    }
    if(q.empty()) cout << -1 << '\n';
    else cout << q.front().round << '\n';
}