#pragma once
#include "objectBase.h"
#include <memory>

template <class T> class lista;
template <class T> class nodo;
template <class T> class iterador;

//--------class nodo----------
template <class T>
class nodo : public Base {
	friend class lista<T>;
	friend class iterador<T>;
public:
	nodo(const T& inf);
	nodo(const T&, shared_ptr<nodo<T>>);
	virtual ~nodo();
	virtual string toString() const override;
private:
	shared_ptr<T> info;
	shared_ptr<nodo<T>> siguiente;
};
//----implementación nodo-----

template <class T>
nodo<T>::nodo(const T& inf):info(make_shared<T>(inf)),siguiente(nullptr){}

template <class T>
nodo<T>::nodo(const T& inf, shared_ptr<nodo<T>> next) : info(make_shared<T>(inf)), siguiente(next) {

}

template <class T>
nodo<T>::~nodo() {}

template <class T>
string nodo<T>::toString() const {
	stringstream s;
	s << *info;
	if (siguiente != nullptr) {
		s << *siguiente;
	}
	return s.str();
}
//--fin implementación nodo--

//-----class iterador----
template <class T>
class iterador {
public:
	iterador(shared_ptr<nodo<T>>);
	virtual T& operator*() const;
	virtual iterador<T>& operator++();
	virtual bool operator!=(const iterador<T>&) const;
	virtual bool operator==(const iterador<T>&otro) const;

private:
	shared_ptr<nodo<T>> crusor;
};

//---implementación Iterador---

template <class T>
iterador<T>::iterador(shared_ptr<nodo<T>> primero) :crusor(primero) {

}

template <class T>
T& iterador<T>::operator*() const {
	return *(crusor->info);
}

template <class T>
iterador<T>& iterador<T>::operator++() {
	crusor = crusor->siguiente;
	return *this;
}

template <class T>
bool iterador<T>::operator!=(const iterador<T>&otro) const {
	return crusor != otro.crusor;
}

template <class T>
bool iterador<T>::operator==(const iterador<T>& otro) const {
	return crusor == otro.crusor;
}

//--fin implementación iterador

//---class lista---
template <class T>
class lista :public Base {
public:
	lista();
	virtual ~lista();
	virtual bool isEmpty();
	virtual lista<T>& agregar(const T&);
	virtual lista<T>& eliminar(const T&);
	virtual string toString() const override;
	virtual iterador<T> begin() const; //patron iterator
	virtual iterador<T> end() const; // patron iterator
private:
	shared_ptr<nodo<T>> primero;
};

//---implementación Lista----

template <class T>
lista<T>::lista(){}

template <class T>
lista<T>::~lista(){}

template <class T>
bool lista<T>::isEmpty() {
	return !primero;
}

template <class T>
lista<T>& lista<T>::agregar(const T&info) {
	shared_ptr<nodo < T>> tmp = make_shared<nodo < T >>(info);

	if (primero == nullptr) {
		primero = tmp;
	}
	else {
		nodo<T>* crusor = primero.get();
		while (crusor->siguiente != nullptr) {
			crusor = crusor->siguiente.get();
		}
		crusor->siguiente = tmp;
	}
	return *this;

}

template <class T>
lista<T>& lista<T>::eliminar(const T& info) {
	if (!primero) return *this;

	if (*(primero->info) == info) {  // compara shared_ptr
		primero = primero->siguiente;
		return *this;
	}

	auto actual = primero;
	while (actual->siguiente && *(actual->siguiente->info) != info) {
		actual = actual->siguiente;
	}

	if (actual->siguiente) {
		actual->siguiente = actual->siguiente->siguiente;
	}

	return *this;
}


template <class T>
string lista<T>::toString() const {
	stringstream s;
	if (primero != nullptr) {
		s << *primero;
	}
	return s.str();
}

template <class T>
iterador<T> lista<T>::begin() const { //patron iterator
	return iterador<T>(primero);

}

template <class T>
iterador<T> lista<T>::end() const { // patron iterator
	return iterador<T>(nullptr);
}

//------
