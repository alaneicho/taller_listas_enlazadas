#include "Lista.h"

Lista::Lista() : longitud_(0), primero_(nullptr), ultimo_(nullptr) {
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo_primero = new Nodo(elem);
    nuevo_primero->proximo = this->primero_;
    //struct Nodo nuevo_primero = {nullptr, elem, this->primero_ };
    this->primero_ = nuevo_primero;
    if (longitud_ == 0){
        this->ultimo_ = nuevo_primero;
    }
    this->longitud_++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo_ultimo = new Nodo(elem);
    nuevo_ultimo->anterior = this->ultimo_;
    //struct Nodo nuevo_ultimo = {this->ultimo_, elem, nullptr};
    this->ultimo_ = nuevo_ultimo;
    if (longitud_ == 0){
        this->primero_ = nuevo_ultimo;
    }
    this->longitud_++;
}

void Lista::eliminar(Nat i) {
    // Completar
}

int Lista::longitud() const {
    return longitud_;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* nodo_actual = this->primero_;
    while (i > 0){
        nodo_actual = nodo_actual->proximo;
        i--;
    }
    return (int &) nodo_actual->valor;
    // Completar
    //assert(false);
}

int& Lista::iesimo(Nat i) {

    Nodo* nodo_actual = this->primero_;
    while (i > 0){
        nodo_actual = nodo_actual->proximo;
        i--;
    }
    return (int &) nodo_actual->valor;
    // Completar (hint: es igual a la anterior...)
    //assert(false);
}

void Lista::mostrar(ostream& o) {
    // Completar
}
