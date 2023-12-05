# include <queue>
# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std ;

void dfs ( int current_node ,vector < vector < int > >& adjacency_list ,unordered_map < int , bool >& visited ){
    
    visited [ current_node ] = true ;
    cout << current_node << " " ;    
    for ( int x : adjacency_list [ current_node ]){
        if (! visited [ x ])
            dfs (x , adjacency_list , visited ) ;
    }
}

int main (){

    vector < vector < int > > adjacency_list ={{} , 
    {2 , 3 , 4} ,
    {1 , 3 , 5 , 7} , {1 , 2 , 6 , 7} ,
    {1} , {2 , 6 , 9} ,
    {3 , 5 , 9} , {2 , 3 , 8} ,
    {7 , 9} , {5 , 6 , 8}
    };
    unordered_map < int , bool > visited ;

    int start_node = 1 ;

    dfs (start_node , adjacency_list , visited ) ;

    cout << endl ;

    return 0;
}