#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n,m;
	int i,j,t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		if(n == 0 || m == 0) {
			printf("1\n");
			continue;
		}
		i = m - n;
		if(i < n) n = i;
		long long fenji = 1;
		for(i = 1; i <= n; i++) {
			fenji *= m;
			m--;
		}
		long long fenmu = 1;
		while(n > 1){
			fenmu *= n;
			n--;
		}
		printf("%lld\n",fenji / fenmu);
	}
	return 0;
}