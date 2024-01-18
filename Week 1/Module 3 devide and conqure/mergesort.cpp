#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int num[N];

void merge(int l, int r, int mid)
{
    int left_sz = mid - l + 1;
    int right_sz = r - mid;
    int L[left_sz + 1];
    int R[right_sz + 1];

    int j = 0;
    for (int i = l; i <= mid; i++, j++)
    {
        L[j] = num[i];
    }

    j = 0;
    for (int i = mid + 1; i <= r; i++, j++)
    {
        R[j] = num[i];
    }

    L[left_sz] = INT_MAX;
    R[right_sz] = INT_MAX;

    int lp = 0;
    int rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            num[i] = L[lp];
            lp++;
        }
        else
        {
            num[i] = R[rp];
            rp++;
        }
    }
}

void mergesort(int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, r, mid);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    mergesort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}
