#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], b[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int i = 1;
  for (int j = 1; j <= m; j++) {
    while (i <= n and a[i] < b[j]) {
      i++;
    }
    cout << i - 1 << ' ';
  }
  cout << '\n';
  
  return 0;
}