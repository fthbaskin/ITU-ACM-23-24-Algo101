#include <iostream>
#include <string>

using namespace std;

int main(){

    string my_string;
    my_string.append("m"); // it takes string as a parameter and appends the given string to the end of the my_string.
    cout << my_string << "\n";

    string new_string = "a";
    string new_string2 = "z";
    string new_string3 = "m";

    cout << my_string.compare(new_string) << "\n"; // if lexicographically greater, 1
    cout << my_string.compare(new_string2) << "\n"; // if lexicographically smaller, -1 
    cout << my_string.compare(new_string3) << "\n"; // if lexicographically equals, 0
    
    
    my_string += "inato";
    
    cout << my_string << "\n";

    my_string.replace(0, 4, "obi"); // first parameter is starting index, second one is the size, third one is the string to add.
    cout << my_string << "\n";

    cout << my_string.substr(1, 3) << "\n"; // first parameter is for starting point, second one is for the length of the substr.

    return 0;
}