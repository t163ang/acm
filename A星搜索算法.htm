<HTML>
<HEAD>
<META NAME="GENERATOR" Content="Microsoft Visual Studio 8.0">
<TITLE></TITLE>
</HEAD>
<BODY>
<h2>A*搜索算法</h2>
<p>
网上有一篇A* Pathfinding for Beginners是经典的入门
</p>
<h3>总结</h3>
<p>
A*算法就像BFS，也是通过队列取出一个node后，将它附近邻接的node插入队列。但A*算法不是盲目地向
搜索，而是根据一个启发式函数F = G + H来计算最优值来选取队列一个node来扩展，利用启发式函数可以
以更快或者更接近地向目标（target）靠近，加快了搜索速度。
</p>
<h3>Note</h3>
<p>
Note: In earlier versions of this article, it was suggested that you can stop when the target square (or node)
has been added to the open list, rather than the closed list.  Doing this will be faster and it will almost always
give you the shortest path, but not always. Situations where doing this could make a difference are when the 
movement cost to move from the second to the last node to the last (target) node can vary significantly -- as 
in the case of a river crossing between two nodes, for example.
</p>
<h2>Question:</h2>
<h3>target要加入closed listed而不是open list,才能终止呢</h3>
<p>
你可能会想bfs在第一次搜索到target便可以停止搜索了，而此时也就是最短路径了。bfs第一次搜索便可以停止是因为它是从里到外，
全面搜索扩展下去的，换句话它是按离start由近及远逐步搜索下去的。<br />
可是A*算法没有bfs那按路径递增的方式搜索特征，而是按启发式函数计算值来扩展的，故不能第一次搜索到target便认为是最短路径。
那么再来分析一下为什么到达closed listed便可以终止呢？我们知道A*利用启发式函数F = G + H最优值来扩展的，且0 <= h(n) <= h*(n) （h*(n)为实际问题的代价值）。
即H的可接纳性，所以当target到达closed listed时有G <= G' + H' <= G''。
</p>
<p>
*算法，作为启发式算法中很重要的一种，被广泛应用在最优路径求解和一些策略设计的问题中。而A*算法最为核心的部分，就在于它的一个估值函数的设计上：
f(n)=g(n)+h(n)
其中f(n)是每个可能试探点的估值，它有两部分组成：一部分为g(n)，它表示从起始搜索点到当前点的代价（通常用某结点在搜索树中的深度来表示）。
另一部分，即h(n)，它表示启发式搜索中最为重要的一部分，即当前结点到目标结点的估值，h(n)设计的好坏，直接影响着具有此种启发式函数的启发式算法的是否能称为A*算法。
</p>
<p>
一种具有f(n)=g(n)+h(n)策略的启发式算法能成为A*算法的充分条件是：
1)搜索树上存在着从起始点到终了点的最优路径。
2) 问题域是有限的。
3）所有结点的子结点的搜索代价值>0。
4）h(n)<= h*(n) （h*(n)为实际问题的代价值）。
当此四个条件都满足时，一个具有f(n)=g(n)+h(n)策略的启发式算法能成为A*算法，并一定能找到最优解。
</p>
<p>
对于一个搜索问题，显然，条件1,2,3都是很容易满足的，而条件4)： h(n)<=h*(n)是需要精心设计的，由于h*(n)显然是无法知道的，
所以，一个满足条件4）的启发策略h(n)就来的难能可贵了。不过，对于图的最优路径搜索和八数码问题，有些相关策略h(n)不仅很好理解，
而且已经在理论上证明是满足条件4)的，从而为这个算法的推广起到了决定性的作用。不过h(n)距离h*(n)的呈度不能过大，
否则h(n)就没有过强的区分能力，算法效率并不会很高。对一个好的h(n)的评价是：h(n)在h*(n)的下界之下，并且尽量接近h*(n).
</p>
<p>
当然，估值函数的设计也就就仅仅是f(n)=g(n)+h(n)一种，另外的估值函数“变种”如：f(n)=w*g(n)+(1-w)*h(n) ，f(n)=g(n)+h(n)+h(n-1)针对不同的具体问题亦会有不同的效果。
</p>
</BODY>
</HTML>
