/*

##Learning##
- Getting maximum / minimum answer for Monotonically increasing or decreasing function.
- Here, I applied binary search on right index which leads to sum with maximum length subarray.


*/

// Given prefix array, returns sum in range [l...r]
int sum_in_range(vi &pref, int l, int r) {
    return pref[r] - (l ? pref[l-1] : 0);
}

void solve() {
    int n, s;
    cin >> n >> s;
    vi v(n), pref(n);
    int i = 0;
    for(int &x: v) {
        cin >> x;
        pref[i] = x;
        if(i) pref[i] += pref[i-1];
        i++;
    }

    int ans = INT_MAX;
    for(int i=0; i<n; i++) {
        int l = i, r = n-1, pos = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(sum_in_range(pref, i, mid) <= s) {
                pos = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        if(pos == -1 or sum_in_range(pref, i, pos) != s) {
            continue;
        }
        ans = min(ans, n - ( pos - i + 1 ));
    }

    cout << ( ans == INT_MAX ? -1 : ans) << endl;
}
