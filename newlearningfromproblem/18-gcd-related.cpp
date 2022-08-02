/*
Problem: C. Paint the Array 
https://codeforces.com/problemset/problem/1618/C

##Learning##
- If you want to find the number which is dividing all numbers a1, a2, a3, .... That will be gcd of (a1, a2, a3,...)
*/

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for(int &x: v) cin >> x;

    int gcdeve = 0; // even pos gcd 
    int gcdodd = 0; // odd pos gcd
    for(int i=0; i<n; i++) {
        if(i&1)
            gcdodd = __gcd(v[i], gcdodd);
        else
            gcdeve = __gcd(v[i], gcdeve);
    }

    bool flag = true;
    for(int i=0; i<n; i+=2) {
        if(v[i]%gcdodd == 0) {
            flag = false;
            break;
        }
    }
    if(flag == true) {
        cout << gcdodd << endl;
        return;
    }

    for(int i=1; i<n; i+=2) {
        if(v[i]%gcdeve == 0) {
            cout << 0 << endl;
            return;
        }
    }
    cout << gcdeve << endl;
}
