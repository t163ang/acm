#include"stdio.h"
//D[k] = min{A[t]} (F[t] = k,F[t]��ʾ��1��t��һ������t��β������������еĳ���)��
//D[k]��ŵ��ǣ�����Ϊk������������ �� δ����С�ġ� �� 1 7 �� 1 3 ͬ�������������е�3 �� 7 С �� �� 3 ���� 7
int d[40024];
int n;
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int m;
	while(n--){
		int p;
		scanf("%d",&p);
		int len = 0,a;
		scanf("%d",&d[len++]);
		while(--p){
			scanf("%d",&a);
			if(a > d[len - 1]) d[len++] = a;
			else{
				int left = 0, right = len - 1;
				while(left <= right){
					int mid = (left + right) >> 1;
					if(d[mid] < a) left = mid + 1;
					else right = mid - 1;
				}
				d[left] = a;
			}
		}
		printf("%d\n",len);
	}
	return 0;
}
