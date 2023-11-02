#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &v){
    int size = v.size();
    for(int i = 0; i < size; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> my_vector;

    my_vector.push_back(77);

    for(int i = 0; i < 5; i++){
        my_vector.push_back(i);
        cout << "size: " << my_vector.size() << "\n";
        cout << "capacity: " << my_vector.capacity() << "\n"; // do not be confused with capacity. When solving questions, use .size();
    }
    cout << "-------------------\n"; 
    print_vector(my_vector);

    my_vector.pop_back(); // deletes the last element in the vector.
    cout << "after pop_back: \n";
    print_vector(my_vector);
    cout << "size: "<< my_vector.size() << "\n"; // size is decreased by 1.
    cout << "capacity: " << my_vector.capacity() << "\n";  // capacity does not change. We allocate the memory with the same amount of byte.
    

    my_vector.insert(my_vector.begin() + 1, 99); // inserts element at the desired place of the vector.
    cout << "after insertion: \n";
    print_vector(my_vector);

    my_vector.erase(my_vector.end() - 2); // deletes the element at the desired place of the vector.
    cout << "after deletion: \n";
    print_vector(my_vector);

    bool is_empty = my_vector.empty();
    if(!is_empty){
        cout << "vector is not empty.\n";
    }else{
        cout << "vector is empty.\n";
    }

    return 0;
}