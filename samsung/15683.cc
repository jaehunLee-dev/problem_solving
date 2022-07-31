#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> cctv;
int N, M;
int** office;
int ans = 65;

int calc_ans(){
    int tmp = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (office[i][j] == 0)
                tmp++;
        }
    }
    return tmp;
}

void watch(int direction, int y, int x){
    switch (direction)  //오른쪽,왼쪽,위,아래
    {
    case 1:
        for (int i=x+1; i<M; i++){
            if (office[y][i] == 6)
                break;
            else if (office[y][i] == 0)
                office[y][i] = 7;
        }
        break;
    
    case 2:
        for (int i=x-1; i>=0; i--){
            if (office[y][i] == 6)
                break;
            else if (office[y][i] == 0)
                office[y][i] = 7;
        }
        break;    

    case 3:
        for (int i=y-1; i>=0; i--){
            if (office[i][x] == 6)
                break;
            else if (office[i][x] == 0)
                office[i][x] = 7;
        }
        break;

    case 4:
        for (int i=y+1; i<N; i++){
            if (office[i][x] == 6)
                break;
            else if (office[i][x] == 0)
                office[i][x] = 7;
        }
        break;

    default:
        break;
    }
}

void backup(int** tmp_office){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            office[i][j] = tmp_office[i][j];
    }
}

void dfs(int now){
    if (now == cctv.size()){
        int tmp_ans = calc_ans();
        if (tmp_ans < ans)
            ans = tmp_ans;        
        return;
    }
    int y = cctv[now].first;
    int x = cctv[now].second;
    int** tmp_office = new int*[N];
    for (int i=0; i<N; i++)
        tmp_office[i] = new int[M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            tmp_office[i][j] = office[i][j];
    }
    switch (office[y][x])
    {
    case 1:
        for (int i=1; i<=4; i++){
            watch(i,y,x);
            dfs(now+1);
            backup(tmp_office);
        }
        break;
    
    case 2:
        for (int i=1; i<=3; i+=2){
            watch(i,y,x);
            watch(i+1,y,x);
            dfs(now+1);
            backup(tmp_office);
        }
        break;

    case 3:        
        watch(1,y,x);
        watch(3,y,x);            
        dfs(now+1);
        backup(tmp_office);
        watch(1,y,x);
        watch(4,y,x);
        dfs(now+1);
        backup(tmp_office);
        watch(2,y,x);
        watch(3,y,x);
        dfs(now+1);
        backup(tmp_office);
        watch(2,y,x);
        watch(4,y,x);
        dfs(now+1);
        backup(tmp_office);
        break;

    case 4:
        for (int i=1; i<=4; i++){
            for (int j=i+1; j<=4; j++){
                for (int k=j+1; k<=4; k++){
                    watch(i,y,x);
                    watch(j,y,x);
                    watch(k,y,x);
                    dfs(now+1);
                    backup(tmp_office);
                }
            }
        }
        break;

    case 5:
        watch(1,y,x);
        watch(2,y,x);
        watch(3,y,x);
        watch(4,y,x);
        dfs(now+1);
        backup(tmp_office);
    default:
        break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    office = new int*[N];
    for (int i=0; i<N; i++)
        office[i] = new int[M];
            
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> office[i][j];    //1~5: cctv, 6: 벽
            if (office[i][j] >0 && office[i][j]<6)
                cctv.push_back(make_pair(i,j));
        }
    }    
    dfs(0);
    cout << ans;
    return 0;
}