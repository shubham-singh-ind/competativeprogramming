/*
##Learning##
If there are 2 players playing game. Try thinking in terms of Even and Odd
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define desc(a) greater<a>()

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi v(n+1);
	int mn = INT_MAX;
	int mnindex = -1;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
		if(v[i] < mn) {
			mnindex = i;
			mn = v[i];
		}
	}
	
	if(n&1) {
		cout << "Mike" << endl; // Mike will empty first pile, and Joe will never be able to move forward. M J M
		return;
	}
	cout << (mnindex&1 ? "Joe" : "Mike") << endl;
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

/*
a1, a2, a3, ... an .. a1, a2, ...
Mike starts.

100 100 - Joe wins.

5 4 3
1 0 3 - Mike wins.

2 3 4
0 1 4
0 0 3 - Mike wins.

5 2 7
3 0 7 - Mike wins.

2 3 4 5 4 3
0 1 4 5 4 3
0 0 3 5 4 3
0 0 0 2 4 3
0 0 0 0 2 3
0 0 0 0 0 1 - Joe wins.

*/
