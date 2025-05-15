#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int unsigned int

vector<bool> allowed(26);
vector<vector<int>> g(50, vector<int>(50, 0));

vector<int> build_lps(string &pat) {
  int n = pat.size();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];
    while (j > 0 and pat[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (pat[i] == pat[j]) j++;
    lps[i] = j;
  }
  return lps;
}

void compute_automaton(string s, vector<vector<int>>& aut) {
  s += '#';
  int n = s.size();
  vector<int> pi = build_lps(s);
  aut.assign(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (!allowed[c]) continue;
      if (i > 0 && 'a' + c != s[i])
        aut[i][c] = aut[pi[i - 1]][c];
      else
        aut[i][c] = i + ('a' + c == s[i]);
    }
  }
}

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

void clr() {
  for (int i = 0; i < 50; i++) {
    if (i < 26) allowed[i] = false;
    for (int j = 0; j < 50; j++) {
      g[i][j] = 0;
    }
  }
}

int cs;
void solve() {
  clr();

  int n; cin >> n;
  string tmp; cin >> tmp;
  for (auto c : tmp) {
    allowed[c - 'a'] = true;
  }
  string s; cin >> s;
  vector<vector<int>> aut;
  compute_automaton(s, aut); 
  // for (int i = 0; i < s.size(); i++) {
  //   for (int j = 0; j <= 2; j++) {
  //     cout << i << ',' << j << ' ' << aut[i][j] << '\n';
  //   }
  //   cout << '\n';
  // }
  for (int i = 0; i < s.size(); i++) {
    for (auto c : tmp) {
      int j = c - 'a';
      if (aut[i][j] != s.size()) g[i][aut[i][j]]++;
    }
  }

  Mat M(g);
  M = M.pow(n);

  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += M.a[0][i];
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}