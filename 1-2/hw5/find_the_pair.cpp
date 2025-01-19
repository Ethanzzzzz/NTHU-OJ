#include <iostream> // AC(8/8)
#include <set>
int main(){
    int M, W, E, score;
    std::set<int> men, women;
    std::cin >> M >> W >> E;
    for(int i=0; i<M; i++){
        std::cin >> score;
        men.insert(score);
    }
    for(int i=0; i<W; i++){
        std::cin >> score;
        women.insert(score);
    }
    while(E--){
        int lucky, find = 0;
        std::cin >> lucky;
        if(men.size() > women.size()){
            for(auto w: women){
                if(men.find(lucky - w) != men.end()){
                    std::cout << "Yes\n";
                    find = 1;
                    break;
                }
            }
            if(!find) std::cout << "No\n";
        }
        else{
            for(auto m: men){
                if(women.find(lucky - m) != women.end()){
                    std::cout << "Yes\n";
                    find = 1;
                    break;
                }
            }
            if(!find) std::cout << "No\n";
        }
    }
}