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
    int degree;
    Vertex *node;
    vector<Vertex*> name;
    //int name[10];
    /* start your program */
    nm->interpret("topo.txt");
    
    
    
    /*if(nm->connected("a","b")==0){
        i+=1;}
    if(nm->connected("a","c")==0){
        i+=1;}
    if(nm->connected("a","d")==0){
        i+=1;}
        
    if(i%2==1){
        printf("odd");}
        
    nm->print_all_e();*/
    
   
    node = nm->get_all_nodes();
    while(node!=0){
        name.push_back(node);
        node=node->next;
    }
    vertexcount=name.size();
    
    for(j=0; j<vertexcount; j++){
        for(k=0; k<vertexcount; k++){
            if(nm->connected(name[j]->name,name[k]->name)==0)
                degree+=1;
        }
    }

 
    cout<<degree;

    return 0;
}