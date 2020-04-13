/*
Stoer-Wagner Algorithm：
用來求出一張無向圖的其中一個Min-Cut。
此處提及的Cut其中一側至少要有一點，而且圖上的邊的權重均非負值。

原理：
在一張無向圖當中，邊的權重皆非負值，令這張圖經過Maximum Adjacency Search所得到的順序是x1-x2-…-xV。
在這張圖中，{x1 … xV-1}與{xV}這一個Cut，必會是這張圖「限制xV-1和xV在Cut不同側」的Min-Cut 。

時間複雜度:
約是V次的Maximum Adjacency Search，總共是O((V^2) * V) = O(V^3)。
*/
int map[9][9];  // adjacency matrix 
int w[9];       // 紀錄各個點到目前的A集合的距離 
bool visit[9];  // 紀錄各個點是不是已找過 
bool combine[9];    // 紀錄各個點被合併過了沒 

void maximum_adjacency_search(int& s, int& t, int& s_t_min_cut_cost) 
{ 
    for (int i=0; i<9; i++) visit[i] = false;  // initialize 
    for (int i=0; i<9; i++) w[i] = 0; 

    for (int i=0; i<V; ++i) 
    { 
        // 找出一個尚未加入A當中、且w(A, x)最大的x點。 
        int a = 0, max = -1e9; 
        for (int j=0; j<V; ++j) 
            if (!combine[i] && !visit[i] && w[i] > max) 
                max = w[i], a = i; 

        visit[a] = true;    // 加入a點到A集合 

        s = t; t = a;   // 不斷紀錄目前的Cut位置 
        s_t_min_cut_cost = w[t];    // 不斷紀錄目前的Cut權重 

        // 加入a點到A集合後，更新w(A, x)的值。 
        for (int b=0; b<V; ++b) 
            if (!combine[i] && !visit[b]) 
                w[b] += map[a][b]; 
    } 
} 

void stoer_wagner() 
{ 
    for (int i=0; i<9; ++i) combine[i] = false; 

    int ans = 0; 
    for (int k=0; k<V-1; ++k) 
    { 
        // s點和t點在Cut不同側 
        int s, t, s_t_min_cut_cost; 
        maximum_adjacency_search(s, t, s_t_min_cut_cost); 
        if (s_t_min_cut_cost < ans) ans = s_t_min_cut_cost; 

        // s點和t點在Cut同側 
        combine[t] = true;      // 把t點標記為被合併過了，變成不存在。 
        for (int i=0; i<V; ++i) // 把t點合併至s點後，更新邊的權重值。 
            if (!combine[i]) 
            { 
                map[i][s] += map[i][t]; 
                map[s][i] += map[t][i]; 
            } 
    } 
    cout << "Min-Cut的權重為" << ans << endl; 
}



const int MN = 524;
int map[MN][MN];
int n,m,V;
int w[MN];
bool combine[MN];
bool vis[MN];
int madj(int &s,int &t){
	memset(w,0,sizeof(w));
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < V; i++){
		int u = -1,maxx = -1;
		for(int j = 0; j < V; j++){
			if(!combine[j] && !vis[j] && w[j] > maxx){
				maxx = w[j];
				u = j;
			}
		}
		if(u == -1) return w[t];
		vis[u] = true; s = t; t = u;
		for(int j = 0; j < V;j++){
			if(!combine[j] && !vis[j]){
				w[j] += map[t][j];
			}
		}
	}
	return w[t];
}
int minCut(){
	int ans = INT_MAX;
	memset(combine,0,sizeof(combine));
	for(int i = 1; i < V; i++){
		int s = -1,t = -1,cut;
		cut = madj(s,t);
		combine[t] = true;
		if(ans > cut) ans = cut;
		for(int j = 0; j < V; j++){
			if(!combine[j]){
				map[s][j] += map[t][j];
				map[j][s] += map[j][t];
			}
		}
	}
	return ans;
}