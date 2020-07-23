#include <bits/stdc++.h>
#include <math.h>
#include <windows.h>

using namespace std;


void twoPlayer(int n)
{   cout<<"toss"<<endl;
    srand(time(0));
    Sleep(2000);
    int p1,p2,i = rand()%2;

    if(i==0)
        cout<<"Player 1 will play first"<<endl;
    else
        cout<<"Player 2 will play first"<<endl;

    cout<<"GAME START"<<endl;


    while(1){

    Sleep(2000);

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"Player 1 lost "<<endl;
          else
               cout<<"Player 2 lost "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"Player 1 lost "<<endl;
        else
           cout<<"Player 2 lost "<<endl;
      }
    break;
    }
  l: if(i==0)
       cout<<"Playe 1 chance "<<endl;
    else
       cout<<"Player 2 chance "<<endl;

    cin>>p1;
    if(p1<4 && p1>=1)
    n=n-p1;
    else
    { cout<<"Invalid move"<<endl;
      goto l;
    }
     cout<<"Remaining Sticks :  "<<n<<endl;
    Sleep(2000);

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"Player 1 lost "<<endl;
          else
               cout<<"Player 2 lost "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"Player 1 lost "<<endl;
        else
           cout<<"Player 2 lost "<<endl;
      }
    break;
    }

   k: if(i==1)
       cout<<"Player 1 chance "<<endl;
    else
       cout<<"Player 2 chance "<<endl;

    cin>>p2;
    if(p2<4 && p2>=1)
    n=n-p2;
    else
    { cout<<"Invalid move"<<endl;
      goto k;
    }

     cout<<"Remaining Sticks :  "<<n<<endl;
}
}
struct store{
  int v;
  int d;
  int i;

};

store t[54];
store f[54];

store mnmx(int n,int dpt,bool player,int alpha,int beta)
{  store z,j,k;
   j.v=0;j.d=0;j.i=0;
   if(n==1)
    {
        if(player)
        {
             z.v = -10;
             z.d = dpt;
             z.i = 0;
             return z;
        }
        else
         {
             z.v = 10;
             z.d = dpt;
             z.i =0;
             return z;
        }
    }
    int i;
    if(player)
    {  int mx=-999;
       int m=999;
        for(i=3;i>=1;i--)
        {  if(n-i>=1)
            {
            j= mnmx(n-i,dpt+1,false,alpha,beta);
            if(j.v>=mx && j.v!=0)
            {  if(j.v==mx)
                { if(j.d<m)
                    {
                    z.v=j.v;
                    z.d=j.d;
                    z.i = i;
                    }
                }
               else
                   {
                    mx=j.v;
                    z.v=j.v;
                    z.d=j.d;
                    z.i = i;
                    }
              //  if(j.v==10)
                   // break;
            }
            alpha=max(alpha,j.v);
            if(beta<alpha)
                break;
           }
        }
     return z;
    }
    else
    {
        int m =999;
       int mx=999;
        for(i=3;i>=1;i--)
        { if(n-i>=1)
            {
              j= mnmx(n-i,dpt+1,true,alpha,beta);
           if(j.v<=mx && j.v!=0)
            {  if(j.v==mx)
                { if(j.d<m)
                    {
                    z.v=j.v;
                    z.d=j.d;
                    z.i = i;
                    }
                }
               else
                   {
                    mx=j.v;
                    z.v=j.v;
                    z.d=j.d;
                    z.i = i;
                    }
                //if(z.v==-10)
                    //break;
            }
            beta=min(beta,j.v);

            if(beta < alpha )
                break;

           }
        }

     return z;
    }
}
void onePlayer(int n)
{
    cout<<"toss"<<endl;
    srand(time(0));
    Sleep(2000);
    int p1,p2,cpu,i = rand()%2;

    if(i==0)
        cout<<"Player won toss"<<endl;
    else
        cout<<"CPU won toss"<<endl;

    cout<<"--------start--------"<<endl;

 while(1){
    Sleep(2000);
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"Player lost "<<endl;
          else
               cout<<"CPU lost "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"Player lost "<<endl;
        else
           cout<<"CPU lost "<<endl;
      }
    break;
    }
    if(i==0)
     {
        l:cout<<"Player chance "<<endl;
        cin>>p1;
        if(p1<4 && p1>=1)
        n=n-p1;
        else
        { cout<<"Invalid move"<<endl;
          goto l;
        }
     }
     else
       {
        store res;
        cout<<"CPU chance "<<endl;
        res = mnmx(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU selects : "<<res.i<<endl;
        n=n-res.i;
       }

     cout<<"Remaining Sticks :  "<<n<<endl;
    Sleep(2000);
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"Player lost "<<endl;
          else
               cout<<"CPU lost "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"Player lost "<<endl;
        else
           cout<<"CPU lost "<<endl;
      }
    break;
    }


   if(i==1)
     {
        k:cout<<"Player chance "<<endl;
        cin>>p2;
        if(p2<4 && p2>=1)
        n=n-p2;
        else
        { cout<<"Invalid move"<<endl;
          goto k;
        }
     }
     else
       {
        store res;
        cout<<"CPU chance "<<endl;
        res = mnmx(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU selects : "<<res.i<<endl;
        n=n-res.i;
       }

        cout<<"Remaining Sticks :  "<<n<<endl;
  }


}


void AiVSAi(int n)
{
    cout<<"toss"<<endl;
    srand(time(0));
    Sleep(2000);
    int p1,cpu,i = rand()%2;

    if(i==0)
        cout<<"CPU 1 won toss"<<endl;
    else
        cout<<"CPU 2 won toss"<<endl;

    cout<<"start"<<endl;

 while(1){

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"CPU 1 lost "<<endl;
          else
               cout<<"CPU 2 lost "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"CPU 1 lost "<<endl;
        else
           cout<<"CPU 2 lost "<<endl;
      }
    break;
    }
    if(i==0)
     {
        cout<<"CPU 1 chance "<<endl;
        store res;
        res = mnmx(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 1 selects : "<<res.i<<endl;
        n=n-res.i;
        cout<<"Remaining Sticks :  "<<n<<endl;
     }
     else
       {
        store res;
        cout<<"CPU 2 chance "<<endl;
        res = mnmx(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 2 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
       }


    Sleep(2000);
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"CPU 1 lost "<<endl;
          else
               cout<<"CPU 2 lost "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"CPU 1 lost "<<endl;
        else
           cout<<"CPU 2 lost "<<endl;
      }
    break;
    }


   if(i==1)
     {
           store res;
        cout<<"CPU 1 chance "<<endl;
        res = mnmx(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 1 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
     }
     else
       {
        store res;
        cout<<"CPU 2 chance "<<endl;
        res = mnmx(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 2 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
       }
  }

}


int main()
{ int i,j,n,l;
  cout<<"Select which game you want:"<<endl;
  cout<<"1.Human Vs Human"<<endl;
  cout<<"2.Human Vs AI"<<endl;
  cout<<"3.AI Vs AI"<<endl;
  cin>>i;
  for(n=0;n<54;n++)
    {f[n].v=20;
    t[n].v=20;}

  cout<<"Enter no. of Sticks you'd like to play with:"<<endl;
  cin>>n;
  store k;
  Sleep(2000);
  cout<<"RULE: Enter a number from 1, 2, 3"<<endl;
  if(i==1)
     {
         twoPlayer(n);
         cout<<"GAME OVER"<<endl;

     }
  if(i==2)
     {
        onePlayer(n);
         cout<<"GAME OVER"<<endl;
     }

  if(i==3)
  {
      AiVSAi(n);
       cout<<"GAME OVER"<<endl;
  }

  return 0;
} 
