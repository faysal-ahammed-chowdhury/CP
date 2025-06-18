#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];

  int mn1[m + 1], mn2[m + 1];
  memset(mn1, -1, sizeof(mn1));
  memset(mn2, -1, sizeof(mn2));

  int j = 1;
  for (int i = 1; i <= m; i++) {
    while (j <= n and a[j] != b[i]) {
      j++;
    }
    if (j <= n and a[j] == b[i]) mn1[i] = j++; 
  }


  j = n;
  for (int i = m; i >= 1; i--) {
    while (j >= 1 and a[j] != b[i]) {
      j--;
    }
    if (j >= 1 and a[j] == b[i]) mn2[i] = j--;
  }

  for (int i = 1; i <= m; i++) {
    int x = mn1[i], y = mn2[i];
    // cout << i << ' ' << x << ' ' << y << '\n';
    if (x != -1 and y != -1 and x < y) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";

  return 0;
}