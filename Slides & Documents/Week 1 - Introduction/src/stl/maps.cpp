// example question link: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/?source=submission-ac

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

void print_map(map<int, string> &m){
    for(auto &element : m){
        cout << "key: " << element.first << " value: " << element.second << "\n";
    }
}

int main(){
    map<int, string> numbers;
    numbers[0] = "not zero"; // if element does exist, it updates.
    cout << numbers[0] << "\n";

    numbers[0] = "zero"; // if element does not exist, it creates.
    cout << numbers[0] << "\n";

    numbers.insert({1, "one"}); // it is written with {} these braces. Takes key and value.
    numbers.insert(make_pair(2, "two"));

    cout << "size: " << numbers.size() << "\n";
    cout << "is empty: " << numbers.empty() << "\n"; // returns if the given map is empty or not. if empty 0 otherwise 1.

    if(numbers.find(3) != numbers.end()){  // if given key does not exist in the map, find will return the numbers.end() iterator. 
        cout << "numbers[3] exists and it is: " << numbers[1] << "\n";
    }else{
        cout << "numbers[3] does not exist. \n";
    }

    auto it = numbers.find(2); // iterator is a pointer which points to the corresponding key value pair in the map.
    cout << "key: " << it->first << " value: " << it->second << "\n";

    cout << "is 2 in map: " << numbers.count(2) << "\n"; // count can be used to determine if a key value pair exists in the map. If exists returns 1 otherwise 0.
    cout << "is 5 in map: " << numbers.count(5) << "\n";

    cout << "-----------\n";
    print_map(numbers);

    return 0;
}