#include <iostream>
#include <fstream>
using namespace std;

typedef struct photo{
    int id[2];
    char hv;
    int tagCount;
    int v;
    string tags[100];
    struct photo *next;
}photo;
photo *start=NULL;

int main(){
    // Input file
    ifstream file("a_example.txt");

    // Assign variables
    int n;
    file>>n;
    for(int i=0;i<n;i++){
        photo *p=new photo;
        p->id[0]=i;
        file>>p->hv>>p->tagCount;
        p->v=-1;
        string s;
        for(int i=0;i<p->tagCount;i++){
            file>>s;
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

    // Arrange photo nodes
    int merge=0,count=0,f;
    photo *ptr=start;
    photo *temp;
    while(ptr!=NULL){
        if(ptr->hv=='V'){
            if(merge==0){
                ptr->hv='H';
                temp=ptr;
                count++;
            }else{
                temp->id[1]=ptr->id[0];
                int tempCount=temp->tagCount;
                for(int i=0;i<ptr->tagCount;i++){
                    f=0;
                    for(int j=0;j<tempCount;j++){
                        //cout<<ptr->tags[i]<<temp->tags[j]<<endl;
                        if(ptr->tags[i]==temp->tags[j]){
                            f=1;
                            break;
                        }
                        if(f==0 && j==tempCount-1){
                            temp->tagCount++;
                            temp->v++;
                            temp->tags[temp->v]=ptr->tags[i];
                            //cout<<temp->tags[temp->v]<<endl;
                        }
                        //cout<<temp->tagCount<<endl;
                    }
                }
                cout<<endl;
                /* for(int i=0;i<temp->tagCount;i++){
                    for(int j=0;j<ptr->tagCount;j++){
                        cout<<temp->tags[i]<<" "<<ptr->tags[j]<<endl;
                        
                    }
                } */
            }
            merge=!merge;
        }else
            count++;
        ptr=ptr->next;
    }

    /* // Order the nodes by tags
    ptr=start;
    photo *ptr2;
    f=0;
    while(ptr!=NULL){
        if(ptr->hv=='V'){
            ptr=ptr->next;
            continue;
        }
        for(int i = 0; i < ptr->next->tagCount; i++){
            ptr2=ptr->next;
            temp=ptr2;
            f=0;
            while(ptr2!=NULL){
                if(ptr2->hv=='V'){
                    temp=ptr2;
                    ptr2=ptr2->next;
                    continue;
                }
                
                for(int j = 0; j < ptr2->tagCount; j++){
                    cout<<ptr->tags[i]<<" "<<ptr2->tags[j]<<" "<<i<<" "<<j<<endl;
                    if(ptr->tags[i]==ptr2->tags[j]){
                        f=1;
                    }
                }
                if(f==1){
                    cout<<"11111111111111111"<<endl;
                    temp->next=ptr2->next;
                    ptr2->next=ptr->next;
                    ptr->next=ptr2;
                    ptr=ptr->next;
                    break;
                }
                temp=ptr2;
                ptr2=ptr2->next;
                cout<<f<<" "<<ptr->next->tags[i]<<" "<<endl;
            }
            cout<<f<<"*"<<endl;

        }
        ptr=ptr->next;
    }
     */

    // Save output file
    ofstream ofile("output1.txt");
    ofile<<count<<endl;
    ptr=start;
    while(ptr!=NULL){
        if(ptr->hv=='H'){

            //
            ofile<<ptr->id[0];
            if(ptr->id[1]){
                ofile<<" "<<ptr->id[1];
            }
            ofile<<endl;
            //

        }
        ptr=ptr->next;
    }
    
}
