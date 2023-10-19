#include <iostream>
using namespace std;

int largestsum(int arr[], int num) {
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < num; i++) {
        // currentSum = max(arr[i], currentSum + arr[i]);
        // maxSum = max(maxSum, currentSum);
        if(currentSum + arr[i] > arr[i]){
            currentSum = currentSum + arr[i]; 
        }
        else{
            currentSum = arr[i]; 
        }
        if(currentSum > maxSum){
            maxSum = currentSum; 
        }
    }

    return maxSum;
}

int main() {
    int arr[] = {-1, 3, -2, 5, 3, -5, 2, 2};
    int num = sizeof(arr) / sizeof(arr[0]);

    int result = largestsum(arr, num);
    cout << "The largest sum of a subarray is: " << result << endl;

    return 0;
}
