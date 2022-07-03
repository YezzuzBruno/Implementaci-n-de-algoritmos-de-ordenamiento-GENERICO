// Merge sort in C++

#include <iostream>
using namespace std;

class Persona{
  private:
    string nombre;
    int edad;
  public:
    void setNombre(string);
    void setEdad(int);
    string getNombre();
    int getEdad();
    ~Persona(){};
};

void Persona::setNombre(string nombre){
  this->nombre=nombre;
}

void Persona::setEdad(int edad){
  this->edad=edad;
}

string Persona::getNombre(){
  return nombre;
}

int Persona::getEdad(){
  return edad;
}
//PARA DATOS PRIMITIVOS-----------------------------------------
//MENOR A MAYOR
template<typename T>
bool compara1(T x,T y){
  return x<=y;
}
//MAYOR A MENOR
template<typename T>
bool compara2(T x,T y){
  return x>y;
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

// Combina dos subarreglos L y M en arr 
template<typename T>
void merge(T arr[], int p, int q, int r,bool(*ptr)(T,T)) {
  
  // Crea L <- A[p..q] y M <- A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  T L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Mantener el índice actual de las subarreglos y del arreglo principal
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Hasta que lleguemos a cualquiera de los extremos de L o M, 
  //escoge el más grande entre elementos L y M y los coloca en 
  //la posición correcta en A[p..r]
  //-----------------------------------------------------
  while (i < n1 && j < n2) {
    if (ptr(L[i], M[j])) {//cambio aqui<-----------------------
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // Cuando nos quedamos sin elementos en L o M, recogemos los 
  //elementos restantes y los ponemos en A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

//-------------------------------------------------------

// Dividir el arreglo en dos subarreglos, ordenarlas y fusionarlas
template<typename T>
void mergeSort(T arr[], int l, int r,bool (*p)(T,T)) {//agregamos un puntero a funcion
  if (l < r) {
    // m es el punto en el que el arreglo se divide en dos subarreglo
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m,p);
    mergeSort(arr, m + 1, r,p);

    // Fusionar los subarreglos ordenados
    
    merge(arr,l,m,r,p);
  }
}

// Imprime el array
template<typename T>
void printArray(T arr[], int size) {
  cout<<"\t";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
template<typename T>
void mostrarObjetos(T array[],int size){
    cout<<"\t";
    for(int i=0;i<size;i++){
        cout<<array[i].getNombre()<<"("<<array[i].getEdad()<<"), ";
    }
    cout<<endl;
}

int main() {
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

    cout<<"USANDO MERGE-SORT"<<endl;
    cout<<"Para enteros: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloEnteros)/sizeof(arregloEnteros[0]);
    printArray(arregloEnteros,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    mergeSort(arregloEnteros,0,size-1,compara1);
    printArray(arregloEnteros,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    mergeSort(arregloEnteros,0,size-1,compara2);
    printArray(arregloEnteros,size);
    //--------------------------------------------
    cout<<"Para float: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloFloat)/sizeof(arregloFloat[0]);
    printArray(arregloFloat,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    mergeSort(arregloFloat,0,size-1,compara1);
    printArray(arregloFloat,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    mergeSort(arregloFloat,0,size-1,compara2);
    printArray(arregloFloat,size);
    //--------------------------------------------
    cout<<"Para string: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloString)/sizeof(arregloString[0]);
    printArray(arregloString,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    mergeSort(arregloString,0,size-1,compara1);
    printArray(arregloString,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    mergeSort(arregloString,0,size-1,compara2);
    printArray(arregloString,size);
    //--------------------------------------------
    cout<<"Para objetos de una clase: "<<endl;
    cout<<"\tPor nombre: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(personas)/sizeof(personas[0]);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    mergeSort(personas,0,size-1,compareNombre1);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    mergeSort(personas,0,size-1,compareNombre2);
    mostrarObjetos(personas,size);

    cout<<"\tPor edad: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    mergeSort(personas,0,size-1,compareEdad1);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    mergeSort(personas,0,size-1,compareEdad2);
    mostrarObjetos(personas,size);

    return 0;
}