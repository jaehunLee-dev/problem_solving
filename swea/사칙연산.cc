#include<iostream>
#include <stdio.h>
#include <string>
using namespace std;

double calc(double* tree, int* left_child, int* right_child, int idx){
    if (tree[idx] < 0){        
        if (tree[idx] == -1)
            return calc(tree,left_child,right_child,left_child[idx]) + calc(tree,left_child,right_child,right_child[idx]);
        if (tree[idx] == -2)
            return calc(tree,left_child,right_child,left_child[idx]) - calc(tree,left_child,right_child,right_child[idx]);
        if (tree[idx] == -3)
            return calc(tree,left_child,right_child,left_child[idx]) * calc(tree,left_child,right_child,right_child[idx]);
        if (tree[idx] == -4)
            return calc(tree,left_child,right_child,left_child[idx]) / calc(tree,left_child,right_child,right_child[idx]);
    }    
    return tree[idx];     
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    
	//freopen("input.txt", "r", stdin);	    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;        
        double* tree = new double[N+1]();
        int* left_child = new int[N+1]();
        int* right_child = new int[N+1]();
        string s;
        getline(cin,s);
        for (int i=1; i<=N; i++){            
            getline(cin,s);            
            char op;
            int idx = -1;
            for (int j=0; j<s.length(); j++){
                if (s[j] == ' '){
                    idx = j;
                    break;
                }
            }
            if (s.length() > idx+2 && s[idx+2] == ' '){ //연산자 노드
                op = s[idx+1];
                switch (op)     //+: -1, -: -2, *: -3, /: -4
                {
                case '+':
                    tree[i] = -1;
                    break;
                
                case '-':
                    tree[i] = -2;
                    break;
                
                case '*':
                    tree[i] = -3;
                    break;

                case '/':
                    tree[i] = -4;
                    break;
                default:
                    break;
                }
                int idx2 = -1;
                for (int j=idx+3; j<s.length(); j++){
                    if (s[j] == ' '){
                        idx2 = j;
                        break;
                    }
                }            
                string lc = s.substr(idx+3,idx2);
                int lc_idx = stoi(lc);
                string rc = s.substr(idx2+1,-1);
                int rc_idx = stoi(rc);
                left_child[i] = lc_idx;
                right_child[i] = rc_idx;                
            }

            else{
                string s_num = s.substr(idx+1,-1);
                double num = stod(s_num);
                tree[i] = num;                
            }
        }
        cout << '#' << test_case << ' ' << calc(tree,left_child,right_child,1) << '\n';
	}
	return 0;
}