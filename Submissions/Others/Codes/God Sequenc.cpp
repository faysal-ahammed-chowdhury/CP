#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  int sum = 0;
  if (a <= b) {
    for (int i = 1; i <= b; i++) {
      cout << -i << ' ';
      sum -= i;
    }
    for (int i = 1; i < a; i++) {
      cout << i << ' ';
      sum += i;
    }
    cout << -sum << '\n';
  }
  else {
    for (int i = 1; i <= a; i++) {
      cout << i << ' ';
      sum += i;
    }
    for (int i = 1; i < b; i++) {
      cout << -i << ' ';
      sum -= i;
    }
    cout << -sum << '\n';
  }

  return 0;
}