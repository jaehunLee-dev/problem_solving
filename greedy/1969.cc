#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int num[20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    char* str = new char[M];
    int ans=0;    
    string* dna = new string[N];
    for (int i=0; i<N; i++){
        cin >> dna[i];
    }
    for (int i=0; i<M; i++){   
        for (int j=0; j<20; j++)
            num[j] = 0;
        for (int j=0; j<N; j++){
            //cout << dna[j][i];            
            num[dna[j][i]-'A']+=1;            
        }
        int frq = max_element(num,num+20) - num;        
        ans += N - *max_element(num,num+20);
        str[i] = frq+'A';
        cout << str[i];
    }    
    cout << '\n' << ans;
    return 0;
}