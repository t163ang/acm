<HTML>
<HEAD>
<META NAME="GENERATOR" Content="Microsoft Visual Studio 8.0">
<TITLE></TITLE>
</HEAD>
<BODY>
<h3>relabel-to-front</h3>
<p>
算法思想：
从源尽量地push,关键的地方是高度函数：h[S] = n;h[T] = 0;
只要h[u] == h[v] + 1才可以往下推，保证了u结点尽可能地向汇结点推进。
结果可能是e[u] == 0或e[u] > 0。对于前者，说明它已将所有库存push,符合流的性质;
对于后者，最后h[u] > h[S],将推回给源,若h[u] > h[s]说明此时已无法向前推进了，所以必须回流保证流的性质。
</p>
</BODY>
</HTML>
