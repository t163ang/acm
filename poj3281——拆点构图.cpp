/*
ID: davidro2
PROG: poj3281
LANG: C++
*/
#include<iostream>
using namespace std;
const int MN = 424;
const int INF = 1 << 30;
int N,F,D;
int cap[MN][MN];
int S = 0,T;
int que[1000000],qh,qt;
int h[MN],num[MN],pre[MN];
void init(){
	qh = qt = 0;
	memset(h,-1,sizeof(h));
	memset(num,0,sizeof(num));
	h[T] = 0;
	num[0]++;
	que[qt++] = T;
	while(qh != qt){
		int u = que[qh++];
		for(int v = S; v <= T; v++){
			if(h[v] == -1 && cap[v][u] > 0){
				h[v] = h[u] + 1;
				que[qt++] = v;
				num[h[v]]++;
			}
		}
	}
}

int find(int u){
	for(int v = S; v <= T; v++){
		if(cap[u][v] > 0 && h[u] == h[v] + 1){
			return v;
		}
	}
	return -1;
}

int relabel(int u){
	int minn = INF;
	for(int v = S; v <= T; v++){
		if(cap[u][v] > 0 && minn > h[v]){
			minn = h[v];
		}
	}
	if(minn != INF) return minn + 1;
	return T + 1;
}

int flow(){
	init();
	memset(pre,-1,sizeof(pre));
	int i = S,j,ans = 0;
	while(h[S] <= T){
		j = find(i);
		if(j >= 0){
			pre[j] = i;
			i = j;
			if(i == T){
				int minn = INF;
				i = T;
				while(i != S){
					minn = min(minn,cap[pre[i]][i]);
					i = pre[i];
				}
				i = T;
				while(i != S){
					cap[pre[i]][i] -= minn;
					cap[i][pre[i]] += minn;
					i = pre[i];
				}
				ans += minn;
			}
		}else{
			int m = relabel(i);
			num[m]++;
			num[h[i]]--;
			if(num[h[i]] == 0) return ans;
			h[i] = m;
			if(i != S){
				i = pre[i];
			}
		}
	}
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,f,d,t;
	while(~scanf("%d%d%d",&N,&F,&D)){
		memset(cap,0,sizeof(cap));
		T = F + N + N + D + 1;
		for(i = 1; i <= N; i++){
			scanf("%d%d",&f,&d);
			cap[F + i][F + N + i] = 1; 
			for(j = 1; j <= f; j++){
				scanf("%d",&t);
				cap[S][t] = 1;
				cap[t][F + i] = 1;
			}
			for(j = 1; j <= d; j++){
				scanf("%d",&t);
				t += N + N + F;
				cap[F + N + i][t] = 1;
				cap[t][T] = 1;
			}
		}
		printf("%d\n",flow());
	}
	return 0;
}