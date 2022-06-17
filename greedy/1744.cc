#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int* seq = new int[N];
    for (int i=0; i<N; i++)
        cin >> seq[i];    
    sort(seq,seq+N,greater<int>());
    int ans =0, neg_idx = N;
    for (int i=0; i<N;){                                //양수인 경우
        if (i != N-1 && seq[i] > 1 && seq[i+1] > 1){    //곱할 수 있는 수 2개가 있고, 둘 다 1 이상이라 곱하는게 이득일 때
            ans+= seq[i]*seq[i+1]; 
            i+=2;
        }
        else if (seq[i] == 1 || (seq[i]>1 && seq[i+1] <= 1)){   //지금 수가 1 -> 바로 더하기, 
            ans += seq[i];        
            i++;
        }
        else{   //0 or 음수            
            neg_idx = i;            
            break;
        }
    }    
    for (int i=N-1; i>=neg_idx;){
        if (i == neg_idx){
            ans += seq[i];
            break;
        }
        if (seq[i] <= 0 && seq[i-1] <= 0){
            ans += seq[i]*seq[i-1];
            i-=2;            
        }
        else{
            cout << "error\n";
            break;
        }
        
    }
    cout << ans;
    return 0;
}