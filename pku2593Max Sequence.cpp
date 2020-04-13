#include<iostream>
using namespace std;

int l[100500];
int r[100500];
int a[100500];
int main(){	
	int i,n;	
	while(scanf("%d",&n),n){		
		for(i = 1; i <= n; i++) scanf("%d",&a[i]);	
		int tmp = l[1] = a[1];	
		for(i = 2; i <= n; i++) {
			if(tmp > 0) tmp = tmp + a[i];
			else tmp = a[i];
			l[i] = max(l[i - 1],tmp);
		}

		tmp = r[n] = a[n];
		for(i = n - 1; i > 0; i--){
			if(tmp > 0) tmp = tmp + a[i];
			else tmp = a[i];
			r[i] = max(r[i + 1],tmp);
		}
		
		int max = INT_MIN;
		for(i = 1; i < n; i++){
			if(max < l[i] + r[i+ 1]) max = l[i] + r[i + 1];
		}
		printf("%d\n",max);
		
	}
	return 0;
}