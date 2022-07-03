#include <iostream>
using namespace std;
void star(int n, int i, int j){   //idx = 제일 위 string index, n = 총 입력해야 할 줄 갯수
    if ((i/n)%3 == 1 && (j/n)%3 == 1){
        cout << ' ';
    }
    else {
        if (n == 1)
            cout << '*';
        else
            star(n/3,i,j);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string* s = new string[n+1];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            star(n,i,j);
        cout << '\n';
    }
    return 0;
}