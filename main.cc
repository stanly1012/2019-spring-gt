/* 
    Your main program goes here
*/
#include <iostream>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"
#include <vector>
using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();




int main(int argc, char** argv){
    int vertexcount;
    int j,k;
    int degree[10];
    Vertex *node;
    vector<Vertex*> name;
    nm->interpret("topo.txt");
 /////////////////////////////////////////////
    node = nm->get_all_nodes();
    while(node!=0){
        name.push_back(node);
        node=node->next;
    }
    vertexcount=name.size();
////////////////////////////////////////////////    
    
    for(j=0; j<vertexcount; j++){
        degree[j]=0;
        for(k=0; k<vertexcount; k++){
            if(nm->connected(name[j]->name,name[k]->name)==0)
                degree[j]+=1;
            else
                degree[j]==degree[j];
        }
    }
    
//////////////////////////////////////////////

    cout<<degree[0]<<endl;
    cout<<degree[1]<<endl;
    cout<<degree[2]<<endl;
    cout<<degree[3]<<endl;
    cout<<degree[4]<<endl;


    return 0;
}