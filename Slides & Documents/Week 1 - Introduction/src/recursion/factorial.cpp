#include <iostream>
#include <vector>

using namespace std;

int recursive_factorial(int input){
    if(input == 0){
        return 1;
    }
    return input * recursive_factorial(input - 1);
}

int iterative_factorial(int input){
    int result = 1;
    for(int i = 2; i <= input; i++){
        result *= i; 
    }
    return result;
}

int main(){

    cout << "4! = " << recursive_factorial(4) << "\n";
    cout << "3! = " << iterative_factorial(3) << "\n";

    return 0;
}