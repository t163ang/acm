//网上的
//d[i][j]=d[i-1][j]+p[i][i-1];(1 <= j < i - 1)
//d[i][i-1]=min(d[i-1][k (j) ]+p[k (j) ][i]) (1 <= k(j) < i - 1)
//void DP()
//{
//    d[1][1]=0;
//    for (int i=2;i<=n;i++)
//        d[i][1]=p[i][1];
//    for (int i=2;i<n;i++)
//    {
//        d[i+1][i]=INT_MAX;
//        for (int j=1;j<=i-1;j++)
//        {
//            d[i+1][j]=d[i][j]+p[i][i+1];
//            d[i+1][i]=min(d[i+1][i],d[i][j]+p[j][i+1]);
//        }
//    }
//}


//我自己的
void dp(){
	b[2][1] = dist[1][2];
	for(int i =3;i <= n; i++){
		b[i][i - 1] = INT_MAX;
		for(int j = 1; j < i - 1; j++){
			b[i][j] = b[i - 1][j] + dist[i - 1][i];
			b[i][i - 1] = min(b[i][i - 1], b[i - 1][j] + dist[j][i]);
		}
	}
	b[n][n] = b[n][n - 1] + dist[n - 1][n];
}
//算法导论的
//for 1 ≤ i ≤ j ≤ n:
//b[1, 2] = |p1 p2| ,
//b[i, j ] = b[i, j − 1] +|pj−1 pj | for i < j − 1 ,
//b[ j − 1, j ] = min
//1≤k<j−1
//{b[k, j − 1] + |pk pj |} .
void dp(){
	b[1][2] = dist[1][2];
	for(j = 3; j <= n; j++){
		for(i = 1; i <= j - 2; i++){
			b[i][j] = b[i][j - 1] + dist[j - 1][j];
			//r[i][j] = j -1;
		}
		b[j - 1][j] = INT_MAX;
		for(k  = 1; k <= j -2; k++){
			int q = b[k][j - 1] + dist[k][j];
			if(q < b[j - 1][j])  {b[j - 1][j] = q;// r[j - 1][j] = k;}
			}
		}
		b[n][n] = b[n -1][n] + dist[n - 1][n];	
	}
}
//b[1, 2] ←|p1 p2|
//for j ← 3 to n
//do for i ← 1 to j − 2
//do b[i, j ] ← b[i, j − 1] +|pj−1 pj |
//r [i, j ] ← j − 1
//b[ j − 1, j ]←∞
//for k ← 1 to j − 2
//do q ← b[k, j − 1] +|pk pj |
//if q < b[ j − 1, j ]
//then b[ j − 1, j ] ← q
//r [ j − 1, j ] ← k
//b[n, n] ← b[n − 1, n] +|pn−1 pn|
//return b and r

//
//PRINT-TOUR(r, n)
//print pn
//print pn−1
//k ←r [n − 1, n]
//PRINT-PATH(r, k, n − 1)
//print pk
//PRINT-PATH(r, i, j )
//if i < j
//then k ←r [i, j ]
//print pk
//if k > 1
//then PRINT-PATH(r, i, k)
//else k ←r [ j, i ]
//if k > 1
//then PRINT-PATH(r, k, j )
//print pk
