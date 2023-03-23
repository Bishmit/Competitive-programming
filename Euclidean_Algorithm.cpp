#include<iostream>
using namespace std; 
int euclidean_algorithm(int a, int b){
	if(b==0) 
	return a; 

  else
  return euclidean_algorithm(b, a%b); 
}

int main(){
	int a, b; 
	cin>>a>>b; 
	int gcd = euclidean_algorithm( a, b); 
	cout<<"GCD "<<gcd<<endl;
	return 0; 
}
