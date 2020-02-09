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

	/*
             1
            / \
           2   3
          /
         4
        / \
       5   6
	*/
	vector<int> root = {1,2,3,4,-1,-1,-1,5,6}; // -1 means NULL
	int k=2;

	unordered_map<int,bool> children,v;
	vector<int> g[1000];
	int n=root.size();

	for(int i=1;i<n;i++) {
		if(root[i]!=-1) {
			g[root[i]].push_back(root[i/2]);
			g[root[i/2]].push_back(root[i]);
			if( (2*i>=n || (2*i<n && root[2*i]==-1)) && 
				(2*i+1>=n || (2*i+1<n && root[2*i+1]==-1)) )
				children[root[i]]=true;
		}
	}

	queue<int> q;
	q.push(k);

	while(!q.empty()) {
		int top = q.front();
		q.pop();
		if(v[top])
			continue;
		v[top]=1;
		if(children[top]) {
			cout<<top<<endl;
			break;
		}
		for(auto aa:g[top])
			if(!v[aa])
				q.push(aa);
	}
}

/*
742. Closest Leaf in a Binary Tree

Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.
Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
Note:
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.
*/