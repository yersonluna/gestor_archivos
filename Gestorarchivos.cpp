#include <iostream>
#include <direct.h>
#include <string> /* libreria*/ 
#include <fstream>
/*
Yerson Andres Luna Escobar
*/
using namespace std; /* se crea un bloque dentro de las funciones de el mismo */

void crear_directorio()
{
	 string opciones;
  cout << "1   ¿Crear carpeta? ";
   cout << "\n2  ¿Crear  cualquier tipo de archivos? "; /* Aca es donde se muestra el texto por la pantalla*/
   cout << "\n3 ¿Agregarle informacion al archivo? ";
   cout << "\n4   ¿Borrrararchivo? ";
           cout << "\nIngrese una opcion: ";
        cin >> opciones;/* Funcion de la biblioteca que lee la secuencia de la entrada en este caso seria opciones*/
  if (opciones == "1") 
  {
   cout << "Ubicacion: ";
   string ubicacion;      /* Esta es la secuencia de los careteres guardados de ubicacion */
   getline(cin, ubicacion);
   cout << "Asignele un nombre a la carpeta: ";
   string carpetas;  /* secuencia de entrada de las carpetas */
   getline(cin, carpetas);  /* Funcion de la biblioteca que lee la secuencia de la entrada en este caso seria carpertas */
   string ubicacion_absoluta = ubicacion + carpetas; /* esta seria la secuencia de entrada de la ubicacion_absoluta que concatena los string de ubicacion y carpeta*/
   if (mkdir(ubicacion_absoluta.c_str()) == 0) cout << "Carpeta creada correctamente" << endl; /* se comprueva si se ha creado la carpeta con la funcion mkdir*/ 
   else cout << "Ha ocurrido un error al crear la carpeta" << endl;
   crear_directorio();   /* se le da al usuario la obcionde crear otra carpeta */ 
  }   
  else if (opciones == "2")
  {
    cout << "Nombre de la carpeta donde quiere guardar el archivo: ";
    string ubicacion; /* variable ubicacion*/
    getline(cin, ubicacion);
    cout << "Nombre del archivo: ";
    string archivos; /* variable archivos*/
    getline(cin, archivos); /* se introduce el valor que coloco el usuario */ 
    string ubicacion_absoluta = ubicacion + archivos; /* se concatena las variables ubicacion y archivos para el resultado */
    FILE * arch; /* se crea el objeto llamado arch */
    if (arch = fopen(ubicacion_absoluta.c_str(), "a")) cout << "Archivo Creado" << endl; /*se hace la comprovacion par ver si se creo el archivo y la ruta absoluta
	se a va convertir en tipo char*/
    else cout << "No se pudo crear el archivo" << endl;  /* si no que vote untesto diciendo que no se pudo crear el archivo*/
    crear_directorio();   /* se vuelve a llamar la funcion crear_directorio*/
  }else if (opciones == "3")
  {  ofstream archivo;  /* se llama el fichero de salida que seria el archivo */
  	cout << "Carpeta donde lo guardo si no se acuerda solo presiona enter el programa se encarga: ";
    string ubicacion;
    getline(cin, ubicacion); /* se introduce el valor que coloco el usuario */
    cout << "Nombre del archivo al que quiere agregarle contenido: ";
    string archivos;
    getline(cin, archivos); /* se introduce el valor que coloco el usuario */
    string ubicacion_absoluta = ubicacion + archivos;
    FILE * arch; /* se llama el objeto arch */
      cout << "Que informacion quiere guardar: ";
    string lineauno; /* variable lineauno*/
    getline(cin, lineauno); /* se introduce el valor que coloco el usuario */
    string informacion =  lineauno;
       cout << "Que informacion quiere guardar: ";
    string lineados;
    getline(cin, lineados); /* se introduce el valor que coloco el usuario */
    string informacion_dos =  lineados;
     archivo.open(ubicacion_absoluta.c_str()); /* se crea archivo.open para la creacion de archivos TXT*/
       archivo << (informacion.c_str())<< endl; /* Aca es donde se introduce el texto*/
       archivo << (informacion_dos.c_str())<< endl;
   crear_directorio(); 
  	 
   
  }else if (opciones == "4")
  {
  	cout << "Carpeta donde lo guardo si no se acuerda solo presiona enter el programa se encarga: ";
    string ubicacion;
    getline(cin, ubicacion); /* se introduce el valor que coloco el usuario */
    cout << "Nombre del archivo que quiere borrar: ";
    string archivos; /*variable archivos */
    getline(cin, archivos);
    string ubicacion_absoluta = ubicacion + archivos; /* se concatena las variables ubicacion y archivos para el resultado */
    FILE * arch; /* llamamos de nuevo el objeto nuevamente */
  if( remove(ubicacion_absoluta.c_str() ) != 0 ) /*La función retorna cero si la operación fue realizada con éxito en este caso seria ubicacion_absoluta en tipo char*/
       perror( "No se pudo borrar" ); /* funcion que manda un mensaje diciendo que no se pudo borrar */
  else
       puts( "Se borro" ); /* seria la secuencia en caso que no se haya borrado */
       crear_directorio(); 
    
  }
  else 
  {
    crear_directorio();  
  }
}
int main(int argc, char *argv[]) /* Aca se va a poder llamar la funcion crear_directorio desde el main*/
{
 crear_directorio();
 system("PAUSE");
 return 0;
}
