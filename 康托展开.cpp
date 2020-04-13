//康托展开，求数列是第几大数
inline int Can(){
	int ct = 0;
	for(int i = 0; i < 8; i++){
		int tmp = 0;
		for(int j = i + 1; j < 9; j++){
			if(puzz[j] < puzz[i]) tmp++;
		}
		ct += tmp * cantor[i];
	}
	return ct;
}

//逆康托展开运算
int revCan(int ct){
	int i,j,v,u,ans;
	bool used[10] = {0};
	for(i = 0; i < 9; i++){
		v = ct / cantor[i];
		for(j = 1,u = 0; j <= 9; j++){		
			if(!used[j]){
				u++;
			}
			if(u == v + 1){			
				used[j] = true;
				puzz[i] = j;
				if(j == 9) ans = i;
				break;
			}
		}
		ct -= v * cantor[i];
	}
	return ans;
}
