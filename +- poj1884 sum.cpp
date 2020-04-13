// 1+2+3+4+5+6+7+8+9+10....因为在A中少加一数X(只能有+,-不加必减)相当于A-2X=B;
//要让X存在.A-B必为偶数.只要有一数A能减去给出的数B的结果C为偶数的话就一定可了.
#include<iostream>
using namespace std;
int main(){
 	int n,i,sum;
 	cin>>n;
 	sum=0;
 	for(i=1;sum<n||((sum-n)%2==1);i++)//小于||相差为奇数
 		sum+=i;
 	cout<<i-1<<endl;
	return 0;
}
