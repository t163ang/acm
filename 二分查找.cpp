#include<stdio.h>
//算法所操作的区间,是左闭右开区间,还是左闭右闭区间,这个区间,需要在循环初始化,循环体是否终止的判断中
//,以及每次修改left,right区间值这三个地方保持一致,否则就可能出错.
int main(){
	int d[12] = {1,2,3,4,5,7,7,7,8,8,8,12};
	int len = 12, a = 0;
	int left = 0, right = len - 1;
	while(left <= right){
		int mid = (left + right) >> 1;
		if(d[mid] == a) {left = mid; break;}//当有重复元素时，这种返回下标不定,若无返回len + 1或0
		if(d[mid] < a) left = mid + 1;//返回最前面的a的下标,   d[left] = a,若无返回len + 1或0
		//if(d[mid] <= a) left = mid + 1;//返加最后面的a的下标的下一位, d[left - 1] = a,若无返回len + 1或0
		else right = mid - 1;
	}
	//这里就判断一下是否找到
	//if(a == a[left]) || if(a == a[left - 1])
	printf("%d\n",left);
	return 0;
}

//实验完毕，结论：
//查最左边的
int M;
int bs(int L, int R, int x){
	while(L <= R){
		M = (L + R) >> 1;
		if(a[M] < x) L = M + 1;
		else R = M - 1;
	}
	return L;
}

//最右边的
int bs(int L, int R, int x){
	while(L <= R){
		M = (L + R) >> 1;
		if(a[M] <= x) L = M + 1;
		else R = M - 1;
	}
	return R;
}
//多么完美的东西!!!