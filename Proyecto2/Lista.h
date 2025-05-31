#pragma once
#include <memory>
#include "Objeto.h"

template <class T> class nodo;
template <class T> class iterador;
template <class T> class lista;

//-------nodo.h---------
template <class T>
class nodo {
	friend class iterador<T>;
	friend class lista<T>;
private:
	shared_ptr<T> objeto;
	shared_ptr<nodo<T>> siguiente;
public:
	nodo(const shared_ptr<T>&, shared_ptr<nodo<T>>);
	virtual string toString() const;
	virtual~nodo();
};
//-------nodo.cpp-------

template <class T>
nodo<T>::nodo(const shared_ptr<T>& obj, shared_ptr<nodo<T>> sig) : objeto(obj), siguiente(sig) {}


template <class T>
string nodo<T>::toString() const {
	stringstream s;
	s << **objeto;
	if (siguiente != nullptr) {
		s << *siguiente;
	}
	return s.str();
}

template <class T>
nodo<T>::~nodo() {
	//no hay que usar una liberacion pues la maneja los punteros inteligentes
}

template <class T>
ostream& operator<<(ostream& os, const nodo<T>& n) {
	os << n.toString();
	return os;
}


//-------iterador.h-------
template <class T>
class iterador {
private:
	shared_ptr<nodo<T>> crusor;
public:
	iterador(shared_ptr<nodo<T>>);
	// Nota:
	  // El iterador debe proveer métodos para la inicialización,
	  // obtener la referencia al elemento actual (dereference),
	  // incrementar la posición del iterador y sobrecargar el operador
	  // de comparación (para verificar el final de la lista).

	virtual T& operator*() const;
	virtual iterador<T>& operator++();
	virtual bool operator!=(const iterador<T>&) const;
};
//-------iterador.cpp-------
template <class T>
iterador<T>::iterador(shared_ptr<nodo<T>>primero) : crusor(primero) {

}

template <class T>
T& iterador<T>::operator*() const {
	return *(crusor->objeto); // preferible porque uso smart pointers
	//en lugar de
	// return **(crusor.get()->objeto);

}
template <class T>
iterador<T>& iterador<T>::operator++() {//esto es para movernos al siguiente;
	crusor = crusor->siguiente;
	return *this;
}

template <class T>
bool iterador<T>::operator!=(const iterador<T>& otro) const {
	// compara si ambos iteradores están en posiciones diferentes
	if (crusor != otro.crusor) {
		return true;
	}
	return false;
}

//-------lista.h-------
template <class T>
class lista {
private:
	shared_ptr<nodo<T>>primero;
public:
	lista();
	virtual ~lista();

	lista(const lista<T>&) = delete;
	lista<T> operator=(const lista<T>&) = delete;

	virtual bool estaVacia() const;
	virtual lista<T>& agregar(const T&);
	virtual void eliminarTodos();
	virtual string toString() const;

	void eliminar(const T&);
	
	virtual iterador<T> begin() const;
	virtual iterador<T> end() const;
};
//---------lista.cpp---------
template <class T>
lista<T>::lista() :primero(nullptr) {}

template <class T>
lista<T>::~lista() {
}

template <class T>
bool lista<T>::estaVacia() const {
	return primero == nullptr;
}

template <class T>
lista<T>& lista<T>::agregar(const T& obj) {
	auto ptr_obj = std::make_shared<T>(obj);
	primero = make_shared<nodo<T>>(ptr_obj, primero);
	return *this;
}


template <class T>
void lista<T>::eliminarTodos() {
	// Nota:
	  // Observe que el método NO elimina los elementos de manera
	  // explícita. Solamente se actualiza la referencia del
	  // primer elemento.
	  // Al hacer que el puntero tenga un valor nulo, la memoria
	  // se recupera automáticamente en el destructor de la lista,
	  // ya que no existirán referencias a los objetos correspondientes.

	primero = nullptr;

}

template <class T>
string lista<T>::toString() const {
	stringstream s;
	if (primero != nullptr) {
		s << *primero << endl;
	}
	return s.str();
}

template <class T>
void lista<T>::eliminar(const T& obj) {
	if (!primero) return; // lista vacía

	// Caso especial: eliminar el primer nodo
	while (primero && *(primero->objeto) == obj) {
		primero = primero->siguiente;
	}

	if (!primero) return;

	// Nodo actual para iterar
	auto actual = primero;
	while (actual->siguiente) {
		if (*(actual->siguiente->objeto) == obj) {
			// Saltamos el nodo a eliminar
			actual->siguiente = actual->siguiente->siguiente;
		}
		else {
			actual = actual->siguiente;
		}
	}
}

template <class T>
iterador<T> lista<T>::begin() const {
	return iterador<T>(primero);

}

template <class T>
iterador<T> lista<T>::end() const {
	return iterador<T>(nullptr);
}