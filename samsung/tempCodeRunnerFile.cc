#include <iostream>
using namespace std;
int N, M, H;
bool** ladder;
int ans = 4;
inline bool do_ladder(){
    for (int l_num = 1; l_num <=N; l_num++){
        int now = l_num;
        for (int i=1; i<=H; i++){
            if (ladder[i][now])
                now = now+1;            
            else if (ladder[i][now-1])
                now = now - 1;
        }
        if (now != l_num){
            return false;
        }
    }
    return true;    
}
void comb(int sero, int garo, int idx){    //1. 가로로 확장 2. 세로로 확장 (왼->오, 위->아래)
    if (ans == 0){
        cout << ans;
        exit(0);
    }
    if (idx > 3)    //정답은 3보다 작아야한다.
        return;
    if (garo >= N){
        garo = 1;
        sero +=1;
    }
    if (idx >= ans) return;
    if (do_ladder()){
        if (idx < ans){            
            ans = idx;
            return; //이미 사다리 완성이면 return
        }
    }    
    //if (idx >= ans) return;
    if (garo > N || sero > H) return;

    if (ladder[sero][garo]){    //원래 사다리가 있으면, 확인 없이 그냥 바로 다다음 사다리로        
        comb(sero,garo+2,idx);        
    }
    //시간복잡도 줄이는 법 -> 이전꺼는 확인 안하기(보장하기) -> 현재꺼에 사다리추가하면 바로 +2번째로, 사다리 추가안하면 +1번째로
    else{
        if (!ladder[sero][garo+1]){
            ladder[sero][garo] = true;            
            comb(sero,garo+2,idx+1);            
            ladder[sero][garo] = false;            
            comb(sero,garo+1,idx);                                        
        }
        else{       //다음꺼가 사다리일때 -> 다다다음꺼 or 다음줄            
            comb(sero,garo+3,idx);            
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
