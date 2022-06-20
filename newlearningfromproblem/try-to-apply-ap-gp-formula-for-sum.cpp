/*
##Learning##
1 2 3
4 5 6
7 8 9
Here requirement was to sum all first row element. So applied sum till N formula, n*(n-1)/2.
Also, we need to sum remaining elements of last column i.e 6 and 9. So applied sum till N formula of A.P. [Sn = (n+1)/2 * (a1 + an)]. Here an = n*m
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define vi vector<int>
#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;
    int sr = m*(m+1)/2; // Sum of first row.
    // Sum of remaning elements in last column
    int sn = ((m*2 +  n*m)*(n-1)) / 2;
    int ans = sr+sn;
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
