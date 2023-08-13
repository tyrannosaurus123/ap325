#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100010
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0)
int arr[100010];
int ans=0;
void mergeSort(int* arr, int len) {
    if (len <= 1) return;

    // Divide the array into two halves
    int leftLen = len / 2, rightLen = len - leftLen;
    int *leftArr = arr, *rightArr = arr + leftLen;

    // Recursively sort the left and right halves
    mergeSort(leftArr, leftLen);
    mergeSort(rightArr, rightLen);

    // Merge the two sorted halves
    static int tmpArr[MAX_N]; // temporary array to store the merged result
    int tmpLen = 0, l = 0, r = 0;
    while (l < leftLen && r < rightLen) {
        if (leftArr[l] <= rightArr[r]) {
            tmpArr[tmpLen++] = leftArr[l++];
            ans+=r;
        } else {
            tmpArr[tmpLen++] = rightArr[r++];
        }
    }
    // Add any remaining elements from the left or right half
    while (l < leftLen) {
        tmpArr[tmpLen++] = leftArr[l++];
        ans+=r;
    }
    while (r < rightLen) {
        tmpArr[tmpLen++] = rightArr[r++];
    }
    // Copy the merged result back into the original array
    for (int i = 0; i < tmpLen; i++) {
        arr[i] = tmpArr[i];
    }
}

signed main() {
    io;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr, n);
    cout<<ans<<endl;
    return 0;
}