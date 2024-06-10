#include <bits/stdc++.h>
using namespace std;
#define ll long long
int f91(int n)
{
    if (n >= 101)
    {
        return n - 10;
    }

    return f91(f91(n + 11));
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        printf("f91(%d) = %d\n", n, f91(n));
    }
    return 0;
}
