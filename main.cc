/* 
    Your main program goes here
*/
#include <iostream>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"
#include <vector>
#include <string>
using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();




int main(int argc, char** argv){
    int vertexcount;
    int j,k;
    int a=0;
    int degree[10];
    vector<Vertex*> oddvertex;
    Vertex *node;
    vector<Vertex*> name;
    nm->interpret("topo.txt");
 /////////////////////////////////////////////catch vertex
    node = nm->get_all_nodes();
    while(node!=0){
        name.push_back(node);
        node=node->next;
    }
    vertexcount=name.size();
////////////////////////////////////////////////find odd vertex     
    

    for(j=0; j<vertexcount; j++){
        degree[j]=0;
        
        for(k=0; k<vertexcount; k++){
            if(nm->connected(name[j]->name,name[k]->name)==0)
                degree[j]+=1;
        }        
           
        if(degree[j]%2==1){            
        oddvertex.push_back(name[j]);
  
        }
    }
////////////////////////////////////////////////////add the edge between two odd vertex
   
   while(a<oddvertex.size()){
    nm->connect(oddvertex[a]->name,oddvertex[a+1]->name);
    a+=2;
    }

    
////////////////////////////////////////euler path





/////////////////////////////////////////////// 

    cout<<degree[0]<<endl;
    cout<<degree[1]<<endl;
    cout<<degree[2]<<endl;
    cout<<degree[3]<<endl;
    cout<<degree[4]<<endl;
    /*cout<<oddvertex[0]->name<<endl;
    cout<<oddvertex[1]->name<<endl;
    cout<<oddvertex[2]->name<<endl;
    cout<<oddvertex[3]->name<<endl;
    cout<<oddvertex[4]->name<<endl;*/

    
    cout<<a<<endl;
 

    nm->print_all_e();
    
    
    Gplot *gp = new Gplot();
    gp->gp_add(nm->elist);
    gp->gp_dump(false);
    gp->gp_export("plot");

    return 0;
}