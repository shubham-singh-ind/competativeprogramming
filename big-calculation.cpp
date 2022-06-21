#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) a.begin(),a.end()
#define desc(a) greater<a>()

const int MOD = 1e9 + 7;

string subtract(string s, string x) {
	//First string should be always large.
	auto checkIfFirstIsLarge = [] (string a, string b) {
		if(a.size() > b.size()) return true;
		for(int i=0; i<a.size(); i++)
		if(a[i] > b[i]) return true;
		return false;
	};
	if(!checkIfFirstIsLarge(s, x)) swap(s, x);	
	reverse(all(s));
	reverse(all(x));
	int i=0;
	int carry = 0;
	string ans;
	while(i < x.size()) {
		int dig1 = s[i]-'0', dig2 = x[i]-'0';
		int sub = dig1-dig2-carry;
		if(sub < 0) {
			sub += 10;
			carry = 1;
		}else {
			carry = 0;
		}
		ans.push_back(sub+'0');
		i++;
	}
	while(i < s.size()) {
		int dig1 = s[i]-'0';
		int sub = dig1-carry;
		if(sub < 0) {
			sub += 10;
			carry = 1;
		}else {
			carry = 0;
		}
		if(sub != 0)
		ans.push_back(sub+'0');
		i++;
	}
	reverse(all(ans));
	return ans;
}

int32_t main() {
  
  cout << subtract("123", "111") << endl;

	return 0;
}

