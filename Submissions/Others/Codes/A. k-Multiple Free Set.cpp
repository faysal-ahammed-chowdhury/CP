#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  set<int> se;
  int remove = 0;
  for(int i = 0; i < n; i++) {
    if(se.find(a[i]) != se.end()) {
      remove++;
      se.erase(a[i]);
      continue;
    }
    i128 need = (i128)a[i] * k;
    bool found = binary_search(a, a + n, need);
    bool next_found = binary_search(a, a + n, need * k);
    if(found && !next_found) {
      remove++;
    }
    else if(found && next_found) {
      se.insert(need);
    }
  }
  cout << n - remove << '\n';

  return 0;
}