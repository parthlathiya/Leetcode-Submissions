#include<bits/stdc++.h>
using namespace std;

/*####################################################
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#         https://github.com/parthlathiya            #
#                                                    #
####################################################*/

vector<vector<int> > grid;
int r=0,c=0;
string island;
bool v[51][51];

void dfs(int i, int j, char d) {
	if(i<0 || i>=r || j<0 || j>=c)
		return;
	if(v[i][j])
		return;
	v[i][j]=1;
	if(grid[i][j])
		island+=d;
	else
		return;
	dfs(i+1,j,'D');  // D - Down
	dfs(i-1,j,'U');
	dfs(i,j+1,'R');
	dfs(i,j-1,'L');
}


int main() {
	
	grid = { 
		{1,1,0,1,1},
		{1,0,0,0,0},
		{0,0,0,0,1},
		{1,1,0,1,1}
	};
	r=grid.size();
	if(r)
		c=grid[0].size();
	set<string> s;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(!v[i][j] && grid[i][j]) {
				island = "";
				dfs(i, j, 'S'); // S - start 
				s.insert(island);
			}
	cout<<s.size();
}

/*
694. Number of Distinct Islands

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/
