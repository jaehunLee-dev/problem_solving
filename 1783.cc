#include <iostream>
using namespace std;
int main(){
    int N,M;
    cin >> N >> M;    
    int ans = 1, nidx=1, midx=1;
    if (M>=7 && N>=3){
        ans+=4;
        midx=7;
    }
    else{       //4번 미만으로 움직일때
        for (int i=0; i<4; i++){
            if (nidx+2 <= N && midx+1 <= M){
                nidx+=2;
                midx+=1;
                ans++;
            }
            else if (nidx+1 <= N && midx+2 <= M){
                nidx+=1;
                midx+=2;
                ans++;
            }
            else if (nidx-2 >= 1 && midx+1 <= M){
                nidx-=2;
                midx+=1;
                ans++;
            }
            else if (nidx-1 >= 1 && midx+2 <= M){
                nidx-=1;
                midx+=2;
                ans++;
            }
            else 
                break;                            
        }
        cout << ans;
        return 0;
    }
    return 0;
}