#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 208;
int n,p,t,S,T;
struct Trail{
	int x,y,c;
	bool operator <(const Trail t){
		return c < t.c;
	}
	Trail(int a,int b,int c):x(a),y(b),c(c){	
	}
	Trail(){}
}trail[40024];
int cap[MN][MN];
void construct(int mid){
	int i,j;
	memset(cap,0,sizeof(cap));
	/*
		注意是边是双向的！这题使用网络流边的容量来限制走的次数。
	*/
	for(i = 0; i < p; i++){
		if(trail[i].c > mid) break;
		cap[trail[i].x][trail[i].y]++;
		cap[trail[i].y][trail[i].x]++;
	}
}

int que[MN],qh,qt;
int pre[MN];
bool vis[MN];
bool bfs(){
	memset(vis,0,sizeof(vis));
	qh = qt = 0;
	que[qt++] = S;
	vis[S] = true;
	while(qh != qt){
		int u = que[qh++];
		for(int v = S; v <= T; v++){
			if(!vis[v] && cap[u][v] > 0){
				vis[v] = true;
				pre[v] = u;
				que[qt++] = v;
				if(v == T){
					return true;
				}
			}
		}
	}
	return false;
}
bool flow(int mid){
	construct(mid);
	int sum = 0;
	while(bfs()){
		int t = T,minn = INT_MAX;
		while(t != S){
			if(minn > cap[pre[t]][t]) minn = cap[pre[t]][t];
			t = pre[t];
		}
		t = T;
		while(t != S){
			/*
				双向边同样适用
			*/
			cap[pre[t]][t] -= minn;
			cap[t][pre[t]] += minn;
			t = pre[t];
		}
		sum += minn;
	}
	if(sum >= t){
		return true;
	}
	return false;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,a,b,c;
	while(~scanf("%d%d%d",&n,&p,&t)){
		int L= INT_MAX,R = 0;
		S = 1; 
		T = n; 
		for(i = 0; i < p; i++){
			scanf("%d%d%d",&a,&b,&c);
			trail[i] = Trail(a,b,c);
			if(R < c) R = c;
			if(L > c) L = c;
		}
		sort(trail,trail + p);
		while(L <= R){
			int mid = (L + R) >> 1;
			if(flow(mid)){
				R = mid - 1;
			}else{
				L = mid + 1;
			}
		}
		printf("%d\n",L);
	}
	return 0;
}