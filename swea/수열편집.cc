#include<iostream>
#include <list>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin>>T;	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M, L, tmp;
        cin >> N >> M >> L;
        list<int> lt;
        while(N--){
            cin >> tmp;
            lt.push_back(tmp);            
        }
        while(M--){
            char cmd;
            cin >> cmd;
            int x, y;
            switch (cmd)
            {
            case 'I': {      //insert                
                cin >> x >> y;
                list<int>::iterator iter = lt.begin();                
                while (x--)
                    iter++;
                lt.insert(iter,y);                                    
                break;
            }            
            case 'D':{
                cin >> x;
                list<int>::iterator iter = lt.begin();
                while (x--)
                    iter++;                
                iter = lt.erase(iter);
                break;
            }
            case 'C':{
                cin >> x >> y;
                list<int>::iterator iter = lt.begin();
                while(x--){
                    iter++;
                }
                *iter = y;
                break;
            }
            default:{
                break;
            }                    
            }
        }
        cout << '#' << test_case << ' ';
        int idx = 0;
        int ans = -1;
        for (auto& i: lt){
            if (idx == L){
                ans = i;
                break;
            }
            idx++;
        }
        cout << ans << '\n';
	}    
	return 0;
}