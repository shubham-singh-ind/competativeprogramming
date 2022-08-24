/*

Problem:
https://codeforces.com/problemset/problem/1656/C

*/


void solve() {
    int n;
    cin >> n;
    bool one = false, zero = false;
    vi v;
    while(n--) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        if(temp == 1) {
            one = true;
        }
        if(temp == 0) {
            zero = true;
        }
    }
    if(!one) {
        cout << "YES" << endl;
        return;
    }
    
    sort(all(v));
    for(int i=1; i<v.size(); i++) {
        if(v[i] == v[i-1]+1) {
            cout << "NO" << endl;
            return;
        }
    }

    if(one and zero) {
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
    }
}
