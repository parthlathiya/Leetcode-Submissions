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
	vector<int> v = {1,2,3,4};
	vector<int> ans(v.size(), 0);
	int r=1;

	ans[0]=1;
	for(int i=1;i<v.size();i++)
		ans[i] = ans[i-1] * v[i-1];
	for(int i=v.size()-2;i>=0;i--) {
		r = r * v[i+1]; 
		ans[i] = ans[i] * r;
	}
	for(int i=0;i<v.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}

/*
238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/