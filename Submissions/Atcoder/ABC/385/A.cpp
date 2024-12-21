#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[0] + a[1] == a[2] or (a[0] == a[1] and a[1] == a[2])) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}