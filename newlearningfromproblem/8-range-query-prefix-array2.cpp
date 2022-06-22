/*
Problem/Solution:
https://codeforces.com/contest/313/submission/161446868
*/
#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	// your code goes here
	string s;
	cin >> s;
	vector<int> pref(s.size(), 0);
	for(int i=1; i<s.size(); i++) {
	       pref[i] = pref[i-1] + (s[i] == s[i-1]);
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
