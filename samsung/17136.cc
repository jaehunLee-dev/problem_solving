#include <iostream>
using namespace std;
int paper_num[6];
int paper[10][10];
int ans, tmp_ans;
bool check(int y_idx, int x_idx, int n){
    if (y_idx+n >10 || x_idx+n > 10)
        return false;
    if (paper_num[n] <= 0)
        return false;
    for (int i=y_idx; i<y_idx+n; i++){
        for (int j=x_idx; j<x_idx+n; j++){
            if (!paper[i][j])   //0
                return false;
        }
    }
    return true;                //all 1
}

void fill(int y_idx, int x_idx, int n){
    for (int i=y_idx; i<y_idx+n; i++){
        for (int j=x_idx; j<x_idx+n; j++)
            paper[i][j] = 0;
    }
    paper_num[n]--;
    tmp_ans++;
}

void recover(int y_idx, int x_idx, int n){
    for (int i=y_idx; i<y_idx+n; i++){
        for (int j=x_idx; j<x_idx+n; j++)
            paper[i][j] = 1;
    }
    paper_num[n]++;
    tmp_ans--;
}

void dfs(int y_idx, int x_idx){
    if (paper[y_idx][x_idx] == 1){
        //cout << "x좌표: "<<x_idx << ", y좌표: "<<y_idx << '\n';
        for (int i = 5; i > 0; i--){    
            if (check(y_idx,x_idx,i)){
                fill(y_idx,x_idx,i);
                if (x_idx == 9){
                    if (y_idx == 9){    //둘다 끝 -> 마지막인데 0 : 다채움.
                        if (tmp_ans < ans)
                            ans = tmp_ans;
                        return;
                    }
                    else dfs(y_idx+1,0);    //다음 행
                }
                else dfs(y_idx,x_idx+1);        //다음 열                
                recover(y_idx,x_idx,i);
            }
        }
    }    
    else{       //1아니라서 못채움 ->바로 다음 idx로
        //cout << "x좌표: "<<x_idx << ", y좌표: "<<y_idx << '\n';
        if (x_idx == 9){
            if (y_idx == 9){    //둘다 끝 -> 마지막인데 0 : 다채움.
                if (tmp_ans < ans)
                    ans = tmp_ans;
                return;
            }
            else dfs(y_idx+1,0);    //다음 행
        }
        else dfs(y_idx,x_idx+1);        //다음 열
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i=1; i<6; i++)
        paper_num[i] = 5;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++)
            cin >> paper[i][j];
    }
    ans = 26;
    dfs(0,0);
    if (ans == 26) ans = -1;
    cout << ans;
    return 0;
}