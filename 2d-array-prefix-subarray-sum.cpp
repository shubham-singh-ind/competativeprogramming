/*
Useful in finding sum of numbers of a subarray containing integers.
For example: Given below grid. Asked to find sum of subarray from [1,1] to [2,2]. It can be found as below formula, if prefix 2D array is provided.

sum = pref[2][2] - pref[0][2] - pref[2][1] + pref[0][0]
sum = pref[A][B] - pref[a-1][B] - pref[A][B-1] + pref[a-1][b-1]

[[1,1],[1,2],[1,3]]
[[2,1],[2,2],[2,3]]
[[3,1],[3,2],[3,3]]
*/

// custom grid utility class
class grid {
    private:
        vector<vector<int>> _grid;
        int N, M;
        vector<vector<int>> pref_sum_grid;
    public:
        grid(vector<vector<int>> &_grid) {
            this->_grid = _grid;
            this->N = _grid.size();
            this->M = _grid[0].size();
        }

        void print_grid() {
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++)
                    cout << _grid[i][j] << " ";
                cout << endl;
            }
        }
        void print_pref_sum_grid() {
            if(pref_sum_grid.size() == 0) {
                cerr << "print_pref_sum_grid Can't be accessed before build_pref_sum function" << endl;
                return;
            }
            for(int i=0; i<=N; i++) {
                for(int j=0; j<=M; j++)
                    cout << pref_sum_grid[i][j] << " ";
                cout << endl;
            }
        }

        void build_pref_sum() {
            this->pref_sum_grid.resize(N+1, vector<int>(M+1));
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                pref_sum_grid[i][j] = _grid[i-1][j-1]
                    + pref_sum_grid[i - 1][j]
                    + pref_sum_grid[i][j - 1]
                    - pref_sum_grid[i - 1][j - 1];
                }
            }
        }

        // Returns sum in range [a,b]...[A,B] of submatrix in O(1)
        // Note: provide a,b,A,B in 1-based indexing
        int get_sum_in_range(int a, int b, int A, int B) {
            int sum = pref_sum_grid[A][B] - pref_sum_grid[a-1][B] - pref_sum_grid[A][b-1] + pref_sum_grid[a-1][b-1];
            return sum;
        }
};
