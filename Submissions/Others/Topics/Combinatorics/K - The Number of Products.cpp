#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int neg = 0, pos = 0;
  long long ans_pos = 0, ans_neg = 0; 

  for (int i = 1; i <= n; i++) {
    if (a[i] < 0) {
      swap(neg, pos);
    }
    
    if (a[i] > 0) {
      pos++;
    }
    else {
      neg++;
    }

    ans_pos += pos, ans_neg += neg;
  }

  cout << ans_neg << ' ' << ans_pos << '\n';

  return 0;
}