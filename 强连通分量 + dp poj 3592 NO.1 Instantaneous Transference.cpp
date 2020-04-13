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
		}else if(instack[j] && dfn[j] < low[v]) low[v] = dfn[j];
	}
	if(dfn[v] == low[v]){
		do{
			j = Stack[--top];
			Scc[j] = B;
			instack[j] = false;	
			mine[B] += w[j];
		}while(v != j);B++;
	}
}

void dfs(){
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
	memset(mine,0,sizeof(mine));
	top =  B = C = 0;
	for(int i = 0; i < N * M; i++)
		if(!dfn[i]) visit(i);//这里visit(0)为什么不行我还是没想明白
}

inline int CV(int i, int j){
	return i * M + j;
}

void dp(){
	int i = Scc[0], max;//这里i = B - 1为什么不行我还是没想明白
	memset(dfn,-1,sizeof(dfn));
	max = dfn[i] = mine[i];
	for(i--; i >= 0; i--){
		for(int j = map[i + MN]; j; j =  edge[j].next){
			int k = edge[j].v;
			if(dfn[i] < dfn[k]) dfn[i] = dfn[k];
		} 
		dfn[i] += mine[i];
		if(max < dfn[i]) max = dfn[i];
	}
	printf("%d\n",max);
}
int main() {
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
		for(i = 0; i < M * N; i++){
			for(j = map[i]; j; j = edge[j].next){
				k = edge[j].v;
				if(Scc[i] != Scc[k]) adde(Scc[k] + MN,Scc[i]);
			}
		}
		dp();
	}
	return 0;
}

//visit(0) AC代码,原因是B = 0, 当末求的连通分量也是Scc[i] = 0,所以我把B = 1作为开始
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
		}else if(instack[j] && dfn[j] < low[v]) low[v] = dfn[j];
	}
	if(dfn[v] == low[v]){
		do{
			j = Stack[--top];
			Scc[j] = B;
			instack[j] = false;	
			mine[B] += w[j];
		}while(v != j);B++;
	}
}

void dfs(){
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
	memset(mine,0,sizeof(mine));
	memset(Scc,0,sizeof(Scc));
	top =  B = C = 1;//当末求的连通分量也是Scc[i] = 0,所以我把B = 1作为开始
	visit(0); 
}

inline int CV(int i, int j){
	return i * M + j;
}

void dp(){
	int i = B - 1, max;
	memset(dfn,-1,sizeof(dfn));
	max = dfn[i] = mine[i];
	for(i--; i >= 0; i--){
		for(int j = map[i + MN]; j; j =  edge[j].next){
			int k = edge[j].v;
			if(dfn[i] < dfn[k]) dfn[i] = dfn[k];
		} 
		dfn[i] += mine[i];
		if(max < dfn[i]) max = dfn[i];
	}
	printf("%d\n",max);
}
int main() {
	//freopen("in.txt","r",stdin);
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
		for(i = 0; i < M * N; i++){
			if(!Scc[i]) continue;
			for(j = map[i]; j; j = edge[j].next){	
				k = edge[j].v;
				if(!Scc[k]) continue;
				if(Scc[i] != Scc[k]) adde(Scc[k] + MN,Scc[i]);
			}
		}
		dp();
	}
	return 0;
}

