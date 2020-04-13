#include<iostream>
#include<cmath>
using namespace std;
//RMQ:�����У����Ǿ�����Ҫ֪��ĳ���������ֵ�Ƕ��٣������������RMQ�����ˡ�
const int MN = 65538;
int N,Q,n;
int RMQ_max[MN][16];
int RMQ_min[MN][16];
void Init(){
	int i,j,k;
	for(i = 1; i <= n; i++) {
		scanf("%d",&j);
		RMQ_min[i][0] = RMQ_max[i][0] = j;
	}
	N = 1; while(N < n) N <<= 1;
	for(k = 1; (1 << k) <= N; k++){
		for(i = 1; i + (1 << k) - 1 <= N; i++){
			RMQ_max[i][k] = max(RMQ_max[i][k - 1],RMQ_max[i + (1 << (k - 1))][k - 1]);
			RMQ_min[i][k] = min(RMQ_min[i][k - 1],RMQ_min[i + (1 << (k - 1))][k - 1]);
		}
	}	
}

void inline Query(int a, int b){
	int k = log(b - a + 1.0) / log(2.0);//����Ǳ�֤����2^k�����䣬��ΪRMQ[][]��ŵ���2^k�����С
	printf("%d\n",max(RMQ_max[a][k],RMQ_max[b - (1 << k) + 1][k]) - min(RMQ_min[a][k],RMQ_min[b - (1 << k) + 1][k]));
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&n,&Q)){
		Init(); 
		int a,b;
		while(Q--){
			scanf("%d%d",&a,&b);
			if(a > b) swap(a,b);
			Query(a,b);
		}
	}
	return 0;
}