#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

struct Bank{
	int k,p;
	bool operator < (const Bank b) const{
		return p < b.p;
	}
	Bank(int k, int p):k(k),p(p){}
};

int main(){
	//freopen("in.txt","r",stdin);
	set<Bank> s;
	set<Bank>::iterator it;
	s.clear();
	int i,k,p;
	while(scanf("%d",&i),i){
		if(i == 1){
			scanf("%d%d",&k,&p);
			s.insert(Bank(k,p));
		}else if(i == 2){
			if(!s.size()) printf("0\n");
			else{
				it = s.end();
				it--;
				printf("%d\n",(*it).k);
				s.erase(*it);
			}
		}else{
			if(!s.size()) printf("0\n");
			else{
				it = s.begin();
				printf("%d\n",(*it).k);
				s.erase(*it);
			}
		}
	}
	return 0;
}
/*
0 The system needs to stop serving 
1 K P Add client K to the waiting list with priority P 
2 Serve the client with the highest priority and drop him or her from the waiting list 
3 Serve the client with the lowest priority and drop him or her from the waiting list 

2
1 20 14
1 30 3
2
1 10 99
3
2
2
0
Sample Output

0
20
30
10
0

#include<iostream>
#include<set>
using namespace std;

typedef struct
{
int k,p;
}settype;

bool operator <(const settype& a,const settype& b)
{
return a.p>b.p;
}

set <settype> sset;
set <settype>::iterator pset;
settype temp;

int main()
{
freopen("in.txt","r",stdin);
int i;
sset.clear();
while(scanf("%d",&i)!=EOF)
{
   if(i==0) 
   break;
   if(i==1) 
   { 
     scanf("%d%d",&temp.k,&temp.p); 
sset.insert(temp); 
   }
   else if(i==2) 
   { 
    if(sset.size()==0) 
   printf("0\n"); 
    else
{ 
   temp=*sset.begin(); 
   printf("%d\n",temp.k); 
   sset.erase(sset.begin()); 
}
   }
   else if(i==3)
   { 
    if(sset.size()==0)
    printf("0\n"); 
    else
{ 
   pset=sset.end(); 
   pset--; 
   temp=*pset; 
   printf("%d\n",temp.k);
    sset.erase(temp); 
}
   }
}

return 0;
}


*/
