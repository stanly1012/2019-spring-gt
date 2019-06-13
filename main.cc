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
#include <fstream>
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
        cout<<"oddvertex size:"<<oddvertex.size()<<endl;
        cout<<"oddvertex:"<<oddvertex.at(oddvertex.size()-1)->name<<endl;
        }
    }
////////////////////////////////////////////////////add the edge between two odd vertex
   
    if((oddvertex.size()==2)&&(nm->connected(oddvertex.at(0)->name,oddvertex.at(1)->name)==0)){
        nm->connect(oddvertex[a]->name,oddvertex[a+1]->name);
        }
    else if(oddvertex.size()>=2){
        int pathdistance[10];
        havepath.insert(havepath.begin(),name[0]);
        pathdistance[0]=0;
        cout<<"path vertex:"<<havepath.at(0)->name<<endl;
        cout<<"distance:"<<pathdistance[0]<<endl;
        for(int j=0; j<name.size(); j++){
            for(int k=0; k<vertexcount; k++){
                if(nm->connected(name.at(j)->name,name.at(k)->name)==0){                
                    havepath.insert(havepath.end(),name[k]);
                    pathdistance[havepath.size()-1]=j+1;
                    if(nm->connected_d(name[j]->name,name[k]->name)==0){
                        nm->linkdown(name[j],name[k]);
                    }
                    else if(nm->connected_d(name[k]->name,name[j]->name)==0){
                        nm->linkdown(name[k],name[j]);
                    }
                    nm->print_all_e();
                    cout<<"path vertex size:"<<havepath.size()<<endl;
                    cout<<"path vertex:"<<havepath.at(havepath.size()-1)->name<<endl;
                    cout<<"distance:"<<pathdistance[havepath.size()-1]<<endl;
                }
            }
        }       
        nm->interpret("topo.txt");
        
        while(e<oddvertex.size()-1){
            int c;
            int d;
            int flag=0;
            for(c=0; c<havepath.size(); c++){
                for(d=0; d<havepath.size(); d++){
                    if(oddvertex.at(e+1)==havepath.at(d)&&oddvertex.at(e)==havepath.at(c)&&(pathdistance[d]-pathdistance[c]==1)) {
                        nm->connect(oddvertex.at(e)->name,oddvertex.at(e+1)->name);
                        flag=1;
                        break;
                    }
                    else if(oddvertex.at(e)==havepath.at(c)&&(oddvertex.at(e+1)==havepath.at(d))&&(pathdistance[d]-pathdistance[c]!=1)){
                            if(nm->connected(oddvertex.at(e)->name,oddvertex.at(e+1)->name)==0){
                                nm->connect(oddvertex.at(e)->name,oddvertex.at(e+1)->name);
                                flag=1;
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
                                                flag=1;
                                                break;
                                            }
                                        }
                                    }
                                    if(flag==1){
                                        break;
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
                                flag=1;
                                break;   
                            }
                            else if(nm->connected(oddvertex.at(e)->name,havepath.at(w)->name)==0
                            &&nm->connected(oddvertex.at(e+1)->name,havepath.at(w)->name)!=0){
                                for(int j=0; j<havepath.size(); j++){
                                    if(nm->connected(havepath.at(j)->name,oddvertex.at(e+1)->name)==0
                                    &&nm->connected(havepath.at(j)->name,oddvertex.at(e)->name)==0){
                                        nm->connect(havepath.at(j)->name,oddvertex.at(e)->name);
                                        nm->connect(havepath.at(j)->name,oddvertex.at(e+1)->name);
                                        flag=1;
                                        break;
                                    }    
                                    else if(nm->connected(havepath.at(j)->name,oddvertex.at(e+1)->name)==0
                                    &&nm->connected(havepath.at(w)->name,havepath.at(j)->name)==0){
                                        nm->connect(havepath.at(w)->name,oddvertex.at(e)->name);
                                        nm->connect(havepath.at(j)->name,oddvertex.at(e+1)->name);
                                        nm->connect(havepath.at(j)->name,havepath.at(w)->name);
                                        flag=1;
                                        break;
                                    }
                                }
                                if(flag==1){
                                    break;
                                }
                            
                            }

                            
                        }
                        if(flag==1){
                            break;
                        }
                        
                    }

                }
                
                if(flag==1){
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
        int o=0;
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
            else if(k>=vertexcount-1){ 
                    cout<<"repeat b:"<<b<<endl;
                    finalpath.push_back(name[b]);
                    q=1; 
                break;
            }
        }
        cout<<"whether repeat or the end:"<<q<<endl;

        if(q==1){
            Vertex* lastrecordpath;
            int p=recordpath.size()-1;
            lastrecordpath=recordpath.at(p);
            int f;
            for(f=0; f<name.size(); f++){
                if(name.at(f)==lastrecordpath)
                    break;
            }
            recordpath.erase(recordpath.end()-1);
            cout<<"repeat f:"<<f<<endl;
            b=f;
            
            
        }
        else if(q==2){
            break;
        }
        else{
            cout<<"no repeat b:"<<k<<endl;
            b=k;
        }
 
    }
    

    for(int w=recordpath.size()-1; w>-1; w--){
        finalpath.insert(finalpath.end(),recordpath.at(w));
        
    }
    cout<<"final path:";
    for(int f=0; f<finalpath.size(); f++){
        cout<<finalpath.at(f)->name<<"->";
    }
    
    for(int f=0; f<finalpath.size()-1; f++){
        nm->connect(finalpath.at(f)->name,finalpath.at(f+1)->name);
    }

    string writeFileName="final_result.txt";
    ofstream out(writeFileName.c_str());
    for(int i=0; i<finalpath.size(); i++){
        out<<finalpath.at(i)->name<<"->";
    }
    out.close();
    
    Gplot *gp = new Gplot();
    gp->gp_add(nm->elist);
    gp->gp_dump(true);
    gp->gp_export("plot");
    
    return 0;
}