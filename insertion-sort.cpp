#include <iostream>

using namespace std;

class Persona{
    private:
        int edad;
        string nombre;
    public:
        void setEdad(int);
        int getEdad();
        void setNombre(string);
        string getNombre();
        ~Persona(){};
};
void Persona::setEdad(int edad){
    this->edad=edad;
}
int Persona::getEdad(){
    return edad;
}

void Persona::setNombre(string nombre){
    this->nombre=nombre;
}
string Persona::getNombre(){
    return nombre;
}


template<typename T>
void mostrarArray(T* array, int n){
    cout<<"\t";
  for (int i=0; i<n; i++){
    cout<<*(array+i)<<", ";
  }
  cout<<endl;
}
template<typename T>
void mostrarObjetos(T array[],int n){
    cout<<"\t";
    for(int i=0;i<n;i++){
        cout<<array[i].getNombre()<<"("<<array[i].getEdad()<<"), ";
    }
    cout<<endl;
}

//PARA DATOS PRIMITIVOS(INT,FLOAT,STRING,CHAR)-----------------
//MENOR A MAYOR
template<typename T>
bool compare1(T x, T y) {
    return x <= y;
}
//MAYOR A MENOR
template<typename T>
bool compare2(T x, T y) {
    return x > y;
}
//PARA CLASES---------------------------------------------------
//MENOR MAYOR CLASES-POR NOMBRE
template<typename T>
bool compareNombre1(T x,T y){
    return x.getNombre()<=y.getNombre();
}
//MAYOR A MENOR-PARA CLASES
template<typename T>
bool compareNombre2(T x,T y){
    return x.getNombre()>y.getNombre();
}
//MENOR MAYOR CLASES-POR EDAD
template<typename T>
bool compareEdad1(T x,T y){
    return x.getEdad()<=y.getEdad();
}
//MAYOR A MENOR-PARA CLASES
template<typename T>
bool compareEdad2(T x,T y){
    return x.getEdad()>y.getEdad();
}

template<typename T>
void insertionsort(T* arreglo,int size, bool (*p)(T , T))
{
    for(int k=1; k<size; k++) 
    { 
        T temp = arreglo[k]; 
        int j = k-1;
        while(j>=0 && p(temp,arreglo[j]) ) 
        { 
            arreglo[j+1] = arreglo[j]; 
            j--;
        } 
        arreglo[j+1] = temp; 
    } 
}

int main(){
    int size;
    int arregloEnteros[10] = {5,2,2,7,1,3,5,2,10,1};
    float arregloFloat[10]={4.5,6.7,8.7,9.8,4.5,6.1,2.3,9.8,6.5,5.7};
    string arregloString[10] = {"Peru","Chile","Colombia","Mexico","Rusia","Venezuela","Inglaterra","Egipto","Panama","Suiza"};
    Persona personas[10];
    //DEFINIENDO EDADES---------------------
    personas[0].setEdad(15);
    personas[1].setEdad(10);
    personas[2].setEdad(30);
    personas[3].setEdad(7);
    personas[4].setEdad(36);
    personas[5].setEdad(18);
    personas[6].setEdad(24);
    personas[7].setEdad(50);
    personas[8].setEdad(47);
    personas[9].setEdad(25);
    //DEFINIENDO NOMBRES---------------------
    personas[0].setNombre("Jesus");
    personas[1].setNombre("Bruno");
    personas[2].setNombre("Manuel");
    personas[3].setNombre("Andy");
    personas[4].setNombre("Axel");
    personas[5].setNombre("Kevin");
    personas[6].setNombre("Ramon");
    personas[7].setNombre("Phil");
    personas[8].setNombre("Ederson");
    personas[9].setNombre("Jack");

    cout<<"USANDO INSERTION-SORT"<<endl;
    cout<<"Para enteros: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloEnteros)/sizeof(arregloEnteros[0]);
    mostrarArray(arregloEnteros,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    insertionsort(arregloEnteros,size,compare1);
    mostrarArray(arregloEnteros,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    insertionsort(arregloEnteros,size,compare2);
    mostrarArray(arregloEnteros,size);
    //--------------------------------------------
    cout<<"Para float: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloFloat)/sizeof(arregloFloat[0]);
    mostrarArray(arregloFloat,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    insertionsort(arregloFloat,size,compare1);
    mostrarArray(arregloFloat,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    insertionsort(arregloFloat,size,compare2);
    mostrarArray(arregloFloat,size);
    //--------------------------------------------
    cout<<"Para string: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloString)/sizeof(arregloString[0]);
    mostrarArray(arregloString,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    insertionsort(arregloString,size,compare1);
    mostrarArray(arregloString,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    insertionsort(arregloString,size,compare2);
    mostrarArray(arregloString,size);
    //--------------------------------------------
    cout<<"Para objetos de una clase: "<<endl;
    cout<<"\tPor nombre: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(personas)/sizeof(personas[0]);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    insertionsort(personas,size,compareNombre1);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    insertionsort(personas,size,compareNombre2);
    mostrarObjetos(personas,size);

    cout<<"\tPor edad: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    insertionsort(personas,size,compareEdad1);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    insertionsort(personas,size,compareEdad2);
    mostrarObjetos(personas,size);

    return 0;
}