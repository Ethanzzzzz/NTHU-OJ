#include <iostream> // AC(4/4)
#include <string>
#include <stack>
#include <map>

int N;
std::string input;
std::map<char, char> parentheses = {{'{', '}'}, {'[', ']'}, 
                                    {'(', ')'}, {'<', '>'}};

int main(){
    std::cin >> N;
    std::getline(std::cin, input);
    for(int n=1; n<=N; n++){
        bool valid = true;
        std::stack<char> s;
        std::getline(std::cin, input);
        for(char c: input){
            if(c == '{' || c == '[' || c == '(' || c == '<') s.push(c);
            else if(c == '}' || c == ']' || c == ')' || c == '>'){
                if(s.empty()){
                    valid = false;
                    break;
                }
                else if(parentheses[s.top()] != c){
                    valid = false;
                    break;
                }
                else s.pop();
            }
        }
        if(!s.empty()) valid = false;
        // valid = check(input);
        std::cout << "Case " << n << ": ";
        valid ?  std::cout << "Yes\n" : std::cout << "No\n";
    }
}