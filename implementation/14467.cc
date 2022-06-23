#include <iostream>
using namespace std;
int main(){
    int N; cin >> N;
    int cross[11];
    int ans = 0;
    for (int i=0; i<11; i++){
        cross[i] = -1;
    }
    int so = -1, dir = -1;
    for (int i=0; i<N; i++){
        cin >> so >> dir;
        if (cross[so] == -1)
            cross[so] = dir;
        if (dir == cross[so])
            continue;
        cross[so] = dir;
        ans++;
    }
    cout << ans;
    return 0;
}