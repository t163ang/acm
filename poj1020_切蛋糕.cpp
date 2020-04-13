#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 100;
int s,n,pies[MN];
int used[MN];
bool ok;

void dfs(int a){
	int i,j,mincol,minrow;
	if(a == n){
		ok = true; exit;
	}
	minrow = used[1];
	mincol = 1;
	for(i = 2; i <= s; i++){
		if(used[i] < minrow) {
			minrow = used[i];
			mincol = i;
		}
	}
	for(i = 10; i > 0; i--){
		if(pies[i] > 0 && i + mincol - 1 <= s && used[mincol] + i - 1<= s){
			bool flag = true;
			for(j = mincol; j < mincol + i; j++){
				if(used[j] > minrow){
					flag = false;
					break;
				}
			}
			if(flag){
				for(j = mincol; j < mincol + i; j++){
					used[j] += i;
				}
				pies[i]--;
				dfs(a + 1);
				for(j = mincol; j < mincol + i; j++){
					used[j] -= i;
				}
				pies[i]++;
			}
		}
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&s,&n);
		int sum = 0;
		memset(pies,0,sizeof(pies));
		for(i = 0; i < n; i++){
			scanf("%d",&j);
			pies[j]++;
			sum += j * j;
		}
		ok = false;;
		if(sum == s * s){		
			for(i = 1; i <= s; i++){
				used[i] = 1;
			}
			dfs(0);
		}
		if(ok) printf("KHOOOOB!\n");
		else printf("HUTUTU!\n");
	}
	return 0;
}