/*
##Learning##
If we want to go from a->b in a circular way of n size array. Then use formula (b-x+n)%n.
Here we are adding `n` so that negative value can become positive. Also, we are taking mod with `n` so that number will not go out of range of `n`.
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vi v(m);
  for(int i=0; i<m; i++) cin >> v[i];
  ll count = 0;
  int x = 1;
  for(int i=0; i<m; i++) {
    count += (v[i]-x+n)%n;
    x = v[i];
  }
  cout << count << endl;
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

3, For 1st task needs to move to a1. Complete all tasks with <i
[1] 2 3 4 ... n
s += (2+4)%4 = 2
s += (2-3+4)%4 = 
1->2->[3]->4->1->[2]->3
3 2 3

if ai+1 < ai:
  n-ai+ai+1
else:
  n-ai
4 3
2 3 3
1+1+

2 1
1 2
1 

*/


