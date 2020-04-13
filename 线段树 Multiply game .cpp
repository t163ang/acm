#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 65536;
__int64 n64;
int tree[(MN << 1) + 100];// 记住：+ 要比 << 要高
int n, q, S;
void change(int k, int x)
{
    int w = S + k - 1;
    tree[w] = x;
    for(w >>= 1; w > 0; w >>= 1){
        n64 = (__int64)tree[w << 1] * tree[w << 1 | 1];
        tree[w] = (int)(n64 % 1000000007);
    }
}

int get(int k, int left, int right, const int L,const int R){
    if(L == left && R == right) return tree[k];
    int mid = (left + right) >> 1;
    if(L > mid) return get(k << 1 | 1, mid + 1, right, L, R) % 1000000007;
    else if(R <= mid) return get(k << 1, left, mid, L, R) % 1000000007;
    else{
       __int64 n64= (__int64)get(k << 1 | 1, mid + 1, right, mid + 1, R) * get(k << 1, left, mid, L,mid);//*若没有（__int64）乘 *结果只会以int保存
        return (int)(n64 % 1000000007);
    }
}

int main(){
   //freopen("in.txt", "r", stdin);
    int T, i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        S = 1;
        while (S < n) S <<= 1;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &tree[S + i]);
        }

        for (i = S - 1; i > 0; i--)
        {
            n64 = (__int64)tree[i << 1] * tree[i << 1 | 1];
            tree[i] = (int)(n64 % 1000000007);
        }

        scanf("%d",&q);
        int com,k1,k2,p;
        for(i = 0; i < q; i++){
            scanf("%d",&com);
            if(com){
                scanf("%d%d",&k1,&p);
                change(k1,p);
            }else{
                scanf("%d%d",&k1,&k2);
                printf("%d\n",get(1,1,S,k1,k2));
            }
        }
    }
    return 0;
}

//
///*
//	暴力的线段树。。。没用lazy定理
//*/
//#include<cstdio>
//#include<cstring>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 50010;
//
//struct Node
//{
//    int left,right;
//    long long mul;
//}nodes[MAXN*4];
//
//long long a[MAXN];
//
//void build(int p,int left,int right)
//{
//    nodes[p].left=left;
//    nodes[p].right=right;    
//    if(left==right)
//    {
//        nodes[p].mul=a[left];
//        return;
//    }
//    int mid=(left+right)>>1;
//    build(2*p,left,mid);
//    build(2*p+1,mid+1,right);
//    nodes[p].mul=nodes[2*p].mul*nodes[2*p+1].mul%1000000007;
//}
//
//long long query(int p,int left,int right)
//{
//    if(nodes[p].left==left&&nodes[p].right==right)return nodes[p].mul;
//    int mid=(nodes[p].left+nodes[p].right)>>1;
//    if(right<=mid)return query(p*2,left,right);
//    else if(left>mid)return query(p*2+1,left,right);
//    return query(2*p,left,mid)*query(2*p+1,mid+1,right)%1000000007;
//}
//void update(int p,int x,long long c)
//{
//    if(nodes[p].left==nodes[p].right)
//    {
//        nodes[p].mul=c;
//        a[x]=c;
//        return ;
//    }
//    int mid=(nodes[p].left+nodes[p].right)>>1;
//    if(x<=mid) update(p*2,x,c);
//    else  update(p*2+1,x,c);
//    nodes[p].mul=nodes[2*p].mul*nodes[2*p+1].mul%1000000007;
//}
//int main()
//{
//
//  // freopen("in", "r", stdin);
//   // freopen("out", "w", stdout);
//
//    int T,n;
//    scanf("%d",&T);
//    while(T--)
//    {
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++)
//            scanf("%d",&a[i]);
//        build(1,1,n);
//        int m,a,b,c;
//        scanf("%d",&m);
//        while(m--)
//        {
//            scanf("%d%d%d",&a,&b,&c);
//            if(a)
//            {
//                update(1,b,c);
//            }
//            else printf("%d\n",query(1,b,c));
//        }
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int MN = 65536;
//__int64 n64;
//int tree[(MN << 1) + 100];// 记住：+ 要比 << 要高
//int tr[MN];
//int poi[MN];//记录叶子j在tree[k]中的位置k在poi[j]
//int n, q;
//void change(int k, int x)
//{
//    int w = poi[k];
//    tree[w] = x;
//    for(w >>= 1; w > 0; w >>= 1){
//        n64 = (__int64)tree[w << 1] * tree[w << 1 | 1];
//        tree[w] = (int)(n64 % 1000000007);
//    }
//}
//
//int get(int k, int left, int right, const int L,const int R){
//    if(L == left && R == right) return tree[k];
//    int mid = (left + right) >> 1;
//    if(L > mid) return get(k << 1 | 1, mid + 1, right, L, R) % 1000000007;
//    else if(R <= mid) return get(k << 1, left, mid, L, R) % 1000000007;
//    else{
//       __int64 n64= (__int64)get(k << 1 | 1, mid + 1, right, mid + 1, R) * get(k << 1, left, mid, L,mid);//*若没有（__int64）乘 *结果只会以int保存
//        return (int)(n64 % 1000000007);
//    }
//}
//
//
//void build(int L, int R, int s){
//	if(L == R){ tree[s] = tr[L]; poi[L]= s; return;};
//	int mid = (L + R) >> 1;
//	build(L, mid,s << 1);
//	build(mid + 1, R,s << 1 | 1);
//	tree[s] = (__int64)tree[s << 1] * tree[s << 1 | 1] % 1000000007;
//}
//
//int main(){
//   //freopen("in.txt", "r", stdin);
//    int T, i;
//    scanf("%d", &T);
//    while (T--)
//    {
//        scanf("%d", &n);
//        for (i = 1; i <= n; i++)
//        {
//            scanf("%d", &tr[i]);
//        }
//		build(1,n,1);
//        //for (i = S - 1; i > 0; i--)
//        //{
//        //    n64 = (__int64)tree[i << 1] * tree[i << 1 | 1];
//        //    tree[i] = (int)(n64 % 1000000007);
//        //}
//
//        scanf("%d",&q);
//        int com,k1,k2,p;
//        for(i = 0; i < q; i++){
//            scanf("%d",&com);
//            if(com){
//                scanf("%d%d",&k1,&p);
//                change(k1,p);
//            }else{
//                scanf("%d%d",&k1,&k2);
//                printf("%d\n",get(1,1,n,k1,k2));
//            }
//        }
//    }
//    return 0;
//}
