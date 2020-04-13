#include<iostream>
using namespace std;

const int BASE  =  3 * 50 * 50 * 50 * 50 + 24;
char hash[3 * 50 * 50 * 50 * 50 + BASE];
int F[110];
int a1,a2,a3,a4,a5;
void  init(){
	for(int i = -50; i <= 50; i++){
		F[i + 50] = i * i * i;
	}
}
int inline f(int i){
	return F[i + 50];
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k;
	init();
	while(~scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)){
		memset(hash,0,sizeof(hash));
		for(i = -50; i <= 50; i++){
			if(!i) continue;
			for(j = -50; j <= 50; j++){
				if(!j) continue;
				for(k = -50; k <= 50; k++){
					if(!k) continue;
					hash[a1 * f(i) + a2 * f(j) + a3 * f(k) + BASE]++;
				}
			}
		}
		int ans = 0,num;
		for(i = -50; i <= 50; i++){
			if(!i) continue;
			for(j = -50; j <= 50; j++){
				if(!j) continue;				
				num = -(a4 * f(i) + a5 * f(j)) + BASE;
				if(hash[num]) ans += hash[num];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}