#include <iostream>
using namespace std;

int main()
{
    int n;                       // number of cupboards
    int left_open, right_open;   // number of left and right doors that are open
    int left_close, right_close; // number of left and right doors that are closed

    cin >> n; // input the number of cupboards

    // input the positions of the left and right doors
    for (int i = 0; i < n; i++)
    {
        int left, right;
        cin >> left >> right;
        if (left == 1)
            left_open++;
        else
            left_close++;
        if (right == 1)
            right_open++;
        else
            right_close++;
    }

    // calculate the minimum number of seconds to change the position of all doors
    int seconds = min(left_open, left_close) + min(right_open, right_close);
    cout << seconds << endl;

    return 0;
}
