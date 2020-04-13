#include<iostream>
#include<cmath>
using namespace std;

int getSum(int x){
	int sum = 0;
	while(x){
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

bool smith(int x){
	int n = x,cnt = getSum(x),tmp;
	int end = sqrt(double(x)),sum = 0;
	for(int i = 2; i <= end; i++){
		tmp = getSum(i);
		while(n % i == 0){
			sum += tmp;
			n /= i;
		}
	}
	if(n > 1) sum += getSum(n);
	if(n != x && sum == cnt){
		return true;
	}
	return false;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,n;
	while(scanf("%d",&n),n){
		for(i = n + 1; ; i++){
			if(smith(i)) break;
		}
		printf("%d\n",i);
	}
	return 0;
}