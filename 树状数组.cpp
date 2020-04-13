#include<iostream>
using namespace std;
const int MN = 32024;
int c[MN], ans[MN]; 
//现在总结一下自己对树状数组吧：
//logn ！是就是它，不是对元素一个一个的存储，
//而是一个2 ^ k 的指数增长存储数据
//相当于指数式保存孩子（前面）的数吧
//这样做有什么好处？将计数范围严格限制在2 ^(k - 1) ~ 2 ^ k间
//难道线段树不是这样吗？
int inline lowbit(int i){
	return i & (-i);
}

void modif(int i, int num){
	while(i < MN){
		c[i] += num;
		i += lowbit(i);//不用怕lowbit(i)越界，因为while(i < MN)
	}
}

int sum(int i){
	int t = 0;
	while(i > 0){
		t += c[i];
		i -= lowbit(i);
	}
	return t;
}
int N,x,y;
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d",&N)){
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		for(i = 0; i < N; i++){
			scanf("%d%d",&x,&y);
			ans[sum(x + 1)]++;
			modif(x + 1,1);
		}
		for(i = 0; i < N; i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}