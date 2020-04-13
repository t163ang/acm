#include<iostream>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	int n,k;
	while(scanf("%d%d",&k,&n),k != -1){
		int s = 0,j;
		for(j = 2; j < k; j++){
			s += j - 1;
			if(s > n) break;
		}
		if(s > n) s -= j - 1;
		int w = n - s + 1;
		for(int i = 1; i <= k - j; i++){
			printf("%d ",i);
		}
		int q = k - j + w;
		printf("%d ",q);
		for(int i = k; i >= k - j + 1; i--){
			if(i != q) printf("%d ",i);
		}
		puts("");
	}
	return 0;
}