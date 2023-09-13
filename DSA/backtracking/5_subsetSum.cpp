#include <iostream>
using namespace std;

int subsets(int *arr, int ci, int li, int k, int sum) {
    if (ci > li) {
        if (sum == k) {
            return 1; // Found a subset that sums to k
        }
        return 0; // Reached the end of the array
    }

    // Include the current element in the subset 
    int include = subsets(arr, ci + 1, li, k, sum + arr[ci]);

    // Exclude the current element from the subset
    int notInclude = subsets(arr, ci + 1, li, k, sum);

    // Return the total count of subsets that sum to k
    return include + notInclude;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << subsets(arr, 0, n - 1, k, 0) << endl;
    }

    return 0;
}
