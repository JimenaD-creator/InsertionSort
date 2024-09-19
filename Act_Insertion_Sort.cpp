#include <iostream>
#include <vector>
using namespace std;

bool esPrimo(int numero){
    if(numero == 1){
        return false;
    }
    if(numero == 2){
        return true;
    }
    if(numero % 2 == 0){
        return false;
    }

    for(int l = 3; l*l < numero; l+=2){
        if(numero % l == 0){
            return false;
        }

    }
    return true;
}
void insertionSort(vector <int> &primos){
    int n = primos.size();
    for(int i = 1; i < n; i++){
        int key = primos[i];
        int j = i-1;
        while(j>=0 && primos[j]>key){
            primos[j+1] = primos[j];
            j = j-1;
        }
        primos[j+1] = key;

    }
}
vector <int> primosOrdenados(vector <int> &numeros){
    vector <int> primos;
    for(int primo : numeros){
        if(esPrimo(primo)){
            primos.push_back(primo);
        }
    }
    insertionSort(primos);
    return primos;

}


int main(){

vector<int> numeros = {12, 5, 3, 7, 11, 4, 8, 13};
vector <int> primos_Ordenados = primosOrdenados(numeros);

for(int num : primos_Ordenados){
    cout << num << " ";

}



}