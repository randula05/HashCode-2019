#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
typedef struct photo{
    int id;
    char hv;
    int tagCount;
    vector<string> tags;
    vector<struct photo*> links;
}photo;

int main(){
    ifstream file("a_example.txt");
    photo *temp;
    int n,merge=0,f=0;
    file>>n;
    for(int i=0;i<n;i++){
        photo *newPhoto=new photo;
        newPhoto->id=i;
        file>>newPhoto->hv>>newPhoto->tagCount;
        for(int j=0;j<newPhoto->tagCount;j++){
            string s;
            file>>s;
            if(newPhoto->hv='V'){
                if(merge==0){
                    newPhoto->tags.insert(newPhoto->tags.end(),s);
                    temp=newPhoto;
                }else{
                    temp->tags.insert(temp->tags.end(),s);
                    f=1;
                }
            }
        }
        if(f!=0) free(newPhoto);
        merge=!merge;
    }

}
