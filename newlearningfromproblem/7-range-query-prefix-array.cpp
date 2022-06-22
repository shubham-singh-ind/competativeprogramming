/*
##Learning##
Related problem: https://codeforces.com/problemset/problem/313/B
If we need to answer any range query, Try to create prefix or suffix sum array and get the answer.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin >> s;
	vector<int> pref(s.size(), 0);
	for(int i=1; i<s.size(); i++) {
	   if(s[i] == s[i-1]) {
	       pref[i] = pref[i-1] + 1;
	   }else {
	       pref[i] = pref[i-1];
	   }
	}

	int q;
	cin >> q;
	while(q--) {
	    int l, r;
	    cin >> l >> r;
        cout << pref[r-1]-pref[l-1] << endl;
	}
	return 0;
}
