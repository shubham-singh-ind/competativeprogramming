/*Author: shubh_singh
02-July-2022 10:09

##Learning##
https://codeforces.com/contest/371/problem/C
https://codeforces.com/contest/670/problem/D1
If something needs to be searched in sorted values/array, we can use binary search to perform search in log(n)
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;
map<char, int> mp;
int costforonehb;

int max(int a, int b) {
    return a>b ? a : b;
}

bool checkIfCanMake(int i, int nb, int ns, int nc, int pb, int ps, int pc, int r) {
    if(nb >= i*mp['B'] && ns >= i*mp['S'] && nc >= i*mp['C']) {
        return true;
    }
    int reqb = max(0, i*mp['B']-nb);
    int reqs = max(0, i*mp['S']-ns);
    int reqc = max(0, i*mp['C']-nc);
    int reqcost = reqb*pb + reqs*ps + reqc*pc;
    return r >= reqcost;
}

void solve() {
    string str;
    cin >> str;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    int r;
    cin >> r;

    for(char ch: str) {
        mp[ch]++;
    }

    int s = 1;
    int e = 1e15;
    int ans = 0;
    while(s <= e) {
        int mid = (s+e)/2;
        if(!checkIfCanMake(mid, nb, ns, nc, pb, ps, pc, r)) {
            e = mid-1;
        }else {
            ans = max(ans, mid);
            s = mid+1;
        }
    }
    cout << ans << endl;
}

void init() {
    // fast IO
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
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
