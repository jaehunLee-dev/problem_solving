#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    int* num = new int[n];
    for (int i=0; i<n; i++)
        cin >> num[i];
    sort(num,num+n);
    int max = 0;
    for (int i=n-1; i>=0; i--){
        for (int j=i-1; j>=0; j--){
            for (int k=j-1; k>=0; k--){
                if (num[i]+num[j]+num[k] <= m && num[i]+num[j]+num[k]>max){
                    max = num[i]+num[j]+num[k];
                    if (max == m){
                        cout << m;
                        return 0;
                    }
                }
            }
        }
    }
    cout << max;
    return 0;
}