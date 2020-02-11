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

	vector<int> a = {-1, 0, 1, 2, -1, -4};
	unordered_map<int,int> count;
	set<vector<int> > ans;

	for(int i=0;i<a.size();i++)
		count[a[i]]++;

	for(int i=0;i<a.size();i++) {
		for(int j=i+1;j<a.size();j++) {
			count[a[i]]--;
			count[a[j]]--;
			if(count[-1*(a[i]+a[j])]>0) {
				vector<int> v = {a[i],a[j],-1*(a[i]+a[j])};
				sort(v.begin(), v.end());
				ans.insert(v);
			}
			count[a[i]]++;
			count[a[j]]++;
		}
	}

	for(auto arr:ans) {
		for(auto ele:arr)
			cout<<ele<<" ";
		cout<<endl;
	}
}

/*
15. 3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/