#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int i,n,end;
	while(true){
		scanf("%d",&n);
		end = sqrt((double)n);
		printf("%d=",n);
		for(i = 2; i <= end; i++){
			while(n % i == 0){
				printf("%d*",i);
				n /= i;
			}
		}
		printf("%d\n",n);
	}
}