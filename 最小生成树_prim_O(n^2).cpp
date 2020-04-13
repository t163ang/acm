int prim(int n){
	memset(vis,0,sizeof(vis));
	int i,j,u = 0,len = 0;
	vis[u] = true;
	for(i = 0; i < n; i++){
		lowcost[i] = dist[u][i];
	}
	for(j = 1; j < n; j++){
		int min = INT_MAX;
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] < min){
				min = lowcost[i];
				u = i;
			}
		}
		if(len < lowcost[u]) len = lowcost[u];
		vis[u] = true;
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] > dist[u][i]){
				lowcost[i] = dist[u][i];
			}
		}
	}
	return len;
}