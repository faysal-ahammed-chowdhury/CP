#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int get_bit(int n, int pos) {
  return (n & (1 << pos)) == 0 ? 0 : 1;
}

void solve() {
  int n, x; cin >> n >> x;
  deque<int> dq1, dq2, dq3;
  for(int i = 0; i < n; i++) {
    int val; cin >> val;
    dq1.push_back(val);
  }
  for(int i = 0; i < n; i++) {
    int val; cin >> val;
    dq2.push_back(val);
  }
  for(int i = 0; i < n; i++) {
    int val; cin >> val;
    dq3.push_back(val);
  }

  int ans = 0;
  for(int i = 0; i < 3 * n; i++) {
    int first = dq1.empty() ? 0 : dq1.front();
    int second = dq2.empty() ? 0 : dq2.front();
    int third = dq3.empty() ? 0 : dq3.front();
    bool first_possible = true, second_possible = true, third_possible = true;
    for(int j = 0; j < 30; j++) {
      if(get_bit(x, j) == 0 && get_bit(first, j) == 1) first_possible = false;
      if(get_bit(x, j) == 0 && get_bit(second, j) == 1) second_possible = false;
      if(get_bit(x, j) == 0 && get_bit(third, j) == 1) third_possible = false;
    }
    if(first_possible && !dq1.empty()) {
      ans |= first;
      dq1.pop_front();
    }
    else if(second_possible && !dq2.empty()) {
      ans |= second;
      dq2.pop_front();
    }
    else if(third_possible && !dq3.empty()) {
      ans |= third;
      dq3.pop_front();
    }
  }
  if(ans == x) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}