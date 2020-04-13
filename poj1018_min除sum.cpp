#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 120;
//the main meaning : compute max{min(bandwidth) / sum(price)}
//my solve way:	selcet the min(bandwidth) first, then select price greedily	
struct Dev{
	int bandwidth;
	int price;
	//bandwidth order by desc price order by asc
	bool operator<(const Dev dev)const{
		if(bandwidth != dev.bandwidth){
			return bandwidth > dev.bandwidth;
		}else{
			return price < dev.price;
		}
	}
}dev[MN][MN];

int main(){
	//freopen("in.txt","r",stdin);
	//Dev dev[3] = {{3,4},{3,3},{1,2}};
	//sort(dev,dev + 3);
	//for(int i = 0; i < 3; i++){
	//	printf("%d\t%d\n",dev[i].bandwidth,dev[i].price);
	//}
	int i,j;
	int t,n,mi,arr_mi[MN];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%d",&mi);
			arr_mi[i] = mi;
			for(j = 0;j < mi; j++){
				scanf("%d%d",&dev[i][j].bandwidth, &dev[i][j].price);
			}
			sort(dev[i],dev[i] + mi);
		}
		//int bandwidth,price;
		int minb,sump;
		double res = -1;
		for(i = 0; i < n; i++){
			//初始化minb和sump为一开始选择的设备，这个设备假设认为是所有选择设备中最小带宽的设备。
			for(j = 0; j < arr_mi[i]; j++){
				minb = dev[i][j].bandwidth;
				sump = dev[i][j].price;

				int ix,jx;
				for(ix = 0; ix < n; ix++){
					if (ix == i) continue;
					int min = INT_MAX;
					if(dev[ix][0].bandwidth < minb) break;//说明没有比最小带宽minb更大的型号
					else{
						for(jx = 0; jx < arr_mi[ix]; jx++){
							if(dev[ix][jx].bandwidth < minb) break;
							if(min > dev[ix][jx].price) min = dev[ix][jx].price;
						}
						sump += min;
					}
				}
				if(ix < n) continue;
				else{
					//printf("%.3f\n",minb / (double)sump);
					res = res > (minb / (double)sump) ? res : (minb / (double)sump);
				}
			}
		}
		printf("%.3f\n",res);
	}
	return 0;
}