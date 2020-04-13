#include<iostream>
#include<algorithm>

using namespace std;
int num[300];
int main(){
	int n;
	int i,j,k;
	while(cin >> n && n){
		num[0] = 0;
		for(i = 1; i <= n; i++){
			cin >> num[i];
		}
		int movetime = 0;
		for(i = 1 ; i <= n; i++){
			if(num[i] > num[i - 1]) 
				movetime += (num[i] - num[i - 1]) * 6; 
			else movetime += (num[i - 1] - num[i]) * 4;
			movetime += 5;
		}

		cout<< movetime << endl;

	}
	return 0;
}