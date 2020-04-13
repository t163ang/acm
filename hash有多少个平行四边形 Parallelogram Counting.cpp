// c++ 4782MS
#include<iostream>
#include<cstdio>
using namespace std;
const int MN = 1002 * 1002;
struct {
	int x,y,t;
}hash[MN];
int n,x[1004],y[1004],ans = 0;
void insert(int x, int y){
	int s = ((x + y) * (x + y)) % MN; 
	while(s < 0) s+= MN;//(x + y) * (x + y)可能因为溢出而出现负数！！
	//printf("s: %d    ",s);
	while(hash[s].t){
		if(hash[s].x == x && hash[s].y == y){
			ans += hash[s].t;
			hash[s].t++;
			return;
		}
		s = (s + 1) % MN;
	}
	hash[s].x = x;
	hash[s].y = y;
	hash[s].t++;
	//printf("ep : %d \n",ep);
}

int main(){
	//freopen("in.txt","r",stdin);
	int t,i,j;scanf("%d",&t);
	while(t--){
		memset(hash,0,sizeof(hash));
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		ans = 0;
		for(i = 0; i < n - 1; i++){
			for(j = i + 1; j < n; j++){
				insert(x[i] + x[j],y[i] + y[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
	
}

//c++ 750ms
#include<iostream>
using namespace std;
//平行四边形对角线互相平分
//int 数组最大能开计算一下 65536 * 1024 / 4 = 16777216(1千6百万左右)
const int MN = 7754131; //hash容量
int hash[MN],ep = 1;
int ans = 0;
struct {
	int x,y,t,next;
}edge[1000004];
int n,x[1024],y[1024];
void insert(int x, int y){
	int s = (x * x + y * y) % MN;
	while(s < 0) s += MN;
	for(int i = hash[s]; i; i = edge[i].next){		
		if( x == edge[i].x && y == edge[i].y){
			ans += edge[i].t;
			edge[i].t++;
			return;
		}
	}
	edge[ep].x = x; edge[ep].y = y;
	edge[ep].t = 1;
	edge[ep].next = hash[s];
	hash[s] = ep++;
}

int main(){
	//freopen("in.txt","r",stdin);
	int t;scanf("%d",&t);
	int i,j;
	while(t--){
		memset(hash,0,sizeof(hash)); ep = 1;
		ans = 0;
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(i = 0; i < n - 1; i++){
			for(j = i + 1; j < n; j++){
				insert(x[i] + x[j],y[i] + y[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
	
}