/*   State Space:- An 8X8 matrix with any arrangement of n<=8 queens
 * Initial State:- No queens on the board(i.e., all entries are null)
 *
 * Action:- Add a new queen in an empty column
 * Goal state:- 8 Queens placed on the board such that all queens are in non-attacking position
 * 
 * Cost:- One per queen placed
 * Heuristic Function:- Number of feaisble blocks(so that queen can be palced) int the current state.
 */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,vector<vector<int>>> p;

bool chkpos(vector<vector<int>> &v,int rws, int clm){
    int i, j;
   
    for (i = 0; i < clm; i++) 
        if (v[rws][i]) 
            return false; 
   
    for (i = rws, j = clm; i >= 0 && j >= 0; i--, j--) 
        if (v[i][j]) 
            return false; 
   
    for (i = rws, j = clm; j >= 0 && i < 8; i++, j--) 
        if (v[i][j]) 
            return false; 
   
    return true; 
}




int hval(vector<vector<int>> &v)
{ int a,b,cnt=0;
  vector<int> pe,q;
  vector<vector<int>> temp(8,vector<int>(8,0)); 
  for( a=0;a<8;a++){
        for(b=0;b<8;b++){
             if(v[a][b]==1)
                  {pe.push_back(a);
                   q.push_back(b);}
        }
  }
  int k = pe.size();
  int h,fl=0,j = q.size();
  
   for( a=0;a<8;a++){
       fl=0;
        for(b=0;b<8;b++){
            for( h=0;h<k;h++){
                if(a==pe[h])
                    {fl=1;
                     break;}
            }                  
            if(fl==1)continue;
            for( h=0;h<k;h++){
                if(b==q[h])
                    {fl=1;
                        break;}
            }
            if(fl==1)continue;
             for( h=0;h<k;h++){
                 if(abs(a-pe[h]) == abs(b-q[h]))
                     {  fl==1;
                        break;}
             }
                 
            if(fl==0)
                cnt++;
        }
   }
             
  return cnt;
  
}
void sovleAstar(priqueue<p,vector<p>,greater<p>> &open, vector<vector<int>> &v){

    open.push(make(0,v));
    int k = 1;
    while(!open.empty()){
        for(int j = 0; j < 8; ++j){
            p pais = open.top();
            vector<vector<int>> vec = pais.second;
            if(pais.first!=0)
                  { int u = hval(vec);
                    pais.first -= u;
                  }
            int t = pais.first;
            if(chkpos(vec,j,t)){
                if(t == 7){
                     vec[j][t] = 1;

                     cout << "solution :"<<k << endl;
                     ++k;

                     for(auto it : vec){
                        for(auto i : it){
                            cout << i << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }else{
                    vec[j][t] = 1;

                    
                   int y = hval(vec);
                   y=y+(t+1);
                    open.push(make(y,vec));
                }  
            }
        }
        open.pop();        
    }
}


int main(){
    
    priqueue<p,vector<p>,greater<p>> open;
    
    vector<vector<int>> v(8,vector<int>(8,0));
    sovleAstar(open,v);
}