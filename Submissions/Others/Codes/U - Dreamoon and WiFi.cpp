#include <bits/stdc++.h>
using namespace std;

string s1, s2;
vector<int> ending;
int n, m;

void fun(int i, int pos) {
  if (i == n) {
    ending.push_back(pos);
    return;
  }
  if (s2[i] == '+') {
    fun(i + 1, pos + 1);
  }
  else if (s2[i] == '-') {
    fun(i + 1, pos - 1);
  }
  else {
    fun(i + 1, pos + 1);
    fun(i + 1, pos - 1);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s1 >> s2;
  n = s1.size();
  m = s2.size();

  fun(0, 0);

  int last = 0;
  for (auto c : s1) {
    if (c == '+') last++;
    else last--;
  }

  int match = 0;
  for (auto x : ending) {
    if (x == last) match++;
  }

  int x = ending.size();
  double ans = (double) match / x;
  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}