#include<bits/stdc++.h>
using namespace std;

/*####################################################
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#         https://github.com/parthlathiya            #
#                                                    #
####################################################*/


bool dp[1001][1001];

int main() {

	string s="cbbd";
	string ans=string(1, s[0]);
	
	for(int l=0;l<s.size();l++) {
		for(int i=0;i<s.size()-l;i++) {
			dp[i][i+l] = (i+l-1<0 || i+1>=i+l-1 || dp[i+1][i+l-1]) && (s[i]==s[i+l]);
			if(dp[i][i+l] && l+1>ans.size())
				ans=s.substr(i,l+1);
		}
	}
	cout<<ans<<endl;
}

/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/