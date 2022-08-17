/*

Problem: https://codeforces.com/problemset/problem/1703/E
##Learning##
After rotating a matrix by 90deg, element at position (i,j) changes to (j,n-i-1). (i.e. Row becomes column, column becomes lastrow).
After rotating a matrix by 180deg, element at position (i,j) changes to (j,n-i-1) for 90deg and another 90deg rotation, that is (n-i-1,n-j-1).
After rotating a matrix by 270deg, element at position (i,j) changes to (j,n-i-1) for 90deg and another 90deg rotation, that is (n-i-1,n-j-1) 
and another 90deg rotation, that is (n-j-1), (n-(n-i-1)-1) => (n-j-1, i).

*/
void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(string &s: v) cin >> s;

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char &a = v[i][j];
            char &b = v[j][n-i-1];
            char &c = v[n-i-1][n-j-1];
            char &d = v[n-j-1][i];
            int z = (a=='0') + (b=='0') + (c=='0') + (d=='0');
            int o = 4 - z;
            if(z < o) {
                if(a == '0') a = '1';
                if(b == '0') b = '1';
                if(c == '0') c = '1';
                if(d == '0') d = '1';
            } else {
                if(a == '1') a = '0';
                if(b == '1') b = '0';
                if(c == '1') c = '0';
                if(d == '1') d = '0';
            }
            ans += min(z, o);
        }
    }
    cout << ans << endl;
}
