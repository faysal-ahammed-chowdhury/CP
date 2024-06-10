#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int first_odd_index = a[1], first_even_index = a[2];
    bool ok_odd_index = true, ok_even_index = true;
    for(int i = 1; i <= n; i++) {
      if(i & 1) {
        if(first_odd_index % 2 != a[i] % 2) {
          ok_odd_index = false;
        }
      }
      else {
        if(first_even_index % 2 != a[i] % 2) {
          ok_even_index = false;
        }
      }
    }

    if(ok_even_index && ok_odd_index) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }

  return 0;
}