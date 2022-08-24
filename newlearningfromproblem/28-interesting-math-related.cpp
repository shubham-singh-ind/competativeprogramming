/*

Problem: https://codeforces.com/problemset/problem/1656/B

##Learning##
- Try to perform operation in terms of a,b,c,d instead of numbers. It will give broad/general idea.

*/

void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(all(v));

    if(n == 1) {
        cout << (v[0]==k ? "YES" : "NO") << endl;
        return;
    }

    int l = 0, r = 1;
    while(r < n) {
        int diff = v[r] - v[l];
        if(diff == k) {
            cout << "YES" << endl;
            return;
        }else if(diff > k) {
            l++;
        }else {
            r++;
        }
    }
    cout << "NO" << endl;
}
