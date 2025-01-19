#include <iostream> // AC(5/5)
#include <set>
#include <vector>
using namespace std;

int getValue(vector<int> v);
vector<int> readSequence();
void printSequence(vector<int>& v);
struct mycompare{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const{
        return getValue(lhs) < getValue(rhs);
    }
};



int main(){
    set<vector<int>, mycompare> seq_set;
    string command;
    while(cin >> command){
        if(command == "insert"){
            vector<int> input = readSequence();
            for(auto cur: seq_set){
                if(getValue(cur) == getValue(input)){
                    cout << "exist" << endl;
                    seq_set.erase(cur);
                    vector<int> temp;
                    for(auto it = input.rbegin(); it != input.rend(); ++it) temp.push_back(*it);
                    input.clear();
                    input = temp;
                }
            }
            seq_set.insert(input);
        }
        else if(command == "range_out"){
            int start = getValue(readSequence()), end = getValue(readSequence());
            for(auto i: seq_set){
                int key = getValue(i);
                if(start <= key && key <= end) printSequence(i);
                else if(key >= end) break;
            }
        }
        else if(command == "output"){
            for(auto i: seq_set) printSequence(i);
        }
    }
}

int getValue(vector<int> v){
    int len = v.size(), ans = 0;
    for(auto i: v){
        ans += i * len;
        len--;
    }
    return ans;
}

vector<int> readSequence(){
    vector<int> read;
    int element;
    while(cin >> element){
        if(element == 0) break;
        else read.push_back(element);
    }
    return read;
}

void printSequence(vector<int>& v){
    for(auto i: v){
        cout << i << ' ';
    }
    cout << '\n';
}
