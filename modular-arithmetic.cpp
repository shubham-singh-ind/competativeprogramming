int addm(int x, int y) {
	return (x + y) % MOD;
}

int subm(int x, int y) {
	return ((x - y) % MOD + MOD) % MOD;
}

// Always take long long int in Multiplication case.
int mulm(int x, int y) {
	return (x * y) % MOD;
}
