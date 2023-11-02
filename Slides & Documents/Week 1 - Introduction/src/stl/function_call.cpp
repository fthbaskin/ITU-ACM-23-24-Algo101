#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &v){
    for(unsigned int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void multiply_with_two(vector<int> my_v, int index){
    cout << "in multiply_with_two_ function: \n";
    my_v[index] *= 2;
    print_vector(my_v);
}

void multiply_with_two_correct(vector<int> &my_v, int index){
    my_v[index] *= 2;
    cout << "in multiply_with_two_correct function: \n";
    print_vector(my_v);
}

void change_variable(int old_value, int new_value){
    cout << "in change_variable function: \n";

    old_value = new_value;
    cout << old_value << "\n";
}

void change_variable_correct(int *old_value, int new_value){
    cout << "in change_variable_correct function: \n";
    cout << old_value << "\n";
    *old_value = new_value;
    cout << *old_value << "\n";
}

// we use & so that we do not write * again and again when we want to change the value that pointers point to.
void change_variable_correct2(int &old_value, int new_value){ 
    cout << "in change_variable_correct2 function: \n";
    cout << old_value << "\n";
    old_value = new_value;
    cout << old_value << "\n";
}

int main(){

    vector<int> v = {0, 1, 2, 3};
    print_vector(v);
    multiply_with_two(v, 2);
    cout << "came back:\n";
    print_vector(v);

    multiply_with_two_correct(v, 2);
    cout << "came back:\n";
    print_vector(v);

    int number = 10;
    change_variable(number, 5);
    cout << "came back:\n";
    cout << number << "\n";

    change_variable_correct(&number, 5);
    cout << "came back:\n";
    cout << number << "\n";

    change_variable_correct2(number, 61);
    cout << "came back:\n";
    cout << number << "\n";

    return 0;
}