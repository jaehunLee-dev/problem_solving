#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, K;
    int max, min;
    cin >> T;
    string W;
    for (int itr=0; itr<T; itr++){
        vector<int> idx[26];
        max =-1,min=10001;
        cin >> W >> K;
        for (int i = 0; i<W.length(); i++){     
            idx[W[i]-'a'].push_back(i);     //해당 알파벳 벡터에 idx 삽입
            if (idx[W[i]-'a'].size() >= K){     //최소 계산 
                int tmp = idx[W[i]-'a'].back() - idx[W[i]-'a'].front()+1;
                if (tmp < min)
                    min = tmp;
                if (tmp > max)
                    max = tmp;
                idx[W[i]-'a'].erase(idx[W[i]-'a'].begin());
            }
        }
        if (max == -1){
            cout << "-1\n";
            continue;
        }
        cout << min << ' ' << max << '\n';
    }
    return 0;    
}