#include <iostream>
#define MAX 152
#define INF 0x3ffffff
using namespace std;

/**//*
dp[s][i]:��¼s��㣬Ҫ�õ�һ��j���ڵ������ȥ�������ٱ���
���������k
  1�������ȥ��k��������
    dp[s][i] = min(dp[s][j]+dp[k][i-j])  0 <= j <= i

  2�����ȥ��k��������
    dp[s][i] =  dp[s][i]+1
�ܵ�Ϊ
    dp[s][i] = min (min(dp[s][j]+dp[k][i-j]) ,  dp[s][i]+1 )
*/

int dp[MAX][MAX];
int son[MAX], bla[MAX], root, n, p;
//son[i]:��¼i���Ķ��ӣ�bla[i]:��¼i�����ֵ�
bool hf[MAX];
//hf[i]:i����Ƿ��и���

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
   ����������������ˮλ�������ӿ�ʱ,ֻ���һ�����Ӽ�ˮ,�������ӵ�ˮλ��Ȼ����ȵ�,�����������,�������Ӹ��Ե���ˮ�ٶ���ˮ�����һ�����ӵ�һ��,��ˮ���ٶȷǳ���,���Ժ��Բ���,�Ҽٶ�Ŀ��ˮλ���Ǳ�ָ����ˮλ�Ը�һ��.
    ���һ�����ӵ�ˮλ�Ѿ����ﶥ��(��Ϊˮλx),ֻҪ���������Ĺ�����ˮλx�����ǿյ�,ˮ���������(ע����ˮλx��,���ܻ������ӹ���ˮ����),������еĹ�����ˮλx����(�����ӹ�����)�Ŀռ䶼��ˮ,ˮλ�Ͳ�������.
    ����������������¼ٶ�:
        1> �ӵ�һ�����ӿ�ʼ��ˮ
        2> û�����ӹܴ�������
        3> û�д���ͬһ��y��������ӹ�
        4> û�����Ͻ�x������ͬ�Ĺ���
        5> ÿ�����ӹܵ������˵㶼�պ����������
   ģ��ˮ�ڹ����е�����,���ˮ��ָ��������������Ŀ��ˮλ�����ʱ��
        1> ���ٻ���,���ӵĽ����s:s=pi*r*r=0.25*pi,��λʱ��ˮ�����ĳ���Ϊ:(v*t)/s=0.25*pi/(0.25*pi)=1cm
        2> �ж�Ŀ��ˮλ�Ƿ���ָ�����ӵ�����,���Ŀ��ˮλ����ָ�����ӵ�����,�����"No Solution"
        3> ÿ����ˮλ����1cm(level--),ģ��ˮ��������ع����е�������ͳ��ʱ��(up),���ܵ�ʱ��time����up���ۼӺ�.
        4> ģ��ˮ��������ع����е�������ͳ��ʱ��(up),���ڲ���֪����ǰˮλ����һ�����ӹ�,Ҳ��֪�����ӹܵ�����������ʲô����,����ֻ�ܽ�������:
              a> �����е����ӹ�,���Ҵ��ڵ�ǰˮλ�����ӹ�i
              b> �����е�ˮ��,�������ӹ�i�������Ǹ�ˮ��j�Ѿ���ˮ(�����������Ӷ�û��ˮ)
              c> ����Ѿ��ҵ���һ������j��ˮ,�������еĹ�����������һ������k,�ҵ�����k֮��,�ַ��������:
                   1>: ����k��δ��ˮ,�������j��״̬,���¼��㵱ǰˮλ���µ����ˮλ
                   2>: ����k�Ѿ���ˮ,������ˮ1cm,ÿ��ֻ�ܳ�ˮ1cm,��ֹ©�������k�������������ӹ�.
#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;

struct pipeShape                                                                                                      //�洢����
{
       int x;                                                                                                         //�������Ͻǵ�x,y����
       int y;
       int height;                                                                                                    //���Ӹ߶�
}pipe[20];

struct linkShape                                                                                                      //�洢���ӹ�
{
       int y;                                                                                                         //���ӹܵ�y����
       int left;                                                                                                      //���ӹ����Ҷ˵�x����
       int right;
}link[50];

int pipeNum,linkNum;                                                                                                   //���ӵ�����,���ӹܵ�����
int targetPipe,targetLevel;                                                                                            //Ŀ�����,Ŀ��ˮλ

void process()                                                                                                         //���㵽��ָ�����ӵ�Ŀ��ˮλ�����ʱ��
{
     int i,j,k,up,level,overflow,time=0;
     bool use[20],pipeFound,noSolution=false;
     stack<int>upSave,pipeSave;                                                                                        //���浱ǰ���ڳ�ˮ�Ĺ���(���ΪpipeSave)�ĳ�ˮʱ��(upSave)
     up=1;                                                                                                             //��ǰˮλ����1cm,ˮ����ع�����������ʱ��
     overflow=pipe[0].y;                                                                                               //��ǰ���ˮλ
     level=pipe[0].y+pipe[0].height;                                                                                   //��ǰˮλ
     memset(use,0,sizeof(use));
     use[0]=true;
     while(!noSolution)                                                                                                //ֻҪ�н�
     {
           pipeFound=false;                                                                                            //�Ƿ��ҵ����µĳ�ˮ����
           for(i=0;i<linkNum;i++)                                                                                      //������ǰˮλ�Ĺ���
           {
               if(link[i].y==level)
               {
                   for(j=0;j<pipeNum;j++)                                                                              //���ӹ�һ�˵Ĺ���
                   {
                        if(use[j])
                        {
                             for(k=0;k<pipeNum;k++)                                                                    //���ӹ���һ�˵Ĺ���
                             {
                                   if((pipe[j].x==link[i].left&&pipe[k].x==link[i].right)||
                                      (pipe[j].x==link[i].right&&pipe[k].x==link[i].left))                             //��Ч����
                                   {
                                       if(!use[k])                                                                     //�¹���,��û�г�ˮ
                                       {
                                            upSave.push(up);                                                           //�������j��״̬
                                            pipeSave.push(j);
                                            level=pipe[k].y+pipe[k].height;                                            //�����µĵ�ǰˮλ
                                            up=1;                                                                      //��ˮ1cm
                                            use[k]=pipeFound=true;                                                     //���Ϊ�Ѿ���ˮ,�ҵ����¹���
                                            if(overflow<pipe[k].y)                                                     //�����µ����ˮλ
                                               overflow=pipe[k].y;
                                       }
                                       else if(!pipeSave.empty()&&(pipeSave.top()==k||pipeSave.top()==j))              //�Ѿ���ˮ�Ĺ���,������ˮ1cm
                                       {
                                            up=upSave.top();
                                            upSave.pop();
                                            pipeSave.pop();
                                            up++;
                                       }
                                       break;                                                                          //�����ӹܼ������(û�����ӹܴ�������)
                                   }
                             }
                             if(k<pipeNum)
                                break;
                        }
                   }
                   break;                                                                                              //��ǰˮλֻ��һ�����ӹ�(û�д���ͬһ��y��������ӹ�)
               }
           }
           if(pipeFound)                                                                                               //���¹��Ӽ�����ˮ
              continue;
           if(level<=overflow||targetLevel<=overflow)                                                                  //���µ����ˮλ��������ж�
           {
               noSolution=true;
               continue;
           }
           if(use[targetPipe]&&level==targetLevel)                                                                     //�����������,ָ���Ĺ��Ӵﵽ��Ŀ��ˮλ
              break;
           level--;                                                                                                    //ˮλ����1cm
           time+=up;                                                                                                   //�ۼ�ˮλ����1cm�����ѵ�ʱ��
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
         if((targetLevel<pipe[targetPipe].y)||(targetLevel>pipe[targetPipe].y+pipe[targetPipe].height))                //Ŀ��ˮλ����ָ�����ӵ�����
         {
              printf("No Solution\n");
              continue;
         }
         process();                                                                                                    //����ﵽָ�����ӵ�Ŀ��ˮλ�����ʱ��
    }
    system("pause");
    return 0;
}
 

