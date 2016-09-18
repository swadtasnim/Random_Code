#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data,row,col;
    node *colprev,*colnext,*rowprev,*rownext;

};

node *headr[2]={NULL};
node *headc[2]={NULL};



node* getnode(int x,int y, int z)
{
    node* n= new node();
    n->data=x;
    n->row=y;
    n->col=z;
    n->colprev=n->colnext=n->rowprev=n->rownext=NULL;

    return n;
}

void ins(int x, int y , int z)
{
    node *n=getnode(x,y,z);

    if (headr[y]==NULL)
    {headr[y]=n;

    }

    else
    {
        headr[y]->colprev=n;
        n->colnext=headr[y];
        headr[y]=n;

    }

    if(headc[z]==NULL)
    {
        headc[z]=n;


    }
    else
    {headc[z]->rowprev=n;
     n->rownext=headc[z];
     headc[z]=n;
     }



}

void disrow(node* r)
{
     while(r->colnext!=NULL)
        r=r->colnext;

    while(r!=NULL)
    {  if(r->data!=0)
       cout<<r->data<<" ";
       else
        cout<<" ";
       r=r->colprev;
    }
    cout<<endl;
}

void discol(node* r)
{
    // cout<<"fine"<<endl;
     while(r->rownext!=NULL)
        r=r->rownext;

    while(r!=NULL)
    {  if(r->data==0)
        cout<<" ";
        else
       cout<<r->data<<" ";
       r=r->rowprev;
    }
    cout<<endl;
}


int main()
{  int n;
   for(int i=0; i<2; i++)
   {
       for(int j=0; j<2; j++)
        {cin>>n;
       ins(n,i,j);}
   }

   for(int i=0; i<2; i++)
   {
       cout<<"row "<<i+1<<endl;
       disrow(headr[i]);

   }


    for(int i=0; i<2; i++)
        {
            cout<<"column "<<i+1<<endl;
            discol(headc[i]);
        }

}
