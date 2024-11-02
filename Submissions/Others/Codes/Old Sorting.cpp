#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];
set<int> se;
int cnt;

void f(int i, int x) {
  cnt++;
  se.insert(a[i]);
  if (a[i] == x) return;
  f(a[i], x);
}

int cs;
void solve() {
  se.clear();
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) continue;
    if (se.find(i) == se.end()) {
      se.insert(a[i]);
      cnt = 0;
      f(a[i], i);
      ans += cnt;
    }
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