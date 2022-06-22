int fastMultiply(int a, int b) {
	int res = 0;
	while(b) {
		if(b&1) {
			res += a;
			res %= MOD;
		}
		a += a;
		a %= MOD;
		b >>= 1;
	}
	return res;
}

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
