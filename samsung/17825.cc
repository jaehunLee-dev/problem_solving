#include <iostream>
#include <vector>
using namespace std;
int mv[10];
int node[31];
int ans;
int seq[10];
void simulation(){
    int horse[4] = {-1,-1,-1,-1};
    bool exist[31] = {};
    bool finish[4] = {};
    int tmp_ans = 0;
    for (int i=0; i<10; i++){
        int h_num = mv[i]; //얼마나 움직일지
        int h_idx = seq[i]; //움직일 말(0,1,2,3)
        int h_node = horse[h_idx];  //현재 말의 위치(0~30/end)
        if (finish[h_idx]) return;  //이미 완료한 말 움직이려하면 return
        if (h_node == 4 || (h_node<=22 && h_node >=20)){    //10에서 출발-> 파란색 간선
            if (h_node == 4){
                h_node = 20;
                h_num--;
            }
            if (h_node + h_num <= 22)
                h_node += h_num;
            else{
                h_num= h_num - (23-h_node);
                h_node = 28;
                h_node += h_num;
            }
        }
        else if (h_node == 9 || h_node == 23 || h_node == 24){ //20에서 출발-> 파란색 간선
            if (h_node == 9){
                h_node = 23;
                h_num--;
            }
            if (h_node+h_num <= 24)
                h_node += h_num;
            else{
                h_num = h_num - (25-h_node);
                h_node = 28;
                h_node += h_num;
            }
        }
        else if (h_node == 14 || h_node>=25){
            if (h_node == 14){
                h_node = 25;
                h_num--;
            }
            h_node += h_num;
        }
        
        bool pass = false;
        if (h_node == 31){
            pass = true;
            h_node = 19;
        }
        
        if (h_node < 20 && !pass){
            h_node += h_num;
            if (h_node > 19) h_node = 31;   //도착 : 31이상
        }
        
        if (h_node >= 31){
            finish[h_idx] = true;
            exist[horse[h_idx]] = false;
            horse[h_idx] = 31;
        }
        else{
            if (h_node>=0 && exist[h_node])  //옮겨갈 위치에 이미 있으면 해당 조합은 실패
                return;
            exist[h_node] = true;
            exist[horse[h_idx]] = false;
            tmp_ans += node[h_node];
            horse[h_idx] = h_node;
        }
    }
    if (tmp_ans > ans) ans = tmp_ans;
}
void dfs(int idx){
    if (idx == 10){
        simulation();
        return;
    }
    seq[idx] = 0;
    dfs(idx+1);
    seq[idx] = 1;
    dfs(idx+1);
    seq[idx] = 2;
    dfs(idx+1);
    seq[idx] = 3;
    dfs(idx+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<10; i++)
        cin >> mv[i];
    for (int i=0; i<20; i++){
        node[i] = i*2+2;
    }
    for (int i=20; i<23; i++){
        node[i] = 13+(i-20)*3;
    }
    node[23] = 22; node[24] = 24; node[25] = 28; node[26] = 27; node[27] = 26; node[28] = 25; node[29]=30; node[30]=35;
    dfs(0);
    cout << ans;
    return 0;
}
