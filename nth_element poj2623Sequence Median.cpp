#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 250024;
unsigned int a[MN];
int main(){
	//freopen("in.txt","r",stdin);
	int n,i;
	double dat;
	while(scanf("%d",&n) != EOF){
		for(i = 0; i < n; i++) scanf("%d",&a[i]);
		if(n & 1){
			nth_element(a,a + (n - 1)/ 2, a + n);
			dat = a[(n - 1) /2];
			printf("%.1f",dat);
		}else{			
			nth_element(a,a + (n - 1)/ 2, a + n);
			dat = a[(n - 1) /2];
			nth_element(a,a + (n + 1)/ 2, a + n);
			dat += a[(n + 1) / 2];
			printf("%.1f",dat / 2.0);
		}
	}
	return 0;
}