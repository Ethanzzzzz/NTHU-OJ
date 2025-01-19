#include <iostream> // 名字有夠容易打錯 考試用複製貼上==
#include <map> // AC(5/5)
#include <string>
using namespace std;

map<string, string> matching = {{"Wa", "Waninoko"}, {"Mi", "Milotic"}, {"Ma", "Magikarp"},
                                {"Va", "Vaporeon"}, {"Sh", "Sharpedo"}, {"Tapu", "Tapu Fini"},
                                {"Em","Empoleon"}, {"La", "Lapras"}, {"Pi", "Pikachu"}, {"Pe", "Pikachu"},
                                {"Me", "Mega Gyarados"}};

int main(){
    int N;
    string name, school;
    cin >> N;
    while(N--){
        cin >> name >> school;
        string temp = "";
        temp += name[0], temp += name[1];
        if(temp.compare("Ta") == 0) temp += name[2], temp += name[3];
        auto it = matching.find(temp);
        if(it != matching.end()) 
            cout << name << " the " << school << " " << it->second << '\n';
        else cout << name << " is looking for a Chinese tutor, too!\n";
    }
}