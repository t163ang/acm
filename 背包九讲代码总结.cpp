
//procedure ZeroOnePack(cost,weight)
//    for v=V..cost
//        f[v]=max{f[v],f[v-cost]+weight}
//
//procedure CompletePack(cost,weight)
//    for v=cost..V
//        f[v]=max{f[v],f[v-c[i]]+w[i]}
//
//procedure MultiplePack(cost,weight,amount)
//    if cost*amount>=V
//        CompletePack(cost,weight)
//        return
//    integer k=1
//    while k<amount
//        ZeroOnePack(k*cost,k*weight)
//        amount=amount-k
//        k=k*2
//    ZeroOnePack(amount*cost,amount*weight)


void ZeroOnePack(cost,weigth){
	for(int j = V; j >= cost; j++){
		dp[j] = max(dp[j],dp[j - cost] + weight);
	}
}

void CompletePack(cost,weight){
	for(int j = cost; j <= V; j++){
		dp[j] = max(dp[j],dp[j - cost] + weight);
	}
}

void MultiplePack(cost,weight,amount){
	if(cost * amount >= V){
		CompletePack(cost,weight);
		return;
	}
	int k = 1;
	while(k < amount){ //������<����<=����Ϊ����<=ʱ�������ܳ���ZeroOnePack(0,0);
		ZeroOnePack(k * cost,k * weight);
		amount -= k;
		k *= 2;
	}
	ZeroOnePack(amount * cost,amount * weight);
}
