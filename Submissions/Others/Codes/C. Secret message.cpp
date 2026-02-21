#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<int> divs[N];

void sieve() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
}

void solve() {
  int n, k; cin >> n >> k;
  set<int> idx[n + 1];
  for (int j = 1; j <= k; j++) {
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
      idx[i].insert(s[i - 1]);
    }
  }

  for (auto d : divs[n]) {
    bool d_ok = true;
    string ans = "";
    for (int i = 1; i <= d; i++) {
      char ch = '#';
      for (char c = 'a'; c <= 'z'; c++) {
        bool ok = true;
        for (int j = i; j <= n; j += d) {
          ok &= idx[j].find(c) != idx[j].end();
        }
        if (ok) {
          ch = c;
          break;
        }
      }
      if (ch == '#') d_ok = false;
      ans += ch;
    }
    if (d_ok) {
      for (int i = 1; i <= (n / d); i++) {
        cout << ans;
      }
      cout << '\n';
      return;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}