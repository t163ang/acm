/*
	题意：给出一个地图，起点为Y，走到R花费为3，走到T为2，走到.为1，走到E旁边就没有了，不能停在P
		   问一开始给出钱C，能走到的所有地方
	一开始我用BFS，我把钱也当做状态，表示成(x,y,C)，几经优化才不TLE
	主要优化在C，因为从起点都最远的点花费为：(max(N-1-sx,sx)+max(M-1-sy,sy))*3
	所以一开始时超过时就修改成这样，然后手写队列就能在600ms左右AC

	发现题意是求能够走到的所有地方，所以钱多走到同一个地方当然比钱少走到同一个地方更好，因为前者
	还能继续走更多的路，上面的BFS就把钱多、钱少都考虑了！
	现在就用visit[x,y]记录到达x,y的最大值即可，用SPFA更新！
	这样一来，状态只用2维表示了！也很快15ms
*/
#include<cstdio>
#include<cstring>

const int MAXN = 10000;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char map[101][101];
bool in[101][101];
int visit[101][101];
int N,M,C,sx,sy;
int Q[MAXN][2];

bool bound(int x,int y)
{
    return x>=0&&x<N&&y>=0&&y<M;
}
void BFS()
{
    memset(in,0,sizeof(in));
    memset(visit,-1,sizeof(visit));
    int front=0,tail=1;
    visit[sx][sy]=C;
    for(Q[0][0]=sx,Q[0][1]=sy;front!=tail;front=(front+1)%MAXN)
    {
        int x = Q[front][0],y=Q[front][1],c=visit[x][y];
		in[x][y]=0;
        for(int k=0;k<4;k++)
        {
            int nx = x+dir[k][0],ny=y+dir[k][1];
            if(!bound(nx,ny)||map[nx][ny]=='E'||map[nx][ny]=='#')continue;
            char ch = map[nx][ny];
            int nc = c-1;
            if(ch=='T')nc-=1;
            if(ch=='R')nc-=2;
            if(nc<=visit[nx][ny]) continue;
            visit[nx][ny]=nc;
            bool chk = false;
            for(int kk=0;kk<4;kk++)
            {
                int xx = nx+dir[kk][0],yy=ny+dir[kk][1];
                if(bound(xx,yy)&&map[xx][yy]=='E'){chk=true;break;}
            }
            if(chk||in[nx][ny])continue;
			in[nx][ny]=1;
            Q[tail][0]=nx,Q[tail][1]=ny;
			tail=(tail+1)%MAXN;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for(int i=0;i<N;i++){
            getchar();
            for(int j=0;j<M;j++){
                map[i][j]=getchar();
                if(map[i][j]=='Y')sx=i,sy=j;
            }        
        }
        BFS();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                if(map[i][j]=='P'||map[i][j]=='Y')putchar(map[i][j]);
                else 	putchar(visit[i][j]>=0?'*':map[i][j]);
            puts("");
        }
        puts("");
    }
    return 0;
}


/*
	题意：给出一个地图，起点为Y，走到R花费为3，走到T为2，走到.为1，走到E旁边就没有了，不能停在P
		   问一开始给出钱C，能走到的所有地方
	一开始我用BFS，我把钱也当做状态，表示成(x,y,C)，几经优化才不TLE
	主要优化在C，因为从起点都最远的点花费为：(max(N-1-sx,sx)+max(M-1-sy,sy))*3
	所以一开始时超过时就修改成这样，然后手写队列就能在600ms左右AC

	发现题意是求能够走到的所有地方，所以钱多走到同一个地方当然比钱少走到同一个地方更好，因为前者
	还能继续走更多的路，上面的BFS就把钱多、钱少都考虑了！
	现在就用visit[x,y]记录到达x,y的最大值即可，用SPFA更新！
	这样一来，状态只用2维表示了！也很快15ms
*/
#include<cstdio>
#include<cstring>

const int MAXN = 10000;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char map[101][101];
bool in[101][101];
int visit[101][101];
int N,M,C,sx,sy;
int Q[MAXN][2];

bool bound(int x,int y)
{
    return x>=0&&x<N&&y>=0&&y<M;
}
void BFS()
{
    memset(in,0,sizeof(in));
    memset(visit,-1,sizeof(visit));
    int front=0,tail=1;
    visit[sx][sy]=C;
    for(Q[0][0]=sx,Q[0][1]=sy;front!=tail;front=(front+1)%MAXN)
    {
        int x = Q[front][0],y=Q[front][1],c=visit[x][y];
		in[x][y]=0;
        for(int k=0;k<4;k++)
        {
            int nx = x+dir[k][0],ny=y+dir[k][1];
            if(!bound(nx,ny)||map[nx][ny]=='E'||map[nx][ny]=='#')continue;
            char ch = map[nx][ny];
            int nc = c-1;
            if(ch=='T')nc-=1;
            if(ch=='R')nc-=2;
            if(nc<=visit[nx][ny])continue;
            visit[nx][ny]=nc;
            bool chk = false;
            for(int kk=0;kk<4;kk++)
            {
                int xx = nx+dir[kk][0],yy=ny+dir[kk][1];
                if(bound(xx,yy)&&map[xx][yy]=='E'){chk=true;break;}
            }
            if(chk||in[nx][ny])continue;
			  in[nx][ny]=1;
            Q[tail][0]=nx,Q[tail][1]=ny;
            tail=(tail+1)%MAXN;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for(int i=0;i<N;i++){
            getchar();
            for(int j=0;j<M;j++){
                map[i][j]=getchar();
                if(map[i][j]=='Y')sx=i,sy=j;
            }        
        }
        BFS();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                if(map[i][j]=='P'||map[i][j]=='Y')putchar(map[i][j]);
                else 	putchar(visit[i][j]>=0?'*':map[i][j]);
            puts("");
        }
        puts("");
    }
    return 0;
}

/*
    题意：给出一个地图，起点为Y，走到R花费为3，走到T为2，走到.为1，走到E旁边就没有了，不能停在P
           问一开始给出钱C，能走到的所有地方
    一开始我用BFS，我把钱也当做状态，表示成(x,y,C)，几经优化才不TLE
    主要优化在C，因为从起点都最远的点花费为：(max(N-1-sx,sx)+max(M-1-sy,sy))*3
    所以一开始时超过时就修改成这样，然后手写队列就能在600ms左右AC

    发现题意是求能够走到的所有地方，所以钱多走到同一个地方当然比钱少走到同一个地方更好，因为前者
    还能继续走更多的路，上面的BFS就把钱多、钱少都考虑了！
    现在就用visit[x,y]记录到达x,y的最大值即可，用SPFA更新！
    这样一来，状态只用2维表示了！也很快15ms
*/
/*
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 10000;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char map[101][101];
bool in[101][101];
int visit[101][101];
int N,M,C,sx,sy;

bool bound(int x,int y)
{
    return x>=0&&x<N&&y>=0&&y<M;
}
void BFS()
{
    memset(in,0,sizeof(in));
    memset(visit,-1,sizeof(visit));
    queue<int>Q;
    visit[sx][sy]=C;
    for(Q.push(sx*M+sy);!Q.empty();Q.pop())
    {
        int x = Q.front()/M,y=Q.front()%M,c=visit[x][y];
        in[x][y]=0;
        for(int k=0;k<4;k++)
        {
            int nx = x+dir[k][0],ny=y+dir[k][1];
            if(!bound(nx,ny)||map[nx][ny]=='E'||map[nx][ny]=='#')continue;
            char ch = map[nx][ny];
            int nc = c-1;
            if(ch=='T')nc-=1;
            if(ch=='R')nc-=2;
            if(nc<=visit[nx][ny])continue;
            visit[nx][ny]=nc;
            bool chk = false;
            for(int kk=0;kk<4;kk++)
            {
                int xx = nx+dir[kk][0],yy=ny+dir[kk][1];
                if(bound(xx,yy)&&map[xx][yy]=='E'){chk=true;break;}
            }
            if(chk||in[nx][ny])continue;
            in[nx][ny]=1;
            Q.push(nx*M+ny);
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for(int i=0;i<N;i++){
            getchar();
            for(int j=0;j<M;j++){
                map[i][j]=getchar();
                if(map[i][j]=='Y')sx=i,sy=j;
            }        
        }
        BFS();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                if(map[i][j]=='P'||map[i][j]=='Y')putchar(map[i][j]);
                else     putchar(visit[i][j]>=0?'*':map[i][j]);
            puts("");
        }
        puts("");
    }
    return 0;
}
*/