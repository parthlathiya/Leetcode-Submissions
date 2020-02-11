#include<bits/stdc++.h>
using namespace std;

/*####################################################
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#         https://github.com/parthlathiya            #
#                                                    #
####################################################*/

unordered_map<char, string> data;
vector<string> ans;

void fun(string s, string str) {
	if(s=="") {
		ans.push_back(str);
		return;
	}
	for(int i=0;i<data[s[0]].size();i++)
		fun(s.substr(1,s.size()-1), str+data[s[0]][i]);
}

int main() {
	string s = "234";

	data['2'] = "abc";
	data['3'] = "def";
	data['4'] = "ghi";
	data['5'] = "jkl";
	data['6'] = "mno";
	data['7'] = "pqrs";
	data['8'] = "tuv";
	data['9'] = "wxyz";

	fun(s,"");
	for(auto aa:ans)
		cout<<aa<<" ";
	cout<<endl;
}

/*
17. Letter Combinations of a Phone Number


Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

2 -> abc
3 -> def
4 -> ghi
5 -> jkl
6 -> mno
7 -> pqrs
8 -> tuv
9 -> wxyz

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/