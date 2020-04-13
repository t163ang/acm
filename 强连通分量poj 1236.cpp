#include<iostream>
using namespace std;
const int MN = 1602;
int N,M;
struct {
	int v,next;
}edge[MN << 2];
int map[MN << 1] = {0}, ep = 1;
inline void adde(int j, int k){
	edge[ep].v = k;
	edge[ep].next = map[j];
	map[j] = ep++;
}
bool instack[MN];
int low[MN],dfn[MN],Scc[MN],Stack[MN],top, B, C,mine[MN], w[MN], mag[MN];
char Map[42][42];
int DP[MN],MAX;
void visit(int v){
	int i,j; C++;
	instack[v] = true;
	Stack[top++] = v;
	dfn[v] = low[v] = C;
	for(i = map[v]; i ; i = edge[i].next){
		j = edge[i].v;
		if(!dfn[j]){
			visit(j);
			if(low[v] > low[j]) low[v] = low[j];
			if(Scc[j] && MAX < DP[Scc[j]])  MAX = DP[Scc[j]];
		}else if(instack[j] && dfn[j] < low[v]) low[v] = dfn[j];
	}
	if(dfn[v] == low[v]){
		do{
			j = Stack[--top];
			Scc[j] = B;
			instack[j] = false;	
			mine[B] += w[j];
		}while(v != j);
		DP[B] = mine[B] + MAX;
		MAX = 0,B++;
	}
}

void dfs(){
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
	memset(mine,0,sizeof(mine));
	memset(Scc,0,sizeof(Scc));
	memset(DP,0,sizeof(DP));
	top =  B = C = 1;
	visit(0);
	printf("%d\n",DP[B - 1]);
}

inline int CV(int i, int j){
	return i * M + j;
}
int main() {
	freopen("in.txt","r",stdin);
	int i,j,k,T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		memset(map,0,sizeof(map)); ep = 1;
		memset(w,0,sizeof(w));
		for(i = 0; i < N; i++) scanf("%s",Map[i]);		
		for(i = 0, k = 0; i < N; i++){
			for(j = 0; j < M; j++){
				char ch = Map[i][j];
				if(ch == '#') continue;
				else if(ch == '*') mag[k++] = CV(i,j);
				else w[CV(i,j)] = ch - '0';
				if(i + 1 < N && Map[i + 1][j] != '#') adde(CV(i,j),CV(i + 1,j));
				if(j + 1 < M && Map[i][j + 1] != '#') adde(CV(i,j),CV(i,j + 1));
			}
		}
		int x,y;
		for(i = 0; i < k; i++){
			scanf("%d%d",&x,&y);
			if(Map[x][y] != '#') adde(mag[i], CV(x,y));
		}	
		dfs();
	}
	return 0;
}
//C<-empty cycle at v0
//while (G has unmarked edges)
//	u<-any vertex on C which has unmarked edges
//	C'<-empty list of edges
//	v<-u
//	do
//		e<-unmarked edge of v
//		mark e
//		Append e to C¡¯
//		v<-other endpoint of e
//	until(v=u)
//Splice C¡¯ into C at u
//endwhile
