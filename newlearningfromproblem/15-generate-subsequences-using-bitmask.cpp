/*Author: shubh_singh
07-July-2022 20:47

Problem: https://codeforces.com/problemset/problem/1097/B
Learnings:
•	To generate all sub-sequences of an array/string, we can use bit-masking.
•	There are 2^N-1 non-empty sub-sequences of N length array. Each digit in binary is considered as 1 sequence. For e.g. 1 -> 0001, 2-> 0010, 3-> 0011 etc.
•	Get ith bit of a number N : ( N&(1<<i) ) 

*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define pi pair<int,int>
#define cout(a,b) cout<<a<<": "<<b<<endl;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    vi v(n);
    cin >> n;
    for(int i=0; i<n; i++) cin >> v[i];

    int noofsubseq = (1<<n)-1; // calculate 2^n-1
    for(int i=0; i<=noofsubseq; i++) { // Iterating through all subsequences
        int sum = 0;
        for(int pos=0; pos<n; pos++) {
            if(i & (1<<pos)) { // Get ith bit of i
                sum += v[pos]; // Rotate clockwise
            }else {
                sum -= v[pos]; // Rotate anti-clockwise
            }
            sum %= 360;
        }
        if(sum%360 == 0) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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
