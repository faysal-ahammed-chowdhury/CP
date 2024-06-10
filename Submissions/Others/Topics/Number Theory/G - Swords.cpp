#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mx = *max_element(a, a + n);

  int g = 0;
  for(int i = 0; i < n; i++) {
    g = __gcd(g, (mx - a[i]));
  }

  long long y = 0, z = g;
  for(int i = 0; i < n; i++) {
    y += (mx - a[i]) / z;
  }

  cout << y << ' ' << z << '\n';

  return 0;
}