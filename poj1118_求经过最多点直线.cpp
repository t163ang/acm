#include<iostream>
using namespace std;

const int MN = 1024;
int x[MN],y[MN];

int main(){
	//freopen("in.txt","r",stdin);
	int count,ans;
	int n,i,j,k;
	while(scanf("%d",&n),n){
		ans = 0;
		for(i = 0; i < n; i++){
			scanf("%d%d",x + i, y + i);
		}
		for(i = 0; i < n; i++){
			for(j = i + 1; j < n; j++){
				count = 2;
				for(k = j + 1; k < n; k++){
					if((y[i] - y[j]) * (x[k] - x[j]) == (y[k] - y[j]) * (x[i] - x[j])){
						count++;
					}
				}
				if(count > ans){
					ans = count;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}