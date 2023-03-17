#include<iostream>
using namespace std; 

// declare functions
void finding_M_and_m1m2m3_value(int x, int y, int z, int& M, int& m1, int& m2, int& m3); 
int checking_for_final_answer(int a, int b, int c, int x, int y, int z, int m1, int m2, int m3, int M); 

int main(){
    int a, b, c, m1, m2, m3, M; 
    int x,y,z; 
    cout<<"Enter the value of a, b and c:"<<endl; 
    cin>>a>>b>>c;
    cout<<"Enter the value of x,y and z:"<<endl; 
    cin>>x>>y>>z; 
    // call function to calculate M and m1,m2,m3
    finding_M_and_m1m2m3_value(x, y, z, M, m1, m2, m3);
    // call function to check for final answer
    int result = checking_for_final_answer(a, b, c, x, y, z, m1, m2, m3, M);
    if(result != -1){
        cout<<"x = "<<result<<endl;
    }

    return 0;
}

// define function to calculate M and m1,m2,m3
void finding_M_and_m1m2m3_value(int x, int y, int z, int& M, int& m1, int& m2, int& m3){
    M = x * y * z; 
    m1 = M/x; m2 = M/y; m3 = M/z; 
}

// define function to check for final answer
int checking_for_final_answer(int a, int b, int c, int x, int y, int z, int m1, int m2, int m3, int M){
    bool bool_var = false; 
    int n1, n2, n3;
    for(n1=1; n1<=10; n1++){
        if((n1*m1)%x == 1){
            bool_var = true;
            break; // exit loop once a solution is found
        }
    }

    for(n2=1; n2<=10; n2++){
        if((n2*m2)%y == 1){
            bool_var = true; 
            break; // exit loop once a solution is found
        }
    }

    for(n3=1; n3<=10; n3++){
        if((n3*m3)%z == 1){
            bool_var = true; 
            break; // exit loop once a solution is found
        }
    }

    if(bool_var){
        // calculate new values of n1, n2, and n3
        int newn1=n1; int newn2 = n2; int newn3 = n3; 
        // calculate final answer for x
        int x_final =(a*newn1*m1 + b*newn2*m2 + c*newn3*m3) % M;  
        return x_final;
    }else{
        return -1; // no solution found
    }
}

