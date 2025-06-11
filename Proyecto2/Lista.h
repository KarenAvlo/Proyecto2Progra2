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

	public:

		nodo(const shared_ptr<T>&, shared_ptr<nodo<T>>);

		virtual string toString() const;
		virtual~nodo();

	private:

		shared_ptr<T> objeto;
		shared_ptr<nodo<T>> siguiente;
};

//-------nodo.cpp-------
template <class T>
nodo<T>::nodo(const shared_ptr<T>& obj, shared_ptr<nodo<T>> sig) : objeto(obj), siguiente(sig) {}

template <class T>
string nodo<T>::toString() const {
	stringstream s;

	s << **objeto<<'\n';

	if (siguiente != nullptr) {
		s << *siguiente;
	}

	return s.str();
}

template <class T>
nodo<T>::~nodo() {}

template <class T>
ostream& operator<<(ostream& os, const nodo<T>& n) {
	os << n.toString();

	return os;
}

//-------iterador.h-------
template <class T>
class iterador {

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

	private:

		shared_ptr<nodo<T>> crusor;
};

//-------iterador.cpp-------
template <class T>
iterador<T>::iterador(shared_ptr<nodo<T>>primero) : crusor(primero) {}

template <class T>
T& iterador<T>::operator*() const {
	return *(crusor->objeto);
}

template <class T>
iterador<T>& iterador<T>::operator++(){
	crusor = crusor->siguiente;

	return *this;
}

template <class T>
bool iterador<T>::operator!=(const iterador<T>& otro) const {
	if (crusor != otro.crusor) {
		return true;
	}

	return false;
}

//-------lista.h-------
template <class T>
class lista {

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

	private:

		shared_ptr<nodo<T>>primero;
};

//---------lista.cpp---------
template <class T>
lista<T>::lista() :primero(nullptr) {}

template <class T>
lista<T>::~lista() {}

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
iterador<T> lista<T>::end() const{
	return iterador<T>(nullptr);
}
