// 1+2+3+4+5+6+7+8+9+10....��Ϊ��A���ټ�һ��X(ֻ����+,-���ӱؼ�)�൱��A-2X=B;
//Ҫ��X����.A-B��Ϊż��.ֻҪ��һ��A�ܼ�ȥ��������B�Ľ��CΪż���Ļ���һ������.
#include<iostream>
using namespace std;
int main(){
 	int n,i,sum;
 	cin>>n;
 	sum=0;
 	for(i=1;sum<n||((sum-n)%2==1);i++)//С��||���Ϊ����
 		sum+=i;
 	cout<<i-1<<endl;
	return 0;
}
