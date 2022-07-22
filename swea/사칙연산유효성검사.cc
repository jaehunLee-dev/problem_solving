#include<iostream>
using namespace std;
bool isNum(char ch){
    if (ch<='9' && ch >= '0')
        return true;
    return false;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);	
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ans = 1;
        int N; 
        cin >> N;
        char* tree = new char[N+1];
        for (int i=1; i<=N; i++){    
            int idx;
            cin >> idx;
            cin >> tree[idx];
            //자식 있으면 연산자, 없으면 숫자여야함
            if (idx*2 < N){ //자식 2개
                int left, right;
                cin >> left >> right;
                if (isNum(tree[idx]))
                    ans = 0;
            }
            else if (idx*2 == N){
                int left;
                cin >> left;
                if (isNum(tree[idx]))
                    ans = 0;            
            }
            else{
                if (!isNum(tree[idx]))
                    ans = 0;
            }            
        }
        cout << '#' << test_case << ' ' << ans << '\n';;
	}
	return 0;
}