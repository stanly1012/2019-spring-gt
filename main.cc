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
    Edge* path;
    vector<Vertex*> name;
    vector<Vertex*> oddvertex;
    vector<Vertex*> finalpath;
    vector<Vertex*> recordpath;
    vector<Vertex*> havepath;
    vector<Vertex*> result;
    vector<Edge*> totalpath;
    nm->interpret("topo.txt");
        
    path=nm->elist;
    while(path!=0){
        totalpath.push_back(path);
        path=path->next;
    }
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
//////////////////////////////////////////add the edge 

  
    if((oddvertex.size()==2)&&(nm->connected(oddvertex.at(0)->name,oddvertex.at(1)->name)==0)){
        nm->connect(oddvertex[a]->name,oddvertex[a+1]->name);
        }
    else if(oddvertex.size()>=2){
        int pathdistance[10];
        for(int j=0; j<oddvertex.size(); j++){
            for(int k=0; k<vertexcount; k++){
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
        
        for(int c=0; c<(totalpath.size()-havepath.size()); c++){
            nm->disconnect(nm->elist->head->name,nm->elist->tail->name);   
        }
        
        nm->interpret("topo.txt");
        
        while(e<oddvertex.size()-1){
            int d;
            for(d=0; d<havepath.size(); d++){
                if(oddvertex.at(e+1)==havepath.at(d)&&pathdistance[d]==1) {
                    nm->connect(oddvertex.at(e)->name,oddvertex.at(e+1)->name);
                    break;
                }
                else if((oddvertex.at(e+1)==havepath.at(d))&&(pathdistance[d]!=1)){
                        if(nm->connected(oddvertex.at(e)->name,oddvertex.at(e+1)->name)==0){
                            nm->connect(oddvertex.at(e)->name,oddvertex.at(e+1)->name);
                            break;
                        }
                        else{
                            for(int w=0; w<havepath.size(); w++){
                                if(nm->connected(oddvertex.at(e+1)->name,havepath.at(w)->name)==0&&pathdistance[w]==pathdistance[d]-1){
                                    //nm->connect(oddvertex.at(e)->name,havepath.at(w)->name);
                                    nm->connect(havepath.at(w)->name,oddvertex.at(e+1)->name);
                                    for(int u=0; u<havepath.size(); u++){
                                        if(nm->connected(havepath.at(w)->name,havepath.at(u)->name)==0&&pathdistance[u]==pathdistance[w]-1){
                                            nm->connect(havepath.at(w)->name,havepath.at(u)->name);
                                        }    
                                    
                                        if(havepath.at(u)==oddvertex.at(e)){
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    
                }
                else if((oddvertex.at(e+1)!=havepath.at(d))&&(nm->connected(oddvertex.at(e)->name,oddvertex.at(e+1)->name)==1)){
                    for(int w=0; w<havepath.size(); w++){
                        if(nm->connected(oddvertex.at(e)->name,havepath.at(w)->name)==0
                        &&nm->connected(oddvertex.at(e+1)->name,havepath.at(w)->name)==0){
                            nm->connect(havepath.at(w)->name,oddvertex.at(e)->name);
                            nm->connect(havepath.at(w)->name,oddvertex.at(e+1)->name);
                            break;   
                        }
                    }
                    break; 
                }    
            }
            
            if(d==havepath.size()){
                e=e+1;
            }    
            else{
                e=e+2;
            }   
                cout<<"next oddvertex:"<<e<<endl;
        }
            

        
    }

////////////////////////////////////////euler path
   while(b<vertexcount){    
        int q=0;
        int k;
        int a;
        for(k=0; k<vertexcount; k++){
            if(nm->connected(name[b]->name,name[k]->name)==0){                
                recordpath.push_back(name[b]);
                
                if(nm->connected_d(name[b]->name,name[k]->name)==0){
                    nm->linkdown(name[b],name[k]);
                }
                else if(nm->connected_d(name[k]->name,name[b]->name)==0){
                    nm->linkdown(name[k],name[b]);
                }
                a=b;
                break;
            } 
            else if (nm->elist==0){
                recordpath.push_back(name[b]);
                q=2;
                break;
            }            
            else if(k==vertexcount-1){                
                recordpath.erase(recordpath.end()-1);
                finalpath.push_back(name[b]);
                q=1;
                break;
            }
        }
        cout<<"whether repeat or the end:"<<q<<endl;
        
        
        //cout<<k<<endl;
        //cout<<a<<endl;
        if(q==1){
            b=a;
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
    cout<<"final path:";
    for(int f=0; f<result.size(); f++){
        cout<<result.at(f)->name<<"->";
    }    

    return 0;
}