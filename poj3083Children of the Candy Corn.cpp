#include<iostream>
#include<queue>


//(-1,0) (0,1) (1,0) (0,-1)������ʱ������ʱ�룬ÿ���ߵ���ͷʱ����ʱ��ת��(dir + 1) % 4,ͬ������ʱ��˳ʱ�����ǣ�dir + 3�� % 4
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n,w,h;
char maze[50][50];
int sx,sy,ex,ey;
int dir, hand,step;


bool dfs(int x, int y){
	if(maze[x][y] == '#' || x < 1 || y < 1 || x > h || y > w) return false;
	step++;
	if(maze[x][y] == 'E') {printf("%d ",step); return true;}
	dir = (dir - hand + 4) % 4; //�����ң�ת	
	while(true){	
		if(dfs(x + dx[dir], y + dy[dir])) return true;  
		dir = (dir + hand) % 4;//�������ң���ת
	}
}


bool place(int x, int y){
	if(maze[x][y] == '#' || x  < 1 || y < 1 || x > h || y > w) return false;
	return true;
}


struct Poi{
	int x, y, step;
	Poi(int x, int y, int step):x(x),y(y),step(step){}
};

void bfs(int sx, int sy){
	std::queue<Poi > que; 
	que.push(Poi(sx,sy,1));
	while(!que.empty()){
		Poi poi = que.front();
		int x = poi.x, y = poi.y, step = poi.step;
		que.pop();
		for(int j = 0; j < 4; j++){
			int x2 = x + dx[j], y2 = y + dy[j];
			if(place(x2,y2)) {
				if(maze[x2][y2] == 'E') {printf("%d\n",step + 1); return;}
				maze[x2][y2] = '#';
				que.push(Poi(x2,y2,step + 1));
			}
		}
	}
	
}



int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		scanf("%d%d",&w,&h);
		for(j = 1; j <= h; j++){
			for(k = 1; k <= w; k++){
				scanf(" %c",&maze[j][k]);
				if(maze[j][k] == 'S') sx = j, sy = k;
			}
		}
		dir = 0, hand = 1,step = 0;
		dfs(sx,sy);
		dir = 0, hand = 3,step = 0;
		dfs(sx,sy);
		bfs(sx,sy);
	}

}

/*
Description

The cornfield maze is a popular Halloween treat. Visitors are shown the entrance and must wander through the maze facing zombies, chainsaw-wielding psychopaths, hippies, and other terrors on their quest to find the exit. 

One popular maze-walking strategy guarantees that the visitor will eventually find the exit. Simply choose either the right or left wall, and follow it. Of course, there's no guarantee which strategy (left or right) will be better, and the path taken is seldom the most efficient. (It also doesn't work on mazes with exits that are not on the edge; those types of mazes are not represented in this problem.) 

As the proprieter of a cornfield that is about to be converted into a maze, you'd like to have a computer program that can determine the left and right-hand paths along with the shortest path so that you can figure out which layout has the best chance of confounding visitors.
Input

Input to this problem will begin with a line containing a single integer n indicating the number of mazes. Each maze will consist of one line with a width, w, and height, h (3 <= w, h <= 40), followed by h lines of w characters each that represent the maze layout. Walls are represented by hash marks ('#'), empty space by periods ('.'), the start by an 'S' and the exit by an 'E'. 

Exactly one 'S' and one 'E' will be present in the maze, and they will always be located along one of the maze edges and never in a corner. The maze will be fully enclosed by walls ('#'), with the only openings being the 'S' and 'E'. The 'S' and 'E' will also be separated by at least one wall ('#'). 

You may assume that the maze exit is always reachable from the start point.
Output

For each maze in the input, output on a single line the number of (not necessarily unique) squares that a person would visit (including the 'S' and 'E') for (in order) the left, right, and shortest paths, separated by a single space each. Movement from one square to another is only allowed in the horizontal or vertical direction; movement along the diagonals is not allowed.
Sample Input

2
8 8
########
#......#
#.####.#
#.####.#
#.####.#
#.####.#
#...#..#
#S#E####
9 5
#########
#.#.#.#.#
S.......E
#.#.#.#.#
#########
Sample Output

37 5 5
17 17 9
*/