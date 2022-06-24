/*
##Learning##
Problem: https://codeforces.com/problemset/problem/467/B
Count number of different bits between 2 numbers. 
XOR generates 1 if bits are different in 2 numbers. Therefore, just did xor of both numbers and counted number of 1s.
__builtin_popcount(n) can be used to count number of 1s in a binary number.
*/
#include <bits/stdc++.h>
using namespace std;

int countBits(int n) {
  int count = 0;
  while(n) {
    n = n & (n-1);
    count++;
  }
  return count;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m+1);
	for(int i=0; i<m+1; i++) cin >> v[i];
	int ans = 0;
	for(int i=0; i<m; i++) {
	    if(__builtin_popcount(v[m] ^ v[i]) <= k) ans++;
	}
	cout << ans << endl;
	return 0;
}

/*
3 3 3
1
2
3
4

k=3
4 -> 0100

1 -> 0001 - F (2)
2 -> 0010 - F (2)
3 -> 0011 - F (3)

- Count no of 1s in X xor Y. Where Y is m elements.
*/
