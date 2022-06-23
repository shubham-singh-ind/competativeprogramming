/*
##Learning##
https://codeforces.com/problemset/problem/368/B
Create suffix array to store and query solution quickly.
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(),a.end()
#define desc(a) greater<a>()
#define pi pair<int,int>

const int MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vi v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	set<int> s;
	vi suff(n, 0);
	for(int i=0; i<n; i++) {
		bool notfound =  (s.find(v[n-i-1]) == s.end());
		suff[n-i-1] = ((n-i)<n ? suff[n-i]: 0) + notfound;
		if(notfound) s.insert(v[n-i-1]);
	}

	while(m--) {
		int t;
		cin >> t;
		cout << suff[t-1] << endl;
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

int i,l,m,n,a[100005],c[100005],r[100005];
main(){
	for(cin>>n>>m;i++<n;)
		cin>>a[i];

	for(;--i;)
		r[i]=r[i+1]+!c[a[i]]++;
		
	for(;m--;cout<<r[l]<<endl)cin>>l;
}
*/
