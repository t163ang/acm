#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 120;
const char months[19][10] ={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin","mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
const char names[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
const int Tzolkin_tot_day = 13 * 20;
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	int t,day,year;
	char month[10];
	while(~scanf("%d",&t)){
		printf("%d\n",t);
		for(i = 0; i < t; i++){
			scanf("%d.%s%d",&day,month,&year);
			int i_month = 0;
			for(i_month = 0; i_month < 19; i_month++){
				if(!strcmp(months[i_month],month)) break;
			}
			int tot = year * 365 + 20 * i_month + day;
			//printf("%d.%s%d",day,month,year);
			int T_year = tot / Tzolkin_tot_day;
			int T_name = tot % 20;
			int T_num = tot % 13 + 1;		
			printf("%d %s %d\n",T_num,names[T_name],T_year);
		}
	}
	return 0;
}