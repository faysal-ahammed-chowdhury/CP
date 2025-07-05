#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += x;
  }

  if (sum <= m) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}