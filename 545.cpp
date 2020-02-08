#include<bits/stdc++.h>
using namespace std;

/*####################################################
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#         https://github.com/parthlathiya            #
#                                                    #
####################################################*/

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

vector<int> left_bound, left_leaves, right_bound, right_leaves;
int left_most_child_found=0, right_most_child_found=0;

void dfsLeft(struct node *p) {
	if (!p)
		return;
	if(!p->left && !p->right) {
		left_most_child_found=1;
		left_leaves.push_back(p->value);
	}
	if(!left_most_child_found)
		left_bound.push_back(p->value);
	dfsLeft(p->left);	
	dfsLeft(p->right);	
}

void dfsRight(struct node *p) {
	if (!p)
		return;
	if(!p->left && !p->right) {
		right_most_child_found=1;
		right_leaves.insert(right_leaves.begin(), p->value);
	}
	if(!right_most_child_found)
		right_bound.insert(right_bound.begin(), p->value);
	dfsRight(p->right);	
	dfsRight(p->left);	
}


int main() {

	struct node *root = createNode(1);
	root->left = createNode(7);
	root->right = createNode(5);
	root->left->left= createNode(7);
	root->right->left= createNode(6);
	root->right->right = createNode(4);

	dfsLeft(root->left);
	dfsRight(root->right);
	cout<<root->value;
	for(auto aa:left_bound)
		cout<<" "<<aa;
	for(auto aa:left_leaves)
		cout<<" "<<aa;
	for(auto aa:right_leaves)
		cout<<" "<<aa;
	for(auto aa:right_bound)
		cout<<" "<<aa;

}

/*
545. Boundary of Binary Tree

Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1
Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
Example 2
Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
*/
