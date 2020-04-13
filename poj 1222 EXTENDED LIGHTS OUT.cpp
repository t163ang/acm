#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 7;
int CA = 1;
int get[MN][MN];
int tmp[MN][MN];
int p[MN][MN];
void inline ps(int i, int j){
	tmp[i][j] = !tmp[i][j];
	if(i > 0) tmp[i - 1][j] = !tmp[i - 1][j];
	if(i < 4) tmp[i + 1][j] = !tmp[i + 1][j];
	if(j > 0) tmp[i][j - 1] = !tmp[i][j - 1];
	if(j < 5) tmp[i][j + 1] = !tmp[i][j + 1];
}

void inline press(int i,int j){
	if(tmp[i - 1][j]) {
		p[i][j] = 1;
		ps(i,j);
	}
}
bool inline allzero(){
	for(int i = 0; i < 6; i++){
		if(tmp[4][i]) return false;
	}
	return true;
}
void solve(){
	int i,j,k;
	for(i = 0; i < (1 << 6); i++){
		memcpy(tmp,get,sizeof(get));
		memset(p,0,sizeof(p));
		//第一行枚举
		for(j = 0; j < 6; j++){
			if(i & (1 << j)){
				p[0][j] = 1;
				ps(0,j);
			}
		}
		//第二至第五行
		for(k = 1; k < 5; k++){
			for(j = 0; j < 6; j++){
				press(k,j);
			}
		}
		if(allzero()) break;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int T; scanf("%d",&T);
	int i,j;
	while(T--){
		for(i = 0; i < 5; i++){
			for(j = 0; j < 6; j++){
				scanf("%d",&get[i][j]);
			}
		}
		solve();
		printf("PUZZLE #%d\n",CA++);
		for(i = 0; i < 5; i++){
			for(j = 0; j < 6; j++){
				printf("%d ",p[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
//sample input
//2
//0 1 1 0 1 0
//1 0 0 1 1 1
//0 0 1 0 0 1
//1 0 0 1 0 1
//0 1 1 1 0 0
//0 0 1 0 1 0
//1 0 1 0 1 1
//0 0 1 0 1 1
//1 0 1 1 0 0
//0 1 0 1 0 0