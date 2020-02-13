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
	
	vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};

	map<string, vector<string> > data;

	for(auto aa:v) {
		string temp = aa;
		sort(temp.begin(), temp.end());
		data[temp].push_back(aa);
	}

	for(auto aa:data) {
		for(auto bb:aa.second)
			cout<<bb<<" ";
		cout<<endl;
	}
}

/*
49. Group Anagrams

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/