#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int MAXN = 25005;

struct Edge
{
    int u,v,w;
    bool operator<(const Edge &E)const
    {
        return w<E.w;
    }
}edges[MAXN];

int fa[510],N;
int find(int a)
{
    if(a==fa[a])return a;
    return fa[a]=find(fa[a]);
}
void un(int a,int b)
{
    int x=find(a),y=find(b);
    if(x==y)return;
    fa[x]=y;
    N--;
}

int main()
{

    //freopen("in","r",stdin);
    int T,M,K;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(int i=1;i<=N;i++)fa[i]=i;
        for(int i=0;i<M;i++)
            scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
        sort(edges,edges+M);
        for(int i=1;i<=K;i++)
        {
            int k,u,v;
            scanf("%d%d%d",&k,&u,&v);
            un(u,v);
            k-=2;
            while(k--)
            {
                scanf("%d",&v);
                un(u,v);
            }
        }
        int ans = 0;
        for(int i=0;N>1&&i<M;i++)
        {
            int u=edges[i].u,v=edges[i].v,w=edges[i].w;
            if(find(u)==find(v))continue;
            ans+=w;
            un(u,v);
        }
        if(N==1)printf("%d\n",ans);
        else puts("-1");
    }
    return 0;
}
/*
Problem F 

Problem Description
In 2100, since the sea level rise, most of the cities disappear. Though some survived cities are still connected with others, but most of them become disconnected. The government wants to build some roads to connect all of these cities again, but they don¡¯t want to take too much money.   Input
The first line contains the number of test cases.
Each test case starts with three integers: n, m and k. n (3 <= n <=500) stands for the number of survived cities, m (0 <= m <= 25000) stands for the number of roads you can choose to connect the cities and k (0 <= k <= 100) stands for the number of still connected cities.
To make it easy, the cities are signed from 1 to n.
Then follow m lines, each contains three integers p, q and c (0 <= c <= 1000), means it takes c to connect p and q.
Then follow k lines, each line starts with an integer t (2 <= t <= n) stands for the number of this connected cities. Then t integers follow stands for the id of these cities.
Output
For each case, output the least money you need to take, if it¡¯s impossible, just output -1. Sample Input
1
6 4 3
1 4 2
2 6 1
2 3 5
3 4 33
2 1 2
2 1 3
3 4 5 6
Sample Output
1

*/