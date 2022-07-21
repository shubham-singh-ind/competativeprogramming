/*
Given two words, find the minimum number of single-character edits required to transform one word into the other. An edit can be insertion, deletion, or substitution and each edit carries a unit cost.

Input: X = "kitten", Y = "sitting"
Output: 3
Explanation: A minimal edit script that transforms the 'kitten' into 'sitting' is:

kitten —> sitten (substitution of 's' for 'k')
sitten —> sittin (substitution of 'i' for 'e')
sittin —> sitting (insertion of 'g' at the end)

Sign: int findMinDistance(string X, string Y)
*/
int findMinDistance(string X, int i, string Y, int j, vector<vector<int>> &dp) {
	int xn = X.size();
	int yn = Y.size();
	if(i == xn ) return yn-j;
	if(j == yn) return xn-i;

	if(dp[i][j] != -1) return dp[i][j];

	if(X[i] == Y[j])
		dp[i][j] = findMinDistance(X, i+1, Y, j+1, dp); /* No operation */
	else dp[i][j] = min({ 
		1+findMinDistance(X, i+1, Y, j, dp), /* Delete X[i] */
		1+findMinDistance(X, i, Y, j+1, dp), /* Delete Y[j] */
		2+findMinDistance(X, i+1, Y, j+1, dp), /* Delete X[i], Y[j] both */
		1+findMinDistance(X, i+1, Y, j+1, dp) /* Edit X[i] to Y[j] */ });
	
	return dp[i][j];
}
