#include <bits/stdc++.h>
using namespace std;

const int N = 105;
#define len(x) (int) x.size();
int n, m;
string s1, s2, dp[N][N];
bool vis[N][N];

string fun(int i, int j) {
  if (i == n or j == m) return "";
  string &ans = dp[i][j];
  if (vis[i][j] == true) return dp[i][j];
  vis[i][j] = true;
  ans = "";
  if (s1[i] == s2[j]) {
    ans = s1[i] + fun(i + 1, j + 1);
  }
  else {
    string ans1 = fun(i + 1, j);
    string ans2 = fun(i, j + 1);
    if (ans1.size() == ans2.size()) {
      ans = min(ans1, ans2);
    }
    else if (ans1.size() > ans2.size()) {
      ans = ans1;
    }
    else {
      ans = ans2;
    }
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> s1 >> s2;
  n = len(s1);
  m = len(s2);
  string x = fun(0, 0);
  cout << "Case " << ++cs << ": "; 
  if (x == "") {
    cout << ":(\n";
  }
  else {
    cout << x << '\n';
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      vis[i][j] = false;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}