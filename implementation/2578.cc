#include <iostream>
using namespace std;
int garo[5], sero[5], cross[2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int bingo[5][5];
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++)
            cin >> bingo[i][j];        
    }
    int tmp, now=0;
    bool out = false;
    for (int i=0; i<25; i++){        
        out = false;
        cin >> tmp;
        for (int k=0; k<5; k++){
            for (int l=0; l<5; l++){
                if (bingo[k][l] == tmp){
                    if(++sero[k] == 5)
                        now++ ;                   
                    if(++garo[l] == 5)
                        now++;
                    if (k == l){    //대각선                
                        if(++cross[0] == 5)
                        now++;
                    }
                    if (k+l == 4){    //대각선2
                        if(++cross[1] == 5)
                        now++;
                    }
                    out = true;
                    break;
                }
            }
            if (out) break;
        }
        if (now >= 3){
            cout << i+1;
            break;
        }        
    }
    return 0;
}