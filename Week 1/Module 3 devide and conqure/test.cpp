#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int num[N];

// Function prototype for merge
void merge(int l, int r, int mid);

void mergesort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
}

void merge(int l, int r, int mid)
{
    int left_sz = mid - l + 1;
    int L[left_sz + 1]; // Corrected the array size
    int right_sz = r - mid;
    int R[right_sz + 1]; // Corrected the array size

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < left_sz; i++) // Corrected the loop condition
    {
        L[i] = num[l + i];
    }
    for (int j = 0; j < right_sz; j++) // Corrected the loop condition
    {
        R[j] = num[mid + 1 + j];
    }

    L[left_sz] = INT_MAX;  // Set sentinel values
    R[right_sz] = INT_MAX; // Set sentinel values

    int lp = 0, rp = 0;

    // Merge the two sorted arrays back into num[]
    for (int k = l; k <= r; k++)
    {
        if (L[lp] <= R[rp])
        {
            num[k] = L[lp];
            lp++;
        }
        else
        {
            num[k] = R[rp];
            rp++;
        }
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
