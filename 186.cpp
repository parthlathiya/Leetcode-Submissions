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

	string s = "the sky is blue";

	while(s.size() && s[0]==' ')s.erase(0,1);
	
	while(s.size() && s[s.size()-1]==' ')s.erase(s.size()-1,1);
	
	int i,j;
	i=0;
	while(i<int(s.size()-1)) {
		if(s[i]==' ' && s[i+1]==' ')
			s.erase(i,1);
		else
			i++;
	}
	
	reverse(s.begin(), s.end());
	i=0;
	while(i<s.size())
	{
		j=i;
		while(j<s.size() && s[j]!=' ')j++;
		reverse(s.begin()+i,s.begin()+j);
		j++;
		i=j;
	}
	cout<<s;

}

/*
186. Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
*/