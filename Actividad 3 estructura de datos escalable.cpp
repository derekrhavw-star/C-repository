//este codigo es el pre fabricado con diseño escalable a largo plazo con la meta de añadir vectores o cadenas a largo plazo...

#include<iostream>

using namespace std;


class Alumnos{
    private:
    int mate, fisica, quimica, resultado; //local variables
    string nombre, datos_ambos_alumnos;

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
        cout<<"ingrese el nombre del alumno: "<<endl;
        cin >> nombre;
    }

    int obtener_promedio(){
        cout<<"Ingrese las calificaciones de matematicas, fisica y quimica:"<<endl;
        
        cin >> mate;
        while(mate < 0 || mate > 10){
            cout<<"Ingrese una calificacion valida (0-10): "<<endl;
            cin >> mate;
        } 

        cin >> fisica;
        while(fisica < 0 || fisica > 10){
            cout<<"Ingrese una calificacion valida (0-10): "<<endl;
            cin >> fisica;
        }

        cin >> quimica;
        while(quimica < 0 || quimica > 10){
            cout<<"Ingrese una calificacion valida (0-10): "<<endl;
            cin >> quimica;
        }
        resultado = (mate + fisica + quimica) / 3;
        return resultado;   
    }

    void mostrar_info_alumno(){
        //teoricamente si aisigno parametros las variables locales mandaran la informacion correctamente(!!)
        cout<<"El nombre del alumno es: "<<nombre<<endl;
        cout<<"El promedio del alumno es: "<<resultado<<endl;
    
    }

    void menu(){
        char opcion;
        cout << "bienvenido, seleccione la opcon a desear: a) Mostrar informacion del alumno \tb) Salir "<<endl;
        cin >> opcion;

            do{
            switch(opcion){

                case 'a':
                mostrar_info_alumno();
                break;
                case 'b':
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

Alumnos alumno2("Juan", 8, 9, 7); //creo un objeto de la clase Alumnos CON parametros previos.

alumno1.Obtener_Nombre(); //llamo a la funcion para obtener el nombre del alumno

alumno1.obtener_promedio(); //llamo a la funcion para obtener el promedio del alumno

alumno1.menu(); 




    return 0;
}
