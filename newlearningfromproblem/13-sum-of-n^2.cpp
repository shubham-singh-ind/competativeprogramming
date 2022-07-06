/*
https://codeforces.com/problemset/problem/1353/C

##Learning##
Sum of squares of n natural numbers.
Sn = (n*(n+1)*(2*n+1))/6
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define f(a,b,c) for(int i=a; i<b; i+=c)
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(),a.end()
#define desc(a) greater<a>()
#define pi pair<int,int>
#define cout(a,b) cout<<a<<": "<<b<<endl;

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	// O(1)
	n/=2;
	int sum = (n*(n+1)*(2*n+1))/6;
	int ans = sum*8;
	cout << ans << endl;

	// O(n)
	// int mul = n/2;
	// int sum = 0;
	// for(int i=n; i>1; i-=2) { // every odd in decreasing order starting from n
	// 	int a = i-1;
	// 	sum += (4*a*mul);
	// 	mul--;
	// }
	// cout << sum << endl;
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
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
