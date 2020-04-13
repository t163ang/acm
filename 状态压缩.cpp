/*
在n*n(n≤20)的方格棋盘上放置n个车(可以攻击所在行、列)，求使它们不能互相攻击的方案总数。
*/

/*
Sol :SCR
Time:O(n*2^n)
Spc :O(2^n)
*/

#include<cstdio>
const int maxs=1<<20;
int n,ms;
long long f[maxs]={1};

int main()
{
	scanf("%d",&n);
	ms=1<<n; // 因为有 2 ^ n : 0000 ~ 1111 状态
	for(int i=1;i<ms;i++)
		for(int t=i;t;t-=t&-t)//这个好！！
			f[i]+=f[i^(t&-t)];
	printf("%I64d\n",f[ms-1]);
	return 0;
}
