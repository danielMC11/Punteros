#include "iostream"
using namespace std;

int**** create_4_ptr(int n1_ptr,int n2_ptr,int n3_ptr,int n4_ptr){

    int**** ptr;

    ptr=(int****) calloc(n1_ptr,sizeof(int));
    for(int i=0;i<n1_ptr;i++){
        ptr[i]=(int***) calloc(n2_ptr,sizeof(int));
        for(int j=0;j<n2_ptr;j++){
            ptr[i][j]=(int**) calloc(n3_ptr,sizeof(int));
                for(int k=0;k<n3_ptr;k++){
                ptr[i][j][k]=(int*) calloc(n4_ptr,sizeof(int));
            }
        }
    }
    return ptr;
}

void show(int**** ptr, int n1, int n2, int n3, int n4){
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            for(int k=0;k<n3;k++){
                for(int l=0;l<n4;l++){
                        cout<<ptr[i][j][k][l]<<" ";
                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }
        cout<<"-------------------"<<endl<<endl;
    }

}

int main(){
    //Arreglo de Arreglos de Matrices de punteros
    int**** ptr;
    ptr=create_4_ptr(4,3,3,4);

    //ptr[3][2][2][2]=4;

    show(ptr,4,3,3,4);

    
    for(int j=0;j<2;j++){
        for(int k=0;k<3;k++){
            for(int l=0;l<4;l++){
                free(ptr[j][k][l]);
            }
        }
    }
    free(ptr);
    ptr=NULL;


    return 0;
}