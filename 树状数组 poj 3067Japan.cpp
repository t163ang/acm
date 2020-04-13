#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 1024;
int T,N,M,K,CASE = 1;
__int64 ans;
__int64 c[MN];
void updata(int x){
	while(x <= M){
		c[x]++;
		x += x & (-x);
	}
}

__int64 sum(int x){
	__int64 ans = 0;
	while(x > 0){
		ans += c[x];
		x -= x & (-x);
	}
	return ans;
}

struct Link{
	int east,west;
	bool operator < (const Link L) const{	
		if(east != L.east) return east > L.east;
		return west > L.west;
	}
}link[1000002];

int main(){
	//freopen("in.txt","r",stdin);
	int i;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%d%d%d",&N,&M,&K);
		for(i = 0; i < K; i++){
			scanf("%d%d",&link[i].east,&link[i].west);
		}
		sort(link,link + K);
		ans = 0;
		for(i = 0; i < K; i++){
			ans += sum(link[i].west - 1);
			updata(link[i].west);
		}
		printf("Test case %d: %I64d\n",CASE++,ans);
	}
	return 0;
}