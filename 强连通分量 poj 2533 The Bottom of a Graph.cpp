#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MN = 5024;
vector<int> adj[MN];

int n,e;
bool instack[MN];
int low[MN], dfn[MN],Scc[MN],Stack[MN],top, B, C;
bool out[MN];
void visit(int v){
	int j; C++;
	instack[v] = true;
	Stack[top++] = v;
	dfn[v] = low[v] = C;
	vector<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		j = *it;
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
		}while(v != j);B++;
	}
}

void dfs(){
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));//不用清空Scc的
	top =  B = C = 0;
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) visit(i);
	}
}


int main() {
   // freopen("in.txt", "r", stdin);
    int i, j, k;
	while(scanf("%d",&n),n){
		
		scanf("%d",&e);
		for(i = 0; i < e; i++){
			scanf("%d%d",&j,&k);
			adj[j].push_back(k);
		}
		dfs();
		memset(out,0,sizeof(out));
		vector<int>::iterator it;
		for(i = 1; i <= n; i++){
			for(it = adj[i].begin(); it != adj[i].end(); it++){
				if(!out[Scc[i]] && Scc[i] != Scc[*it]) out[Scc[i]] = true;
			}
		}
		for(i = 1; i <= n; i++){
			if(!out[Scc[i]]) printf("%d ",i);
			adj[i].clear();//记住adj也要清空
		}
		puts("");
	}
    return 0;
}

//
//The input contains several test cases, each of which corresponds to a directed graph G. 
//Each test case starts with an integer number v, denoting the number of vertices of G=(V,E),
//where the vertices will be identified by the integer numbers in the set V={1,...,v}. 
//You may assume that 1<=v<=5000. That is followed by a non-negative integer e and,
//thereafter, e pairs of vertex identifiers v1,w1,...,ve,we with the meaning that (vi,wi)∈E.
//There are no edges other than specified by these pairs. The last test case is followed by a zero.
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int MN = 5024;
////vector<int> adj[MN];
//struct {
//	int v,next;
//}edge[MN << 4];
//int map[MN] = {0}, ep = 1;
//inline void adde(int j, int k){
//	edge[ep].v = k;
//	edge[ep].next = map[j];
//	map[j] = ep++;
//	//for(i = map[v]; i ; i = edge[i].next)
//	//	j = edge[i].v;
//}
//int n,e;
//bool instack[MN];
//int low[MN], dfn[MN],Scc[MN],Stack[MN],top, B, C;
//bool out[MN];
//void visit(int v){
//	int i,j; C++;
//	instack[v] = true;
//	Stack[top++] = v;
//	dfn[v] = low[v] = C;
//	for(i = map[v]; i ; i = edge[i].next){
//		j = edge[i].v;
//		if(!dfn[j]){
//			visit(j);
//			if(low[v] > low[j]) low[v] = low[j];
//		}else if(instack[j] && dfn[j] < low[v]) low[v] = dfn[j];
//	}
//	if(dfn[v] == low[v]){
//		do{
//			j = Stack[--top];
//			Scc[j] = B;
//			instack[j] = false;
//		}while(v != j);B++;
//	}
//}
//
//void dfs(){
//	memset(dfn,0,sizeof(dfn));
//	memset(instack,0,sizeof(instack));//不用清空Scc的
//	top =  B = C = 0;
//	for(int i = 1; i <= n; i++){
//		if(!dfn[i]) visit(i);
//	}
//}
//
//
//int main() {
//	//freopen("in.txt", "r", stdin);
//	//freopen("F:\out","w",stdout);
//	int i, j, k;
//	while(scanf("%d",&n),n){
//		scanf("%d",&e);
//		memset(map,0,sizeof(map)); ep = 1;
//		for(i = 0; i < e; i++){
//			scanf("%d%d",&j,&k);
//			//adj[j].push_back(k);
//			adde(j,k);
//		}
//		dfs();
//		memset(out,0,sizeof(out));
//		for(i = 1; i <= n; i++){
//			for(j = map[i]; j; j = edge[j].next){
//				k = edge[j].v;
//				if(!out[Scc[i]] && Scc[i] != Scc[k]) out[Scc[i]] = true;
//			}
//		}
//		for(i = 1; i <= n; i++){
//			if(!out[Scc[i]]) printf("%d ",i);
//			//adj[i].clear();//记住adj也要清空
//		}
//		puts("");
//	}
//	return 0;
//}