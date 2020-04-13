/*���⣬�����յ�����ɡ�������������n*n�ľ���Ȼ�����ÿһ�з�һ�����������۸�Ϊri��Ҳ����ÿһ�з�һ������������Ϊci��Ҫ������С���۾Ϳ��԰�����ɡ��ȫ�������������ǿ��԰�һ�ж����˻���һ�ж�����,���Ĵ����������������۵Ļ������ǿ�����log�ѳ˷�ת��Ϊ�ӷ���Ȼ����exp�ѽ���ٴ�ת��������Ϊ��log a+log b = log a*b��exp����ȥlog�Ĳ���  

����С��Ӧ�á��еķ���������һ��s��t��·����һ������s-u-v-t����ʽ����������ǲ�����һ����s��t��·������·����
������<s,u>,<u,v>,<v,t> ��������һ�����ڸ��С�����Ϊ����<u,v>����������С���У�����������Ϊ�����ޣ��������Ϊ
<s,u>,<v,t>��������һ��������С���У���������㸲�Ǽ���������(u����Vec��v����Vec��VecΪ�㸲�Ǽ�)����ʽ��ͬ����Ŀ
������С����Ȩ֮�ͣ�ǡ��Ҳ����С���Ż�Ŀ�ꡣ*/

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
const int MN = 110;
const double INF = 1e10;;
const double eps = 1e-8;
int m,n,l;
int h[MN],S,T;
double G[MN][MN],e[MN];
bool inque[MN];
int que[MN << 10],head,tail;
int inline dblcmp( double x){ 
	if(fabs(x) < eps) return 0;
	else return x > eps ? 1 : -1;
}
void inline push(int u, int v){
	double dt = min(e[u],G[u][v]);
	G[u][v] -= dt;
	G[v][u] += dt;
	e[u] -= dt;
	e[v] += dt;
	if(v != T && v != S && !inque[v]) {
		//que.push(Node(v));
		que[tail++] = v;
		inque[v] = true;
	}
}
void discharge(int u){
	while(dblcmp(e[u]) > 0){ //e[u] �� double ��סҪ��dblcmp
		int mm = INT_MAX;
		for(int i = S; i <= T && dblcmp(e[u]) > 0; i++){
			if(G[u][i]){
				if(h[u] == h[i] + 1) push(u,i);
				else if(mm > h[i]) mm = h[i];
			}
		}
		if(dblcmp(e[u]) > 0) h[u] = mm + 1;
	}
}

void maxflow(){
	memset(e,0,sizeof(e));
	memset(h,0,sizeof(h));
	memset(inque,0,sizeof(inque));
	//while(!que.empty()) que.pop();
	e[S] = INF; h[S] = T + 1;
	for(int i = S; i <= T; i++){
		if(G[S][i]) push(S,i);
	}
	//while(!que.empty()){
	while(head != tail){
		int u = que[head++];inque[u] = false;
		discharge(u);
	}
	printf("%.4f\n",exp(e[T]));
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&m,&n,&l);
		S = 0, T = m + n + 1;
		memset(G,0,sizeof(G));
		double x;
		for(i = 1; i <= m; i++){
			scanf("%lf",&x);
			G[S][i] = log(x);
		}
		for(i = m + 1; i <= m + n; i++){
			scanf("%lf",&x);
			G[i][T] = log(x);
		}
		int u,v;
		for(i = 0; i < l; i++){
			scanf("%d%d",&u,&v);
			G[u][v + m] = INF;
		}
		maxflow();
	}
	return 0;
}