# include <queue>
# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std ;

int main (){
    vector < vector < int > > adjacency_list = {
                    {} ,
                    {2 , 7 , 6} ,
                    {3 , 7 , 1} ,
                    {4 , 7 , 2} ,
                    {5 , 7 , 3} ,
                    {6 , 7 , 4} ,
                    {1 , 7 , 5} ,
                    {1 , 2 , 3 , 4 , 5 , 6}};
    unordered_map < int , bool > visited ;
    unordered_map < int , int > levels ;
    queue < int > bfs ;

    int start_node = 7 ;
    
    bfs . push (start_node) ;
    visited [start_node] = true ;
    levels [start_node] = 0 ; 
    
    while (! bfs . empty () ){
        int current_node = bfs . front () ;
        for ( int x : adjacency_list [ current_node ]){
            if (! visited [ x ]){
                bfs . push ( x ) ;
                visited [ x ] = true ;
                levels [ x ] = levels [ current_node ] + 1 ; 
            }
        }
        bfs . pop () ;
        cout << current_node << " Level: " << levels[current_node] << endl; 
    }
    cout << endl ;
    return 0;
}
