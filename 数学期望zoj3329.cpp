#include<iostream>
using namespace std;
const int maxn=505;
const double eps=1e-9;
//递推
//给定一个骰子初始值为0，d1置a,d2置b,d3置c,那么设定值为0，否则把三个数加起来
//如果还是<n,那么继续执行，否则游戏结束
//dp[i]用来表示当前总和为i时，到游戏结束的期望步数 p[i]表示投掷到和为i时的概率
//当i>=n时dp[i]=0,dp[i]=sum(dp[i+k]*p[k])+p[a+b+c]*dp[0]+1;(3<=k<=m,m=(k1+k2+k3))
//我们把dp[i]都写成x[i]*dp[0]+y[i]即可 
//则dp[i] = sum(x[i+ k] * dp[0] + y[i+k]) * p[k] + pp * dp[0] + 1;
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
 