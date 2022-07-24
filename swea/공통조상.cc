#include<iostream>
#include <vector>

using namespace std;

void calc_level(int** child, int idx, int* level){
	for (int i=0; i<2; i++){
		if (child[idx][i] != 0){
			level[child[idx][i]] = level[idx]+1;
			calc_level(child,child[idx][i],level);
		}
	}
}

int calc_size(int** child, int idx, int* sub_size){
	int ans = 1;
	for (int i=0; i<2; i++){
		if (child[idx][i] != 0)
			ans+= calc_size(child,child[idx][i],sub_size);
	}	
	sub_size[idx] = ans;
	return ans;
}

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
		int V, E, v1, v2;
        cin >> V >> E >> v1 >> v2;
		int* parent = new int[V+1]();
		int** child = new int*[V+1];		
		for (int i=0; i<V+1; i++)
			child[i] = new int[2]();		//최대 2개의 자식노드
		int* level = new int[V+1]();
		int* sub_size = new int[V+1]();
		int prt, chd;
		for (int i=0; i<E; i++){
			cin >> prt >> chd;
			parent[chd] = prt;		//chd의 부모가 누군지 저장
			if (child[prt][0] == 0){
				child[prt][0] = chd;				
			}
			else child[prt][1] = chd;			
		}
		calc_level(child,1,level);		//노드 레벨 저장
		calc_size(child,1,sub_size);	//subtree 사이즈 저장
		while (level[v1] > level[v2]){	//v1이 v2보다 레벨이 높은 경우(즉 더 아래에 있는 경우), 같은 레벨까지 올려야함.
			v1 = parent[v1];
		}
		while (level[v1] < level[v2]){
			v2 = parent[v2];
		}
		while (v1 != v2){
			v1 = parent[v1];
			v2 = parent[v2];
		}		
		cout << '#' << test_case << ' ' << v1 << ' ' << sub_size[v1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
parent 배열에도 저장. parent[x] = 5. x의 부모가 5라는 뜻
또한, 자식의 수를 기록하는 배열, child_num[]도 생성. parent[x] = 5할때,  child_num[parent[x]]++ 도 같이. 이렇게 하려면, leaf node부터 해야함.
이때, 레벨도 기록
level[n] : n번 노드의 레벨. level[1] = 1.
level[n] = level[parent[n]]+1
레벨이 다르면 -> 레벨 높은거를 똑같이 맞출때까지 부모로..
일단 부모, 자식 배열에 다 넣은 후, 부모부터 탐색하며 레벨 계산해서 넣고, 
child[x][0] = 0 -> x는 leaf node
*/