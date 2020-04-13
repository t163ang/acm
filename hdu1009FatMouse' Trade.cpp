#include<iostream>
#include<algorithm>
using namespace std;

struct Food{
	int f;
	int j;
	double t;
	bool operator < (const Food &p) const{
		return t > p.t;
	}
}food[2000];
int m,n;
int main(){
	int i,k;
	while(cin >> m >> n && (m != - 1 || n != -1)){
		for(i = 0; i < n; i++){
			cin >> food[i].j>>food[i].f;
			food[i].t = (double)food[i].j / food[i].f;
		}
		sort(food,food + n);
		k = m;
		double get = 0;
		for(i = 0; i < n; i++){
			if(food[i].f > k) break;
			k -= food[i].f;
			get += food[i].j;
		}
		if(k > 0 && i < n){
			get += food[i].j * (double)k / food[i].f;
		}
		printf("%.3f\n",get);
	}
	return 0;
}