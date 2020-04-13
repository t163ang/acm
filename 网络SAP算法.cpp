/*
注意到我们在某次增广后，最大流可能已经求出，因此算法做了许多无用功。可
以发现，距离标号是单调增的。这启示我们如果标号中存在“间隙”，则图中不
会再有可增广路，于是算法提前终止。实践中我们使用数组vh记录标号为i的
顶点个数，若重标号使得vh中原标号项变为0，则停止算法。
*/
int que[1000000],qh,qt;
int h[MN],num[MN];
int pre[MN];
void init(){
	qh = qt = 0;
	memset(h,-1,sizeof(h));
	memset(num,0,sizeof(num));
	h[T] = 0;
	que[qt++] = T;
	while(qh != qt){
		int u = que[qh++];
		for(int v = S; v <= 2 * N; v++){
			if(h[v] == -1 && map[v][u] > 0){
				h[v] = h[u] + 1;
				que[qt++] = v;
				num[h[v]]++;
			}
		}
	}
}

int find(int u){
	for(int v = S; v <= 2 * N; v++){
		if(map[u][v] > 0 && h[u] == h[v] + 1){
			return v;
		}
	}
	return -1;
}

int relable(int u){
	int minn = INF;
	for(int v = S; v <= 2 * N; v++){
		if(map[u][v] > 0 && minn > h[v]){
			 minn = h[v];
		}
	}
	if(minn != INF) return minn + 1;
	return 2 * N + 1;
}
int flow(){
	init();
	memset(pre,-1,sizeof(pre));
	int i = S,j,flow = 0;
	while(h[S] <= 2 * N){
		j = find(i);
		if(j >= 0){
			pre[j] = i;
			i = j;
			if(i == T){
				int minn = INF;
				i = T;
				while(i != S){
					if(minn > map[pre[i]][i]) minn = map[pre[i]][i];
					i = pre[i];
				}
				i = T;
				while(i != S){
					map[pre[i]][i] -= minn;
					map[i][pre[i]] += minn;
					i = pre[i];
				}
				flow += minn;
			}
		}else{
			int m = relable(i);
			num[m]++;
			num[h[i]]--;
			if(num[h[i]] == 0) return flow;
			h[i] = m;
			if(i != S){
				i = pre[i];
			}
		}
	}
	return flow;
}
//改进版
int minCut(){
	bfs();
	int u = S,fl = 0,aug = INF,cnt = 0; 
	bool flag;
	Edge *edg;
	memcpy(curHead,head,sizeof(head));
	while(h[S] <= T){
		flag = true;
		while((edg = curHead[u]) != NULL){
			int v = edg->v,c = edg->c;
			if(c > 0 && h[u] == h[v] + 1){
				flag = false;
				if(aug > c) aug = c;
				fro[cnt++] = edg;
				u = v;
				if(u == T){
					for(int i = 0; i < cnt; i++){
						fro[i]->c -= aug;
						fro[i]->rev->c += aug;
					}
					cnt = 0;
					fl += aug;
					aug = INF;
					u = S;				
					break;
				}
			}else{
				curHead[u] = curHead[u]->next;
			}
		}	
		if(flag){
			int minn = INF;
			for(edg = head[u];edg != NULL;edg=edg->next){
				if(edg->c > 0 && minn > h[edg->v]){
					minn = h[edg->v];
				}
			}
			if(minn == INF) return fl;
			minn++;
			num[minn]++;
			num[h[u]]--;
			if(!num[h[u]]) return fl;
			h[u] = minn;
			curHead[u] = head[u];
		}
	}
	return fl;
}