#include<iostream>
#include<queue>
using namespace std;
int width,height;
int map[30][30];
int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
int mintimes;

void dfs(int h,int w, int step){
	if(step >= mintimes || step > 10) return;
	if(map[h][w] == 3){
		if(mintimes > step)  mintimes = step;
		return;
	}
	for(int i = 0; i < 4; i++){
		int th = h ,tw = w;
		while(!map[th += dir[i][0]][tw += dir[i][1]]);
		if(map[th][tw] == 3) dfs(th,tw,step + 1);
		else if(map[th][tw] == 1){
			int ta = th - dir[i][0], tb = tw - dir[i][1];
			if(ta == h && tb == w) continue;
			map[th][tw] = 0;
			dfs(ta,tb,step + 1);
			map[th][tw] = 1;
		}
	}
	
}

int main(){
	int i,j;
	int sh,sw;
	while(scanf("%d%d",&width,&height),width || height){
		memset(map,1,sizeof(map));
		for(i = 1; i <= height; i++){
			for(j = 1; j <= width; j++){
				scanf("%d",&map[i][j]);
				if(map[i][j] == 2) {
					sh = i, sw = j;
					map[i][j] = 0;
				}
			}
		}
		mintimes = INT_MAX;
		dfs(sh,sw,0);
		if(mintimes <= 10) printf("%d\n",mintimes);
		else printf("-1\n");
	}
	return 0;
}

//bool isok(int h, int w, int dh,int dw, int &sh, int &sw){ 	
//	if(map[h + dh][w + dw] == 1) return false;
//	while(h <= height && w <= width && h >= 1 && w >= 1){
//		if(map[h][w] == 3 || map[h][w] == 1){
//			sh = h; 
//			sw = w;
//			if(map[h][w] == 1) {
//				map[h][w] = 0;
//				sw -= dw, sh -= dh;
//			}
//			return true;
//		}
//		h += dh; w += dw;
//	}
//	return false;
//}
//
//
//struct Poi{
//	int h,w,step;
//	Poi(int h,int w,int step):h(h),w(w),step(step){}
//};
//void bfs(int height, int width){
//	std::queue<Poi > que;
//	que.push(Poi(height,width,0));
//	while(!que.empty()){
//		Poi p = que.front();que.pop();
//		int h = p.h, w = p.w, step = p.step;	
//		for(int i = 0; i < 4; i++){
//			int th = h ,tw = w;
//			while(!map[th += dir[i][0]][tw += dir[i][1]]);
//			if(map[th][tw] == 3) { printf("%d\n",step + 1); return; }
//			else if(map[th][tw] == 1){
//				int ta = th - dir[i][0], tb = tw - dir[i][1];
//				if(ta == h && tb == w) continue;
//				que.push(Poi(ta,tb,step + 1));
//				map[th][tw] = 0;
//			}
//		}
//	}
//	printf("-1\n");
//}

之前wa的现在改了ac了
//#include<iostream>
//int w,h;
//int map[30][30];
//int dw[6]={0,1,0,-1},dh[6]={1,0,-1,0};
//int times;
//int mintimes;
//bool isok(int starth, int startw, int dh, int dw, int &sh, int &sw, int &kind){ 
//	if(map[starth + dh][startw + dw] == 1) return false;
//	while(starth <= h && startw <= w && starth >= 1 && startw >= 1){
//		if(map[starth][startw] == 3 || map[starth][startw] == 1){
//			sh = starth; 
//			sw = startw;
//			kind = 1;
//			if(map[starth][startw] == 1) {
//				map[starth][startw] = 0;
//				sw -= dw, sh -= dh;
//				kind = 2;
//			}
//			return true;
//		}
//		starth += dh; startw += dw;
//	}
//	return false;
//
//}
//
//void dfs(int height,int width){
//	if(times >= mintimes || times > 10) return;
//	if(map[height][width] == 3){
//		if(mintimes > times)  mintimes = times;
//		return;
//	}
//	int i,sh,sw,kind;
//	for(i = 0; i < 4; i++){
//		if(isok(height, width,dh[i],dw[i],sh,sw,kind)){
//			times++;
//			dfs(sh,sw);
//			if(kind == 2) map[sh + dh[i]][sw + dw[i]] = 1;	
//			times--;
//		}
//	}
//	
//}
//
//
//int main(){
//	int i,j;
//	int sh,sw;
//	while(scanf("%d%d",&w,&h),w || h){
//		memset(map,0,sizeof(map));
//		for(i = 1; i <= h; i++){
//			for(j = 1; j <= w; j++){
//				scanf("%d",&map[i][j]);
//				if(map[i][j] == 2) 
//				{
//					sh = i, sw = j;
//					map[i][j] = 0;
//				}
//			}
//		}
//		times = 0;
//		mintimes = INT_MAX;
//		dfs(sh,sw);
//		if(mintimes <= 10) printf("%d\n",mintimes);
//		else printf("-1\n");
//	}
//}
