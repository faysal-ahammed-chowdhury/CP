#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int a[N], n;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  stack<pair<int, int>> st;
  int right1[n + 1];
  for (int i = 1; i <= n; i++) {
    while (!st.empty() and st.top().first <= a[i]) {
      right1[st.top().second] = i - 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    right1[st.top().second] = n;
    st.pop();
  }

  int left1[n + 1];
  for (int i = n; i >= 1; i--) {
    while (!st.empty() and st.top().first < a[i]) {
      left1[st.top().second] = i + 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    left1[st.top().second] = 1;
    st.pop();
  }

  int right2[n + 1];
  for (int i = 1; i <= n; i++) {
    while (!st.empty() and st.top().first >= a[i]) {
      right2[st.top().second] = i - 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    right2[st.top().second] = n;
    st.pop();
  }

  int left2[n + 1];
  for (int i = n; i >= 1; i--) {
    while (!st.empty() and st.top().first > a[i]) {
      left2[st.top().second] = i + 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    left2[st.top().second] = 1;
    st.pop();
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long mx = 1ll * (i - left1[i] + 1) * (right1[i] - i + 1) * a[i];
    long long mn = 1ll * (i - left2[i] + 1) * (right2[i] - i + 1) * a[i];
    ans += mx;
    ans -= mn;
  }
  cout << ans << '\n';

  return 0;
}