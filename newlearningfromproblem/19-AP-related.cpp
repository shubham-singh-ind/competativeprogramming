/*Author: shubh_singh
13-August-2022 11:55

Problem: https://codeforces.com/problemset/problem/1409/C
Solution: https://codeforces.com/contest/1409/submission/168045423
##Learning##
Creating elements of AP series and finding AP with smallest last term. Also, AP should include given elements x and y.

*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define pi pair<int,int>

void __print(int32_t x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MOD = 1e9 + 7;

// Divide param1 by param2 to get ceil value
inline int ceil(int divident, int divisor) {
    if(divisor == 0) return 0;
    return divident/divisor + (divident%divisor!=0);
}

int max(int &a, int &b) {
    return a>b?a:b;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vi ans;
    for(int a=1; a<51; a++) {
        for(int d=1; d<51; d++) {
            vi series;
            for(int i=0; i<n; i++) {
                int an = a + i*d;
                series.push_back(an);
            }
            bool xf = false, yf = false;
            for(int &num: series) {
                if(num == x) xf = true;
                if(num == y) yf = true;

            }
            if(xf and yf) {
                if(ans.empty()) {
                    ans = series;
                } 
                else if(series.back() < ans.back()) {
                    ans = series;
                }
            }   
        }
    }

    for(int &t: ans) cout << t << " ";
    cout << endl;
}

int32_t main() {   
    // fast IO
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // file IO
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
        freopen("debug.out", "w", stderr);
    #endif

    int t=1;
    cin>>t; // Comment for 1 testcase
    while(t--) {
        solve();
    }
    return 0;
}
