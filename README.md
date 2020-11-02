[![Run on Repl.it](https://repl.it/badge/github/Javier-P-C/Proyecto_Estructura_arboles)](https://repl.it/github/Javier-P-C/Proyecto_Estructura_arboles)
# Proyecto_Estructura_arboles

----------------------------------------------------------------------
DOCUMENTACIÓN
1.-Explicación general del código
2.-Complejidades de los algoritmos
4.-Casos de Prueba

----------------------------------------------------------------------
1)EXPLICACIÓN GENERAL DEL CÓDIGO
-Se crea un árbol heap para almacenar los datos después de ser leídos de datos_alumnos.csv. Los datos se sacan del heap y se meten las instacias de alumno en un arreglo aparte. Salir del heap los ordena de acuerdo a sus promedios. En el nuevo arreglo se le da valor al promedio_curva de cada Alumno. Después se crea un archivo de texto con los datos de los alumnos ordenados de forma ascendente de acuerdo a su promedio. Por último, se imprime información general del grupo en consola.

2)COMPLEJIDADES DE LOS ALGORITMOS

MAIN
void plantarAlumnos(Heap<Alumno>*);
    -Usa una variable de tipo ifstream para leer cada línea del .csv. Se repite el proceso hasta que se acaben las líneas. Al depender del número de líneas es de complejidad n O(n)

void ordenarEstudiante(Heap<Alumno>*,Alumno[],int);
  -Saca los elementos del heap uno por uno por lo que depende de número de elementos. Esto lo vuelve de complejidad O(n)

float calcularCurva(Alumno[],int);
  -Hace una sola resta, su complejidad es O(1)

void establecerPromCurva(Alumno[],int,float);
  -Establece el valor de promedio_curva de todos los alumnos. Al tener que pasar por todos le da una complejidad O(n)

void crearDocResultados(Alumno[],int);
  -Recorre todo el arreglo para poner la información en el archivo de texto, por lo mismo es lineal O(n)

void infoGrupo(Alumno[],int);
  -Recorre todos las alumnos para sacar el promedio del grupo, lo que lo vuelve de complejidad lineal O(n)

HEAP
unsigned int parent(unsigned int) const;
  -Devuelve el resultado de una división por lo que siempre es constante, O(n)

unsigned int left(unsigned int) const;
  -Devuelve el resultado de una operación por lo que siempre es constante, O(n).

unsigned int right(unsigned int) const;
  -Devuelve el resultado de una operación por lo que siempre es constante, O(n).

void heapify(unsigned int);
  -Se asegura que el elemento de la raíz sea el menor. Para ello recorre cada nivel del árbol. Como recorre cada piso y no elemento por elemento en el peor de los casos la búsqueda sigue siendo menor a n. Su complejidad por lo tanto es de log(n).

void swap(unsigned int, unsigned int);
  -Hace un cambio entre elementos, su complejidad es siempre constante, O(1).

bool full() const;
  -Comprueba que count no sea igual a size, es constante, O(1), porque nunca cambia lo que hace.

void add(Alumno);
  -Es constante porque solo agrega un nuevo elemento en el siguiente espacio

Alumno remove();
  -Como llama a heapify tiene la misma complejidad que este,  log(n)

ALUMNO
std::string getMatricula();
float getPromedio();
float getPromedio_Curva();  
  -Devuelven el valor de un atributo, al no cambiar su complejidad es constante, O(1);

void setPromedio_Curva(float);
void calcularPromedio();
  -Realizan un operación para poner el valor de un atributo por lo que son constantes, O(1).

void mostrarDatos(); 
  -Devuelve el valor de todos los atributo. Como el némro de atributos nunca cambia su complejidad es constante, O(1);

--------------------------------------------------------------------- 
3)CASOS DE PRUEBA
Lectura/Escritura
  -Borrar el contenido de calificaciones_finales.txt y correr el programa.

  OUTPUT
    -Los mismos nombre y matrículas deben aparecer en el calificaciones_finales.txt

Ordenamiento
  -Borrar el contenido de calificaciones_finales.txt y correr el programa.

  OUTPUT
    -Los promedios deben ir de menor a mayor en el archivo .txt
    -En consola deben conicidir la calificación más alta y más baja con las del documento