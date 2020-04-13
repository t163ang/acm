#include<iostream>
using namespace std;
const int MN = 160;
int w[MN][MN];
int lx[MN],ly[MN];
int linky[MN];
int visx[MN],visy[MN];
int N;
int slack[MN];
void input(){
	scanf("%d",&N);
	int i,j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N;j++){
			scanf("%d",&w[i][j]);
		}
	}
}

bool find(int x){
	visx[x] = true;
	for(int y = 0; y < N; y++){
		if(visy[y]) continue;
		int t = lx[x] + ly[y] - w[x][y];
		if(t == 0) {
			visy[y] = true;
			if(linky[y] == -1 || find(linky[y])) {
				linky[y] = x;
				return true;
			}
		}else{
			if(slack[y] > t) slack[y] = t;
		}
	}
	return false;
	
}
void KM(){
	int i,j,x;
	memset(linky,-1,sizeof(linky));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			if(lx[i] < w[i][j]) lx[i] = w[i][j];
	for(x = 0; x < N; x++){
		for(i = 0; i < N; i++) slack[i] = INT_MAX;
		while(true){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(find(x)) break;
			int d = INT_MAX;
			for(i = 0;  i < N; i++){
				if(!visy[i]){
					if(d > slack[i]) d = slack[i];
				}
			}

			for(i = 0; i < N; i++){
				if(visy[i]) ly[i] += d;
				else slack[i] -= d;
				if(visx[i]) lx[i] -= d;
			}
		}
	}
}


void output(){
	int res = 0;
	for(int j = 0; j < N; j++){
		for(int i = 0; i < N; i++){
			res += w[i][j];
		}
		res -= w[linky[j]][j];
	}
	printf("%d\n",res);
}
int main(){
//	freopen("in.txt","r",stdin);
	input();
	KM();
	output();
	return 0;
}
//求最小权
//先分别用一个很大的数inf去减每条边的权，转化为最大权匹配问题。然后用KM算法求解。
// w' = inf - w => w越小，w'越大
//最后将求得的最大权用n*inf减去就可以了。
// sum(w') = n * inf - nw =>
//nw = n * inf - sum(w')
//
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int maxn=160,OO=2147483647;
//
//int w[maxn][maxn];
//int lx[maxn],ly[maxn];
//int linky[maxn];
//int visx[maxn],visy[maxn];
//int N;
//int slack[maxn];
//
//void input(){
//	scanf("%d",&N);
//	for(int i=0;i<N;++i)
//		for(int j=0;j<N;++j)
//			scanf("%d",&w[i][j]);
//}
//bool find(int x){
//	visx[x]=true;
//	for(int y=0;y<N;++y){
//		if(visy[y])continue;
//		int t=lx[x]+ly[y]-w[x][y];
//		if(t==0){
//			visy[y]=true;
//			if(linky[y]==-1||find(linky[y])){
//				linky[y]=x;
//				return true;
//			}
//		}
//		else{
//			if(slack[y]>t)
//				slack[y]=t;
//		}
//	}
//	return false;
//}
//void KM(){
//	memset(linky,-1,sizeof(linky));
//	memset(lx,0,sizeof(lx));
//	memset(ly,0,sizeof(ly));
//	for(int i=0;i<N;++i)
//		for(int j=0;j<N;++j)
//			if(w[i][j]>lx[i])
//				lx[i]=w[i][j];
//	for(int x=0;x<N;++x){
//		for(int i=0;i<N;++i)
//			slack[i]=OO;
//		for(;;){
//			memset(visx,0,sizeof(visx));
//			memset(visy,0,sizeof(visy));
//			if(find(x))break;
//			int d=OO;
//			for(int i=0;i<N;++i){
//				if(!visy[i])
//					if(d>slack[i])
//						d=slack[i];
//			}
//			for(int i=0;i<N;++i){
//				if(visx[i])
//					lx[i]-=d;
//			}
//			for(int i=0;i<N;++i){
//				if(visy[i])
//					ly[i]+=d;
//				else
//					slack[i]-=d;
//			}
//		}
//	}
//}
//void output(){
//	int res=0;
//	for(int j=0;j<N;++j){
//		for(int i=0;i<N;++i)
//			res+=w[i][j];
//		res-=w[linky[j]][j];
//	}
//	printf("%d\n",res);
//}
//int main(){
//	input();
//	KM();
//	output();
//	return 0;
//}

