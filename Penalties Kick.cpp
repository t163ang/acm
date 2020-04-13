#include<iostream>
using namespace std;

bool play[5][30];
int mn = 1;
int main(){
	//freopen("in.txt","r",stdin);
	int t,i,j,k;
	scanf("%d",&t);
	char s[5];
	while(t--){
		for(i = 0; i < 22; i++){
			for(j = 0; j < 3; j++){
				scanf("%s",s);
				if(!strcmp(s,"yes")) play[j][i] = true;
				else play[j][i] = false;
			}
		}
		int r = 0,c = 0,home = 0,away = 0;
		bool flag = false;
		//kick 5
		for(i = 0; i < 5; i++){
			if(play[r][i]) home++;
			if(home > away + 5 - i || away > home + 4 - i){
				flag = true; 
				break;
			}
			if(play[r][i + 11]) away++;
			if(home > away + 4 - i || away > home + 4 - i){
				flag = true; 
				break;
			}		
		}

		if(!flag){
			while(home == away){
				r = i / 11, c = i % 11;
				if(play[r][c]) home++;
				if(play[r][c + 11]) away++;
				i++;
			}
		}
		printf("Match %d:\n",mn++);
		printf("Winner: %s\n",home > away ? "home":"away");
		printf("Score: %d:%d\n",home,away);
	}
	return 0;
}
/*
Input

The first line gives the number of test cases T, (1 ¡Ü T ¡Ü 1000), after the first line followed T cases. In each case, the first 11 lines give the kick results of the home team, in each line, there are 3 words(each word is either "yes" or "no") which indicates the result of the player's first kick, second kick and third kick(of course, the game would end before take three turns, but Doraemon always makes things bad). The next 11 lines give the kick result of the away team. Home team takes the kick first, and player kicks in the given order.

Output

For each case, output contains three lines. The first line is "Match #:", where "#" is the case number. The second line is the "Winner: winner_name", (winner_name is either "home" or "away"). The third line is the final score "Score: home_score:away_score".

Sample Input

1
yes yes yes
yes yes yes
yes no no
yes no no
yes no no
no no no
no no no
no no no
no no no
no no no
no no no
yes no no
no no no
no no no
yes no no
yes no no
yes yes yes
yes yes yes
yes yes yes
yes yes yes
yes yes yes
yes yes yes
Sample Output

Match 1:
Winner: home
Score: 4:1
*/