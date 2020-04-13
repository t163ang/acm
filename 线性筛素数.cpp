#include<cstdio>
#include<cstring>

const int MAXN = 1000005;

int pr[MAXN],pn;
bool isp[MAXN];

void init()
{
    for(int i=2;i<MAXN;i++)    
    {    
        if(!isp[i])pr[pn++]=i;
        for(int j=0;j<pn&&i*pr[j]<MAXN;j++)
        {
            isp[i*pr[j]]=1;
            if(i%pr[j]==0)break;
        }
    }
}
//i * pr[j + 1] = （k * pr[j]）* pr[j + 1] = pr[j] * (k * pr[j + 1])
//令
//i = k * pr[j]
//x = k * pr[j + 1]
//因为
//pr[j] < pr[j + 1]
//所以  
//i < x
//所以 
//i * pr[j + 1] 会被比i大的x * pr[j]筛去掉。
//
//每个合数仅被它的最小素因子筛去正好一次。所以为线性时间。
//代码中体现在：
//if(i%pr[j]==0)break;
//pr数组中的素数是递增的,当i能整除pr[j]，那么i*pr[j+1]这个合数肯定被pr[j]乘以某个数筛掉。
//因为i中含有pr[j],pr[j]比pr[j+1]小。接下去的素数同理。所以不用筛下去了。
//在满足i%pr[j]==0这个条件之前以及第一次满足改条件时,pr[j]必定是pr[j]*i的最小因子。
int lowerbound(int x)
{
    int left = -1,right = pn;
    while(right-left>1)
    {
        int mid = (left+right)/2;
        if(pr[mid]>x)right=mid;
        else left = mid;
    }    
    return left;
}
int main()
{

    init();
    int N;
    while(~scanf("%d",&N))
    {
        if(N==1)puts("0");
        else
        {
            int i;
            for(i=0;pr[i]*pr[i]<=N;i++)
            {
                if(N%pr[i])continue;
                while(N%pr[i]==0)N/=pr[i];
            }
        //    printf("%d %d\n",i,N);
            if(N>1)//
            {
                i = lowerbound(N)+1;
            }
            printf("%d\n",i);
        }
    }
    return 0;
}