/*ID: davidro2
PROG: poj3469
LANG: C++
*/
/*
对于原图中的一条路径s->u->v->t, <s,u>,<u,v>,<v,t>至少有一个在最小割中, 又每个任务都和s,t相连,
所以对于任务u, 必然<s,u>,<u,t>至少有一个在最小割中, 所以此图的最小割即为所求. 
*/
#include<iostream>
using namespace std;
const int MN = 800000;
const int INF = 1 << 30;
int N,M,S,T;
struct Edge{
	int v,c;
	Edge *next,*rev;
}edge[MN],*head[MN],*curHead[MN],*topp;
void inline adde(int u,int v,int c,int c2){
	topp->v = v;
	topp->c = c;
	topp->next = head[u];
	topp->rev = topp + 1;
	head[u] = topp++;
	topp->v = u;
	topp->c = c2;
	topp->next = head[v];
	topp->rev = topp - 1;
	head[v] = topp++;
}
int h[MN],num[MN];
int que[MN],qh,qt;
Edge *fro[MN],*edg;
void bfs(){
	h[T] = 0;
	num[0]++;
	qh = qt = 0;
	que[qt++] = T;
	Edge *edg;
	while(qh != qt){
		int u = que[qh++];
		for(edg = head[u]; edg != NULL; edg = edg->next){
			int v = edg->v;
			if(h[v] == -1){
				h[v] = h[u] + 1;
				num[h[v]]++;
				que[qt++] = v;
			}
		}
	}
}
int minCut(){
	bfs();
	int u = S,fl = 0,aug = INF,cnt = 0; 
	bool flag;
	Edge *edg;
	memcpy(curHead,head,sizeof(head));
	while(h[S] <= T){
		flag = true;
		while((edg = curHead[u]) != NULL){
			int v = edg->v,c = edg->c;
			if(c > 0 && h[u] == h[v] + 1){
				flag = false;
				if(aug > c) aug = c;
				fro[cnt++] = edg;
				u = v;
				if(u == T){
					for(int i = 0; i < cnt; i++){
						fro[i]->c -= aug;
						fro[i]->rev->c += aug;
					}
					cnt = 0;
					fl += aug;
					aug = INF;
					u = S;				
					break;
				}
			}else{
				curHead[u] = curHead[u]->next;
			}
		}	
		if(flag){
			int minn = INF;
			for(edg = head[u];edg != NULL;edg=edg->next){
				if(edg->c > 0 && minn > h[edg->v]){
					minn = h[edg->v];
				}
			}
			if(minn == INF) return fl;
			minn++;
			num[minn]++;
			num[h[u]]--;
			if(!num[h[u]]) return fl;
			h[u] = minn;
			curHead[u] = head[u];
		}
	}
	return fl;
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,a,b,c;
 	scanf("%d%d",&N,&M);
	S = 0; T = N + 1; 
	for(i = S; i <= T; i++){
		head[i] = NULL;
		h[i] = -1;
		num[i] = 0;
	}
	topp = edge;
	for(i = 1; i <= N; i++){
		scanf("%d%d",&a,&b);
		adde(S,i,a,0);
		adde(i,T,b,0);
	}
	for(i = 0; i < M; i++){
		scanf("%d%d%d",&a,&b,&c);
		adde(a,b,c,c);
	}
	printf("%d\n",minCut());
	return 0;
}
