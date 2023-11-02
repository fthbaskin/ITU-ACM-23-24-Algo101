#include <iostream>
#include <set>

using namespace std;

void print_set(set<int> &s){
    for(auto &element : s){
        cout << element << " ";
    }
    cout << "\n";
}

int main(){
    set<int> my_set;

    for(int i = 0; i < 10; i++){
        my_set.insert(i);
    }
    print_set(my_set);

    if(my_set.find(1) != my_set.end()){ // if 1 does not exist iterator will be my_set.end() otherwise will point to the 1.
        cout << "1 exists in the set\n";
    }else{
        cout << "1 does not exist in the set\n";
    }
    auto it = my_set.find(5);
    cout << "*it = " <<  *it << "\n";

    cout << "size: " << my_set.size() << "\n";
    cout << "is empty: "<< my_set.empty() << "\n"; // returns 1 if set is empty otherwise 0.

    my_set.erase(4);
    cout << "after deletion\n";
    print_set(my_set);

    return 0;
}