/*
Problem: https://codeforces.com/contest/1714/problem/A
A. Everyone Loves to Sleep

##Learning##:
- First convert time into minutes, which will help us perform operations easily. (hour*60 + minute)
Difference between 2 times A and B can be easily calculated using below steps =>
-If B's time is less than A's time then, add (24*60) minutes time in B to make it more than A. If not, then ignore this step.
-Now, simply subtract B's time in minutes with A's time in minutes. diff = (Bminutes - Aminutes).
-Now, diff in minutes can be used to get hour and minute as below.
- Hour = diff/60
- Minute = diff%60
*/

void solve() {
    int n, h, m;
    cin >> n >> h >> m;
    int ans = INT_MAX;
    int sleep = h*60+m;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        int bed = x*60+y;
        if(bed < sleep) bed += (24*60);
        ans = min(ans, bed-sleep);
    }
    cout << (ans/60) << " " << (ans%60) << endl;
}
