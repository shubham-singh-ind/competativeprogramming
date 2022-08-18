/*

Problem: https://codeforces.com/problemset/problem/1692/E
##Learning##
- Sliding Window Technique is used in this problem.
- Ask was to find length of largest subarray whose sum is equal to S.

*/

void solve() {
    int n, s;
    cin >> n >> s;
    vi v(n);
    for(int &x: v) cin >> x;
    int i=0, j=0;
    int sum = v[0];
    int ans = INT_MAX;
    while(i <= j and j < n) {
        if(sum == s) {
            ans = min(ans, n - (j-i+1));
            j++;
            sum += v[j];
        }else if(sum > s ) {
            sum -= v[i];
            i++;
        }else {
            j++;
            sum += v[j];
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}
