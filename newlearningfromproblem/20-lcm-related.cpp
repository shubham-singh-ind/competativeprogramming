/*
Problems:
https://codeforces.com/problemset/problem/1497/C1
https://codeforces.com/problemset/problem/1497/C2

##Learning##
If we want to divide a number N in terms of few numbers A1 to Ak and lcm(A1...Ak) <= N. Then, it can be divided using below.
If N is odd:
  {N/2, N/2, 1, k-3 times 1}
If N is even:
  if N is multiple of 4:
    {n/2, n/4, n/4, k-3 times 1}
  if N is not multiple of 4:
    {n/2-1, n/2-1, 2, k-3 times 1}
Note: Here we are appending 1 since it will not affect out LCM. Therefore, we will be getting least LCM possible.

*/
vi get3Numbers(int n) {
    if(n&1) {
        return {n/2, n/2, 1};
    }
    if(n%4) {
        return {n/2-1, n/2-1, 2};
    }
    return {n/2, n/4, n/4};
}

void solve() {
    int n, k;
    cin >> n >> k;
    if(k == 3) {
        vi ans = get3Numbers(n);
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }else {
        n -= (k-3);
        vi ans = get3Numbers(n);
        for(auto i: ans) cout << i << " ";
        for(int i=0; i<k-3; i++) cout << 1 << " ";
        cout << endl;
    }
}
