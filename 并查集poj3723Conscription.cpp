#include<iostream>
#include<algorithm>

const int MN = 20100;
int par[MN];
int rank[MN];
int find(int x){
	if(x != par[x]) par[x] = find(par[x]);
	return par[x];
}
int cons = MN;//这里要初值，main里也要
int cost = 100000;
void un(int x, int y, int d){	
	x =  find(x), y = find(y);
	if(x == y) return;
	if(rank[x] > rank[y]) par[y] = x;
	else{
		par[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	cons--;
	cost -= d;
}

struct Rla{
	int x,y,d;
	bool operator < (const Rla a) const{
		return d > a.d;
	}
}rla[50100];
int n,m,r;

int main(){
	//freopen("in.txt","r",stdin);
	int t,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&r);
		cons = n + m, cost = 10000 * cons;
		memset(rank,0,sizeof(rank));
		for(i = 0; i < cons; i++) par[i] = i;

		for(i = 0; i < r; i++){
			scanf("%d%d%d",&rla[i].x,&rla[i].y,&rla[i].d);
		}

		std::sort(rla,rla + r);
		
		for(i = 0; i < r && cons > 1; i++){
			un(rla[i].x,rla[i].y + n,rla[i].d);
		}
		printf("%d\n",cost);
	}
	
	return 0;
}
/*
Input

The first line of input is the number of test case.
The first line of each test case contains three integers, N, M and R.
Then R lines followed, each contains three integers xi, yi and di.
There is a blank line before each test case.


1 ≤ N, M ≤ 10000
0 ≤ R ≤ 50,000
0 ≤ xi < N
0 ≤ yi < M
0 < di < 10000


Output

For each test case output the answer in a single line.
Sample Input

2

5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781

5 5 10
2 4 9820
3 2 6236
3 1 8864
2 4 8326
2 0 5156
2 0 1463
4 1 2439
0 4 4373
3 4 8889
2 4 3133

Sample Output

71071
54223

*/