#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += a[i] == a[1];
  }
  if (cnt <= (n / 2)) cout << "Alice\n";
  else cout << "Bob\n";

  return 0;
}