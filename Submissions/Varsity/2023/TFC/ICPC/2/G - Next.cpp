#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  int pos = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i].first;
    if(a[i].first == 1) pos++;
  }
  sort(a + 1, a + n + 1);
  if(pos == 0) {
    cout << -a[1].second << '\n';
    return;
  }
  reverse(a + 1, a + n + 1);
  long long sum = 0;
  for(int i = 1; i <= pos; i++) {
    sum += a[i].second;
  }
  long long ans = sum * pos;
  for(int i = pos + 1; i <= n; i++) {
    if((sum + a[i].second) * (pos - 1) > ans) {
      ans = (sum + a[i].second) * (pos - 1);
      sum += a[i].second, pos--;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}