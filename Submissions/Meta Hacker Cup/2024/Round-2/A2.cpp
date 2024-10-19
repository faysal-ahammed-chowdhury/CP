#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n;
vector<int> v;

void f(int cnt, int last, int val) {
  if (cnt == 0) {
    v.push_back(val);
    return;
  }
  int x = (n + 1) / 2;
  if (cnt == x) {
    for (int i = last + 1; i <= 9; i++) {
      f(cnt - 1, i - 1, val * 10 + i);
    }
  }
  else if (cnt > x) {
    for (int i = last; i <= 8; i++) {
      f(cnt - 1, i, val * 10 + i);
    }
  }
  else {
    for (int i = last; i >= 1; i--) {
      f(cnt - 1, i, val * 10 + i);
    }
  }
}

void prec() {
  for (int len = 3; len <= 17; len += 2) {
    n = len;
    f(len, 1, 0);
  }
}

int cs;
void solve() {
  int a, b, m; cin >> a >> b >> m;
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    if (i >= a and i <= b and i % m == 0) {
      ans++;  
    }
  }
  // for (auto x : v) {
  //   if (x >= a and x <= b and x % m == 0) {
  //     ans++;
  //   }
  // }
  auto it1 = lower_bound(v.begin(), v.end(), a);
  auto it2 = upper_bound(v.begin(), v.end(), b);
  while (it1 != it2) {
    int x = *it1;
    if (x >= a and x <= b and x % m == 0) {
      ans++;
    }
    ++it1;
  }
  cout << "Case #" << ++cs << ": " << ans << '\n';
}

void main_() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();
  // cout << v.size() << '\n';

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
  char *stack, *send;
  stack = (char *)malloc(stsize);
  send = stack + stsize - 16;
  send = (char *)((uintptr_t)send / 16 * 16);
  asm volatile(
    "mov %%rsp, (%0)\n"
    "mov %0, %%rsp\n"
    :
    : "r"(send));
  func();
  asm volatile("mov (%0), %%rsp\n" : : "r"(send));
  free(stack);
}


int32_t main() {
  run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
  return 0;
}