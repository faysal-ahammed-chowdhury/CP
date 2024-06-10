#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  set<int> missing_numbers;
  for (int i = 0; i <= n + 200; i++) {
    missing_numbers.insert(i);
  }

  int a[n + 1];
  map<int, int> freq;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
    missing_numbers.erase(a[i]);
  }

  while (q--) {
    int i, x; cin >> i >> x;
    int y = a[i];
    a[i] = x;
    missing_numbers.erase(x);
    freq[y]--;
    freq[x]++;
    if (freq[y] == 0) {
      freq.erase(y);
      missing_numbers.insert(y);
    }
    cout << *missing_numbers.begin() << '\n';
  }

  return 0;
}