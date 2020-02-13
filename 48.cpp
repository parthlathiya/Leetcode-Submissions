#include<bits/stdc++.h>
using namespace std;

/*####################################################
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#         https://github.com/parthlathiya            #
#                                                    #
####################################################*/

int main() {
	
	vector<vector<int> > v = {
		{ 5, 1, 9,11},
		{ 2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};


	int r = v.size();
	int c = v[0].size();


	for(int i=0;i<(r+1)/2;i++)
		for(int j=i;j<c-i-1;j++) {
			int temp = v[i][j];
			v[i][j] = v[r-1-j][i];
			v[r-1-j][i] = v[r-1-i][c-1-j];
			v[r-1-i][c-1-j] = v[j][c-1-i];
			v[j][c-1-i] = temp;
		}
	for(auto aa:v) {
		for(auto bb:aa)
			cout<<bb<<" ";
		cout<<endl;
	}

}

/*
48. Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/