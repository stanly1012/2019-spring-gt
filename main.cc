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
    int b=0;
    int a=0;
    int degree[10];
    Vertex *node;
    vector<Vertex*> name;
    vector<Vertex*> oddvertex;
    vector<Vertex*> finalpath;
    vector<Vertex*> recordpath;
    nm->interpret("topo.txt");
 /////////////////////////////////////////////catch vertex
    node = nm->get_all_nodes();
    while(node!=0){
        name.push_back(node);
        node=node->next;
    }
    vertexcount=name.size();
////////////////////////////////////////////////find odd vertex     
    

    for(int j=0; j<vertexcount; j++){
        degree[j]=0;
        
        for(int k=0; k<vertexcount; k++){
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
    while(b<vertexcount){  
        int q=0;
        int k;
        for(k=0; k<vertexcount; k++){
            if(nm->connected(name[b]->name,name[k]->name)==0){
                recordpath.push_back(name[b]);
                nm->linkdown(name[b],name[k]);  

                //nm->linkdown(name[k],name[b]);
                /*if(name[k]>name[b]){
                    nm->linkdown(name[b],name[k]);
                    nm->linkdown(name[k],name[b]);
                }
                else{
                    nm->linkdown(name[k],name[b]);
                    nm->linkdown(name[b],name[k]);
                }*/
                break;
            } 
            else if (nm->elist==0){
                cout<<"whether is last one:"<<b<<endl;
                recordpath.push_back(name[b]);
                q=2;
                break;
            }            
            else if(k==4&&b!=4){                
                recordpath.erase(recordpath.end()-1);
                finalpath.push_back(name[b]);
                q=1;
                break;
            }


        }
        cout<<"whether repeat:"<<q<<endl;
        if(q==1){
            b=recordpath.size();
            cout<<"repeat b:"<<b<<endl;
        }
        else if(q==2){
            b=5;
        }
        else{
            cout<<"no repeat b:"<<k<<endl;
            b=k;
        }    
        //cout<<k<<endl;

    }
    
    
/////////////////////////////////////////////// 

    /*cout<<degree[0]<<endl;
    cout<<degree[1]<<endl;
    cout<<degree[2]<<endl;
    cout<<degree[3]<<endl;
    cout<<degree[4]<<endl;*/
    cout<<"recordpath size:"<<recordpath.size()<<endl;
    cout<<recordpath.at(0)->name<<endl;
    cout<<recordpath.at(1)->name<<endl;
    cout<<recordpath.at(2)->name<<endl;
    cout<<recordpath.at(3)->name<<endl;
    cout<<recordpath.at(4)->name<<endl;
    cout<<recordpath.at(5)->name<<endl;
    cout<<recordpath.at(6)->name<<endl;
    cout<<recordpath.at(7)->name<<endl;
    //cout<<recordpath.at(8)->name<<endl;
    //cout<<recordpath.at(9)->name<<endl;
    cout<<"finalpath size:"<<finalpath.size()<<endl;    
    cout<<finalpath.at(0)->name<<endl;
    //cout<<finalpath.at(1)->name<<endl;
    nm->print_all_e();
    
   
    
    Gplot *gp = new Gplot();
    gp->gp_add(nm->elist);
    gp->gp_dump(false);
    gp->gp_export("plot");

    return 0;
}