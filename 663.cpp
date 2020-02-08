#include<bits/stdc++.h>
using namespace std;

/*####################################################
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#         https://github.com/parthlathiya            #
#                                                    #
####################################################*/


unordered_map<int, std::vector<int> > sum;
struct node {
	int value;
	struct node *left;
	struct node *right;
};


struct node *createNode(int data) {
	struct node *newNode =  (struct node *)malloc(sizeof(struct node));
	newNode->value = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

int subtreeSum(int idx, struct node *root) {
	if (root==NULL)
		return 0;
	int s = root->value + subtreeSum(idx*2, root->left) + subtreeSum(idx*2+1, root->right); 
	sum[s].push_back(idx);
	return s;
}

int main() {

	struct node *root = createNode(1);
	root->left = createNode(7);
	root->right = createNode(5);
	root->left->left= createNode(7);
	root->right->left= createNode(6);
	root->right->right = createNode(4);
	int total = subtreeSum(1, root);

	if (total%2==0) {
		if (sum[total/2].size()==0)
			cout<<-1;
		else {
			for(auto aa:sum[total/2])
				cout<<"Edge between node "<<aa<<" and "<<aa/2<<endl;
		}
	}
	else
		cout<<-1;
}


/*
663. Equal Tree Partition

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
*/