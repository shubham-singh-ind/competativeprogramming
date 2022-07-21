/*
Shortest Common Supersequence:
If char matches with other char, then 1+f(i+1, j+1).
If does not match, then min({1+f(i,j+1), 1+f(i+1,j), 2+f(i+1,j+1)}) 
*/
int scs(string &X, int i, string &Y, int j, vector<vector<int>> &dp) {
	
	int xn = X.size();
	int yn = Y.size();
	if(i == xn) return yn-j;
	if(j == yn) return xn-i;

	if(dp[i][j] != -1) return dp[i][j];

	if(X[i] == Y[j]) dp[i][j] = 1+scs(X, i+1, Y, j+1, dp);
	else dp[i][j] = min({1+scs(X, i, Y, j+1, dp), 1+scs(X, i+1, Y, j, dp), 2+scs(X, i+1, Y, j+1, dp)});
	
	return dp[i][j];
}
