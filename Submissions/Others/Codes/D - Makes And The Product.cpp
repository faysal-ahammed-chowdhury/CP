#include <bits/stdc++.h>
using namespace std;
#define int long long

int nCr(int n, int r) {
  if (r == 1) return n;
  if (r == 2) return (n * (n - 1)) / 2;
  return (n * (n - 1) * (n - 2)) / 6;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  if (a[1] == a[2] and a[2] == a[3]) {
    cout << nCr(mp[a[1]], 3) << '\n';
  }
  else if (a[2] == a[3]) {
    cout << nCr(mp[a[2]], 2) << '\n';
  }
  else {
    cout << nCr(mp[a[3]], 1) << '\n';
  }

  return 0;
}