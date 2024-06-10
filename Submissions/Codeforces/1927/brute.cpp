#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  do {
    unordered_set<int> se;
    for (int i = 1; i <= n; i++) {
      int sum = 0;
      for (int j = i; j <= i + k - 1; j++) {
        sum += a[j];
      }
      se.insert(sum);
    }
    for (int j = 1; j <= n; j++) {
      cout << a[j] << ' ';
    }
    if (se.size() == 1) {
      cout << "OK";
      cout << '\n';
    }
    else if (se.size() == 2) {
      int f = *se.begin();
      se.erase(se.begin());
      int s = *se.begin();
      if (abs(f - s) <= 1) {
        cout << "OK";
        cout << '\n';
      }
    }
    else {
      cout << '\n';
    }
  } while (next_permutation(a + 1, a + n + 1));

  return 0;
}