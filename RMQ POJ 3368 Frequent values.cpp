#include<iostream>
#include<cmath>
using namespace std;
const int MN = 100002;
int n,q;
int F[MN];//F[i] 代表相同的左边的节点数（包括自己），例如，(-1 -1 1 1 1 1 3 10 10 10) ==>(1 2 1 2 3 4 1 1 2 3)。
int index[MN];//index[i]代表开始连续下标,仍然如上例(1 1 3 3 3 3 7 8 8 8)
int RMQ[MN][18];
void init(){
	int i,k;
	for(i = 1; i <= n; i++) RMQ[i][0] = F[i];
	for(k = 1; (1 << k) <= n; k++){
		for(i = 1; i + (1 << k) - 1 <= n; i++){
			RMQ[i][k] = max(RMQ[i][k -  1], RMQ[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int Query(int a, int b){
	int k = log(b - a + 1.0) / log(2.0);
	return max(RMQ[a][k],RMQ[b - (1 << k) + 1][k]);
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,x,cur,a,b;
	while(scanf("%d",&n),n){
		scanf("%d",&q);
		F[1] = index[1] = 1;
		scanf("%d",&cur);
		for(i = 2; i <= n; i++){
			scanf("%d",&x);
			if(x == cur) {index[i] = index[i - 1]; F[i] = F[i - 1] + 1;}
			else {cur = x; index[i] = i; F[i] = 1;} 
		}
		init();

		for(i = 1; i <= q; i++){
			scanf("%d%d",&a,&b);
			if(index[a] == index[b]) {
				printf("%d\n", b - a + 1);
				continue;
			}
			int left = 1, right = n,mid;
			while(left <= right){
				mid = (left + right) >> 1;
				if(index[mid] <= a) left = mid + 1;
				else right = mid - 1;
			}
			int ans = 0;			
			if(index[left] == index[b]) ans = b - left + 1;
			else ans = Query(left,b);
			if(right > 0) ans = max(ans,F[right] - (a - index[right]));
			printf("%d\n",ans);
		}
	}
	return 0;
}