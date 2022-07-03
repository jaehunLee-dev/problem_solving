#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    pair<int,int> *body = new pair<int,int>[n];
    for (int i=0; i<n; i++){
        cin >> body[i].first;
        cin >> body[i].second;
    }
    int* ans = new int[n]();
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (body[i].first > body[j].first && body[i].second > body[j].second)
                ans[j]++;
            else if (body[i].first < body[j].first && body[i].second < body[j].second)
                ans[i]++;
        }
    }
    for (int i=0; i<n; i++){
        cout << ans[i]+1<<' ';
    }
    return 0;
}