/* 
    Your main program goes here
*/
#include <iostream>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();




int main(int argc, char** argv){
    int vertexcount;
    int b=0;
    int a=0;
    int e=0;
    int degree[10];
    Vertex *node;
    vector<Vertex*> name;
    vector<Vertex*> oddvertex;
    vector<Vertex*> finalpath;
    vector<Vertex*> recordpath;
    vector<Vertex*> havepath;
    vector<Vertex*> result;
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
   
  /*while(a<oddvertex.size()){
    nm->connect(oddvertex[a]->name,oddvertex[a+1]->name);
    a+=2;
    }*/
//////////////////////////////////////////add the edge with dijkstra
    cout<<"number of odd:"<<oddvertex.size()<<endl;
    if(oddvertex.size()==2){
        nm->connect(oddvertex[a]->name,oddvertex[a+1]->name);
        }
    else if(oddvertex.size()>2){
        for(int j=0; j<oddvertex.size(); j++){
            for(int k=0; k<vertexcount; k++){
                int pathdistance[10];
                if(nm->connected(oddvertex.at(j)->name,name.at(k)->name)==0){                
                    havepath.insert(havepath.end(),name[k]);
                    pathdistance[havepath.size()-1]=j+1;
                    if(nm->connected_d(oddvertex[j]->name,name[k]->name)==0){
                        nm->linkdown(oddvertex[j],name[k]);
                    }
                    else if(nm->connected_d(name[k]->name,oddvertex[j]->name)==0){
                        nm->linkdown(name[k],oddvertex[j]);
                    }
                    nm->print_all_e();
                    cout<<"path vertex size:"<<havepath.size()<<endl;                
                    cout<<"distance:"<<pathdistance[0]<<endl;
                    cout<<"distance:"<<pathdistance[1]<<endl;
                    cout<<"distance:"<<pathdistance[2]<<endl;
                    cout<<"distance:"<<pathdistance[3]<<endl;
                    cout<<"distance:"<<pathdistance[4]<<endl;
                    cout<<"distance:"<<pathdistance[5]<<endl;
                    cout<<"distance:"<<pathdistance[6]<<endl;
                    cout<<"distance:"<<pathdistance[7]<<endl;
                }

            }
   
        }
        nm->interpret("topo.txt");
        while(e<oddvertex.size()-1){
            int d;
            for(d=0; d<havepath.size(); d++){
                if(oddvertex.at(e+1)==havepath.at(d)) {
                    nm->connect(oddvertex.at(e)->name,oddvertex.at(e+1)->name);
                    break;
                }
            }
            
            if(e-d==0){
                e=e+2;
            }    
            else{
                e=e+1;
            }     
        }
            

        
    }

////////////////////////////////////////euler path

   while(b<vertexcount){    
        int q=0;
        int k;
        for(k=0; k<vertexcount; k++){
            if(nm->connected(name[b]->name,name[k]->name)==0){                
                recordpath.push_back(name[b]);
                if(nm->connected_d(name[b]->name,name[k]->name)==0){
                    nm->linkdown(name[b],name[k]);
                }
                else if(nm->connected_d(name[k]->name,name[b]->name)==0){
                    nm->linkdown(name[k],name[b]);
                }
                break;
            } 
            else if (nm->elist==0){
                recordpath.push_back(name[b]);
                q=2;
                break;
            }            
            else if(k==4){                
                recordpath.erase(recordpath.end()-1);
                finalpath.push_back(name[b]);
                q=1;
                break;
            }
        }
        cout<<"whether repeat or the end:"<<q<<endl;
        if(q==1){
            int a;
            a=recordpath.size();
            b=abs(k-a);
            cout<<"repeat b:"<<b<<endl;
        }
        else if(q==2){
            break;
        }
        else{
            cout<<"no repeat b:"<<k<<endl;
            b=k;
        }
 
    }
    
    for(int v=0; v<finalpath.size(); v++){
        result.insert(result.begin(),finalpath.at(v));
    }
    
    for(int w=recordpath.size()-1; w>-1; w--){
        result.insert(result.end(),recordpath.at(w));
    }
    
    cout<<"final result size:"<<result.size()<<endl;
    cout<<"final result:"<<result.at(0)->name<<endl;
    cout<<"final result:"<<result.at(1)->name<<endl;
    cout<<"final result:"<<result.at(2)->name<<endl;
    cout<<"final result:"<<result.at(3)->name<<endl;
    cout<<"final result:"<<result.at(4)->name<<endl;
    cout<<"final result:"<<result.at(5)->name<<endl;
    cout<<"final result:"<<result.at(6)->name<<endl;
    cout<<"final result:"<<result.at(7)->name<<endl;
    cout<<"final result:"<<result.at(8)->name<<endl;
    cout<<"final result:"<<result.at(9)->name<<endl;
    cout<<"final result:"<<result.at(10)->name<<endl;
    cout<<"final result:"<<result.at(11)->name<<endl;
/////////////////////////////////////////////// 

    /*cout<<degree[0]<<endl;
    cout<<degree[1]<<endl;
    cout<<degree[2]<<endl;
    cout<<degree[3]<<endl;
    cout<<degree[4]<<endl;*/
    /*cout<<"recordpath size:"<<recordpath.size()<<endl;
    cout<<recordpath.at(0)->name<<endl;
    cout<<recordpath.at(1)->name<<endl;
    cout<<recordpath.at(2)->name<<endl;
    cout<<recordpath.at(3)->name<<endl;
    cout<<recordpath.at(4)->name<<endl;
    cout<<recordpath.at(5)->name<<endl;
    cout<<recordpath.at(6)->name<<endl;
    cout<<recordpath.at(7)->name<<endl;
    cout<<recordpath.at(8)->name<<endl;*/
    //cout<<recordpath.at(9)->name<<endl;
    /*cout<<"finalpath size:"<<finalpath.size()<<endl;    
    cout<<finalpath.at(0)->name<<endl;
    cout<<finalpath.at(1)->name<<endl;*/
    nm->print_all_e();
    nm->print_all_v();
   
    
    Gplot *gp = new Gplot();
    gp->gp_add(nm->elist);
    gp->gp_dump(false);
    gp->gp_export("plot");

    return 0;
}