#include<iostream>
using namespace std;
const int MN = 62;
bool stick[MN];//��¼����Ƿ���� 
struct{
	int x[4];
}squre[MN]; //��¼ÿ�������εĸ�����
void init(int n){//��ʼ��squre
	int i,j, m = 1;
	int rows[6][6],cols[6][6];
	for(i = 1; i <= n + 1; i++){
		for(j = 1; j <= n; j++){
			rows[i][j] = m++;
		}
		for(j = 1; j <= n + 1; j++){
			cols[i][j] = m++;
		}
	}
	
}
void dfs(int s){

}
int main(){
	freopen("in.txt","r",stdin);
	int i,j,n,t,k;
	scanf("%d",&t);
	while(t--){		
		scanf("%d%d",&n,&k);	
		for(i = 0; i < k; i++){
			scanf("%d",&j);
			stick[j] = false;
		}		
		memset(stick,true,sizeof(stick));
		init();
		dfs(1);
	}
	return 0;
}