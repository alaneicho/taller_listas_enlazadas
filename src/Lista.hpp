#include "Lista.h"

Lista::Lista() : longitud_(0), primero_(nullptr), ultimo_(nullptr) {
}

Lista::Lista(const Lista &l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    this->destruirLista();
}

void Lista::destruirLista() {
    Nodo *proximo_a_borrar = this->primero_;
    while (proximo_a_borrar != nullptr) {
        Nodo *temp = proximo_a_borrar->proximo;
        delete proximo_a_borrar;
        proximo_a_borrar = temp;
    }
    this->primero_ = nullptr;
    this->ultimo_ = nullptr;
    this->longitud_ = 0;
}

Lista &Lista::operator=(const Lista &aCopiar) {
    this->destruirLista();
    int i = 0;
    while (i < aCopiar.longitud()){
        this->agregarAtras(aCopiar.iesimo(i));
        i++;
    }
    return *this;
}

void Lista::agregarAdelante(const int &elem) {
    Nodo *nuevo_primero = new Nodo(elem);
    nuevo_primero->proximo = this->primero_;
    if (this->longitud_ > 0) {
        this->primero_->anterior = nuevo_primero;
    }
    this->primero_ = nuevo_primero;
    if (longitud_ == 0) {
        this->ultimo_ = nuevo_primero;
    }
    this->longitud_++;
}

void Lista::agregarAtras(const int &elem) {
    Nodo *nuevo_ultimo = new Nodo(elem);
    nuevo_ultimo->anterior = this->ultimo_;
    if (this->longitud_ > 0) {
        this->ultimo_->proximo = nuevo_ultimo;
    }
    this->ultimo_ = nuevo_ultimo;
    if (longitud_ == 0) {
        this->primero_ = nuevo_ultimo;
    }
    this->longitud_++;
}

void Lista::eliminar(Nat i) {
    // Completar

    if (longitud_ == 1) {
        delete this->primero_;
        this->primero_ = nullptr;
        this->ultimo_ = nullptr;

    } else {
        Nodo *nodo_byebye = this->primero_;
        while (i > 0) {
            nodo_byebye = nodo_byebye->proximo;
            i--;
        }
        if (nodo_byebye == this->primero_) {
            Nodo *nuevo_primero = this->primero_->proximo;
            this->primero_ = nuevo_primero;
            this->primero_->anterior = nullptr;
        } else if (nodo_byebye == this->ultimo_) {
            Nodo *nuevo_ultimo = this->ultimo_->anterior;
            this->ultimo_ = nuevo_ultimo;
            this->ultimo_->proximo = nullptr;
        } else {
            nodo_byebye->anterior->proximo = nodo_byebye->proximo;
            nodo_byebye->proximo->anterior = nodo_byebye->anterior;
        }

        delete nodo_byebye;
    }
    this->longitud_--;
}

int Lista::longitud() const {
    return longitud_;
}

const int &Lista::iesimo(Nat i) const {
    Nodo *nodo_actual = this->primero_;
    while (i > 0) {
        nodo_actual = nodo_actual->proximo;
        i--;
    }
    return nodo_actual->valor;
}

int &Lista::iesimo(Nat i) {

    Nodo *nodo_actual = this->primero_;
    while (i > 0) {
        nodo_actual = nodo_actual->proximo;
        i--;
    }
    return nodo_actual->valor;
    // Completar (hint: es igual a la anterior...)
    //assert(false);
}

void Lista::mostrar(ostream &o) {
    // Completar
}
