/*
##Learning##
I had to calculate power(8,n)%10, where n<=10^9. So, if i simply calculate 8^n, it will take O(n) time and also it will give me incorrect answer.
It will give incorrect answer because here we are first calculating power(8,n), which will not fit into even long long.
Solve: To solve this issue, we used modulo binary exponentiation method. In which, we implemented power function by our own. We took modulo of number to 10 at each step.
Also, time taken for binary exponentiation will be O(logn) <<<< O(n)
*/

/*Author: shubh_singh
06-July-2022 14:04
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define pi pair<int,int>
#define cout(a,b) cout<<a<<": "<<b<<endl;

const int MOD = 10;

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1)
			res = res*a, res %= MOD;
		a *= a; 
		a%=MOD;
		b /= 2;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	// O(log(n))
	int ans = power(8, n);
	cout << ans << endl;

	// O(1)
	// if(n==0) {
	// 	cout << 1 << endl;
	// 	return;
	// }
	// int arr[] = {6,8,4,2};
	// n %= 4;
	// cout << arr[n] << endl;

}

void init() {
	// fast IO
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
	#endif
}

int32_t main() {   
	init();
	int t=1;
	// cin>>t; // Comment for 1 testcase
	while(t--) {
		solve();
	}
	return 0;
}
