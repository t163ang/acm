#include<stdio.h>
//�㷨������������,������ҿ�����,��������ұ�����,�������,��Ҫ��ѭ����ʼ��,ѭ�����Ƿ���ֹ���ж���
//,�Լ�ÿ���޸�left,right����ֵ�������ط�����һ��,����Ϳ��ܳ���.
int main(){
	int d[12] = {1,2,3,4,5,7,7,7,8,8,8,12};
	int len = 12, a = 0;
	int left = 0, right = len - 1;
	while(left <= right){
		int mid = (left + right) >> 1;
		if(d[mid] == a) {left = mid; break;}//�����ظ�Ԫ��ʱ�����ַ����±겻��,���޷���len + 1��0
		if(d[mid] < a) left = mid + 1;//������ǰ���a���±�,   d[left] = a,���޷���len + 1��0
		//if(d[mid] <= a) left = mid + 1;//����������a���±����һλ, d[left - 1] = a,���޷���len + 1��0
		else right = mid - 1;
	}
	//������ж�һ���Ƿ��ҵ�
	//if(a == a[left]) || if(a == a[left - 1])
	printf("%d\n",left);
	return 0;
}

//ʵ����ϣ����ۣ�
//������ߵ�
int M;
int bs(int L, int R, int x){
	while(L <= R){
		M = (L + R) >> 1;
		if(a[M] < x) L = M + 1;
		else R = M - 1;
	}
	return L;
}

//���ұߵ�
int bs(int L, int R, int x){
	while(L <= R){
		M = (L + R) >> 1;
		if(a[M] <= x) L = M + 1;
		else R = M - 1;
	}
	return R;
}
//��ô�����Ķ���!!!