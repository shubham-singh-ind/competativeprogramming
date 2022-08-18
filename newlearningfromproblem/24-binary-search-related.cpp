/*
Problem: https://codeforces.com/contest/371/problem/C
Solution: https://codeforces.com/contest/371/submission/162506916

##Learning##
- Applied Binary search on monotonically increasing function to get the maximum value.

*/

bool checkIfCanMake(int i, int nb, int ns, int nc, int pb, int ps, int pc, int r) {
    if(nb >= i*mp['B'] && ns >= i*mp['S'] && nc >= i*mp['C']) {
        return true;
    }
    int reqb = max(0, i*mp['B']-nb);
    int reqs = max(0, i*mp['S']-ns);
    int reqc = max(0, i*mp['C']-nc);
    int reqcost = reqb*pb + reqs*ps + reqc*pc;
    return r >= reqcost;
}
 
void solve() {
    string str;
    cin >> str;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
 
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
 
    int r;
    cin >> r;
 
    for(char ch: str) {
        mp[ch]++;
    }
 
 
    int s = 1;
    int e = 1e15;
    int ans = 0;
    while(s <= e) {
        int mid = (s+e)/2;
        if(!checkIfCanMake(mid, nb, ns, nc, pb, ps, pc, r)) {
            e = mid-1;
        }else {
            ans = max(ans, mid);
            s = mid+1;
        }
    }
    cout << ans << endl;
}
