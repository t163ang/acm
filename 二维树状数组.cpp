#include<iostream>
using namespace std;
//二维树状数组
//c[i][j] 记录的是二维数据0..i,0..j的和,不过i,j也是以指数式跳跃
const int MN = 1048;
int c[MN][MN];
int lowbit(int i){
	return i & (-i);
}
void updata(int x, int y, int num){
	for(int i = x; i < MN; i += lowbit(i)){
		for(int j = y; j < MN; j += lowbit(j)){
			c[i][j] += num;
		}
	}
}
int sum(int x, int y){
	int ans = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		for(int j = y; j > 0; j -= lowbit(j)){
			ans += c[i][j];
		}
	}
	return ans;
}
int ins,x1,y1,x2,y2,num,ans;
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&ins,&x1);
	memset(c,0,sizeof(c));
	while(scanf("%d",&ins), ins != 3){
		if(ins == 1){
			scanf("%d%d%d",&x1,&y1,&num);
			updata(x1 + 1,y1 + 1,num);
		}else{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ans = sum(x2 + 1,y2 + 1) + sum(x1,y1) - sum(x1,y2 + 1) - sum(x2 + 1, y1);
			printf("%d\n",ans);
		}
	}
	return 0;
}