#include<iostream>
using namespace std;
const int MN = 202;
const int INF = 1 << 30;
int n,m;
struct{
	int x,y;
}H[MN],M[MN];
int S,T;
int cap[MN][MN],val[MN][MN];
int dis[MN],pre[MN],que[10000000],qh,qt;
bool inque[MN];
bool spfa(){
	qh = qt = 0;
	memset(inque,0,sizeof(inque));
	fill(dis,dis + T + 1,INF);
	dis[S] = 0;
	que[qt++] = S;
	while(qh != qt){
		int u = que[qh++];
		inque[u] = false;
		for(int v = 0; v <= T; v++){
			if(cap[u][v] > 0 && dis[u] != INF && dis[u] + val[u][v] < dis[v]){
				dis[v] = dis[u] + val[u][v];
				pre[v] = u;
				if(!inque[v]){
					inque[v] = true;
					que[qt++] = v;
				}
			}
		}
	}
	return dis[T] != INF;
}

int feeflow(){
	int ans = 0;
	while(spfa()){
		int p = T,minn = INF;
		while(p != S){
			minn = min(minn,cap[pre[p]][p]);
			p = pre[p];
		}
		p = T;
		while(p != S){
			cap[pre[p]][p] -= minn;
			cap[p][pre[p]] += minn;
			p = pre[p];
		}
		ans += minn * dis[T];
	}
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,ch,cm;
	char c;
	while(scanf("%d%d",&n,&m),n + m){
		for(i = 0,ch = 0,cm = 0; i < n; i++){
			getchar();
			for(j = 0; j < m; j++){
				c = getchar();
				if(c == 'H'){
					H[ch].y = i;
					H[ch++].x = j;
				}else if(c == 'm'){
					M[cm].y = i;
					M[cm++].x = j;
				}
			}		
		}
		memset(cap,0,sizeof(cap));
		memset(val,0,sizeof(val));
		S = cm + ch; T = S + 1;
		for(i = 0; i < cm; i++){
			cap[S][i] = 1;
			val[S][i] = 0;
			for(j = 0; j < ch; j++){
				int L = abs(M[i].x - H[j].x) + abs(M[i].y - H[j].y);
				cap[i][j + cm] = 1;
				val[i][j + cm] = L;
				val[j + cm][i] = -L;
			}
		}
		for(j = 0; j < ch; j++){
			cap[j + cm][T] = 1;
			val[j + cm][T] = 0;
		}
		printf("%d\n",feeflow());
	}
}