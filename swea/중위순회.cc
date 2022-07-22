#include<iostream>
using namespace std;

void traverse(char* tree, int N, int idx){
    if (idx*2 <= N)
        traverse(tree,N,idx*2);
    cout << tree[idx];
    if (idx*2+1 <=N)
        traverse(tree,N,idx*2+1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);	
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        char* tree = new char[N+1];
        for (int i=1; i<=N; i++){            
            int idx;
            cin >> idx;
            cin >> tree[idx];
            if (idx*2 < N){ //자식 2개
                int left, right;
                cin >> left >> right;
            }
            else if (idx*2 == N){
                int left;
                cin >> left;            
            }            
        }
        cout << '#' << test_case << ' ';
        traverse(tree,N,1);
        cout << '\n';
	}
	return 0;
}