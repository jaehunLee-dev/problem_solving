#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string t1, t2;
    int h1, h2, m1, m2, s1, s2;
    cin >> t1 >> t2;    
    if (t1 == t2){
        cout << "24:00:00";
        return 0;
    }
    h1 = (t1[0]-'0')*10 + t1[1]-'0';
    h2 = (t2[0]-'0')*10 + t2[1]-'0';
    m1 = (t1[3]-'0')*10 + t1[4]-'0';
    m2 = (t2[3]-'0')*10 + t2[4]-'0';
    s1 = (t1[6]-'0')*10 + t1[7]-'0';
    s2 = (t2[6]-'0')*10 + t2[7]-'0';
    int ans_h = h2-h1, ans_m = m2-m1, ans_s = s2-s1;
    if (ans_s<0){
        ans_s +=60;
        ans_m-=1;
    }
    if (ans_m<0){
        ans_m +=60;
        ans_h-=1;
    }
    if (ans_h<0)
        ans_h +=24;            

    cout.width(2);cout.fill('0');
    cout << ans_h;
    cout << ":";
    cout.width(2);cout.fill('0');
    cout << ans_m;
    cout << ":";
    cout.width(2);cout.fill('0');
    cout << ans_s;
    return 0;
}