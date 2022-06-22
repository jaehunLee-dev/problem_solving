#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;
    for (int itr = 0; itr<T; itr++){
        int N; cin >> N;
        int* num = new int[N];
        for (int i=0;i<N;i++)
            cin >> num[i];
        cout << *min_element(num,num+N) << ' ' << *max_element(num,num+N) << '\n';
    }
    return 0;
}