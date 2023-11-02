#include <iostream>
#include <vector>

using namespace std;

int recursive_fibonacci(int input){
    if(input == 0 || input == 1){ // base condition.
        return 1;
    }

    return recursive_fibonacci(input - 1) + recursive_fibonacci(input - 2);
}

int iterative_fibonacci(int input){
    if(input == 0 || input == 1){
        return 1;
    }
    vector<int> fibonacci = {1,1}; // defined as 
    int new_fibonacci = 0;
    for(int i = 2; i <= input; i++){
        new_fibonacci = fibonacci[i-1] + fibonacci[i-2];
        fibonacci.push_back(new_fibonacci);
    }
    return fibonacci[input];
}

int main(){ 

    cout << recursive_fibonacci(8) << "\n";
    cout << iterative_fibonacci(7) << "\n";
    return 0;
}