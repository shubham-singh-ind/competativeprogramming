#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;

int gcd(int a, int b) { //O(logn)
    if(!b) return a;
    return gcd(b, a%b);
}

void solve() {

}

void init() {
	// fast IO
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
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
