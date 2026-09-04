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
        resultado = (mate + fisica + quimica) / 3; //para que juan pueda tener su promedio se debe especificar al constructor base como calcularlo, ya que juan tiene sus datos pre definidos.
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
 
    int obtener_promedio(Alumnos alumno1, Alumnos alumno2){ 
        cout<<"Ingrese las calificaciones de matematicas, fisica y quimica, estas deben tener un rango de 60 a 100:"<<endl; 
         
        cin >> mate; 
        while((mate < 60 || mate > 100) || (cin.fail())){ 
            cout<<"Ingrese una calificacion valida (60-100): "<<endl; 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cin >> mate; 
        }  
 
        cin >> fisica; 
        while((fisica < 60 || fisica > 100) || (cin.fail())){ 
            cout<<"Ingrese una calificacion valida (60-100): "<<endl; 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cin >> fisica; 
        } 
 
        cin >> quimica; 
        while((quimica < 60 || quimica > 100) || (cin.fail())){ 
            cout<<"Ingrese una calificacion valida (60-100): "<<endl; 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cin >> quimica; 
        } 
        resultado = (mate + fisica + quimica) / 3; 
        return resultado;    
    } 
 
    void mostrar_info_alumno(Alumnos alumno1, Alumnos alumno2){ 
        //teoricamente si aisigno parametros las variables locales mandaran la informacion correctamente(!!) 
        cout<<"El nombre del alumno es: "<<alumno1.nombre<<endl; 
        cout<<"El promedio del alumno es: "<<alumno1.resultado<<endl; 
        cout<<"El nombre del alumno es: "<<alumno2.nombre<<endl; 
        cout<<"El promedio del alumno es: "<<alumno2.resultado<<endl;
     
    } 
 
    void menu(Alumnos alumno1, Alumnos alumno2){ 
        char opcion; 
        cout << "bienvenido, seleccione la opcon a desear: a) Mostrar informacion del alumno \tb) Salir "<<endl;  
 
            do{     
            cin >> opcion;
            cin.clear();
            cin.ignore(1000, '\n');
            switch(opcion){ 
                case 'a': 
                mostrar_info_alumno(alumno1, alumno2); 
                break; 
                case 'b': 
                cout<<"saliendo del programa..."<<endl; 
                break; 
                default: 
                cout<<"opcion no valida, intente de nuevo..."<<endl; 
 
            } 
             
        }while((opcion != 'a' && opcion != 'b') || (cin.fail()));  
 
    } 
 
}; 
 
int main(){ 
 
Alumnos alumno1; //creo un objeto de la clase Alumnos sin parametros previos. 
 
Alumnos alumno2("Juan", 80, 90, 70); //creo un objeto de la clase Alumnos CON parametros previos. 
 
alumno1.Obtener_Nombre(); //llamo a la funcion para obtener el nombre del alumno 
 
alumno1.obtener_promedio(alumno1, alumno2); //llamo a la funcion para obtener el promedio del alumno 
 
alumno1.menu(alumno1, alumno2);  
 
 
 //ya solo queda añadir la verificacion de aprobar o reprobar materias y ya... mañana queda...
 
    return 0; 
}