#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

#include "alumno.h"

//árbol heap
template <class T>
class Heap {
private:
	Alumno *data; //Arreglo de instancias de Alumno
	unsigned int size; //Tamaño del arreglo
	unsigned int count; //Ayuda a meter los objetos en su lugar
	
	unsigned int parent(unsigned int) const; //Devuelve la posición del elemento padre
	unsigned int left(unsigned int) const; //Devuelve la posición del elemento de la izquierda
	unsigned int right(unsigned int) const; //Devuelve la posición del elemento de la derecha
	void heapify(unsigned int); //Ordena el heap
	void swap(unsigned int, unsigned int); //Cambia de posición dos elementos
	
public:
	Heap(unsigned int); //Construtor
	~Heap(); //Destructor
	bool empty() const; //Indica si el heap se encuentra sin elementos
	bool full() const; //Indica si el heap se encuentra lleno
	void add(Alumno); //Añade un elemento al heap
	Alumno remove(); //Elimina un elemento del heap
	void clear(); //Elimina todos los elementos del heap
};

template <class T>
Heap<T>::Heap(unsigned int sze)  {
  size = sze;
  data = new Alumno[size];
  count = 0;
}

template <class T>
Heap<T>::~Heap() {
  clear();
 }

template <class T>
bool Heap<T>::empty() const {
  return (count == 0);
}

template <class T>
bool Heap<T>::full() const {
	return (count == size);
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return ((pos-1)/2);
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return (pos*2+1);
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return (pos*2+2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
  unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le < count && data[le].getPromedio() < data[min].getPromedio()) {
		min = le;
	}
	if (ri < count && data[ri].getPromedio() < data[min].getPromedio()) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::add(Alumno al) {
  if(full())
  {
    std::cout<<"HEAP LLENO NO SE PUDO AGREGAR EL DATO"<<std::endl;
    return;
  }

  int pos = count;
  data[count++] = al;
  while(pos>0 && al.getPromedio()<data[parent(pos)].getPromedio())
  {
    swap(pos,parent(pos));
    pos = parent(pos);
  }
}

template <class T>
Alumno Heap<T>::remove() {
	if(empty())
    std::cout<<"HEAP VACIÓ"<<std::endl;
  Alumno aux;
	aux = data[0];
  data[0] = data[--count];
  heapify(0);
	return aux;
}

template <class T>
void Heap<T>::clear() {
  delete [] data;
  /*for(int i=0;i<size;i++)
  {
    if(data[i]!=NULL)
      data[i]->~Alumno();
  }*/
  count = 0;
  size = 0;
}

#endif /* HASH_H_ */