#include<iostream>
using namespace std;

const int MN = 124;
int N;
bool adj[MN][MN];

int Stack[MN], top;
bool instack[MN];
int dfn[MN],low[MN],Scc[MN],B,D;
void visit(int i){
	int j; D++;
	low[i] = dfn[i] = D;	
	Stack[top++] = i;
	instack[i] = true;
	for(j = 1; j <= N; j++){
		if(!adj[i][j]) continue;
		if(!dfn[j]){
			visit(j);
			if(low[i] > low[j]) low[i] = low[j]; 
		}else{
			if(instack[j]&&dfn[j] < low[i]) low[i] = dfn[j];
		}
	}
	if(dfn[i] == low[i]){
		do{
			j = Stack[--top];
			instack[j] = false;
			Scc[j] = B;
		}while(j != i); B++;
	}
}
void dfs(){
	int i;
	B = D = top = 0;
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	for(i = 1; i <= N; i++){
		if(!dfn[i]) visit(i);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d",&N)){
		memset(adj,0,sizeof(adj));
		for(i = 1; i <= N; i++){
			while(scanf("%d",&j),j){
				adj[i][j] = true;
			}
		}
		dfs();
		//求缩点的出入度
		int in[MN] = {0}, out[MN] = {0};
		for(i = 1; i <= N; i++){
			for(j = 1; j <= N; j++){
				if(adj[i][j] && Scc[i] != Scc[j]) {
					in[Scc[j]]++;
					out[Scc[i]]++;
				}
			}
		}
		if(B == 1){
			printf("1\n0\n");
			continue;
		}
		//求统计所有连通分量的出入度为零总和
		int IN = 0,OUT = 0;
		for(i = 0; i < B; i++){//B连通分量数
			if(!in[i]) IN++;
			if(!out[i]) OUT++;
		}
		printf("%d\n",IN);
		printf("%d\n",IN > OUT ? IN : OUT);
	}
	return 0;
}
