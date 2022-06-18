/*
##Learning##
To count number of 1's in binary, fastest way is to (x = x & (x-1)) untill x becomes 0. Count every repitition.
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;

void solve() {
  int x;
  cin >> x;
  int count = 0;
  while(x) {
    count += (x&1);
    x >>= 1;
  }
  
  /*
  while(x) {
    x = (x & (x-1));
    count++;
  }
  */
  
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
