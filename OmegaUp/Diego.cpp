#include <iostream>
#include <algorithm>

using namespace std;

int N, mili;
int arr[2000002];
int botellas = 1;
int tamaActual;
long long int necesario;
int respuestaBotella = 0;
int respuestaTama = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ini = 1, fin = 1, sobra;
    cin >> N >> mili;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    sobra = mili;
    tamaActual = arr[1];
    respuestaBotella = 1;
    respuestaTama = tamaActual;
    while(fin < N){
        fin++;
        necesario = (long long int) (arr[fin] - tamaActual) * botellas;
        if(sobra >= necesario){
            sobra = sobra - necesario;
            botellas++;
            tamaActual = arr[fin];
        }else{
            sobra = sobra + (tamaActual - arr[ini]);
            ini++;
            fin--;
            botellas--;
        }
        if(botellas > respuestaBotella){
            respuestaBotella = botellas;
            respuestaTama = tamaActual;
        }
    }
    cout << respuestaBotella << " " << respuestaTama;
    return 0;
}