 #include<iostream>
#include<algorithm>
using namespace std;
const int MN = 600;
int value[MN];
int request[MN];
int n,m,req;
int tmp[MN],N;
bool visited[MN];
struct Node{
	int types,tot,highest;
	int answer[5];
	bool operator < (const Node n){
		if(types != n.types) {
			return types > n.types;
		}else{
			if(tot != n.tot) return tot < n.tot;
			else return highest > n.highest;
		}
	}
}ans[1000000];
void dfs(int tot, int types,int pre){
	int sum = 0;
	for(int i = 0; i < tot; i++){
		sum += tmp[i];
		ans[N].answer[i] = tmp[i];
	}
	if(sum == req){
		ans[N].tot = tot;
		ans[N].types = types;
		ans[N++].highest = tmp[tot - 1];
		return;
	}
	if(tot >= 4){
		return;
	}
	for(int i = 0; i < n; i++){
		if(i < pre) continue;
		tmp[tot] = value[i];
		if(visited[i]) dfs(tot + 1,types,i);
		else{
			visited[i] = true;
			dfs(tot + 1,types + 1,i);
			visited[i] = false;
		}
	}

}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,k;
	while(~scanf("%d",&k)){
		n = 0;
		while(k != 0){
			value[n++] = k;
			scanf("%d",&k);
		}
		sort(value,value + n);
		m = 0;
		while(scanf("%d",&k),k){
			request[m++] = k;
		}
		for(i = 0; i < m; i++){
			req = request[i]; 
			N = 0;
			tmp[0] = 0;
			memset(visited,0,sizeof(visited));
			dfs(0,0,-1);
			if(N == 0){
				printf("%d ---- none",req);
			}else{
				sort(ans,ans + N);
				printf("%d (%d):",req,ans[0].types);
				bool flag = true;
				if(N > 1){					
					if(ans[0].tot == ans[1].tot && ans[0].types == ans[1].types && ans[0].highest == ans[1].highest){
						printf(" tie");
						flag = false;
					}
				}
				if(flag){
					for(j = 0;j < ans[0].tot; j++){
						printf(" %d",ans[0].answer[j]);
					}	
				}
			}
			printf("\n");
		}

	}
	return 0;
}
