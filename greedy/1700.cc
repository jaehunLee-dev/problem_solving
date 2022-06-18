#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int* now = new int[N]();
    int* todo = new int[K]();
    int ans =0;
    for (int i=0; i<K; i++){
        cin >> todo[i];
    }
    bool full = false;
    for (int i=0; i<K; i++){
        if (find(now,now+N,todo[i]) != now+N){                                //1. 이미 콘센트에 꼽혀있다 -> 다음거
            continue;
        }
        if (!full){
            for (int j=0; j<N; j++){        //2. 콘센트 자리 있다 -> 꼽는다.
                if (now[j] == 0){
                    now[j] = todo[i];
                    if (j == N-1)
                        full = true;
                    break;
                }                                
            }
            continue;
        }
        int* last_idx = todo;
        int last_idx_idx = 0;
        for(int j=0; j<N; j++){                       //3. 콘센트 자리없고, 안꼽혀있다 -> 가장 늦게 쓰일 것 빼기
            if (find(todo+i+1,todo+K,now[j]) > last_idx){
                last_idx = find(todo+i+1,todo+K,now[j]);
                last_idx_idx = j;
            }
        }
        now[last_idx_idx] = todo[i];
        ans++;
    }
    cout << ans;
    return 0;
}