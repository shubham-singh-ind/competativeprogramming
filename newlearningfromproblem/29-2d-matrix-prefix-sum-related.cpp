/*
Problem: https://codeforces.com/contest/1722/problem/E
##Learning##
  - Sum of values of submatrix in O(1)
  - Created prefix sum of matrix
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


void solve() {
    int n, q;
    cin >> n >> q;

    // create grid at 0-based indexing
    vector<vi> v(1001, vi(1001));
    for(int i=0; i<n; i++) {
        int h, w;
        cin >> h >> w;
        v[h-1][w-1] += (h*w);
    }
    
    grid g(v);
    g.build_pref_sum();

    while(q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        int sum = g.get_sum_in_range(hs+1, ws+1, hb-1, wb-1); // provide values as 1-based indexing
        cout << sum << endl;
    }
}
