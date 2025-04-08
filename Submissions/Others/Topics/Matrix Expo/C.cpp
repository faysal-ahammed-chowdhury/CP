#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 998244353;

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
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
      }
    }
    return ans;
  } 
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < b.m; j++) {
        for(int k = 0; k < m; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int d, n, m;
  while (1) {
    cin >> d >> n >> m;
    if (d == 0 and n == 0 and m == 0) break;
    mod = m;

    int a[d + 1], val[d + 1];
    for (int i = 1; i <= d; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= d; i++) {
      cin >> val[i];
    }

    if (n <= d) {
      cout << (val[n] % mod) << '\n';
      continue;
    }

    Mat A(d, 1), M(d, d);

    for (int i = 0, j = d; i < d; i++, j--) {
      A.a[i][0] = val[j];
    }

    for (int i = 0; i < d; i++) {
      for (int j = 0; j < d; j++) {
        if (i == 0) {
          M.a[i][j] = a[j + 1];
        }
        else {
          M.a[i][j] = 0;
        }
      }
      if (i > 0) {
        M.a[i][i - 1] = 1;
      }
    }

    Mat pw = M.pow(n - d);
    Mat ans = pw * A;
    cout << ans.a[0][0] << '\n';
  }

  return 0;
}