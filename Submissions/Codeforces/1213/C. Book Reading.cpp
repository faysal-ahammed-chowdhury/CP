#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  long long n, m; cin >> n >> m;
  long long divide = n / m;
  long long mul = divide / 10;
  long long rem = divide % 10;
  long long sum = 0;
  for(int i = 1; i <= 10; i++) {
    sum += (m * i) % 10;
  }
  long long ans = sum * mul;
  for(int i = 1; i <= rem; i++) {
    ans += (m * i) % 10;
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