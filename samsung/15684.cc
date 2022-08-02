#include <iostream>
using namespace std;
int N, M, H;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> H;
    bool** ladder = new bool*[N+1]; //ladder[2][1] : 2번째 가로에서 1->2로 가는 것
    for (int i=1; i<H; i++)
        ladder[i] = new bool[H+1]();
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;        //a번째 가로에서 a->a+1 가는 것
    }

    return 0;
}
//