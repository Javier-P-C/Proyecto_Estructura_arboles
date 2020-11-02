/*
Javier Piña Camacho
1 de noviembre de 2020
Proyecto entrega 3
El programa sirve para promediar a estudiantes por medio de sus entregas, ordenarlos de acuerdo a sus calificaciones y sacar su calificación si se decide calificarlos por curva de ponderación
*/
#include <iostream>
#include <fstream>
#include <string>

#include "heap.h"

//#include "avl_alumno.h"
#include "alumno.h"

//crea a los alumnos con el .csv para meterlos al heap
void plantarAlumnos(Heap<Alumno>*);
//Pone en un arreglo a los estudiantes de forma ascedentent con respecto a sus calificaciones
void ordenarEstudiante(Heap<Alumno>*,Alumno[],int);
//Calucula la cantidad de puntos a agregarle al promedio
float calcularCurva(Alumno[],int);
//Le da valores al atributo promedio_Curva de cada alumno
void establecerPromCurva(Alumno[],int,float);
//Crea un archivo .txt de la información de cada alumno
void crearDocResultados(Alumno[],int);
//Datos generales del grupo
void infoGrupo(Alumno[],int);

int main()
{ 
  unsigned int numAlumnos = 20;
  Heap<Alumno> *arbol = new Heap<Alumno>(20);
  plantarAlumnos(arbol);

  Alumno *arregloAlumnos;
  arregloAlumnos = new Alumno[numAlumnos];
  ordenarEstudiante(arbol,arregloAlumnos,numAlumnos);
  establecerPromCurva(arregloAlumnos,numAlumnos,calcularCurva(arregloAlumnos,numAlumnos));
  crearDocResultados(arregloAlumnos,numAlumnos);
  infoGrupo(arregloAlumnos,numAlumnos);
  std::cout<<std::endl<<"Archivo de texto listo para descargar";
}

void plantarAlumnos(Heap<Alumno> *tree)
{
  std::ifstream reader("datos_alumnos.csv"); 
  if(reader.is_open())
  {
    while(reader.good())
    {
      std::string l1,l2,l3,l4,l5;
      getline(reader,l1,',');
      getline(reader,l2,',');
      getline(reader,l3,',');
      getline(reader,l4,',');
      getline(reader,l5,'\n');
      Alumno temporal(l1,l2,std::stof(l3),std::stof(l4),std::stof(l5));
      tree->add(temporal);
    }
    reader.close();
  }
  else
    std::cout<<"ERROR: No se puede abrir el archivo"<<std::endl;
}

void ordenarEstudiante(Heap<Alumno> *tree,Alumno al[],int num)
{
  for(int i=0;i<num;i++)
  {
    al[i] = tree->remove();
  }
}

float calcularCurva(Alumno al[],int num)
{
  float aumento;
  aumento=100-al[num-1].getPromedio();
  return aumento;
}

void establecerPromCurva(Alumno al[],int num,float aumento)
{
  for(int i=0;i<num;i++)
  {
    al[i].setPromedio_Curva(aumento);
  }
}

void crearDocResultados(Alumno al[],int num)
{
  std::ofstream writer("calificaciones_finales.txt");
    if(writer.is_open())
    {
      writer<<"Matrícula    |Nombre    |Promedio    |Promedio con Curva"<<"\n";
      for(int i=0;i<num;i++)
      {
        writer<<al[i].getMatricula()<<"---";
        writer<<al[i].getNombre()<<"---";
        writer<<al[i].getPromedio()<<"---";
        writer<<al[i].getPromedio_Curva()<<"\n";
      }
      writer.close();
    }
    else
    {
      std::cout<<"No se puede abrir el archivo"<<std::endl;
    }
}

void infoGrupo(Alumno al[],int num)
{
  std::cout<<"Número de alumnos: "<<num<<std::endl;
  std::cout<<"Calificación más alta: "<<al[num-1].getPromedio()<<std::endl;
  std::cout<<"Calificación más baja:  "<<al[0].getPromedio()<<std::endl;
  std::cout<<"Promedio del grupo: ";
  int promT = 0;
  for(int i=0;i<num;i++)
  {
    promT+=al[i].getPromedio();
  }
  promT /= num; 
  std::cout<<promT<<std::endl;  
}
