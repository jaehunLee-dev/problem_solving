#include <iostream>
using namespace std;
int main(){
    int min = 64;
    int n,m;
    cin >> n >> m;
    char** board = new char*[n];
    for (int i=0; i<n; i++)
        board[i] = new char[m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            cin >> board[i][j];
    }    
    //first : white version
    for (int i=0; i<=n-8; i++){
        for (int j=0; j<=m-8; j++){
            int tmp = 0, tmp2=0;
            for (int k=0; k<8; k++){
                for (int h=0; h<8; h++){
                    int y = i+k;
                    int x = j+h;
                    if (y%2 == x%2 && board[y][x] != 'W')
                        tmp++;
                    else if (y%2 != x%2 && board[y][x] != 'B')
                        tmp++;
                    else if (y%2 == x%2 && board[y][x] != 'B')
                        tmp2++;
                    else if (y%2 != x%2 && board[y][x] != 'W')
                        tmp2++;
                }
            }
            if (tmp < min) min = tmp;
            if (tmp2<min) min = tmp2;
        }
    }
    cout << min;
    return 0;
}