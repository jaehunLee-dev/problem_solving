#include <iostream>
using namespace std;
int N, M, H;
bool** ladder;
int ans = 4;
bool do_ladder(){
    bool rtn = true;
    for (int l_num = 1; l_num <=N; l_num++){
        int now = l_num;
        for (int i=1; i<=H; i++){
            if (now != N && ladder[i][now])
                now = now+1;            
            else if (now>1 && ladder[i][now-1])
                now = now - 1;
        }
        if (now != l_num){
            rtn = false;
            break;
        }
    }
    return rtn;    
}
void comb(int sero, int garo, int idx){    //1. 가로로 확장 2. 세로로 확장 (왼->오, 위->아래)
    if (idx > 3)    //정답은 3보다 작아야한다.
        return;    
    if (do_ladder()){
        if (idx < ans){            
            ans = idx;
            return;
        }
    }
    if (garo > N || sero > H) return;

    if (ladder[sero][garo]){    //원래 사다리가 있으면, 확인 없이 그냥 바로 다음 사다리로
        if (garo != N-1)
            comb(sero,garo+1,idx);
        else comb(sero+1,1,idx);
    }
    
    else{
        if (!ladder[sero][garo-1] && !ladder[sero][garo+1]){
            ladder[sero][garo] = true;
            if (garo != N-1){
                comb(sero,garo+1,idx+1);
            }                
            else comb(sero+1,1,idx+1);
            ladder[sero][garo] = false;
            if (garo != N-1){
                comb(sero,garo+1,idx);
            }                
            else comb(sero+1,1,idx);
        }
        else{
            if (garo != N-1)
                comb(sero,garo+1,idx);
            else comb(sero+1,1,idx);
        }
    }    
    //사다리 추가하는 작업 후 항상 do_ladder로 완성됐는지 체크
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    
    cin >> N >> M >> H;
    ladder = new bool*[H+2]; //ladder[2][1] : 2번째 가로에서 1->2로 가는 것
    for (int i=0; i<H+2; i++)
        ladder[i] = new bool[N+2]();
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;        //a번째 가로에서 b->b+1 가는 것
    }    
    comb(1,1,0);
    if (ans == 4)
        ans = -1;
    cout << ans;    
    return 0;
}
