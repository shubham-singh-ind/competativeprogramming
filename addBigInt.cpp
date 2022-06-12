#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()

const int MOD = 1e9 + 7;

string addBigInt(string n1, string n2) {
    auto digitToChar = [](int digit) {
        return (char)(digit + '0');
    };
    auto charToDigit = [](char ch) {
        return ch - '0'; 
    };
    
    if(n1.size() > n2.size())
        swap(n1, n2);
    string result = "";
    int digit, carry; digit = carry = 0;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    for(int i=0; i<n1.size(); i++) {
        int d1 = charToDigit(n1[i]);
        int d2 = charToDigit(n2[i]);
        int sum = (d1+d2) + carry;
        int digit = sum%10;
        carry = sum/10;
        result.push_back(digitToChar(digit));
    }
    
    for(int i=n1.size(); i<n2.size(); i++) {
        int d2 = charToDigit(n2[i]);
        int sum = d2 + carry;
        digit = sum % 10;
        carry = sum/10;
        result.push_back(digitToChar(digit));
    }
    if(carry) result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}

void solve() {
    cout << addBigInt("-222", "111");
}

void init() {
	// fast IO
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif	
}

int32_t main() {
  // init();
   
	int t=1;
	cin>>t; // Comment for 1 testcase
	while(t--) {
		solve();
	}
	return 0;
}
