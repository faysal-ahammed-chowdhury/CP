#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
const int inf = 1e9;
string st, en;
set<string> se;
int dp[23000][10];

int f(string s, int mask) {
  if (se.find(s) != se.end()) return inf;
  if (s == en) return 0;

  int hash = ((s[0] - 'a' + 1) * 29 * 29) + ((s[1] - 'a' + 1) * 29) + (s[2] - 'a' + 1);
  int &ans = dp[hash][mask];
  if (ans != -1) return ans;

  ans = inf;
  if (s[0] != en[0]) {
    string cur = s;
    if (CHECK(mask, 0)) {
      if (cur[0] == 'z') cur[0] = 'a';
      else cur[0]++;
    }
    else {
      if (cur[0] == 'a') cur[0] = 'z';
      else cur[0]--;
    }
    ans = min(ans, 1 + f(cur, mask));
  }
  if (s[1] != en[1]) {
    string cur = s;
    if (CHECK(mask, 1)) {
      if (cur[1] == 'z') cur[1] = 'a';
      else cur[1]++;
    }
    else {
      if (cur[1] == 'a') cur[1] = 'z';
      else cur[1]--;
    }
    ans = min(ans, 1 + f(cur, mask));
  }
  if (s[2] != en[2]) {
    string cur = s;
    if (CHECK(mask, 2)) {
      if (cur[2] == 'z') cur[2] = 'a';
      else cur[2]++;
    }
    else {
      if (cur[2] == 'a') cur[2] = 'z';
      else cur[2]--;
    }
    ans = min(ans, 1 + f(cur, mask));
  }
  return ans;
}

int cs;
void solve() {
  se.clear();
  cin >> st >> en;
  int n; cin >> n;
  while (n--) {
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    for (auto c1 : s1) {
      for (auto c2 : s2) {
        for (auto c3 : s3) {
          string s = "";
          s += c1;
          s += c2;
          s += c3;
          se.insert(s);
        }
      }
    }
  }

  memset(dp, -1, sizeof dp);
  int ans = inf;
  for (int k = 0; k <= 7; k++) {
    ans = min(ans, f(st, k));
  } 
  cout << "Case " << ++cs << ": " << (ans >= inf ? -1 : ans) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}