#include<iostream>
using namespace std;

const int MN = 128;
struct{
	int v,next;
}node[MN << 2];
int head[MN],pn;
int n,col[MN],ans;
inline void adde(int u,int v){
	node[pn].v = v;
	node[pn].next = head[u];
	head[u] = pn++;
}

bool isOK(int u){
	for(int i = head[u]; i ; i = node[i].next){
		int v = node[i].v;
		if(col[u] == col[v]) return false;
	}
	return true;
}

void dfs(int k){
	if(k >= n){
		bool used[5] = {false};
		for(int i = 0; i < n; i++){
			used[col[i]] = true;
		}
		int m = used[1] + used[2] + used[3] + used[4];
		if(ans > m) ans = m;
		return;
	}

	for(int i = 1; i <= 4; i++){
		col[k] = i;
		if(isOK(k)) dfs(k + 1);
		col[k] = 0;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,len,u;
	char inp[MN];
	while(scanf("%d",&n),n){
		for(i = 0,pn = 1; i < MN; i++){//³õÊ¼»¯
			head[i] = 0;
			col[i] = 0;
		}
		for(i = 0; i < n; i++){
			scanf("%s",inp);
			len = strlen(inp);
			u = inp[0] - 'A';
			if(len > 2){
				for(j = 2; j < len; j++){
					adde(u,inp[j] - 'A');
				}
			}
		}
		ans = 999;
		dfs(0);
		if(ans == 1) printf("1 channel needed.\n");
		else printf("%d channels needed.\n",ans);
	}
	return 0;
}