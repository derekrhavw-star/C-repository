#include<iostream>
#include<vector>

using namespace std;

//creacion del nodo y su funcionalidad
class Nodo{
public:

    float valor;
    Nodo* next;
    Nodo* prev;


    void insertarAdelante(float valor, Nodo* Inicio){ //definicion de acomodo y logica de memoria

        Nodo* nuevo = new Nodo; //¿Que hace "new" exactamente??
        nuevo->valor = valor;

        nuevo->prev = Inicio; //nuevo apuntando a previo para declararse como inicio??
        nuevo->next = Inicio->next; //crear espacio siguiente despues del inicio

        Inicio->next = nuevo;
        if(Inicio->next->next != NULL){

            Inicio->next->next->prev = nuevo; //si al espacio siguiente del siguiente hay NULL, un espacio antes sera el ultimo "nuevo"

        }



    }


    float Eliminar_adelante(Nodo* ejecutar){

        float valor = ejecutar->valor;

        ejecutar->prev->next = ejecutar->next;
        ejecutar->next->prev = ejecutar->prev;

        delete ejecutar;
        return valor;

    }

};

class Lista{
public:
    Nodo Inicio;
    Nodo Fin;

    Lista(){  //constructor
        Inicio.next = &Fin;
        Inicio.prev = NULL;
        Fin.prev = &Inicio;
        Fin.next = NULL;
    }

    void InsertarPrincipio(float valor){
        Inicio.insertarAdelante(valor, &Inicio);
    }


    void Imprimir(){ //logica de imprimir 
        Nodo* temporal = Inicio.next;
        while(temporal != &Fin){ //mientras el siguiente espacio no sea fin se imprimen más valores
            cout<<temporal->valor<<"->";
            temporal = temporal->next;
        }
        cout << endl;
    }

    void Insertar_al_final(float valor){
        Fin.prev->insertarAdelante(valor, Fin.prev);
    }

    bool Vacia(){
        return Inicio.next == &Fin; //esto devuelve true si la lista está vacía
    }

    void Eliminar_principio(){
        if(Vacia()){
            cout << "no se puede eliminar una lista vacia" << endl;
        }else{
            cout << "Numero eliminado es: " << Inicio.Eliminar_adelante(Inicio.next) << endl; //me falta la funcion eliminar??
        }
    }

    void Eliminar_final(){
        if(Vacia()){
            cout << "lista vacia" << endl;
        }else{
            cout << "valor eliminado fue: " << Fin.prev->prev->Eliminar_adelante(Fin.prev) << endl; //falta funcion eliminar adelante
        }
    }

};

int main(){
//Ahora esta es una lista parametrizada, no es una lista de memoria dinamica...
//como podria hacer que la lista fuera de memoria dinamica??
    Lista lista;
    lista.InsertarPrincipio(7.2);
    lista.InsertarPrincipio(8.4);
    lista.InsertarPrincipio(10.1);
    lista.Imprimir();

    lista.Insertar_al_final(2.2);
    lista.Imprimir(); 

    lista.Eliminar_final();
    lista.Imprimir();
    
    lista.Eliminar_principio();
    lista.Imprimir();

    lista.Eliminar_principio();
    lista.Imprimir();

    lista.Eliminar_principio();
    lista.Imprimir();

    lista.Eliminar_principio();
    lista.Imprimir();


return 0;
}