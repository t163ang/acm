#include<iostream>
using namespace std;
const int maxn=505;
const double eps=1e-9;
//����
//����һ�����ӳ�ʼֵΪ0��d1��a,d2��b,d3��c,��ô�趨ֵΪ0�������������������
//�������<n,��ô����ִ�У�������Ϸ����
//dp[i]������ʾ��ǰ�ܺ�Ϊiʱ������Ϸ�������������� p[i]��ʾͶ������Ϊiʱ�ĸ���
//��i>=nʱdp[i]=0,dp[i]=sum(dp[i+k]*p[k])+p[a+b+c]*dp[0]+1;(3<=k<=m,m=(k1+k2+k3))
//���ǰ�dp[i]��д��x[i]*dp[0]+y[i]���� 
//��dp[i] = sum(x[i+ k] * dp[0] + y[i+k]) * p[k] + pp * dp[0] + 1;
//=> dp[i] = sum(x[i + k] * dp[0] + pp) * p[0] + y[i + k] * p[k] + 1 
//=> x[i] = sum(x[i + k] * dp[0] + pp) , y[i] = y[i + k] * p[k] + 1 
int n,k1,k2,k3,a,b,c,m;
double p[100],pp;
typedef struct node
{
    double x,y;//x*dp[0]+y;
    node(){};
    node(double xx,double yy){x=xx;y=yy;}    
    }node;
node dp[maxn],w;
int main()
{
    int test,i,j,k,t;
    double x,y,fen;
    scanf("%d",&test);
    while(test--)
    {
          scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
          m=k1+k2+k3;
          for(i=0;i<=m;i++)p[i]=0;
          for(i=1;i<=k1;i++)for(j=1;j<=k2;j++)for(k=1;k<=k3;k++) p[i+j+k]+=1.0/(k1*k2*k3);
          pp=1.0/(k1*k2*k3);p[a+b+c]-=1.0/(k1*k2*k3);
          
          dp[n+1]=node(0.0,0.0); 
          for(i=n;i>=0;i--)
          {
              x=pp;y=1.0;               
              for(k=3;k<=m;k++)
              {
                  j=min(n+1,i+k);
                  x+=p[k]*dp[j].x;
				  y+=p[k]*dp[j].y;                                       
			  }
              dp[i]=node(x,y);                   
		  }
          printf("%.15lf\n",dp[0].y/(1.0-dp[0].x));    
	}
    return 0;
}
 