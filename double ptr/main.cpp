#include "iostream"

using namespace std;

int main(){

    int** matriz;

    matriz =(int**) calloc(3, sizeof(int));

    for(int i=0;i<3;i++)
        matriz[i] = (int* ) calloc(5, sizeof(int));
    

    int* vec = (int*) calloc(5, sizeof(int));
    vec[0] = 1;
    vec[2] = 1;
    vec[4] = 1;

    matriz[1] = vec;


    /*for(int i=0;i<3;i++){
        for(int j=0;j<5;j++)
            {
                matriz[i][j] = i + j;

            }
    }*/

    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++)
            {
               //cout<<matriz[i][j]<<" ";
               cout<<*(*(matriz+i)+j)<<" ";
            }
            cout<<endl;
    }

    for(int i=0;i<3;i++)
        free(matriz[i]);


    free(vec);
    free(matriz);
    vec=NULL;
    matriz=NULL;
    
    

    

    return 0;
}