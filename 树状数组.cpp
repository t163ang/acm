#include<iostream>
using namespace std;
const int MN = 32024;
int c[MN], ans[MN]; 
//�����ܽ�һ���Լ�����״����ɣ�
//logn ���Ǿ����������Ƕ�Ԫ��һ��һ���Ĵ洢��
//����һ��2 ^ k ��ָ�������洢����
//�൱��ָ��ʽ���溢�ӣ�ǰ�棩������
//��������ʲô�ô�����������Χ�ϸ�������2 ^(k - 1) ~ 2 ^ k��
//�ѵ��߶�������������
int inline lowbit(int i){
	return i & (-i);
}

void modif(int i, int num){
	while(i < MN){
		c[i] += num;
		i += lowbit(i);//������lowbit(i)Խ�磬��Ϊwhile(i < MN)
	}
}

int sum(int i){
	int t = 0;
	while(i > 0){
		t += c[i];
		i -= lowbit(i);
	}
	return t;
}
int N,x,y;
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d",&N)){
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		for(i = 0; i < N; i++){
			scanf("%d%d",&x,&y);
			ans[sum(x + 1)]++;
			modif(x + 1,1);
		}
		for(i = 0; i < N; i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}