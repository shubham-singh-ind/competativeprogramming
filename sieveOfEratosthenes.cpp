#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;

bool prime[100005];
void sieveOfEratosthenes(int n) { //O(nloglogn) 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++)  { 
        if (prime[p] == true) {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        }
    }
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
