#include<bits/stdc++.h>
using namespace std;

/*####################################################
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#         https://github.com/parthlathiya            #
#                                                    #
####################################################*/

vector<string> word_dict;
unordered_map<string, bool> hash_map;
unordered_map<string, bool> memo;

bool is_breakable(string s) {
    if(memo.count(s)>0)
        return memo[s];
    if(s=="")
        return memo[s]=true;
    bool temp = false;
    for(int i=1;i<=s.size();i++)
        temp = temp || (hash_map[s.substr(0,i)] && is_breakable(s.substr(i,s.size()-i)));
    return memo[s]=temp;
}

int main() {
	string s = "catsandog";
	word_dict = {"cats", "dog", "sand", "and", "cat"};
	for(auto word:word_dict)
		hash_map[word]=true;
	cout<<((is_breakable(s)==1)?"true":"false")<<endl;
}

/*
139. Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/