#include <iostream>     
#include <string>
#include <vector>
using namespace std;

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize,0);
    int j = 0;
    for (int i=1; i<patternSize;i++){
        while(j>0 && pattern[i] != pattern[j])
            j = table[j-1];
        if (pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

int main(){
    string s, p;
    cin >> s >> p;
    if (p.length() > s.length()){
        cout << 0;
        return 0;
    }
    vector<int> pi = makeTable(p);
    for (int i=0; i<p.length(); i++){
        
    }

    return 0;
}