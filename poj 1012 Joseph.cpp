#include<iostream>
#include<cstdio>
using namespace std;
const int MN = 20;
int k;
int ans[MN];
inline void init(){
	for(int k = 1; k <= 13; k++){
		int m = k + 1;
		while(true){
			int i = 0,n = k << 1,num = 0;
			while(num < k){	
				i = (i + m - 1) % n;
				if(i < k) break;
				num++;
				n--;	
			}
			if(num < k) {
				m++;
			}else {
				ans[k] = m;
				break;
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	init();
	while(scanf("%d",&k),k){
		printf("%d\n",ans[k]);
	
	}
	return 0;
}