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
//i * pr[j + 1] = ��k * pr[j]��* pr[j + 1] = pr[j] * (k * pr[j + 1])
//��
//i = k * pr[j]
//x = k * pr[j + 1]
//��Ϊ
//pr[j] < pr[j + 1]
//����  
//i < x
//���� 
//i * pr[j + 1] �ᱻ��i���x * pr[j]ɸȥ����
//
//ÿ����������������С������ɸȥ����һ�Ρ�����Ϊ����ʱ�䡣
//�����������ڣ�
//if(i%pr[j]==0)break;
//pr�����е������ǵ�����,��i������pr[j]����ôi*pr[j+1]��������϶���pr[j]����ĳ����ɸ����
//��Ϊi�к���pr[j],pr[j]��pr[j+1]С������ȥ������ͬ�����Բ���ɸ��ȥ�ˡ�
//������i%pr[j]==0�������֮ǰ�Լ���һ�����������ʱ,pr[j]�ض���pr[j]*i����С���ӡ�
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