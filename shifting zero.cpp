#include <iostream>
using namespace std;

void lastzero(int arr[], int num) {
    int count = 0; 
    for(int i = 0; i<num; i++){
        if(arr[i]!=0){
           arr[count] = arr[i]; 
           count++; 
        }
    }
    for(int j = count; j<num; j++){
        arr[j] = 0; 
    }

}
void render(int arr[], int num) {
    for(int i = 0; i<num; i++){
        cout<<arr[i]<<" "; 
    }
}
int main() {
    int arr[] = {0,1,0,3,12};
    int num = sizeof(arr) / sizeof(arr[0]);
    lastzero(arr,num); 
    render(arr,num); 

    return 0;
}
