/*
##Learning##
Upper bound can be used on a sorted array. It gives iterator to element which is strictly greater than that element.
We can subtract that iterator with first iterator in array to get counts.
(ub - arr.begin())
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(),a.end()
#define desc(a) greater<a>()

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	sort(all(v));
	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		auto up = upper_bound(all(v), t); // count of elements <= t
		cout << (up-v.begin()) << " " << endl;
	}
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
	// cin>>t; // Comment for 1 testcase
	while(t--) {
		solve();
	}

	return 0;
}

/*
*/
