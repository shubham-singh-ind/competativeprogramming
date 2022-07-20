/*
LCS: Longest common subsequences.
#Learnings#
- IMPORTANT steps for thinking about recursive problem:
  - [S]ubproblem Definition:
    - Think of subproblem definition. For example: Suppose, lcs(X, i, Y, j) gives no. of maximum length of subsequence (i...j). (Let's have faith on that).
    - In this step, make sure to use states that are required. For example: Here, i had X, Y as string and i and j as indexes.
  - [R]elate Subproblem Solutions Recursively:
    - Think and relate how to solve subproblem if its result is already available to us.
    - In this example, out case was as below.
    - If X[i] and Y[j] are matching, that means we have a solution as 1 + lcs(X, i+1, Y, j+1). Otherwise, we have max(lcs(X, i+1, Y, j), lcs(X, i, Y, j+1).
  - [T]o reduce the subproblem by some order:
    - Here, I am reducing subproblem by either i+1, or j+1, or both i+1 and j+1.
  - [B]ase case of relation:
    - Think on which note, our problem will end. The smallest possible case.
*/

int findLcsLength(string &X, int i, string &Y, int j, vector<vector<int>> &dp) {
  
	int xn = X.size();
	int yn = Y.size();
	if(i>=xn || j>=yn) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(X[i] == Y[j])
		return dp[i][j] = 1 + findLcsLength(X, i+1, Y, j+1, dp);
	return dp[i][j] = max(findLcsLength(X, i+1, Y, j, dp), findLcsLength(X, i, Y, j+1, dp));
  
}

int main() {
    
   string a = "ABCBDAB";
   string b = "BDCABA";
   vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, -1));
   cout << lcsubsequence(a, 0, b, 0, dp) << endl;
  
   return 0;
}
 
