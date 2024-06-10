#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  if (n == 0) {
    cout << 10 << '\n';
    return 0;
  }
  if (n < 10) {
    cout << n << '\n';
    return 0;
  }

  vector<int> v;
  for (int i = 9; i > 1; i--) {
    while (n % i == 0) {
      v.push_back(i);
      n /= i;
    }
  }

  if (n != 1) {
    cout << -1 << '\n';
    return 0;
  }

  sort(v.begin(), v.end());
  for (auto x : v) cout << x;
  cout << '\n';

  return 0;
}