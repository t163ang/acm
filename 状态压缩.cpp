/*
��n*n(n��20)�ķ��������Ϸ���n����(���Թ��������С���)����ʹ���ǲ��ܻ��๥���ķ���������
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
	ms=1<<n; // ��Ϊ�� 2 ^ n : 0000 ~ 1111 ״̬
	for(int i=1;i<ms;i++)
		for(int t=i;t;t-=t&-t)//����ã���
			f[i]+=f[i^(t&-t)];
	printf("%I64d\n",f[ms-1]);
	return 0;
}
