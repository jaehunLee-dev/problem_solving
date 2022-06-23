#include <iostream>
using namespace std;
bool submit[30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int jun_cash, sung_cash;
    cin >> jun_cash;
    sung_cash = jun_cash;
    int jun_num = 0, sung_num = 0;
    int flow = 0;
    int juga[14];
    for (int i=0; i<14; i++)
        cin >> juga[i];
    for (int i=0;i<14;i++){
        if (jun_cash/juga[i] > 0){
            jun_num+= jun_cash/juga[i];
            jun_cash %= juga[i];
        }
        if (i != 0 ){
            if (juga[i] > juga[i-1]){
                if (flow > 0)
                    flow++;
                else flow = 1;
            }
            else if (juga[i] < juga[i-1]){
                if (flow < 0)
                    flow--;
                else flow = -1;
            }
            else flow = 0;
            if (flow>=3){
                if (sung_num > 0){                
                    sung_cash += sung_num*juga[i];
                    sung_num= 0;                    
                }  
            }
            else if (flow <= -3){
                if (sung_cash/juga[i] > 0){
                    sung_num+= sung_cash/juga[i];
                    sung_cash %= juga[i];
                }                  
            }
        }
    }
    jun_cash += juga[13]*jun_num;
    sung_cash += juga[13]*sung_num;    
    string ans =  (jun_cash > sung_cash) ? "BNP" : (jun_cash == sung_cash) ? "SAMESAME" :"TIMING";    
    cout << ans;
    return 0;
}