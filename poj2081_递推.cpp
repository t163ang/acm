#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 500010;
int am[MN];
bool res[MN << 3]; //其实可以用hash表
int main(){
	//freopen("in.txt","r",stdin);
	int k;
	am[0] = 0; res[0] = true;
	for(k = 1; k <= 500000; k++){
		if(am[k - 1] >= k && !res[am[k - 1] - k]) am[k] = am[k - 1] - k;
		else am[k] = am[k - 1] + k;
		res[am[k]] = true;
	}
	while(scanf("%d",&k), k != -1){
		printf("%d\n",am[k]);
	}
	return 0;
}