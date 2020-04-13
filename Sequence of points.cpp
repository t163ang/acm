#include<iostream>
using namespace std;
int n,j;
const int MN  = 10E5 + 100;
struct Cor{
	int x,y;
}A[MN];
Cor M1,M0;
void getm(Cor &M1, const Cor &M0,const Cor &A0){
	M1.x = (A0.x << 1) - M0.x;
	M1.y = (A0.y << 1) - M0.y;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("F:\out","w",stdout);
	int i,j;
	while(~scanf("%d%d",&n,&j)){
		scanf("%d%d",&M0.x, &M0.y);
		for(i = 0; i < n; i++){
			scanf("%d%d",&A[i].x, &A[i].y);
		}
		for(i = 0; i < j % (n << 1); i++){
			getm(M1,M0,A[i % n]);
			M0 =  M1;
		}
		printf("%d %d\n",M0.x,M0.y);
	}
	return 0;

}