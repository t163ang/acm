#include<iostream>
using namespace std;
int f[50][50];
int X,Y,K,B;
void init(){
	//统计一棵高度为i的完全二叉树内二进制表示中恰好含有j个1的数的个数
	//+++++++注意当j = 0时 f[i][0] = 1没有1的个数是1
	int i,j;
	f[0][0] = 1;
	for(i = 1; i <= 31; i++){
		f[i][0] = 1;
		for(j = 1; j <= i; j++) f[i][j] = f[i - 1][j] + f[i -1][j - 1];
	}
}


int solve(int x, int b){
	//将b进制的视为二进制，因为二叉树，>>当1时表视b^i 存在<<。###数位统计，统计的就是每一数位是否存在吧！！！！#####
	int s[40], i = 0;
	int ans = 0;
	while(x > 0) s[i++] = x % b, x /= b;
	for(i--;i >= 0;i-- ){ 
		if(s[i] > 1){
			ans--;
			ans += 1 << (i + 1);
			break;
		}
		ans+=s[i]*(1<<i);
	} 
	return ans;
} 

//int change(int x, int b){
//	int s[40], i = 0;
//	while(x > 0) s[i++] =  x % b, x /= b;
//	int ans = 0;
//	for(--i; i > -1; i--){
//		if(s[i] > 1){
//			ans--;
//			ans |= 1 << (i + 1);
//			break;
//		}
//		ans |= (1 & s[i])<< i;
//	}
//	return ans;
//}

//int change(int x,int b)
//{
//	string s;
//	do {
//		s=char('0'+x%b)+s;
//		x/=b;
//	} while (x>0);
//	for (int i=0;i<s.size();++i)
//		if (s[i]>'1') {
//			for (int j=i;j<s.size();++j) s[j]='1';
//			break;
//		}
//	x=0;
//	for (int i=0;i<s.size();++i)
//		x=x|((s[s.size()-i-1]-'0')<<i);
//	return x;
//}

int calc(int x, int k){
	int tot = 0, ans = 0;//tot当前
	x = solve(x,B);
	for(int i = 31; i >= 0; i--){
		if(x & (1 << i)){
			////到达叶子一样行，因为tot计算了的就是x的位，这样x的右兄弟叶子为f[0][j > 0]将为0
			ans += f[i][k - tot];
			tot++;
			//到达叶子一样一行，因为tot计算了的就是x的位，这样ans也要加1 
			if(tot == k) { ans++; break;}
		}
	}
	return ans;
} 
int main(){
	//freopen("in.txt","r",stdin);
	init();
	while(EOF!=scanf("%d %d %d %d",&X,&Y,&K,&B)){
		printf("%d\n",calc(Y,K)-calc(X-1,K));
	}
	return 0;
}

//语言的操作符共有15个优先级，如下：
//() [] -> .                                                                                         left to right
//! ~ ++ -- +（正号） -（负号） *（指针取值符） (type) sizeof      right to left
//* / %                                                                                         left to right
//+ -                                                                                            left to right
//<<   >>                                                                                     left to right
//< <= >   >=                                                                              left to right
//== !=                                                                                        left to right
//&                                                                                              left to right
//^                                                                                                left to right
//|                                                                                                left to right
//&&                                                                                           left to right
//||                                                                                               left to right
//?:                                                                                             right to left
//= += -=   *= /=   %=   &=   ^=   |=   <<=   >>=                             right to left
//,                                                                                                left to right
//
//记忆口诀
//
//括号成员第一;                                     //括号运算符[]() 成员运算符. ->
//全体单目第二;                                   //所有的单目运算符比如++ -- +(正) -(负) 指针运算*&
//乘除余三,加减四;                             //这个"余"是指取余运算即%
//移位五，关系六;                           //移位运算符：<< >> ，关系：> < >= <= 等
//等于(与)不等排第七;                   //即== !=
//位与异或和位或;                        //这几个都是位运算: 位与(&)异或(^)位或(|) 
//"三分天下"八九十; 
//逻辑或跟与;                             //逻辑运算符:|| 和 &&
//十二和十一;                           //注意顺序:优先级(||) 底于 优先级(&&) 
//条件高于赋值,                       //三目运算符优先级排到 13 位只比赋值运算符和","高
//逗号运算级最低!                 //逗号运算符优先级最低          