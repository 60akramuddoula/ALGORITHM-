#include <bits/stdc++.h>
using namespace std;

int bnSearch(vector<int> &v, int k)
{
    int l = 0;
    int r = v.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == k)
            return mid;
        else if (v[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    int ans = bnSearch(v, k);
    if (ans != -1)
        cout << "Index: " << ans << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
