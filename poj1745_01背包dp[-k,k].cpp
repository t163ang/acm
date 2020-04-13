#include<iostream>
using namespace std;
int n,k,num[10012];
bool now[210],pre[210];
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&n,&k)){
		for(int i = 0; i < n; i++){
			scanf("%d",num + i);
		}
		memset(pre,0,sizeof(pre));
		now[k] = true;
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < (k << 1); j++){
				if(now[j]){
					pre[(j + num[i]) % k + k] = true;
					pre[(j - num[i]) % k + k] = true;
				}
			}
			for(int j = 0; j < (k << 1); j++){
				now[j] = pre[j];
				pre[j] = false;
			}
		}
		if(now[k]) puts("Divisible");
		else puts("Not divisible");
	}
	return 0;
}