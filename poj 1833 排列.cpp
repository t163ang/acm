#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 1024;
int n,k;
int get[MN];
int main(){
	//freopen("in.txt","r",stdin);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i = 0; i < n; i++){
			scanf("%d",&get[i]);
		}
		while(k > 0){
			if(!next_permutation(get,get + n)){
				for(int i = 0; i < n; i++){
					get[i] = i + 1;
				}
			}
			k--;
		}
		for(int i = 0; i < n; i++){
			printf("%d ",get[i]);
		}
		puts("");
	}
	return 0;
}