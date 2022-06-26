/*
##Learning##
Problem: https://codeforces.com/problemset/problem/1360/C
User binary search / unordered_map search to find target.
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long int
#define f(a,b,c) for(int i=a; i<b; i+=c)
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(),a.end()
#define desc(a) greater<a>()
#define pi pair<int,int>

const int MOD = 1e9 + 7;

// Time: O(nlogn)
// Space: O(1)
pi getPairWithDiffK(vi v, int k) {
	sort(all(v));
	int l=0, r=1;
	while(l <= r && r<v.size()) {
		int absdiff = abs(v[l]-v[r]);
		if(absdiff == k && l!=r) {
			return {v[l], v[r]};
		}
		if(absdiff > k) {
			l++;
		}else {
			r++;
		}
	}
	return {-1, -1};
}

// Time: O(nlogn) / O(n) -> If used unordered_set
// Space: O(n)
pi getPairWithDiffKDP(vi v, int k) {
	set<int> s;
	f(0, v.size(), 1) {
		int absdiff = abs(v[i]-k);
		if(s.find(absdiff) != s.end()) {
			return {v[i], absdiff};
		}else if(s.find(absdiff) != s.end()) {
			return {v[i], absdiff};
		}else {
			s.insert(v[i]);
		}
	}
	return {-1, -1};
}

void solve() {
	int n;
	cin >> n;
	vi v(n);
	int odds=0,evens=0;
	f(0, n, 1) {
		cin >> v[i];
		odds += (v[i]&1);
		evens += !(v[i]&1);
	}
	odds = odds%2;
	evens = evens%2;
	if(odds+evens == 2) {
		pi p = getPairWithDiffK(v, 1);
		cout << (p.first!=-1 ? "YES" : "NO");
	}else {
		cout << ((odds+evens==0)?"YES":"NO");
	}
	cout << endl;
}

void init() {
	// fast IO
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 	#ifndef ONLINE_JUDGE
	    freopen("input.in", "r", stdin);
	    // freopen("output.txt", "w", stdout);
	#endif	
}

int32_t main() {
  	init();
	int t=1;
	cin>>t; // Comment for 1 testcase
	while(t--) {
		solve();
	}
	return 0;
}
