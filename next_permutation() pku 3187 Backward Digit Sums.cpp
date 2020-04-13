#include<iostream>
#include<algorithm>
using namespace std;

int n,sum;
int cnk(int n, int k){
	k = n - k < k ? n - k : k;
	if(k == 0) return 1;
	int ank = 1,i;
	for(i = 0; i < k; i++){
		ank *= n;
		n -= 1;
	}
	int kk = 1;
	while(k != 1) kk *= k--;
	return ank / kk;
}
const int N = 20;
int a[N];
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d%d",&n,&sum) != EOF){
		for(i = 1; i <= n; i++) a[i - 1] = i;			
		do{
			int tot = 0;
			for(i = 0; i < n && tot < sum; i++){
				tot += cnk(n - 1, i) * a[i];
			}
			if(i == n && tot == sum) {
				for(i = 0; i < n - 1; i++){
					printf("%d ",a[i]);
				}
				printf("%d\n",a[i]);
				break;
			}		
		}while(next_permutation(a,a + n));
	}
	return 0;
}
