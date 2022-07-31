#include <iostream>
#include <vector>
using namespace std;
bool dragon[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int x, y, d, g;
    for (int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        dragon[y][x] = true;        
        vector<int> cmd;
        cmd.push_back(d);
        while(g--){
            for (int j=cmd.size()-1; j>=0; j--){
                int tmp = (cmd[j]+1)%4;
                cmd.push_back(tmp);
            }
        }
        for (auto& j:cmd){
            switch (j)
            {
            case 0:
                x = x + 1;
                break;
            case 1:
                y = y - 1;
                break;
            case 2:
                x = x - 1;
                break;
            case 3:
                y = y + 1;
                break;
            default:
                break;
            }
            dragon[y][x] = true;
        }
    }
    int ans = 0;
    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            if (dragon[i][j] && dragon[i][j+1] && dragon[i+1][j] && dragon[i+1][j+1])
                ans++;
        }
    }
    cout << ans;
    return 0;
}