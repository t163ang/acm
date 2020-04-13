#include<iostream>
#include<cstring>
using namespace std;

int max(int a, int b){
	if(a > b) return a;
	return b;
}

char a[1100],b[1100];
int m[2][1100];
int main(){
	int t,i,j;
	cin >> t;
	while(t--){
		memset(m,0,sizeof(m));
		cin >> a >> b;
		int lena = strlen(a), lenb = strlen(b);
		for(i = 1; i <= lena; i++){
			for(j = 1; j <= lenb; j++){
				if(a[i - 1] == b[j - 1]) m[i % 2][j] = m[(i - 1) % 2][j - 1] + 1;
				else{
					m[i % 2][j] = max(m[(i - 1) %2][j], m[i % 2][j - 1]);
				}
			}
		}
		cout << m[lena % 2][lenb] << endl;
	}
	return 0;
}