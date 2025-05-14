#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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

vector<string> v;
map<string, int> mp;
vector<vector<int>> g(35, vector<int>(35, 0));

bool valid(int i, int j, int k, int l) {
  set<int> se = {i, j, k, l};
  if (se.size() < 4) return false;
  int x = min({i, j, k, l});
  int y = max({i, j, k, l});
  return (x >= 0 and y < 7);
}

bool ok(string s1, string s2) {
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      for (int k = 1; k <= 2; k++) {
        for (int l = 1; l <= 2; l++) {
          int idx1 = -1, idx2 = -1, idx3 = -1, idx4 = -1;
          for (int tmp = 0; tmp < 7; tmp++) {
            if (s1[tmp] != '1') continue;
            if (idx1 == -1) idx1 = tmp;
            else if (idx2 == -1) idx2 = tmp;
            else if (idx3 == -1) idx3 = tmp;
            else if (idx4 == -1) idx4 = tmp;
          }
          idx1 += (i == 1 ? -1 : +1);
          idx2 += (j == 1 ? -1 : +1);
          idx3 += (k == 1 ? -1 : +1);
          idx4 += (l == 1 ? -1 : +1);

          if (valid(idx1, idx2, idx3, idx4)) {
            string t = "0000000";
            t[idx1] = '1';
            t[idx2] = '1';
            t[idx3] = '1';
            t[idx4] = '1';

            if (t == s2) return true;
          }
        }
      }
    }
  }
  return false;
}

void prec() {
  string s = "0001111";
  do {
    v.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 0; i < v.size(); i++) {
    mp[v[i]] = i;
  }

  for (int i = 0; i < 35; i++) {
    for (int j = 0; j < 35; j++) {
      string s1 = v[i], s2 = v[j];
      if (ok(s1, s2)) {
        g[mp[s1]][mp[s2]]++;
      }
    }
  }
}

int cs;
void solve() {
  int n; cin >> n;
  string s = "";
  for (int i = 0; i < 7; i++) {
    char c; cin >> c;
    s += c == '0' ? c : '1';
  }

  // cout << s << ' ' << mp[s] << '\n';

  cout << "Case " << ++cs << ": ";
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  Mat M(g);
  M = M.pow(n - 1);
  int ans = 0;
  int i = mp[s];
  for (int j = 0; j < 35; j++) {
    ans += M.a[i][j];
    ans %= mod;
  }

  cout << ans << '\n';
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
