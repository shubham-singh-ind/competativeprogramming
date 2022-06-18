/*
##Learning##
In this problem, I was using MAP data structure which was taking extra space. Further I found that there were only 2 teams who were playing.
So, no need to make O(n) space map. We can use constant space.
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  int counter = 1;
  string a, b, c;
  cin >> a;
  b = a;
  n--;
  while(n--) {
	cin >> a;
	if(a == b) {
		counter++;
	}else {
		c = a;
		counter--;
	}
  }
  cout << (counter>0 ? b : c) << endl;
}
void init() {
	// fast IO
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 	#ifndef ONLINE_JUDGE
	    freopen("input.in", "r", stdin);
	    // freopen("output.txt", "w", stdout);
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
