/*
Problem: https://codeforces.com/contest/670/problem/D1
Solution: https://codeforces.com/contest/670/submission/162510584

##Learning##
- Applied binary search on monotonically increasing function.
*/

bool checkIfCanMake(int i, vi &req, vi &tot, int magic) {
    int size = req.size();
    int unavailableingredients = 0;
    bool flag = true;
    for(int j=0; j<size; j++) {
        if(req[j]*i > tot[j]) {
            flag = false;
        }
        unavailableingredients += max(0, req[j]*i - tot[j]);
    }
    if(flag) return true;
 
    return unavailableingredients <= magic;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    vi required(n), total(n);
    for(int i=0; i<n; i++) cin >> required[i];
    for(int i=0; i<n; i++) cin >> total[i];
 
    int l = 1;
    int r = INT_MAX;
    int ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(!checkIfCanMake(mid, required, total, k)) {
            r = mid-1;
        }else {
            l = mid+1;
            ans = max(ans, mid);
        }
    }
    cout << ans << endl;
}
