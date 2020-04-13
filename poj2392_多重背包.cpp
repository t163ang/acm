#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 40002 * 100;
int V;
bool dp[MN];
struct Block{
	int h,a,c;
	bool operator < (const Block b){
		return a < b.a;
	}
}block[4000],*B;

inline void ZeroOnePack(int cost, int weight){
	for(int i = weight; i >= cost; i--){
		dp[i] = dp[i] || dp[i - cost];
	}
}

inline void CompletePack(int cost,int weight){
	for(int i = cost; i <= weight; i++){
		dp[i] = dp[i] || dp[i - cost];
	}
}

inline void MultiplePack(int cost, int weight, int amount){
	if(cost * amount >= V){
		CompletePack(cost,weight);
		return;
	}
	int k = 1;
	while(k < amount){
		ZeroOnePack(k * cost, weight);
		amount -= k;
		k *= 2;
	}
	ZeroOnePack(amount * cost,weight);
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,k;
	int h,a,c;
	scanf("%d",&k);
	for(i = 0, B = block, V = 0; i < k; i++,B++){
		scanf("%d%d%d",&h,&a,&c);
		B->h = h;
		B->a = a;
		B->c = c;
		if(V < a) V = a;
	}
	sort(block,block + k);
	dp[0] = true;
	for(i = 1; i <= V; i++){
		dp[i] = false;
	}
	for(i = 0,B = block; i < k; i++,B++){
		MultiplePack(B->h,B->a,B->c);
	}

	for(i = V; i >= 0; i--){
		if(dp[i]) {
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

//传说的O(NV)的做法
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int MN = 40002 * 100;
//int V;
//bool dp[MN];
//int num[MN];
//struct Block{
//	int h,a,c;
//	bool operator < (const Block b){
//		return a < b.a;
//	}
//}block[4000],*B;
//
//inline void MultiplePack(int cost, int weight, int amount){
//	//memset(num,0,sizeof(num));
//	for(int j = 0; j <= weight; j++){
//		num[j] = 0;
//	}
//	for(int j = cost; j <= weight; j++){
//		if(!dp[j] && dp[j - cost] && num[j - cost] < amount){
//			dp[j] = true;
//			num[j] = num[j - cost] + 1;
//		}
//	}
//}
//int main(){
//	//freopen("in.txt","r",stdin);
//	int i,k;
//	int h,a,c;
//	scanf("%d",&k);
//	for(i = 0, B = block, V = 0; i < k; i++,B++){
//		scanf("%d%d%d",&h,&a,&c);
//		B->h = h;
//		B->a = a;
//		B->c = c;
//		if(V < a) V = a;
//	}
//	sort(block,block + k);
//	dp[0] = true;
//	for(i = 1; i <= V; i++){
//		dp[i] = false;
//	}
//	for(i = 0,B = block; i < k; i++,B++){
//		MultiplePack(B->h,B->a,B->c);
//	}
//
//	for(i = V; i >= 0; i--){
//		if(dp[i]) {
//			printf("%d\n",i);
//			break;
//		}
//	}
//	return 0;
//}