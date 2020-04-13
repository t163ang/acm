#include<iostream>
#include<algorithm>
using namespace std;
int a,b,n,i;
int main(){
	while(scanf("%d%d%d",&a,&b,&n),a){
		int f[300] = {0,1,1};
		printf("\n f[i] : 1\t1\t");
		bool flag;
		for(flag = true, i = 3;flag; i++){
			f[i] = (b * f[i - 2] + a * f[i - 1] ) % 7;
			printf("%d\t",f[i]);
			for(int j = 1; j <= i - 2; j++){
				if(f[j] == f[i - 1] && f[j + 1] == f[i]) {
					flag = false;
					break;			
				}
			}
		}
		cout<<endl;
		i = i - 3;
		f[0] = f[i];
		cout<<f[n % i]<<endl;
	}
	return 0;
}