#include<iostream>
using namespace std;
const int MN = 4;
int N,T;
int c[MN][MN];
//�޸�[xiu gai]һ��Ԫ�ض����ӻ����һ����ֵ����ѯһ��Ԫ�ص�ֵ��
//ͬ����logN����ġ�����[wen ti]������ת���ģ�
//�����a-b����[qu jian]�ڵ�Ԫ�ض�Ҫ����v��
//��ôʵ�ʾͿ��԰�aԪ������v, b+1����v����ô��ѯaԪ�ص�ֵ�أ�
//������sum(1->a)����Ԫ�صĺ;����ˣ�
void updata(int x, int y){
	for(int i = x; i <= N; i += i & (-i)){
		for(int j = y; j <= N; j += j & (-j)){
			c[i][j]++;
		}
	}
}

int sum(int x, int y){
	int ans = 0;
	for(int i = x; i > 0; i -= i & (-i)){
		for(int j = y; j > 0; j -= j & (-j)){
			ans += c[i][j];
		}
	}
	return ans;
}
char ins; int x1,y1,x2,y2;
int main(){
	freopen("in.txt","r",stdin);
	int t; scanf("%d",&t);
	int i,j;
	while(t--){
		memset(c,0,sizeof(c));
		scanf("%d%d",&N,&T);
		for(i = 0; i < T; i++){
			scanf(" %c",&ins);
			if(ins == 'Q'){
				scanf("%d%d",&x1,&y1);
				printf("%d\n",sum(x1,y1) & 1);

			}else{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				updata(x1,y1);
				updata(x1,y2 + 1);
				updata(x2 + 1, y1);
				updata(x2 + 1, y2 + 1);
			}
		}
		puts("");
	}
	return 0;

}