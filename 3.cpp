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
	string s = "abcabcbb";

	unordered_map<char,bool> hash_map;
	int j=1;
	string ans;
	int len=-1;
	hash_map[s[0]]=true;
	for(int i=0;i<s.size();i++) {
		while(j<s.size() && !hash_map[s[j]]) {
			hash_map[s[j]]=true;
			j++;
		}
		if(j-i>len) {
			len = j-i;
			ans = s.substr(i,j-i);
		}
		hash_map[s[i]]=false;
	}
	cout<<ans;
}

/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
