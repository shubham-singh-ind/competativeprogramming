int sieveArr[N+1] = {0};
vector<int> primes; 

void sieve() {
	// sieve
	for(long long i=2; i <= N; i++) {
		if(sieveArr[i] == 0) {
			primes.push_back(i);
			for(long long j=i*i; j<=N; j+=i)
				sieveArr[j] = 1;
		}
	}
}

vi segmentedSieve(int m, int n) {
    vi segment(n-m+1, 0);

    for(int p: primes) {
        if(p*p > n) break;

        int start = (m/p)*p;

        if(p>=m && p<=n) // optimization, saving extra iteations (special case)
			start = 2*p;

        for(int i=start; i<=n; i += p) {
            if(i < m) continue;
            segment[i-m] = 1; // marking non prime
        }
    }

    vi ans;
    for(int i=m; i<=n; i++)
        if(segment[i-m] == 0 && i!=1) ans.push_back(i);
    return ans;
}
