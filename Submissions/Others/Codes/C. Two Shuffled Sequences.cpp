#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n];
  map<int, int> freq;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
  sort(a, a + n);

  bool ok = true;

  vector<int> ans1, ans2;
  for(auto [val, cnt]: freq) {
    if(cnt > 2) {
      ok = false;
      break;
    }
    if(cnt == 1) {
      ans2.push_back(val);
    }
    else {
      ans1.push_back(val);
      ans2.push_back(val);
    }
  }

  if(ok) {
    reverse(ans2.begin(), ans2.end());
    cout << "Yes\n";
    cout << (int)ans1.size() << '\n';
    for(auto i: ans1) {
      cout << i << ' ';
    }
    cout << '\n';
    cout << (int)ans2.size() << '\n';
    for(auto i: ans2) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  else {
    cout << "No\n";
  }
  return 0;
}