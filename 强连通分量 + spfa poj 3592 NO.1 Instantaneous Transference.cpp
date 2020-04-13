#include<iostream>
using namespace std;

const int MN = 1800;
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
int low[MN], dfn[MN],Scc[MN],Stack[MN],top, B, C;
int mine[MN], w[MN], mag[MN];
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
		if(!dfn[i]) visit(i);
}

inline int CV(int i, int j){
	return i * M + j;
}

int que[MN],head,tail;
int dis[MN];
void Spfa(){
	memset(instack,0,sizeof(instack));
	memset(dis,0,sizeof(dis));
	head = tail = 0;	

	int u,v,ans;
	que[tail++] = Scc[0];
	dis[Scc[0]] = ans =  mine[Scc[0]];
	instack[Scc[0]] = true;
	
	while(head != tail){
		u = que[head]; head = (head + 1) % MN;
		instack[u] = false;
		for(int i = map[u + MN]; i; i = edge[i].next){
			v = edge[i].v;
			if(dis[v] < dis[u] + mine[v]){
				dis[v] = dis[u] + mine[v];
				if(ans < dis[v]) ans = dis[v];
				if(!instack[v]){
					instack[v] = true;
					que[tail] = v;
					tail = (tail + 1) % MN;
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main() {
	//freopen("in.txt", "r", stdin);
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
		//重新(反向)构图
		for(i = 0; i < M * N; i++){
			for(j = map[i]; j; j = edge[j].next){
				k = edge[j].v;
				if(Scc[i] != Scc[k]) adde(Scc[i] + MN,Scc[k]);
			}
		}
		Spfa();
	}
	return 0;
}
