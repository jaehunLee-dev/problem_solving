#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int** arr = new int*[n];
    for (int i=0; i<n; i++){
        arr[i] = new int[n];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cin >> arr[i][j];                    
    }
    int ans = 0;
    queue<tuple<int,int,int>> q;        //y좌표, x좌표, mode (0:가로,1:세로,2:대각선)
    q.push(make_tuple(0,0,0));
    while(!q.empty()){
        tuple<int,int,int> tmp = q.front();
        int tmp_y = get<0>(tmp);
        int tmp_x = get<1>(tmp);
        int mode = get<2>(tmp);
        q.pop();
        if (mode == 0){ //현재 가로일 때
            if (tmp_x+1 == n-1 && tmp_y == n-1)
                ans++;                            
            if (tmp_x+2 < n && !arr[tmp_y][tmp_x+2])
                q.push(make_tuple(tmp_y,tmp_x+1,0));            
            if (tmp_x+2 < n && tmp_y+1 < n && !arr[tmp_y][tmp_x+2] && !arr[tmp_y+1][tmp_x+1] && !arr[tmp_y+1][tmp_x+2])
                q.push(make_tuple(tmp_y,tmp_x+1,2));            
        }

        if (mode == 1){ //현재 세로일 때
            if(tmp_x == n-1 && tmp_y+1 == n-1)
                ans++;                            
            if (tmp_y+2 < n && !arr[tmp_y+2][tmp_x])
                q.push(make_tuple(tmp_y+1,tmp_x,1));            
            if (tmp_y+2 < n && tmp_x+1 < n && !arr[tmp_y+2][tmp_x] && !arr[tmp_y+1][tmp_x+1] && !arr[tmp_y+2][tmp_x+1])
                q.push(make_tuple(tmp_y+1,tmp_x,2));            
        }

        if (mode == 2){ //현재 대각선일 때
            if(tmp_x+1 == n-1 && tmp_y+1 == n-1)
                ans++;                
            if (tmp_y+1 < n && tmp_x+2 < n && !arr[tmp_y+1][tmp_x+2])
                q.push(make_tuple(tmp_y+1,tmp_x+1,0));            
            if (tmp_y+2 < n && tmp_x+1 < n && !arr[tmp_y+2][tmp_x+1])
                q.push(make_tuple(tmp_y+1,tmp_x+1,1));            
            if (tmp_y+2 < n && tmp_x+2 < n && !arr[tmp_y+2][tmp_x+1] && !arr[tmp_y+1][tmp_x+2] && !arr[tmp_y+2][tmp_x+2])
                q.push(make_tuple(tmp_y+1,tmp_x+1,2));            
        }
    }
    cout << ans;
    return 0;
}