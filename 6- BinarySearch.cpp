#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target){
    if(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] < target){
            return binarySearch(arr, mid + 1, high, target);
        }

        return binarySearch(arr, low, mid - 1, target);
    }

  
    return -1;
}

int main(){
    int arr[] = {11, 12, 22, 54, 78};
    int target = 22;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, target);

    if(result != -1){
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;

}
