#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char x[1008];
char y[1008];
int m[1008][1008];
int main(){
	int i,j;
	while(cin >> x >> y){
		memset(m,0,sizeof(m));
		int lenx = strlen(x), leny = strlen(y);
		for(i = 0; i < lenx;  i++){
			for(j = 0; j < leny; j++){
				if(x[i] == y[j]) m[i][j] = m[i - 1][j - 1] + 1;//注意这个式子错because when i == 1 , this is out of array bounds in m[i - 1][j - 1]
				else {				
					m[i][j] =  (m[i - 1][j] > m[i][j - 1] ? m[i - 1][j] : m[i][j - 1]);
			    }
			}
		}
		if(lenx >= 1 && leny >= 1)
		cout << m[lenx - 1][leny - 1] << endl;

	}
	return 0;
}