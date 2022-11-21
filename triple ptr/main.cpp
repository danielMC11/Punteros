#include "iostream"
#include "random"
using namespace std;


int*** create_triple_ptr(int n1_ptr, int n2_ptr,int n3_ptr){
    int ***ptr;
    ptr = (int***) calloc(n1_ptr, sizeof(int));
    for(int i=0;i<n1_ptr;i++){
        ptr[i] = (int**) calloc(n2_ptr, sizeof(int));
        for(int j=0;j<n2_ptr;j++){
            ptr[i][j]=(int*) calloc(n3_ptr,sizeof(int));
        }
    }

    return ptr;
}

void show(int*** ptr,int n1,int n2,int n3){

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            for(int k=0;k<n3;k++){
                cout<<ptr[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    
}


int main(){

    int*** ptr;

    int n1,n2,n3;

    ptr=create_triple_ptr(4,3,4);

    show(ptr,4,3,4);

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            free(ptr[i][j]);
        }
    }

    free(ptr);

    ptr=NULL;

    return 0;
}