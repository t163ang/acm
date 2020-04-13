/*
ID: davidro2
PROG: poj1815
LANG: C++
*/
/*
	���������㼯�ģ�������������������и�㼯�У�����������С��һ�֣�����С��㼯�����������ڸ�㼯�з�������ĿҪ����С�ġ�
	�����������ģ���ÿһ�������ֳ�i i',����c(i,i') = 1;��С����ö��ÿһ�����㣬�����������С�ˣ�˵�����ǵ�ǰ������ĸ�㣬�����ɾ����ͬʱ����ǰ����������١�
	ΪʲôҪ���ϵ�ɾ���㲢�����������?�����ǽ���ǰ���������������ɾ���أ���ǰ��������������Ǹ�ߣ����Ƕ���֮��������ϵ�ģ���ɾ����һ����㣬���ܾ͵������������ʧЧ��
	���ò��������֮Ҫ���ϼ�����ֱ��Դ�ͻ㲻��ͨ���Ϳ��ҵ�����һ����㼯��
*/
#include<iostream>
#include<queue>
using namespace std;
const int MN = 424;
const int INF = 1 << 30;
int n,s,t,pn;
struct Edge{
	int v;
	Edge* next;
}edge[100000],*head[MN];
void inline adde(int u,int v){
	edge[pn].v = v;
	edge[pn].next = head[u];
	head[u] = edge + pn++;
}
int cap[MN][MN];
int f[MN][MN];
int ans[MN];
queue<int> que;
int h[MN],num[MN];
int pre[MN];
//void init(){
//	memset(h,-1,sizeof(h));
//	memset(num,0,sizeof(num));
//	memset(f,0,sizeof(f));
//	h[t] = 0;
//	num[0]++;
//	que.push(t);
//	while(!que.empty()){
//		int u = que.front();que.pop();
//		for(int v = 1; v <= n + n; v++){
//			if(h[v] == -1 && cap[v][u] > 0){
//				h[v] = h[u] + 1;
//				num[h[v]]++;
//				que.push(v);
//			}
//		}
//	}
//}
//
//int find(int u){
//	for(int v = 1; v <= n + n; v++){
//		if(cap[u][v] > f[u][v] && h[u] == h[v] + 1){
//			return v;
//		}
//	}
//	return -1;
//}
//
//int relabel(int u){
//	int minn = INF;
//	for(int v = 1; v <= n + n; v++){
//		if(cap[u][v] > f[u][v] && minn > h[v]){
//			 minn = h[v];
//		}
//	}
//	if(minn != INF) return minn + 1;
//	return n + n - 1;
//}
//
//int flow(){
//	init();
//	int i = s,j,fl = 0;
//	while(h[s] < n + n - 2){
//		j = find(i);
//		if(j >= 0){
//			pre[j] = i;
//			i = j;
//			if(i == t){
//				int minn = INF;
//				i = t;
//				while(i != s){
//					minn = min(cap[pre[i]][i] - f[pre[i]][i],minn);
//					i = pre[i];
//				}
//				i = t;
//				while(i != s){
//					f[pre[i]][i] += minn;
//					f[i][pre[i]] -= minn;
//					i = pre[i];
//				}
//				fl += minn;
//			}
//		}else{
//			int m = relabel(i);
//			num[m]++;
//			num[h[i]]--;
//			if(num[h[i]] == 0) return fl;
//			h[i] = m;
//			if(i != s) i = pre[i];
//		}
//	}
//	return fl;
//}


bool vis[MN];
bool bfs(){
	memset(vis,0,sizeof(vis));
	vis[s] = true;
	while(!que.empty()) que.pop();
	que.push(s);
	while(!que.empty()){
		int u = que.front(); que.pop();
		//for(int v = 1; v <= n + n; v++){
		for(Edge *edg = head[u]; edg != NULL; edg = edg->next){
			int v = edg->v;
			if(!vis[v] && cap[u][v] > f[u][v]){
				vis[v] = true;
				pre[v] = u;
				que.push(v);
				if(v == t){
					return true;
				}
			}
		}
	}
	return false;
}
int slove(){
	int sum = 0;
	memset(f,0,sizeof(f));
	while(bfs()){
		int p = t,minn = INT_MAX;
		while(p != s){
			if(cap[pre[p]][p] - f[pre[p]][p] < minn){
				minn = cap[pre[p]][p] - f[pre[p]][p];
			}
			p = pre[p];
		}
		p = t;
		while(p != s){
			f[pre[p]][p] += minn;
			f[p][pre[p]] -= minn;
			p = pre[p];
		}
		sum += minn;
	}
	return sum;
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j,x;
	while(~scanf("%d%d%d",&n,&s,&t)){
		memset(cap,0,sizeof(cap));
		memset(head,NULL,sizeof(head)); 
		pn = 0;
		for(i = 1; i <= n; i++){
			if(i != s && i != t){
				cap[i][i + n] = 1;
  				adde(i,i + n);
				adde(i + n,i);
			}
		}
		for(i = 1; i<= n; i++){
			for(j = 1; j <= n; j++){
				scanf("%d",&x);
				if(x == 1 && i != j){
					if(i == s || i == t){
						cap[i][j] = 1;
						adde(i,j);
						adde(j,i);
					}else{
						cap[i + n][j] = 1;
						adde(i + n,j);
						adde(j,i + n);
					}
				}
			}
		}

		if(cap[s][t]){
			puts("NO ANSWER!");
			continue;
		}
		int cnt = 0;
//		int max_flow = flow();
		int max_flow = slove();
		for(i = 1; i <= n; i++){
			if(i == s || i == t){
				continue;
			}
			cap[i][i + n] = 0;
//			int tmp = flow();
			int tmp = slove();
			if(tmp < max_flow){
				cnt++;
				ans[cnt] = i;
				max_flow--;
			}else{
				cap[i][i + n] = 1;
			}
			if(max_flow <= 0) break;
		}
		printf("%d\n",cnt);
		for(i = 1; i <= cnt; i++){			
			if(i == cnt){
				printf("%d\n",ans[cnt]);
			}else{
				printf("%d ",ans[i]);
			}
		}
	}
	return 0;
}

