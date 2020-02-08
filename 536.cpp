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
	struct node *parent;
};

struct node *createNode(int value, struct node *parent) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->value = value;
	newNode->left=newNode->right=NULL;
	newNode->parent = parent;
	return newNode;
}

int main() {

	string s = "4(2(3)(1))(6(5))";
	struct node *tree = createNode(-1,NULL);
	struct node *root = tree;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9')
			tree->value = s[i]-'0';
		else if(s[i]=='(')
			if(!tree->left)
				tree = tree->left = createNode(-1,tree);
			else
				tree = tree->right = createNode(-1,tree);
 		else if(s[i]==')')
 			tree = tree->parent;
		
}

/*
536. Construct Binary Tree from String

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   
Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".
*/