#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, T;
int dy[4] = {-1,0,1,0}; //위,오,아,왼
int dx[4] = {0,1,0,-1}; //위,오,아,왼
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> T;
    int** circle = new int*[N+1];
    double sum = 0, div = N*M;    //총 합, 총 갯수
    for (int i=1; i<N+1; i++){
        circle[i] = new int[M];
        for (int j=0; j<M; j++){
            cin >> circle[i][j];
            sum += circle[i][j];
        }
    }
    int x, d, k;
    while(T--){
        cin >> x >> d >> k;
        if (d == 0) d = -1; //시계방향
        d*=k;
        for (int i=1; i<N+1; i++){  //회전
            if (i%x != 0) continue;
            vector<int> cp;
            for (int j=0; j<M; j++)
                cp.push_back(circle[i][j]);
            for (int j=0; j<M; j++)
                circle[i][j] = cp[(j+d+M)%M];
        }
        
        double div_org = div;
        for (int i=1; i<N+1; i++){  //인접 제거
            for (int j=0; j<M; j++){
                if (circle[i][j] == 0) continue;    //0: 제거된 수
                queue<pair<int,int>> q;
                for (int dir = 0; dir<4; dir++){
                    int ny = i + dy[dir];
                    int nx = (j + dx[dir] + M) % M;
                    if (ny>0 && ny<=N){
                        if (circle[i][j] == circle[ny][nx])    //같은 수 발견
                            q.push(make_pair(ny, nx));
                    }
                }
                if (!q.empty()) {
                    sum-=circle[i][j];
                    div--;
                    circle[i][j] = 0;
                }
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    if (circle[y][x] == 0) continue;    //기존에 큐에 있던게 0이 돼있으면 그냥 빼버리기
                    for (int dir=0; dir<4; dir++){
                        int ny = y + dy[dir];
                        int nx = (x + dx[dir] + M) % M;
                        if (ny>0 && ny<=N){
                            if (circle[y][x] == circle[ny][nx])
                                q.push(make_pair(ny, nx));
                        }
                    }
                    sum -= circle[y][x];
                    circle[y][x] = 0;
                    div--;
                }
            }
        }
        if (div_org == div){    //인접한 수 없음 -> 평균 계산
            if (div > 0){
                double avg = sum/div;
                for (int i=1; i<N+1; i++){
                    for (int j=0; j<M; j++){
                        if (circle[i][j] ==0) continue;
                        if (circle[i][j] < avg){
                            circle[i][j]++;
                            sum++;
                        }
                        else if (circle[i][j] > avg){
                            circle[i][j]--;
                            sum--;
                        }
                    }
                }
            }
        }
    }
    cout << (int)sum;
    return 0;
}