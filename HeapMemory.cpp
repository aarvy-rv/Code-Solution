#include<iostream>
using namespace std;

void squareAndCubeNumber(int num){
    int* ar = new int[2];
    int square = num*num;
    int cube = square * num;
    
    ar[0] = square;
    ar[1] = cube;

    cout<<ar[0] << " "<< ar[1]<<"\n";

    /*
    
     logic to use square and cub to reach a result 
    
    */

   delete(ar);

}
int main(){

    squareAndCubeNumber(2);
    squareAndCubeNumber(3);
    squareAndCubeNumber(4);

}