#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int leftSize = mid - l + 1;
    int rightSize = r - mid;
    int L[leftSize], R[rightSize];
    int k = 0;
    for (int i = l; i <= mid; i++)
    {
        L[k] = arr[i];
        k++;
    }
    k = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        R[k] = arr[i];
        k++;
    }

    int i = 0, j = 0;
    int cur = l;
    while (i < leftSize && j < rightSize)
    {
        if (L[i] <= R[j])
        {
            arr[cur] = L[i];
            i++;
        }
        else
        {
            arr[cur] = R[j];
            j++;
        }
        cur++;
    }

    while (i < leftSize)
    {
        arr[cur] = L[i];
        i++;
        cur++;
    }

    while (j < rightSize)
    {
        arr[cur] = R[j];
        j++;
        cur++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);

    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}