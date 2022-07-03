// Quick sort in C++

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

//PARA DATOS PRIMITIVOS------------
//DE MENOR A MAYOR
template<typename T>
bool compara1(T x,T y){
    return x<=y;
}
//DE MAYOR A MENOR
template<typename T>
bool compara2(T x,T y){
    return x>y;
}
//PARA TRABAJAR CON CLASES-----------
template<typename T>
bool comparaEdad1(T x,T y){
    return x.getEdad()<=y.getEdad();
}
//DE MAYOR A MENOR
template<typename T>
bool comparaEdad2(T x,T y){
    return x.getEdad()>y.getEdad();
}

template<typename T>
bool comparaNombre1(T x,T y){
    return x.getNombre()<=y.getNombre();
}
//DE MAYOR A MENOR
template<typename T>
bool comparaNombre2(T x,T y){
    return x.getNombre()>y.getNombre();
}
// funcion que intercambia los elementos
template<typename T>
void swap(T *a, T *b) {
  T t = *a;
  *a = *b;
  *b = t;
}

// funcion que imprime el arreglo
template<typename T>
void printArray(T array[], int size) {
  cout<<"\t";
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
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

// función para reordenar el array (encontrar el punto de partición)
template<typename T>
int partition(T array[], int low, int high,bool (*p)(T,T)) {
    
  // seleccionar el elemento más a la derecha como pivote
  T pivot = array[high];
  
  int i = (low - 1);

  // recorrer cada elemento del array compararlos con el pivote
  for (int j = low; j < high; j++) {
    if (p(array[j],pivot)) {//aqui esta el critero de comparacion
        
      //  si se encuentra un elemento menor que el pivote cambiarlo 
      //por el elemento mayor señalado por i
      i++;
      
      // intercambiar el elemento i con el elemento en j
      swap(&array[i], &array[j]);
    }
  }
  
  swap(&array[i + 1], &array[high]);
  
  // devuelve el punto de particion
  return (i + 1);
}
template<typename T>
void quickSort(T array[], int low, int high,bool (*p)(T,T)) {
  if (low < high) {
      
    // encontrar el elemento pivote de forma que los elementos menores 
    //que el pivote estén a la izquierda del mismo, y los elementos mayores 
    //que el pivote estén a la derecha del pivote
    int pi = partition(array, low, high,p);

    // llamada recursiva a la izquierda del pivote
    quickSort(array, low, pi - 1,p);

    // llamada recursiva a la derecha del pivote
    quickSort(array, pi + 1, high,p);
  }
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

    cout<<"USANDO QUICK-SORT"<<endl;
    cout<<"Para enteros: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloEnteros)/sizeof(arregloEnteros[0]);
    printArray(arregloEnteros,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    quickSort(arregloEnteros,0,size-1,compara1);
    printArray(arregloEnteros,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    quickSort(arregloEnteros,0,size-1,compara2);
    printArray(arregloEnteros,size);
    //--------------------------------------------
    cout<<"Para float: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloFloat)/sizeof(arregloFloat[0]);
    printArray(arregloFloat,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    quickSort(arregloFloat,0,size-1,compara1);
    printArray(arregloFloat,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    quickSort(arregloFloat,0,size-1,compara2);
    printArray(arregloFloat,size);
    //--------------------------------------------
    cout<<"Para string: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(arregloString)/sizeof(arregloString[0]);
    printArray(arregloString,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    quickSort(arregloString,0,size-1,compara1);
    printArray(arregloString,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    quickSort(arregloString,0,size-1,compara2);
    printArray(arregloString,size);
    //--------------------------------------------
    cout<<"Para objetos de una clase: "<<endl;
    cout<<"\tPor nombre: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    size=sizeof(personas)/sizeof(personas[0]);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    quickSort(personas,0,size-1,comparaNombre1);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    quickSort(personas,0,size-1,comparaNombre2);
    mostrarObjetos(personas,size);

    cout<<"\tPor edad: "<<endl;
    cout<<"\tArreglo desordenado"<<endl;
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de menor a mayor: "<<endl;
    quickSort(personas,0,size-1,comparaEdad1);
    mostrarObjetos(personas,size);
    cout<<"\tOrdenando de mayor a menor: "<<endl;
    quickSort(personas,0,size-1,comparaEdad2);
    mostrarObjetos(personas,size);

    return 0;
}
