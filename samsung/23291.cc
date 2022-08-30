#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int N, K;
int turn;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
vector<int>* bowl;
bool isEnd(){
    int max_f = -1, min_f = INT_MAX;
    for (int i=0; i<N; i++){
        if (bowl[i][0] < min_f) min_f = bowl[i][0];
        if (bowl[i][0] > max_f) max_f = bowl[i][0];
    }
    if (max_f - min_f <= K) return true;
    return false;
}
void fish_move(int left){
    vector<int>* cp_bowl = new vector<int>[N];
    for (int i=0; i<N; i++)
        cp_bowl[i] = bowl[i];
    for (int i=left; i<N; i++){
        for (int j=0; j<cp_bowl[i].size(); j++){
            for (int dir=0; dir<4; dir++){
                int ny = j + dy[dir];
                int nx = i + dx[dir];
                if (ny >=0 && nx >= left && nx<N && ny < cp_bowl[nx].size()){
                    if (cp_bowl[i][j] > cp_bowl[nx][ny]){
                        bowl[nx][ny] += (cp_bowl[i][j] - cp_bowl[nx][ny])/5;
                        bowl[i][j] -= (cp_bowl[i][j] - cp_bowl[nx][ny])/5;
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    bowl = new vector<int>[N];
    for (int i=0; i<N; i++){
        int tmp; cin >> tmp;
        bowl[i].push_back(tmp);
    }
    while(++turn){
        int min_fish = INT_MAX;
        vector<int> f_min;
        for (int i=0; i<N; i++){
            if (bowl[i][0] < min_fish){
                min_fish = bowl[i][0];
                f_min.clear();
                f_min.push_back(i);
            }
            else if (bowl[i][0] == min_fish)
                f_min.push_back(i);
        }
        for (int i=0; i<f_min.size(); i++)
            bowl[f_min[i]][0]++;
        int left = 1;   //어항이 하나 이상 있는 칸 중 가장 왼쪽의 idx
        bowl[1].push_back(bowl[0][0]);
        bowl[0].clear();
        while(true){    //공중 부양시킨 어항 중 가장 오른쪽에 있는 어항의 아래에 바닥에 있는 어항이 있을때까지
            vector<vector<int>> nv;
            int len = 0;
            for (int i=left; i<N; i++){
                if (bowl[i].size() < 2){
                    len = N-i;
                    left = i;
                    break;
                }
                vector<int> tmp;
                for (auto& itr:bowl[i])
                    tmp.push_back(itr);
                nv.push_back(tmp);
            }
            if (len < nv[0].size()){
                left = N - nv.size() - len;
                break;     //길이 넘음 -> 불가능
            }
            for (int i=nv.size()-1; i>=0; i--){
                for(int j=0; j<nv[i].size(); j++)
                    bowl[left+j].push_back(nv[i][j]);                
            }
            for (int i=0; i<left; i++)
                bowl[i].clear();
        }
        //물고기 조절
        fish_move(left);
        //다시 일렬
        vector<int> tmp_sv;
        for (int i=left; i<N; i++){
            if (bowl[i].size() < 2) break;
            for (int j=0; j<bowl[i].size(); j++)
                tmp_sv.push_back(bowl[i][j]);
            bowl[i].clear();
        }
        for (int i=0; i<tmp_sv.size(); i++)
            bowl[i].push_back(tmp_sv[i]);
        //공중부양2
        for (int i=0; i<N/2; i++){
            bowl[N-1-i].push_back(bowl[i][0]);
            bowl[i].clear();
        }
        for (int i=N/2; i<N-N/4; i++){
            bowl[N-1-i+N/2].push_back(bowl[i][1]);
            bowl[N-1-i+N/2].push_back(bowl[i][0]);
            bowl[i].clear();
        }
        left = N-N/4;
        fish_move(left);
        tmp_sv.clear();
        for (int i=0; i<N; i++){
            for (int j=0; j<bowl[i].size(); j++){
                tmp_sv.push_back(bowl[i][j]);
            }
        }
        for (int i=0; i<N; i++){
            bowl[i].clear();
            bowl[i].push_back(tmp_sv[i]);
        }
        if (isEnd()) break;
    }
    cout << turn;
    return 0;
}
