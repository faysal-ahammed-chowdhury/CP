#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
int fibo[45];

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
        ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
      }
    }
    return ans;
  }
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
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

int cs;
void solve() {
  int n, x, m, y, k; cin >> n >> x >> m >> y >> k;
  if (n > m) {
    swap(n, m);
    swap(x, y);
  }

  cout << "Case " << ++cs << ": ";

  if (n > 45 or m > 45 or y < x) {
    cout << "Impossible\n";
    return;
  }

  int idx1 = m - n + 1;
  int idx2 = idx1 - 1;

  if (idx1 >= 45) {
    cout << "Impossible\n";
    return;
  }

  int z = (y - (x * fibo[idx1])) / fibo[idx2];

  // cout << x * fibo[idx1] + z * fibo[idx2] << ' ' << z << '\n';

  if (x * fibo[idx1] + z * fibo[idx2] != y) {
    cout << "Impossible\n";
    return;
  }

  int last = z, last2 = x;
  int here = 0;
  for (int i = n - 2; i >= 1; i--) {
    int now = last2 - last;
    last2 = last;
    last = now;
    if (i == k) here = now;
  }

  if (n > 1 and last2 > last * 2) {
    cout << "Impossible\n";
    return;
  }
  if (last > last2) {
    cout << "Impossible\n";
    return;
  }

  if ((n > 1 and last == 0) or last < 0) {
    cout << "Impossible\n";
    return;
  }

  if (k == n) {
    cout << x << '\n';
    return;
  }

  if (k == m) {
    cout << y << '\n';
    return;
  }

  if (k == n - 1) {
    cout << z << '\n';
    return;
  }

  if (k < n) {
    cout << here << '\n';
    return;
  }

  Mat m1({{1, 1}, {1, 0}}), m2({{x, z}});

  Mat pw = m1.pow(k - n);
  Mat ans = m2 * pw;

  cout << (ans.a[0][0]) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fibo[1] = fibo[2] = 1;
  for (int i = 3; i < 45; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}