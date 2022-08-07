#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int** A;    //겨울에 추가될 양분의 양
vector<int> **tree; //나무의 나이를 나타내는 배열, 0일시 나무 없음
int** food; //현재 땅의 양분 양
int dy[8] = {1,0,-1,0,1,1,-1,-1};
int dx[8] = {0,1,0,-1,1,-1,1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    A = new int*[N+1];
    tree = new vector<int>*[N+1];
    food = new int*[N+1];
    for (int i=1; i<N+1; i++){
        A[i] = new int[N+1];
        tree[i] = new vector<int>[N+1];
        food[i] = new int[N+1];
    }
    for (int i=1; i<N+1; i++){
        for (int j=1; j<N+1; j++){
            cin >> A[i][j];
            food[i][j] = 5;     //처음 양분 : 전부 5
        }
    }
    for (int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        int tmp;
        cin >> tmp;
        for (auto itr=tree[x][y].begin(); itr != tree[x][y].end(); itr++){
            if (*itr < tmp){
                tree[x][y].insert(itr, tmp);
                break;
            }
        }
        if (tree[x][y].size() == 0)
            tree[x][y].push_back(tmp);
    }
    
    while(K--){
        //봄
        for (int i=1; i<N+1; i++){
            for (int j=1; j<N+1; j++){
                int dead = 0;   //죽은 나무
                int v_sz = tree[i][j].size()-1;
                for(int itr = v_sz; itr>=0;itr--){
                    int left = food[i][j] - tree[i][j][itr];    //itr: 어린 나무부터
                    if (left >= 0){ //나무 생존 가능 -> 양분 먹고 나이+1
                        food[i][j] = left;
                        tree[i][j][itr]++;
                    }
                    else {
                        dead += tree[i][j][itr]/2;
                        tree[i][j][itr] = -1;
                    }
                }
                tree[i][j].erase(std::remove(tree[i][j].begin(),tree[i][j].end(),-1),tree[i][j].end());
                //여름
                food[i][j] += dead;
            }
        }
        //가을
        for (int i=1; i<N+1; i++){
            for (int j=1; j<N+1; j++){
                for (auto& itr: tree[i][j]){
                    if (itr%5 != 0) continue;   //5의 배수인 나무만 가을에 활동
                    for (int dir = 0; dir<8; dir++){
                        int ny = i+dy[dir];
                        int nx = j+dx[dir];
                        if (ny>0 && nx>0 && ny<N+1 && nx<N+1){
                            tree[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
        //겨울
        for (int i=1; i<N+1; i++){
            for (int j=1; j<N+1; j++)
                food[i][j] += A[i][j];
        }
    }
    int ans = 0;
    for (int i=1; i<N+1; i++){
        for (int j=1; j<N+1; j++)
            ans+= tree[i][j].size();
    }
    cout << ans;
    return 0;
}
