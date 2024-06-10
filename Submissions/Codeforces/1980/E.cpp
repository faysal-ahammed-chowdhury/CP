#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)), aa(m, vector<int>(n));
  vector<vector<int>> b(n, vector<int>(m)), bb(m, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      aa[j][i] = a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
      bb[j][i] = b[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    sort(a[i].begin(), a[i].end());
    sort(b[i].begin(), b[i].end());
  }
  for (int i = 0; i < m; i++) {
    sort(aa[i].begin(), aa[i].end());
    sort(bb[i].begin(), bb[i].end());
  }

  sort(a.begin(), a.end());
  sort(aa.begin(), aa.end());
  sort(b.begin(), b.end());
  sort(bb.begin(), bb.end());

  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 0; i < m; i++) {
    if (aa[i] != bb[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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