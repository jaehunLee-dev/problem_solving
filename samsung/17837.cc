#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int N, K;
int** color;    //보드의 색깔 저장 배열
deque<int>** horse;    //말의 위치 저장 배열
int dy[5] = {0,0,0,-1,1};   //오왼위아
int dx[5] = {0,1,-1,0,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    color = new int*[N+1];
    horse = new deque<int>*[N+1];
    for (int i=1; i<N+1; i++){
        color[i] = new int[N+1];
        horse[i] = new deque<int>[N+1];
        for (int j=1; j<N+1; j++)
            cin >> color[i][j];     //0:흰색, 1:빨간색, 2:파란색
    }
    int* direction = new int[K+1]();  //말은 1번부터 시작, i번 말의 방향을 저장하는 배열
    vector<pair<int,int>> loc;  //말의 위치 저장
    pair<int,int> tmp;
    loc.push_back(tmp);
    for (int i=1; i<=K; i++){
        int y, x;
        cin >> y >> x >> direction[i];
        horse[y][x].push_back(i);   //i번 말을 해당 위치 벡터에 추가 (덱의 앞일수록 아래에 있는 말)
        loc.push_back(make_pair(y, x)); //loc[i] : i번째 말의 좌표
    }
    int turn = 0;
    while(++turn){
        for (int idx = 1; idx<=K; idx++){       //1번 말부터 차례대로 이동
            int y = loc[idx].first;
            int x = loc[idx].second;
            int dir = direction[idx];
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny>N || nx>N || ny<=0 || nx<=0 || color[ny][nx] == 2){    //벽에 부딛히거나 파란색인 경우
                switch (dir) {
                    case 1:
                        direction[idx] = 2;
                        break;
                        
                    case 2:
                        direction[idx] = 1;
                        break;
                        
                    case 3:
                        direction[idx] = 4;
                        break;
                        
                    case 4:
                        direction[idx] = 3;
                        break;
                    default:
                        break;
                }
                dir = direction[idx];
                ny = y + dy[dir];
                nx = x + dx[dir];   //반대 방향으로
                if (ny>N || nx>N || ny<=0 || nx<=0 || color[ny][nx] == 2)
                    continue;
            }
            if (color[ny][nx] == 0){    //흰색       A위에 말이 있는 경우 해당 말들까지 전부.
                int top_idx = horse[y][x].back();   //현재 가장 위의 말
                while(horse[y][x].front() != idx){  //현재 옮겨야할 말이 가장 아래로 올 때까지 밑에 말 빼서 위로 올리기
                    int tmp = horse[y][x].front();
                    horse[y][x].pop_front();
                    horse[y][x].push_back(tmp);
                }
                //while(!horse[y][x].empty()){
                while(horse[y][x].front() != top_idx){
                    int h = horse[y][x].front();    //가장 밑의 말부터
                    loc[h].first = ny;
                    loc[h].second = nx;
                    horse[y][x].pop_front();
                    horse[ny][nx].push_back(h);
                }
                int h = horse[y][x].front();    //가장 밑의 말부터
                loc[h].first = ny;
                loc[h].second = nx;
                horse[y][x].pop_front();
                horse[ny][nx].push_back(h);
            }
            else if (color[ny][nx] == 1){   //빨간색
                while(horse[y][x].back() != idx){       //수정 필요
                    int h = horse[y][x].back();
                    loc[h].first = ny;
                    loc[h].second = nx;
                    horse[y][x].pop_back();
                    horse[ny][nx].push_back(h);
                }
                int h = horse[y][x].back();
                loc[h].first = ny;
                loc[h].second = nx;
                horse[y][x].pop_back();
                horse[ny][nx].push_back(h);
            }
            if (horse[ny][nx].size() >= 4){
                cout << turn;
                return 0;
            }
        }
        if (turn == 1000) break;
    }
    cout << -1;
    return 0;
}