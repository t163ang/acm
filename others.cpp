#include <iostream>
#define MAX 152
#define INF 0x3ffffff
using namespace std;

/**//*
dp[s][i]:记录s结点，要得到一棵j个节点的子树去掉的最少边数
考虑其儿子k
  1）如果不去掉k子树，则
    dp[s][i] = min(dp[s][j]+dp[k][i-j])  0 <= j <= i

  2）如果去掉k子树，则
    dp[s][i] =  dp[s][i]+1
总的为
    dp[s][i] = min (min(dp[s][j]+dp[k][i-j]) ,  dp[s][i]+1 )
*/

int dp[MAX][MAX];
int son[MAX], bla[MAX], root, n, p;
//son[i]:记录i结点的儿子，bla[i]:记录i结点的兄弟
bool hf[MAX];
//hf[i]:i结点是否有父亲

void dfs(int s)
{
    int i, j, k, temp;
    for(i = 0; i <= p; i++)
        dp[s][i] = INF;
    dp[s][1] = 0;
    k = son[s];
    while(k){
        dfs(k);
        for(i = p; i >= 0; i--){
            temp = dp[s][i]+1;
            for(j = 0; j <= i; j++){
                if(dp[k][i-j] + dp[s][j] < temp)
                    temp = dp[k][i-j] + dp[s][j];
            }
            dp[s][i] = temp;
        }
        k = bla[k];
    }
}

int slove(int root)
{
    dfs(root);
    int i, ans;
    ans = dp[root][p];
    for(i = 1; i <= n; i++){
        if(dp[i][p] < ans)
            ans = dp[i][p] + 1;
    }
    return ans;
}

int main()
{
    //freopen("data.txt", "r", stdin);
    int i, s, t;
    while(cin >> n >> p){
        memset(son, 0, sizeof(son));
        for(i = 1; i < n; i++){
            cin >> s >> t;
            bla[t] = son[s];
            son[s] = t;
            hf[t] = true;
        }
        for(i = 1; i <= n; i++){
            if(!hf[i])
                root = i;
        }
        cout << slove(root) << endl;
    }
    return 0;
}


#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;
const int maxm = 100010;
const int Ma = 999999999;
const int Mi = 9;
int n, m;

struct Edge{
	int v, cost, next;
}et[maxm];
int eh[maxn], tot;

bool vist[maxn];

void add(int u, int v, int cost) {
	Edge e = {v, cost, eh[u]};
	et[tot] = e;
	eh[u] = tot++;
}

bool bfs(int x) {
	queue<int> que;
	memset(vist, false, sizeof(vist));
	que.push(1);
	vist[1] = true;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = eh[u]; i !=-1; i = et[i].next) {
			int v = et[i].v, cost = et[i].cost;
			if (!vist[v] && cost >= x) {
				if (v == n) return true;
				vist[v] = true;
				que.push(v);
			}
		}
	}
	return false;
}

void solve() {
	int res = 9;
	for (int x = Mi; x <= Ma; x = x * 10 + 9)
		if (bfs(x) == true) res = x;
	printf("%d\n", res);
}

int main() {
	int T;
	scanf("%d", &T);
	int a, b, c;
	while (T--) {
		memset(eh, -1, sizeof(eh));
		tot = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			add(a, b, c), add(b, a, c);
		}
		solve();
	}
	return 0;
}


#include<cstdio>
#include <algorithm>
using namespace std;

#define maxn 1010
int maz[maxn][maxn];
int n, m;
bool vist[maxn];
int dist[maxn];

void dij(int s, int t) {
    for (int i = 1; i <= n; i++)
        dist[i] = maz[s][i], vist[i] = false;
    vist[s] = true, dist[s] = 0;
    for (int j = 1; j <= n; j++) {
        int u = -1;
        for (int i = 1; i <= n; i++) 
            if (!vist[i] && (u == -1 || dist[i] > dist[u])) 
                u = i;
        if (u == -1) break;
        vist[u] = true;
        for (int i = 1; i <= n; i++) 
            if (!vist[i]) dist[i] = max(dist[i], min(dist[u], maz[u][i]));
    }
}

int main() {
    //freopen("in","r",stdin);
    int T;
    int a, b, c;
    int cont = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        memset(maz, 0, sizeof(maz));
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            maz[a][b] = c, maz[b][a] = c;
        }
        dij(1, n);
        printf("%d\n", dist[n]);
    }
    return 0;
}
   当两个管子相连且水位超过连接口时,只需对一个管子加水,两个管子的水位依然是相等的,在这种情况下,两个管子各自的涨水速度是水进入第一个管子的一半,加水的速度非常快,可以忽略不计,且假定目标水位总是比指定的水位略高一点.
    如果一个管子的水位已经到达顶端(记为水位x),只要与其相连的管子在水位x以下是空的,水都不会溢出(注意在水位x处,可能会有连接管是水流动),如果所有的管子在水位x以下(有连接管连接)的空间都有水,水位就不能上升.
    对输入的数据做如下假定:
        1> 从第一个管子开始加水
        2> 没有连接管穿过管子
        3> 没有处于同一个y坐标的连接管
        4> 没有左上角x坐标相同的管子
        5> 每个连接管的两个端点都刚好与管子相连
   模拟水在管子中的流动,求解水在指定管子中流动到目标水位所需的时间
        1> 流速换算,管子的截面积s:s=pi*r*r=0.25*pi,则单位时间水流过的长度为:(v*t)/s=0.25*pi/(0.25*pi)=1cm
        2> 判断目标水位是否在指定管子的里面,如果目标水位不再指定管子的里面,就输出"No Solution"
        3> 每次让水位上升1cm(level--),模拟水在所有相关管子中的流动并统计时间(up),则总的时间time就是up的累加和.
        4> 模拟水在所有相关管子中的流动并统计时间(up),由于并不知道当前水位是哪一个连接管,也不知道连接管的两端连接着什么管子,所以只能进行搜索:
              a> 对所有的连接管,查找处于当前水位的连接管i
              b> 对所有的水管,查找连接管i的两边那个水管j已经充水(不能两个管子都没有水)
              c> 如果已经找到了一个管子j有水,则在所有的管子中找另外一个管子k,找到管子k之后,又分两种情况:
                   1>: 管子k从未充水,保存管子j的状态,重新计算当前水位和新的溢出水位
                   2>: 管子k已经充水,继续充水1cm,每次只能充水1cm,防止漏掉与管子k相连的其他连接管.
#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;

struct pipeShape                                                                                                      //存储管子
{
       int x;                                                                                                         //管子左上角的x,y坐标
       int y;
       int height;                                                                                                    //管子高度
}pipe[20];

struct linkShape                                                                                                      //存储连接管
{
       int y;                                                                                                         //连接管的y坐标
       int left;                                                                                                      //连接管左右端的x坐标
       int right;
}link[50];

int pipeNum,linkNum;                                                                                                   //管子的数量,连接管的数量
int targetPipe,targetLevel;                                                                                            //目标管子,目标水位

void process()                                                                                                         //计算到达指定管子的目标水位所需的时间
{
     int i,j,k,up,level,overflow,time=0;
     bool use[20],pipeFound,noSolution=false;
     stack<int>upSave,pipeSave;                                                                                        //保存当前正在充水的管子(编号为pipeSave)的充水时间(upSave)
     up=1;                                                                                                             //当前水位上升1cm,水在相关管子中流动的时间
     overflow=pipe[0].y;                                                                                               //当前溢出水位
     level=pipe[0].y+pipe[0].height;                                                                                   //当前水位
     memset(use,0,sizeof(use));
     use[0]=true;
     while(!noSolution)                                                                                                //只要有解
     {
           pipeFound=false;                                                                                            //是否找到了新的充水管子
           for(i=0;i<linkNum;i++)                                                                                      //搜索当前水位的管子
           {
               if(link[i].y==level)
               {
                   for(j=0;j<pipeNum;j++)                                                                              //连接管一端的管子
                   {
                        if(use[j])
                        {
                             for(k=0;k<pipeNum;k++)                                                                    //连接管另一端的管子
                             {
                                   if((pipe[j].x==link[i].left&&pipe[k].x==link[i].right)||
                                      (pipe[j].x==link[i].right&&pipe[k].x==link[i].left))                             //有效连接
                                   {
                                       if(!use[k])                                                                     //新管子,还没有充水
                                       {
                                            upSave.push(up);                                                           //保存管子j的状态
                                            pipeSave.push(j);
                                            level=pipe[k].y+pipe[k].height;                                            //计算新的当前水位
                                            up=1;                                                                      //充水1cm
                                            use[k]=pipeFound=true;                                                     //标记为已经充水,找到了新管子
                                            if(overflow<pipe[k].y)                                                     //计算新的溢出水位
                                               overflow=pipe[k].y;
                                       }
                                       else if(!pipeSave.empty()&&(pipeSave.top()==k||pipeSave.top()==j))              //已经充水的管子,继续充水1cm
                                       {
                                            up=upSave.top();
                                            upSave.pop();
                                            pipeSave.pop();
                                            up++;
                                       }
                                       break;                                                                          //该连接管计算完毕(没有连接管穿过管子)
                                   }
                             }
                             if(k<pipeNum)
                                break;
                        }
                   }
                   break;                                                                                              //当前水位只有一个连接管(没有处于同一个y坐标的连接管)
               }
           }
           if(pipeFound)                                                                                               //对新管子继续充水
              continue;
           if(level<=overflow||targetLevel<=overflow)                                                                  //对新的溢出水位进行溢出判断
           {
               noSolution=true;
               continue;
           }
           if(use[targetPipe]&&level==targetLevel)                                                                     //计算任务完成,指定的管子达到了目标水位
              break;
           level--;                                                                                                    //水位上升1cm
           time+=up;                                                                                                   //累加水位上升1cm所花费的时间
     }
     if(noSolution)
        printf("No Solution\n");
     else
        printf("%d\n",time);
}


int main()
{
    int i,ncase,length;
    scanf("%d",&ncase);
    while(ncase--)
    {
         scanf("%d",&pipeNum);
         for(i=0;i<pipeNum;i++)
             scanf("%d%d%d",&pipe[i].x,&pipe[i].y,&pipe[i].height);
         scanf("%d",&linkNum);
         for(i=0;i<linkNum;i++)
         {
             scanf("%d%d%d",&link[i].left,&link[i].y,&length);
             link[i].right=link[i].left+length;
             link[i].left--;
         }
         scanf("%d%d",&targetPipe,&targetLevel);
         targetPipe--;
         if((targetLevel<pipe[targetPipe].y)||(targetLevel>pipe[targetPipe].y+pipe[targetPipe].height))                //目标水位不在指定管子的里面
         {
              printf("No Solution\n");
              continue;
         }
         process();                                                                                                    //计算达到指定管子的目标水位所需的时间
    }
    system("pause");
    return 0;
}
 

