#include<iostream>
#include<vector>
using namespace std;
const int MN = 524;
int N,M;
struct Squre{
	int x1,y1,x2,y2;
	Squre(int x1,int y1, int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
	Squre(){}
};

bool cross(Squre a, Squre b){
	if(a.x1 >= b.x2 || a.x2 <= b.x1 || a.y1 >= b.y2 || a.y2 <= b.y1) return false;
	return true;
}

struct Conlon{
	vector<Squre> vec;
	vector<int> ans;
	void cut(const Squre &cutsq, int n);
}colon[MN];

void Conlon::cut(const Squre &cutsq, int n){
	int i,j,k1,k2,k3,k4;
	Squre sq; 
	bool hascut = false;
	for(i = 0; i < vec.size(); i++){
		sq = vec[i];
		if(cross(sq,cutsq)){
			vec.erase(vec.begin() + i);	
			i -= 1;//没有这个wa了n次，不过学会了调试，值得啦<..> 原因是在erase后，size()会变，importantly,同时i也会因此可能忽略了前面一个，because你删除了一个，它们向前移了一位！！！
			k1 = max(sq.x1,cutsq.x1),k2 = min(sq.x2,cutsq.x2);
			if(sq.x1 < k1) vec.push_back(Squre(sq.x1,sq.y1,k1,sq.y2));
			if(sq.x2 > k2) vec.push_back(Squre(k2,sq.y1,sq.x2,sq.y2));

			k3 = max(sq.y1,cutsq.y1),k4 = min(sq.y2,cutsq.y2);
			if(sq.y1 < k3) vec.push_back(Squre(k1,sq.y1,k2,k3));
			if(k4 < sq.y2) vec.push_back(Squre(k1,k4,k2,sq.y2));
			hascut = true;
		}
	}
	if(hascut) ans.push_back(n);
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,k,x1,y1,x2,y2;
	Squre sq;
	while(~scanf("%d",&N)){
		memset(colon,0,sizeof(colon));
		for(i = 1; i <= N; i++){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			sq = Squre(x1,y1,x2,y2);
			colon[i].vec.push_back(sq);
			for(j = 1; j < i; j++){
	    	 colon[j].cut(sq,i);
			}
		}
		scanf("%d",&M);
		for(i = 1; i <= M; i++){
			scanf("%d",&k);
			int len = colon[k].ans.size();
			printf("%d",len);
			for(j = 0; j < len; j++) printf(" %d",colon[k].ans[j]);
			puts("");
		}
		puts("");
	}
	return 0;
}
//买一送一
//附加当没有i -= 1时，我发现错误的测试数据：
//4
//-8 -8 8 8
//5 3 88880 5848484
//-154551 -51215441 2 2
//0 -65 51 0
//1 
//1
//调试输出信息：
//2: (-8,-8 : 5,8)
//2: (5,-8 : 8,3)
//3: (5,-8 : 8,3)
//3: (2,-8 : 5,8)
//3: (-8,2 : 2,8)
//4: (2,-8 : 5,8) (这个数据错了，你发现了吗？画个图就知道了！！)
//4: (-8,2 : 2,8)
//4: (5,0 : 8,3)