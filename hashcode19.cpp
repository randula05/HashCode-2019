#include <iostream>
using namespace std;

typedef struct photo{
    int id;
    char hv;
    int tagCount;
    int v;
    string tags[100000];
    struct photo *next;
}photo;
photo *start=NULL;


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        photo *p=new photo;
        p->id=i;
        cin>>p->hv>>p->tagCount;
        p->v=-1;
        string s;
        for(int i=0;i<p->tagCount;i++){
            cin>>s;
            p->v++;
            p->tags[p->v]=s;
        }
        p->next=NULL;

        photo *ptr=start;
        if(ptr==NULL){
            start=p;
        }else{
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=p;
        }
    }
    photo *ptr=start;
    while(ptr!=NULL){
        cout<<ptr->id<<ptr->hv<<ptr->tagCount<<" "<<ptr->tags[0]<<ptr->tags[1]<<endl;
        ptr=ptr->next;
    }
    
}
