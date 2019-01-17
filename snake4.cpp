#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
int pp=1;
struct value{

int x,y,x1,y1;
char val;
};
struct snake{

int x,y;
char val;
};
struct node
{
    char data;
    int x,y;
    node *next,*next1,*next2;

};
class linked_list
{
private:
    node *head,*tail,*head1,*head2;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node_at_tail(char n,int g,int f)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->x= g;
        tmp->y= f;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void endd(int g,int h){

    node *t,*tt;
    int i=0,k=0,flag=0;
    while(i<20){
        k=0;
        while(k<60){
                flag=0;
                if(i==0 || i==19)
                cout<<"-";
        else if(k==0||k==59 )
            cout<<"|";
            else
            {if(i==g && k==h)
                    if(pp==1){
                            flag=1;
                cout<<"H";
                    }
        t=head;
            while(t!=NULL){
                if(i==t->x && k==t->y){
                    cout<<t->data;

                    flag=1;
                }
                t=t->next;
            }

        if(flag==0)
            cout<<" ";
            }


            k++;
        }
        cout<<endl;
        i++;
    }



    }
void up(){
        int i=0,j,h;
node *t,*p,*tt;
t=head;

j=t->x;
h=t->y;
while(t->next!=NULL){
    tt=t;
    t=t->next;

}
tt->next=NULL;

t->next=head;

head=t;
t=head;
j=j-1;
t->x=j;
t->y=h;
    }
    void right(){
        int i=0,j,h;
node *t,*p,*tt;
t=head;

j=t->x;
h=t->y;
while(t->next!=NULL){
    tt=t;
    t=t->next;

}
tt->next=NULL;

t->next=head;

head=t;
t=head;
h=h+1;
t->x=j;
t->y=h;
t=head;
while(t!=NULL){
    t=t->next;
}
    }

    void left(){
        int i=0,j,h;
node *t,*p,*tt;
t=head;
j=t->x;
h=t->y;
while(t->next!=NULL){
    tt=t;
    t=t->next;

}
tt->next=NULL;

t->next=head;

head=t;
t=head;
h=h-1;
t->x=j;
t->y=h;

    }
void down(){
        int i=0,j,h;
node *t,*p,*tt;
t=head;

j=t->x;
h=t->y;
while(t->next!=NULL){
    tt=t;
    t=t->next;

}
tt->next=NULL;

t->next=head;

head=t;
t=head;
j=j+1;
t->x=j;
t->y=h;

    }

    int food(int x,int y){
    node *t,*p= new node;
    t=head;
    int j,h;
    j=t->x;
    h=t->y;
    t=t->next;
    while(t!=NULL){
        if(j==t->x && h==t->y)
        {
         cout<<"YOU ARE OUT"<<endl;
return 1;
        }
        t=t->next;
    }
    t=head;

    if(t->x==x && t->y==y){

pp=0;
        while(t->next!=NULL){
            t=t->next;
        }

        p->x=t->x+1;
        p->y=t->y;
        p->data='@';
        p->next=NULL;
        t->next=p;

    }



return 0;
    }
    void save(int a,int b){
        node *t;
        fstream st;
st.open("mjindal.txt");
t=head;
while(t!=NULL){
    st<<t->x<<","<<t->y<<",";
    cout<<t->x<<"+"<<t->y<<endl;
    t=t->next;
}
cout<<"saved"<<endl;
    }


    void saved(){

fstream in;
string d;
    string filepath = "mjindal.txt";
in.open("mjindal.txt");

cout<<"--------"<<endl;

while(!in.eof()){

    in>>d;
}
int i,j,k=0,j1,k1=0;
for(i=0;d[i]!='\0';i++){
        k=0;k1=0;
        while(d[i]!=','){
    j=d[i]-48;
    k=k*10+j;
    i++;
        }
        i++;
        while(d[i]!=','){
    j1=d[i]-48;
    k1=k1*10+j1;
    i++;
        }
cout<<k<<"-"<<k1<<endl;
add_node_at_tail('@',k,k1);
}
in.close();
in.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc);
in.close();
    }
};
int main(){
linked_list a;
int opt,n,n1,i,f;
int k;
struct value v;
struct snake s;
v.x=3;
v.y=5;
v.val='H';
s.x=4;
s.y=8;
s.val='@';
int w,q,e;
int nn;
cout<<"enter 1 for saved"<<endl;
cin>>nn;
if(nn!=1){
          cout<<"Enter the node value: ";
      cin>>n;
      for(i=0;i<n;i++){
              a.add_node_at_tail(s.val,s.x,s.y);
              s.x++;
    }
}
else{
        a.saved();
}
    a.endd(v.x,v.y);
cin>>w;
while(w!=0){
if(w==1){
        a.left();
        f=a.food(v.x,v.y);
a.endd(v.x,v.y);
}
    else if(w==3){
            a.right();
            f=a.food(v.x,v.y);
    a.endd(v.x,v.y);
    }
    else if(w==5){
             a.up();
             f=a.food(v.x,v.y);
    a.endd(v.x,v.y);
    }
    else
    if(w==2){
             a.down();
             f=a.food(v.x,v.y);
    a.endd(v.x,v.y);

    }
    cout<<"enter 0 to exit else "<<endl;
    cin>>w;
    if(f==1)
        break;
  if(pp==0){
    v.x=rand() % 15 + 1;
        v.y=rand() % 15 + 1;
        pp=1;
  }
}
a.save(v.x,v.y);
}
