#include<cstdio>
//const int R = 2, C1 = 2 , C2 = 2;  

//void matmul(int tmp[][C2],int a[][C1], const int b[][C2]){
//	for(int k = 0; k < C1; k++){
//		for(int i = 0; i < R; i++)  if(a[i][k]){
//			for(int j = 0; j < C2; j++){
//				tmp[i][j] = a[i][k] * b[k][j];
//			}
//		}
//	}
//}

int r,n,m,s;
const int N = 32770;
struct Mat{
	int a,b,c,d;
}x[N << 1];

Mat product(Mat A, Mat B){
	Mat C;
	C.a = (A.a * B.a + A.b * B.c) % r;
	C.b = (A.a * B.b + A.b * B.d) % r;
	C.c = (A.c * B.a + A.d * B.c) % r;
	C.d = (A.c * B.b + A.d * B.d) % r;
	return C;
 }

void init(){	
	for(int i = s - 1; i > 0; i--){
		x[i] = product(x[i << 1], x[i << 1 | 1]);
	}
}

Mat query(int d, int left, int right, int i, int j){
	if(i == left && j == right) return x[d];
	int mid = (left + right) >> 1;
	if(i > mid) return query(d << 1 | 1, mid + 1, right, i,j);
	else if(j <= mid) return query(d << 1, left,mid,i,j);
	return product(query(d<<1,left,mid,i,mid),query(d<<1 | 1, mid + 1,right, mid + 1,j));
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	bool blank = false; //多case的不能不while里写一个输出或不输出回车
	while(~scanf("%d%d%d",&r,&n,&m)){	
		s = 1;
		while(s < n) s <<=1;
		for(i = 0; i < n; i++)
			scanf("%d%d%d%d",&x[s + i].a,&x[s + i].b,&x[s + i].c,&x[s + i].d);		
		init();
		while(m--){
			if(blank) puts("");
			else blank = true;
			scanf("%d%d",&i,&j);
			Mat ans = query(1,1,s,i,j);
			printf("%d %d\n%d %d\n",ans.a, ans.b, ans.c,ans.d);
		}
	}
	return 0;
}