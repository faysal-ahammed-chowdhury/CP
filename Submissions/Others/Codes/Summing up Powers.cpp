#include<bits/stdc++.h>
using namespace std;

#define int unsigned int

struct Mat {
  int n, m;
  vector<vector<int>> a;
  Mat() { }
  Mat(int _n, int _m) {n = _n; m = _m; a.assign(n, vector<int>(m, 0)); }
  Mat(vector< vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
  inline void make_unit() {
    assert(n == m);
    for (int i = 0; i < n; i++)  {
      for (int j = 0; j < n; j++) a[i][j] = i == j;
    }
  }
  inline Mat operator + (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] + b.a[i][j]);
      }
    }
    return ans;
  }
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - b.a[i][j]);
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < b.m; j++) {
        for (int k = 0; k < m; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j]);
        }
      }
    }
    return ans;
  }
  inline Mat pow(long long k) {
    assert(n == m);
    Mat ans(n, n), t = a; ans.make_unit();
    while (k) {
      if (k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
  inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
  inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
  inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
  inline bool operator == (const Mat& b) { return a == b.a; }
  inline bool operator != (const Mat& b) { return a != b.a; }
};

int C[55][55];

void prec() { // O(n^2)
  // nCr = (n-1)C(r-1) + (n-1)Cr
  for (short i = 0; i < 55; i++) {
    C[i][i] = 1;
    for (short j = 0; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
    }
  }
}

int nCr(int n, int r) {
  if (n < r) return 0;
  return C[n][r];
}

int cs;
void solve() {
  long long n, k; cin >> n >> k;
  cout << "Case " << ++cs << ": ";
  if (k == 0) {
    cout << n % (1ll << 32) << '\n';
    return;
  }
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  Mat A(k + 2, 1);
  for (int i = 0; i <= k + 1; i++) {
    A.a[i][0] = 1;
  }

  Mat T(k + 2, k + 2);
  for (int i = 0; i < k + 2; i++) {
    for (int j = i, jj = 0; j < k + 2; j++, jj++) {
      if (j == k + 1) {
        T.a[i][j] = i == k + 1;
        continue;
      }
      T.a[i][j] = nCr(k - i, jj);
    }
  }

  for (int j = 0; j < k + 1; j++) {
    T.a[k + 1][j] = nCr(k, j);
  }

  // for (int i = 0; i <= k + 1; i++) {
  //   for (int j = 0; j <= k + 1; j++) {
  //     cout << T.a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  T = T.pow(n - 1) * A;

  cout << T.a[k + 1][0] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
