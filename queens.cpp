#include <iostream>
#include<stdlib.h>
#define N 8
using namespace std;

struct node{
int arr[8];
struct node *next;
};
struct node *first = NULL;
struct node *last = NULL;
struct node* tmp;
void insert(int value,int ar[N]) {
int check =0;
if (last == NULL) {
  last = (struct node *)malloc(sizeof(struct node));
  last->next = NULL;
  for(int i=0;i<N;i++)
  {
              if(ar[i]==0 && check==0)
              {
                      last->arr[i]=value;
                      check++;
              }
              else
              {
                      last->arr[i]=ar[i];
              }
  }
  first = last;
} else {
  tmp=(struct node *)malloc(sizeof(struct node));
  last->next = tmp;
   for(int i=0;i<N;i++)
  {
  if(ar[i]==0 && check==0)
  {
  tmp->arr[i]=value;
  check++;
}
else
{
tmp->arr[i]=ar[i];
}
}
  tmp->next = NULL;
  last = tmp;
}
}
int *delete2() {
tmp = first;
if (tmp->next != NULL) {
  first=first->next;
  return tmp->arr;
} else {
 tmp = first;
  first = NULL;
  last = NULL;
  return tmp->arr;

}

}
void printSolution(int board[N][N],int ls[N])
{
    for(int i=0;i<N;i++)
    {
    board[i][ls[i]-1]=1;
    }
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
        cout << " | " << ((board[i][j]==1)?((char)(board[i][j]+80)):((char)(board[i][j]+88)));
    cout << " |\n";
}
exit(0);

}

bool isSafe(int board[N][N], int col, int l[N])
{
int check = 0;

int i, j,row,b[8][8]={0};

for(int i=0;i<N;i++)
{
if(l[i]==0 && check==0)
{
row=i;
break;
}
if(l[i]!=0)
{
b[i][l[i]-1]=1;
}
}
for (i = 0; i < row; i++)
    if (b[i][col])
        return false;

for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (b[i][j])
        return false;

for (i = row, j = col; i >= 0 && j < N; i--, j++)
    if (b[i][j])
        return false;

if(row==7)
{
l[row]=col+1;
printSolution(board,l);
}

return true;
}

void solve8(int board[N][N],bool cnd)
{
int arr[N]= {0};
if(!cnd)
{
            int *ptr;
            ptr = delete2();
            for(int i=0;i<N;i++)
            {
            arr[i]=*ptr;
            ptr++;
            }

            for(int i=0;i<N;i++)
            {
                    if(isSafe(board,i,arr))
                            {
                                    insert(i+1,arr);
                            }
           }
    }

            if(cnd)
            {
                    for (int i = 0; i < N; i++)
                    {
                              insert(i+1,arr);
                    }
                    cnd=false;
            }
            solve8(board,cnd);
}

int main()
{

int board[N][N] = {{0, 0, 0, 0,0, 0, 0, 0},
{0, 0, 0, 0,0, 0, 0, 0},
{0, 0, 0, 0,0, 0, 0, 0},
{0, 0, 0, 0,0, 0, 0, 0},
{0, 0, 0, 0,0, 0, 0, 0},
{0, 0, 0, 0,0, 0, 0, 0},
{0, 0, 0, 0,0, 0, 0, 0},
{0, 0, 0, 0,0, 0, 0, 0} };

solve8(board, true);

return 0;
}
