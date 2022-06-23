#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    char** bomb = new char*[n];
    char** open = new char*[n];
    char** ans_table = new char*[n];
    bool explode = false;
    for (int i=0; i<n; i++){
        bomb[i] = new char[n];        
        open[i] = new char[n];
        ans_table[i] = new char[n];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cin >> bomb[i][j];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cin >> open[i][j];
    }    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int ans = 0;
            if (open[i][j] == 'x'){
                if (bomb[i][j] == '*'){
                    explode = true;
                }
                else{
                    if (i>0){
                        if (bomb[i-1][j] == '*')
                            ans++;
                    }
                    if (j>0){
                        if (bomb[i][j-1] == '*')
                            ans++;
                    }
                    if (i<n-1){
                        if (bomb[i+1][j] == '*')
                            ans++;
                    }
                    if (j<n-1){
                        if (bomb[i][j+1] == '*')
                            ans++;
                    }
                    if (i>0 && j>0){
                        if (bomb[i-1][j-1] == '*')
                            ans++;
                    }
                    if (i>0 && j<n-1){
                        if (bomb[i-1][j+1] == '*')
                            ans++;
                    }
                    if (i<n-1 && j>0){
                        if (bomb[i+1][j-1] == '*')
                            ans++;
                    }
                    if (i<n-1 && j<n-1){
                        if (bomb[i+1][j+1] == '*')
                            ans++;
                    }
                    ans_table[i][j] = ans+'0';
                }
            }
            else
                ans_table[i][j] = '.';
        }
    }
    if (explode){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (bomb[i][j] == '*')
                    ans_table[i][j] = '*';
            }
        }
    }    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cout << ans_table[i][j];
        cout << '\n';
    }
    return 0;
}