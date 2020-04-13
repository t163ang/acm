#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 21;
int a,b,c;
int mw[MN][MN][MN];
int w(int a, int b, int c){
	//先前下面这两句判断调换了就错了，所以递归顺序也很重要
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	else if(a > 20 || b > 20 || c > 20) return w(20,20,20);
	else{
		if(mw[a][b][c]) return mw[a][b][c];
		else if(a < b && b < c) mw[a][b][c] = w(a,b,c - 1) - w(a,b - 1,c) + w(a,b - 1, c - 1);
		else mw[a][b][c] = w(a - 1,b,c) - w(a - 1,b - 1,c - 1) + w(a - 1, b - 1,c ) + w(a - 1, b, c - 1);
		return mw[a][b][c];
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&a,&b,&c),a != -1 || b != -1 || c != -1){
		memset(mw,0,sizeof(mw));
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
	return 0;
}