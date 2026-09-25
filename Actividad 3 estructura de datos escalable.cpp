//este codigo es el pre fabricado con diseño escalable a largo plazo con la meta de añadir vectores o cadenas a largo plazo...

#include<iostream>

using namespace std;


class Nodo{
public:

    

    int valor;
    string valor_string;
    Nodo* next;
    Nodo* prev;

    Nodo* cabezera = NULL;

    bool vacio(){
        if (cabezera == NULL)
            return true;

        return false;
    }

    void ultimo_elemento(){
        if (vacio()){
            cout<<"la lista esta vacia"<<endl;
        }
        else{
            cout<<"el ultimo elemento es: "<<cabezera->valor<<endl;
        }
    }

    void Agregar(int valor){
        Nodo* temp;
        temp = new Nodo(); //agregar e inicializar cadena de datos de calificacion

        //evaluacion de primer elemento
        if (vacio()){
            temp->valor = valor;
            temp->prev = NULL;
            temp->next = NULL;
            cabezera = temp;
        }
        else{
            temp->valor = valor;
            temp->next = cabezera;
            cabezera->prev = temp; //el valor anterior a cabezera es ahora el de temporal
            temp->prev = NULL; //para que es esta linea exactamente?? (!!).
            cabezera = temp;
        }

    }

    void Agregar_string(string valor_string){
        Nodo* temp;
        temp = new Nodo(); //agregar e inicializar cadena de datos de calificacion

        //evaluacion de primer elemento
        if (vacio()){
            temp->valor_string = valor_string;
            temp->prev = NULL;
            temp->next = NULL;
            cabezera = temp;
        }
        else{
            temp->valor_string = valor_string;
            temp->next = cabezera;
            cabezera->prev = temp; //el valor anterior a cabezera es ahora el de temporal
            temp->prev = NULL; //para que es esta linea exactamente?? (!!).
            cabezera = temp;
        }

    }

    
    void corroborar_error(int& valor){
        while((valor < 60 || valor > 100) || (cin.fail())){
            cout<<"ingrese una calificacion valida (60-100): "<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> valor;
        }
    }

    void ingresar_datos(int& valor){ //manejo de las variables originales gracias al signo "&", para obtener mejor control de los resultados se deben pasar como argumentos las variables originales a los proximos parametros.
            cout<<"ingrese la calificacion: "<<endl;
            cin >> valor;
            corroborar_error(valor);
            Agregar(valor);    
        }

    void Ingresar_nombre(string& valor_string){ //ingreso de datos tipo nombre, recibidos por parametros
        cout<<"ingresa tu nombre: "<<endl;
        cin>>valor_string;
        Agregar_string(valor_string);
    }    

    void eliminar_top(){
        Nodo* temp;
        if (vacio()){
            cout<<"espacio vacio"<<endl;
        }
        else if (cabezera->next == NULL && cabezera->prev == NULL){
            temp = cabezera;
            cabezera = NULL;
            delete(cabezera);
        }
        else{
            temp = cabezera;
            cabezera = cabezera->next;
            cabezera->prev = NULL;
            delete(temp);
        }
    }    
    
};

class Alumnos : public Nodo{
    protected:
    int mate, fisica, quimica, resultado; //variables locales
    string nombre;

    public: //constructor

    Alumnos(){}; //constructor por defecto. Es importante para poder crear objetos sin parametros previos.

    Alumnos(string n, int m, int f, int q){
        nombre = n;
        mate = m;
        fisica = f;
        quimica = q;
    }

    //setters

    void setNombre(string n){
        nombre = n;
    }

    void setMaterias(int m, int f, int q){
        mate = m;
        fisica = f;
        quimica = q;
    }

    //getters

    string getNombre(){
        return nombre;
    }

    int getMaterias(){ //teoricaly posible...(!!)
        return mate;
        return fisica;
        return quimica;
    }

    void Obtener_Nombre(){
        Ingresar_nombre(nombre); //Una vez agregado el parametro se pasa a una funcion que no lo necesita para llamarla sin mayor problema y obtener un diseño escalable
    }                             //nombre al ser una variable de Alumnos funciona como parametro del argumento previo de la función nodo "valor_string"


    int obtener_promedio(){
        cout<<"Ingrese las calificaciones de matematicas, fisica y quimica:"<<endl;

        ingresar_datos(mate);

        ingresar_datos(fisica);

        ingresar_datos(quimica);

        resultado = (mate + fisica + quimica) / 3;  
        
        return resultado;   
    }

    void mostrar_info_alumno(){
        //teoricamente si aisigno parametros las variables locales mandaran la informacion correctamente(!!)
        cout<<"El nombre del alumno es: "<<nombre<<endl;
        cout<<"El promedio del alumno es: "<<resultado<<endl;
    
    }

    void Tamaño(){
        int tamaño = 0;

        Nodo* actual = cabezera;

        while( actual != NULL){
            tamaño++;
            actual = actual->next;
        }
        cout << "tamaño de cadena: " << tamaño << endl;
    }

    void Imprimir_lista_calificacionesInd(int& valor){ //posiblemente se impriman valores basura al manejar solo variables locales
        Nodo* actual = cabezera;

        cout << "La lista de elementos es: " << endl;

        while (actual != NULL){
            cout << actual->valor << "";
            actual = actual->next;
            cout << endl;
        }

        //cout << "\t" << endl;
        //todo es una sola linea...
        //¿Por que imprime 0 extras?(!!)
    }

    void menu(){
        char opcion;
        cout << "bienvenido, seleccione la opcon a desear: a) Mostrar informacion del ultimo alumno \tb) Imprimir lista  \tc) Salir "<<endl;
        cin >> opcion;

            do{
            switch(opcion){

                case 'a':
                mostrar_info_alumno();
                break;
                case 'b':
                Imprimir_lista_calificacionesInd(valor); //funciona pero imprime todas de las calificaciones, sin formato alguno ni los promedios, ademas de que hay un 0 de mas en cada cola de la lista. (!!)
                break;
                case 'c':
                cout<<"saliendo del programa..."<<endl;
                break;
                default:
                cout<<"opcion no valida, intente de nuevo..."<<endl;

            }
            
        } while(opcion != 'a' && opcion != 'b');

    }

};

int main(){

Alumnos alumno1; //creo un objeto de la clase Alumnos sin parametros previos.

alumno1.Obtener_Nombre(); //llamo a la funcion para obtener el nombre del alumno

alumno1.obtener_promedio(); //llamo a la funcion para obtener el promedio del alumno

alumno1.Obtener_Nombre(); 

alumno1.obtener_promedio();



alumno1.menu(); 




    return 0;
}


//Agregar funciones: Tamaño de la lista, Destruir la lista, Agregar alumnos a la lista de forma indefinida.