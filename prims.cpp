#include<iostream> 
using namespace std; 
void displayArray(int arr[]) 
{ 
 for(int i = 1;i<=6;i++) 
 { 
 cout<<arr[i]<<"\t"; 
 cin>>arr[i];
 } 
 cout<<endl; 
} 
class Graph 
{ 
 private: 
 int v,e; 
 int parent[20]; 
 int select(int c[],int k[]); 
 int adjMatrix[10][10]; 
 string departments[20]; 
 public: 
 Graph(); 
 void getv(); 
 void CreateGraph(); 
 void DisplayGraph(); 
 void Prim(); 
 void CheckInput(); 
 int findparent(int); 
 
  
}; 
Graph::Graph() 
 { 
 v = 0; 
 for(int i = 1 ; i<=10;i++) 
 {  
 parent[i]=i; 
 for(int j = 1;j<=10;j++) 
 { 
 adjMatrix[i][j] = 0; 
 departments[i]=" "; 
 } 
 } 
 } 
int Graph:: select(int c[],int k[]) 
 {  
 int min = 32767,ver; 
 for(int i =2;i<=v;i++) 
 { 
 if(c[i]<=min && k[i] == 0) 
 { 
 min = c[i]; 
 ver = i; 
 } 
 } 
  
 k[ver] = 1; 
 return ver; 
 } 
void Graph::getv() 
 { 
 cout<<"Enter no. of departments :: "<<endl;  cin>>v;
 for(int j=1;j<=v;j++){ 
 cout<<"Enter department "<<j<<endl; 
 string a; 
 cin>>a; 
 departments[j]=a; 
 } 
 } 
void Graph::CheckInput() { 
 cout<<"Checking input :: "<<endl; 
 for(int i = 1;i<=v;i++) 
 { 
 for(int j = 1;j<=v;j++) 
 { 
 cout<<adjMatrix[i][j]<<" "; 
 } 
 cout<<endl; 
 } 
 } 
void Graph :: CreateGraph() 
{  
 int s,d,w;  
 cout<<"Enter no. of paths :: "<<endl; 
 cin>>e; 
 cout<<"Creating paths :: (Enter appropriate source and  destination.)"<<endl; 
 for(int i = 1;i <= e;i++) 
 { 
 string source,destination; 
 cout<<"Enter Source :: "<<endl; 
 cin>>source; 
 cout<<"Enter Destination :: "<<endl; 
 cin>>destination; 
 for(int j=1;j<=v;j++){ 
 if(departments[j]==source){ 
 s=j; 
 } 
 else if(departments[j]==destination){ 
 d=j; 
 } 
  
 } 
 cout<<"Enter Distance :: "<<endl; 
 cin>>w; 
 adjMatrix[s][d] = w; 
 adjMatrix[d][s] = w; 
 }  
} 
void Graph :: DisplayGraph() 
{ 
 for(int i = 1; i<=v;i++) 
 { 
 cout<<"Adjacent vertices to "<<departments[i]<<" are :: "<<endl;  for(int j = 1;j<=v;j++) 
 { 
 if(adjMatrix[i][j] != 0) 
 { 
 cout<<departments[j]<<"\t";
 } 
 } 
 cout<<endl; 
 } 
} 
void Graph :: Prim() 
{  
 int TotWei = 0; 
 int cost[10],known[10],prev[10]; 
 int current = 1,Totv = 0; 
 for(int i = 2;i<=v;i++) 
 { 
 cost[i] = 32767; 
 known[i] = 0; 
 prev[i] = 0; 
 } 
 known[1] = 1;cost[1] = 0;prev[1] = -1; 
 cout<<"Process:: "<<endl; 
 while(Totv != v) 
 {  
 for(int i = 1;i<=v;i++) 
 { 
 if(adjMatrix[current][i] > 0 && adjMatrix[current][i] < cost[i]  && known[i] == 0) 
 { 
 cost[i] = adjMatrix[current][i]; 
 prev[i] = current; 
 } 
 } 
 current = select(cost,known); 
  
 Totv += 1; 
 } 
 cout<<"OUTPUT ::"<<endl; 
 cout<<"Start vertex :: "<<1<<endl; 
 cout<<"Following are the paths in the MST :: "<<endl;  for(int i = 2;i<=v;i++) 
 { 
 int temp; 
 temp=prev[i]; 
 cout<<"("<<departments[temp]<<", "<<departments[i]<<")"<<"\t";  TotWei += cost[i]; 
 } 
 cout<<"\nTotal distance of the MST :: "<<TotWei; 
} 
int Graph::findparent(int v) 
{ 
 if(parent[v] == v) 
 return v; 
 return findparent(parent[v]); 
} 
int main() 
{  
 Graph g; 
 g.getv(); 
 g.CreateGraph(); 
 g.CheckInput(); 
 g.DisplayGraph(); 
 int cont=1; 
 while(cont==1){
 int choice; 
  
cout<<"****************************************************************\n"; cout<<"\n1.MST by Prim's algorithm\n2.MST by Kruskal's algorithm\n3.Exit\n";  cin>>choice; 
 switch(choice){ 
 case 1: 
 cout<<"MST by Prim's algorithm:\n"; 
 g.Prim(); 
 cout<<endl; 
 break; 
 case 3: 
 cout<<"\nEnd of prg"<<endl; 
 cont=0; 
 break; 
 } 
 } 
 return 0; 
}
