#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>

//Clase para los datos de los alumnos
class Alumno
{
  private:
    //Si se quiere cambiar el numero de works el único método que se deb modificar es el constructor
    static int const works = 3; //Número de trabajos
    std::string nombre;
    std::string matricula;
    float promedio;
    float entregas[works];
    float promedio_curva;
  public:
    Alumno();
    Alumno(std::string, std::string, float, float, float); //Constructor
    //~Alumno(); //Destructor
    
    std::string getNombre();
    std::string getMatricula();
    float getPromedio();
    float getPromedio_Curva();

    void setPromedio_Curva(float);

    void mostrarDatos(); //Imprime toda la información del alumno
    void calcularPromedio(); //Calcula el promedio de las entragas    
};

Alumno::Alumno()
{
  nombre = " ";
  matricula= " ";
  promedio = 0;
  entregas[0] = 0;
  entregas[1] = 0;
  entregas[2] = 0;
}

Alumno::Alumno(std::string name, std::string mat, float cal1, float cal2, float cal3):nombre(name),matricula(mat)
{
  entregas[0] = cal1;
  entregas[1] = cal2;
  entregas[2] = cal3;
  calcularPromedio();
}

std::string Alumno::getNombre() { return nombre; }

std::string Alumno::getMatricula() { return matricula; }

float Alumno::getPromedio() { return promedio; }

float Alumno::getPromedio_Curva() { return promedio_curva; }

void Alumno::setPromedio_Curva(float aumento) { promedio_curva = promedio+aumento; }

void Alumno::mostrarDatos()
{
  std::cout<<std::endl;
  std::cout<<"Nombre: "<<nombre<<std::endl;
  std::cout<<"Matrícula: "<<matricula<<std::endl;
  std::cout<<"Promedio: "<<promedio<<std::endl;
  for(int i=0;i<works;i++)
  {
    std::cout<<"  Entrega "<<i+1<<": "<<entregas[0]<<std::endl;
  }
  std::cout<<std::endl;
}

void Alumno::calcularPromedio()
{
  int suma = 0;
  for(int i=0;i<works;i++)
  {
    suma+=entregas[i];
  }
  promedio = suma/works;
}

#endif 