#include <bits/stdc++.h>
using namespace std;

// @author: Faaysal

#define ll long long
const int MAX = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int x;
    for (ll i = 1, sum = 1; i <= MAX; i *= 2, sum += i) {
      if (n % sum == 0) {
        x = sum;
      }
    }

    cout << n / x << '\n';
  }

  return 0;
}