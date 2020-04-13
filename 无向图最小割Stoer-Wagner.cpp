/*
Stoer-Wagner Algorithm��
�Á����һ���o��D������һ��Min-Cut��
��̎�ἰ��Cut����һ������Ҫ��һ�c�����҈D�ϵ�߅�ę��ؾ���ֵؓ��

ԭ��
��һ���o��D���У�߅�ę��ؽԷ�ֵؓ�����@���D���^Maximum Adjacency Search���õ��������x1-x2-��-xV��
���@���D�У�{x1 �� xV-1}�c{xV}�@һ��Cut���ؕ����@���D������xV-1��xV��Cut��ͬ�ȡ���Min-Cut ��

�r�g�}�s��:
�s��V�ε�Maximum Adjacency Search��������O((V^2) * V) = O(V^3)��
*/
int map[9][9];  // adjacency matrix 
int w[9];       // �o䛸����c��Ŀǰ��A���ϵľ��x 
bool visit[9];  // �o䛸����c�ǲ��������^ 
bool combine[9];    // �o䛸����c���ρ��^�˛] 

void maximum_adjacency_search(int& s, int& t, int& s_t_min_cut_cost) 
{ 
    for (int i=0; i<9; i++) visit[i] = false;  // initialize 
    for (int i=0; i<9; i++) w[i] = 0; 

    for (int i=0; i<V; ++i) 
    { 
        // �ҳ�һ����δ����A���С���w(A, x)����x�c�� 
        int a = 0, max = -1e9; 
        for (int j=0; j<V; ++j) 
            if (!combine[i] && !visit[i] && w[i] > max) 
                max = w[i], a = i; 

        visit[a] = true;    // ����a�c��A���� 

        s = t; t = a;   // ����o�Ŀǰ��Cutλ�� 
        s_t_min_cut_cost = w[t];    // ����o�Ŀǰ��Cut���� 

        // ����a�c��A�����ᣬ����w(A, x)��ֵ�� 
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
        // s�c��t�c��Cut��ͬ�� 
        int s, t, s_t_min_cut_cost; 
        maximum_adjacency_search(s, t, s_t_min_cut_cost); 
        if (s_t_min_cut_cost < ans) ans = s_t_min_cut_cost; 

        // s�c��t�c��Cutͬ�� 
        combine[t] = true;      // ��t�c��ӛ�鱻�ρ��^�ˣ�׃�ɲ����ڡ� 
        for (int i=0; i<V; ++i) // ��t�c�ρ���s�c�ᣬ����߅�ę���ֵ�� 
            if (!combine[i]) 
            { 
                map[i][s] += map[i][t]; 
                map[s][i] += map[t][i]; 
            } 
    } 
    cout << "Min-Cut�ę��؞�" << ans << endl; 
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