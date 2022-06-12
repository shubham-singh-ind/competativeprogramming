#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;

vi generateFactors(int n) {
    vi fact;
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            fact.push_back(i);
            if(n/i != i)
                fact.push_back(n/i);
        }
    }
    fact.push_back(1);
    fact.push_back(n);
    sort(fact.begin(),fact.end());
    return fact;
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
