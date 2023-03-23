#include<iostream>
using namespace std;

void pascaltriangle(int h, int arr[][10]){
    for(int i=0; i<h; i++){
        for(int j=0; j<h; j++){
            if(j==0 || i==j) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
}

void render(int h, int arr[][10]){
   for(int i=0; i<h; i++){
        // print spaces before the numbers
        for(int k=0; k<h-i; k++){
            cout<<"  ";
        }
        for(int j=0; j<=i; j++){
            // print each number with two spaces between them
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int h;
    cout<<"Enter the number you want to find the Pascal triangle up to: ";
    cin>>h;
    int arr[10][10];
    pascaltriangle(h, arr);
    render(h, arr);
    return 0;
}

