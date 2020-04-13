/*题意，国家收到敌人伞兵攻击，给你个n*n的矩阵，然后可以每一行放一个炮塔，代价各为ri，也可以每一列放一个炮塔，代价为ci，要你求最小代价就可以把所有伞兵全部打死，炮塔是可以把一行都打了或者一列都打了,最后的代价是所有炮塔代价的积，我们可以用log把乘法转换为加法，然后用exp把结果再次转换回来因为（log a+log b = log a*b）exp就是去log的操作  

《最小割应用》中的分析：任意一条s到t的路径，一定具有s-u-v-t的形式。割的性质是不存在一条从s到t的路径。故路径上
三条边<s,u>,<u,v>,<v,t> 中至少有一条边在割中。若人为的令<u,v>不可能在最小割中，即令其容量为正无限，则简化条件为
<s,u>,<v,t>中至少有一条边在最小割中，这正好与点覆盖集限制条件(u属于Vec或v属于Vec，Vec为点覆盖集)的形式相同。而目
标是最小化点权之和，恰好也是最小割优化目标。*/

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
	while(dblcmp(e[u]) > 0){ //e[u] 是 double 记住要用dblcmp
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