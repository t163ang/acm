#include"stdio.h"
//D[k] = min{A[t]} (F[t] = k,F[t]表示从1到t这一段中以t结尾的最长上升子序列的长度)。
//D[k]存放的是：长度为k的上升子序列 中 未数最小的。 如 1 7 和 1 3 同样是上升子序列但3 比 7 小 故 用 3 而弃 7
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
