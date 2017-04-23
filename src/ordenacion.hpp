#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#include "modo_ejecucion.hpp"
extern modo_ejecucion MODO;  // Se importa la variable global MODO como variable externa


////////// FUNCIONES AUXILIARES //////////

// Función que muestra por pantalla la secuencia y los valores que se están comparando
template <class T>
void comparando (vector<T> secuencia, int a, int b){
    getchar();
    for (int i=0; i<secuencia.size(); i++){
        secuencia[i].write(cout);
    }
    cout << endl;
    for (int i=0; i<secuencia.size(); i++){
        if ((i == a) || (i == b)){
            cout << setw(10) << "-------";
        }
        else{
            cout << setw(10) << "";
        }
    }
    cout << "\nComparando: " << a << " - " << b << endl;
}

// Función que imprime la subsecuencia especificada
template <class T>
void impr_subsec (vector<T> secuencia, int izq, int dch){
    for (int i=izq; i<=dch; i++){
        secuencia[i].write(cout);
    }
}


////////// FUNCIONES DE ORDENACION //////////

//////////////////// ORDENACION POR SELECCION ////////////////////
template <class T>
vector<T> ordenacion_seleccion (vector<T> secuencia, int size){
    int min;  // Valor mínimo encontrado
    T aux;
    // Se recorre la secuencia entera
    for (int i=0; i<size-1; i++){
        if (MODO == demostracion){
            cout << "\n\n----- Iteracion " << i+1 << " -----\n" << endl;
        }
        min = i;
        // Se recorre la subsecuencia que no está ordenada
        for (int j=i+1; j<size; j++){
            if (MODO == demostracion){
                comparando(secuencia, j, min);
            }
            // Si se encuentra un valor menor que el mínimo actual, dicho valor pasa a ser el valor mínimo
            if (secuencia[j] < secuencia[min]){
                if (MODO == demostracion){
                    cout << "Nueva posicion con valor minimo: " << j << endl;
                }
                min = j;
            }
        }
        if (MODO == demostracion){
            cout << "Minimo de la subsecuencia: ";
            secuencia[min].write(cout);
            cout << endl;
        }
        // Se coloca el valor mínimo encontrado en la posición correspondiente
        aux = secuencia[min];
        secuencia[min] = secuencia[i];
        secuencia[i] = aux;
    }
    return secuencia;
}


//////////////////// ORDENACION BINSORT ////////////////////
template <class T>
vector<T> ordenacion_binsort (vector<T> secuencia, int size){
    int inicio;  // Inicio de la subsecuencia
    int fin;  // Fin de la subsecuencia
    int medio;  // Medio de la subsecuencia
    T aux;
    // Se itera n-1 veces, donde n es el tamaño de la secuencia
    for (int i=1; i<size; i++){
        if (MODO == demostracion){
            cout << "\n\n----- Iteracion " << i << " -----\n" << endl;
        }
        aux = secuencia[i];
        inicio = 0;
        fin = i - 1;
        while (inicio <= fin){
            medio = (inicio + fin) / 2;
            // Si el valor del medio es menor que el auxiliar, se pasa a comparar en la subsecuencia de la derecha
            if (secuencia[medio] < aux){
                inicio = medio + 1;
            }
            // Si el valor del medio es mayor o igual que el auxiliar, se pasa a comparar en la subsecuencia de la izquierda
            else{
                fin = medio - 1;
            }
        }
        if (MODO == demostracion){
            comparando(secuencia, inicio, i);
        }
        // Se ruedan los valores una posición a la izquierda para colocar el nuevo valor
        for (int j=i-1; j>=inicio; j--){
            secuencia[j+1] = secuencia[j];
        }
        // Se coloca el nuevo valor
        secuencia[inicio] = aux;
    }
    return secuencia;
}


//////////////////// ORDENACION BURBUJA ////////////////////
template <class T>
vector<T> ordenacion_burbuja (vector<T> secuencia, int size){
    int inicio = 0;  // Inicio de la subsecuencia
    int fin = size - 1;  // Fin de la subsecuencia
    int it = 1;  // Iteración
    bool ordenado = false;
    T aux;
    while ((inicio < fin) && (!ordenado)){  // Mientras el inicio esté detrás del fin, y la secuencia no esté ordenada
        if (MODO == demostracion){
            cout << "\n\n----- Iteracion " << it << " -----\n" << endl;
        }
        ordenado = true;
        // Se recorre la subsecuencia desde el fin hacia el inicio
        for (int i=fin; i>inicio; i--){
            if (MODO == demostracion){
                comparando(secuencia, i, i-1);
            }
            // Si el valor es menor que su anterior se intercambian
            if (secuencia[i] < secuencia[i-1]){
                if (MODO == demostracion){
                    secuencia[i].write(cout);
                    cout << " <";
                    secuencia[i-1].write(cout);
                    cout << ". Intercambiando posiciones..." << endl;
                }
                aux = secuencia[i];
                secuencia[i] = secuencia[i-1];
                secuencia[i-1] = aux;
                ordenado = false;
            }
        }
        inicio ++;
        if (MODO == demostracion){
            it ++;
        }
    }
    return secuencia;
}


//////////////////// ORDENACION POR SACUDIDA ////////////////////
template <class T>
vector<T> ordenacion_sacudida (vector<T> secuencia, int size){
    int inicio = 0;  // Inicio de la subsecuencia
    int fin = size - 1;  // Fin de la subsecuencia
    int tope;  // Posición tope de la subsecuencia
    int it = 1;  // Iteración
    bool ordenado = false;
    T aux;
    while ((inicio < fin) && (!ordenado)){  // Mientras el inicio esté detrás del fin, y la secuencia no esté ordenada
        if (MODO == demostracion){
            cout << "\n\n----- Iteracion " << it << " -----\n" << endl;
        }
        ordenado = true;
        // Se recorre la subsecuencia desde el fin hacia el inicio
        for (int i=fin; i>inicio; i--){
            if (MODO == demostracion){
                comparando(secuencia, i, i-1);
            }
            // Si el valor es menor que su anterior se intercambian
            if (secuencia[i] < secuencia[i-1]){
                if (MODO == demostracion){
                    secuencia[i].write(cout);
                    cout << " <";
                    secuencia[i-1].write(cout);
                    cout << ". Intercambiando posiciones..." << endl;
                }
                aux = secuencia[i];
                secuencia[i] = secuencia[i-1];
                secuencia[i-1] = aux;
                tope = i;
                ordenado = false;
            }
        }
        inicio = tope;
        // Se recorre la subsecuencia desde el nuevo inicio hacia el fin
        for (int i=inicio; i<fin; i++){
            if (MODO == demostracion){
                comparando(secuencia, i, i+1);
            }
            // Si el valor es mayor que su siguiente se intercambian
            if (secuencia[i] > secuencia[i+1]){
                if (MODO == demostracion){
                    secuencia[i].write(cout);
                    cout << " >";
                    secuencia[i+1].write(cout);
                    cout << ". Intercambiando posiciones..." << endl;
                }
                aux = secuencia[i];
                secuencia[i] = secuencia[i+1];
                secuencia[i+1] = aux;
                tope = i;
                ordenado = false;
            }
        }
        fin = tope;
        if (MODO == demostracion){
            it ++;
        }
    }
    return secuencia;
}


//////////////////// ORDENACION POR MEZCLA ////////////////////
template <class T>
void mezcla (vector<T> &secuencia, int inicio, int centro, int fin){
    if (MODO == demostracion){
        cout << "\n\nMezclando subsecuencias:" << endl;
        impr_subsec(secuencia, inicio, centro);
        cout << endl;
        impr_subsec(secuencia, centro+1, fin);
        cout << endl;
    }
    vector<T> aux(fin+1);  // Vector auxiliar para guardar las subsecuencias mezcladas
    int i = inicio;  // Inicio de la subsecuencia
    int c = centro + 1;  // Centro de la subsecuencia
    int k = inicio;  // Índice del vector auxiliar
    // Mientras ambas subsecuencias tengan algún elemento...
    while ((i <= centro) && (c <= fin)){
        // Si el valor de la primera subsecuencia es el menor, se añade al vector auxiliar
        if (secuencia[i] < secuencia[c]){
            aux[k] = secuencia[i];
            i ++;
        }
        // Si no, se añade el valor de la segunda subsecuencia al vector auxiliar
        else{
            aux[k] = secuencia[c];
            c ++;
        }
        if (MODO == demostracion){
            getchar();
            impr_subsec(aux, inicio, aux.size()-1);
            cout << endl;
        }
        k ++;
    }
    // Si el primer vector ha quedado vacío, se añade el segundo al vector auxiliar
    if (i > centro){
        while (c <= fin){
            aux[k] = secuencia[c];
            if (MODO == demostracion){
                getchar();
                impr_subsec(aux, inicio, aux.size()-1);
                cout << endl;
            }
            c ++;
            k ++;
        }
    }
    // Si el segundo vector ha quedado vacío, se añade el primero al vector auxiliar
    else{
        while (i <= centro){
            aux[k] = secuencia[i];
            if (MODO == demostracion){
                getchar();
                impr_subsec(aux, inicio, aux.size()-1);
                cout << endl;
            }
            i ++;
            k ++;
        }
    }
    // Se modifica la subsecuencia con la subsecuencia mezclada
    for (int j=inicio; j<=fin; j++){
        secuencia[j] = aux[j];
    }
}

template <class T>
void sub_ord_mezcla (vector<T> &secuencia, int inicio, int fin){
    if (inicio < fin){  // Si la subsecuencia tiene más de un valor...
        int centro = (inicio + fin) / 2;  // Se "divide" la subsecuencia en 2 partes
        if (MODO == demostracion){
            getchar();
            cout << "\n\nOrdenando subsecuencia " << inicio << " - " << centro << endl;
            impr_subsec(secuencia, inicio, centro);
        }
        sub_ord_mezcla(secuencia, inicio, centro);  // Recursividad para dividir la primera de las divisiones
        if (MODO == demostracion){
            getchar();
            cout << "\n\nOrdenando subsecuencia " << centro+1 << " - " << fin << endl;
            impr_subsec(secuencia, centro+1, fin);
        }
        sub_ord_mezcla(secuencia, centro+1, fin);  // Recursividad para dividir la segunda de las divisiones
        mezcla(secuencia, inicio, centro, fin);  // Se mezclan las dos subsecuencias obtenidas
    }
}

template <class T>
vector<T> ordenacion_mezcla (vector<T> secuencia, int size){
    sub_ord_mezcla(secuencia, 0, size-1);
    return secuencia;
}


//////////////////// ORDENACION RAPIDA ////////////////////
template <class T>
void sub_ord_rapida (vector<T> &secuencia, int inicio, int fin){
    int i = inicio;  // Inicio de la subsecuencia
    int f = fin;  // Fin de la subsecuencia
    int it = 1;  // Iteración
    T p = secuencia[(i + f) / 2];  // Pivote
    T aux;
    while (i < f){  // Mientras el inicio y el fin no se crucen...
        if (MODO == demostracion){
            comparando(secuencia, i, f);
            cout << "Pivote: ";
            p.write(cout);
            cout << endl;
        }
        while (secuencia[i] < p){  // Mientras el valor de la izquierda sea menor que el pivote se pasa al siguiente elemento
            i ++;
            if (MODO == demostracion){
                comparando(secuencia, i, f);
                cout << "Pivote: ";
                p.write(cout);
                cout << endl;
            }
        }
        while (secuencia[f] > p){  // Mientras el valor de la derecha sea mayor que el pivote se pasa al elemento anterior
            f --;
            if (MODO == demostracion){
                comparando(secuencia, i, f);
                cout << "Pivote: ";
                p.write(cout);
                cout << endl;
            }
        }
        if (i <= f){  // Si el inicio y el fin no se ha sobrepasado...
            if (MODO == demostracion){
                getchar();
                cout << "Intercambiando posiciones..." << endl;
            }
            // Se intercambian los valores de los lados izquierdo y derecho
            aux = secuencia[i];
            secuencia[i] = secuencia[f];
            secuencia[f] = aux;
            i ++;  // Se pasa al siguiente elemento de la parte izquierda
            f --;  // Se pasa al elemento anterior de la parte derecha
        }
        if (MODO == demostracion){
            it ++;
        }
    }
    if (inicio < f){  // Si el fin no ha rebasado el inicio original...
        if (MODO == demostracion){
            cout << "\nOrdenando nueva subsecuencia...\n" << endl;
        }
        sub_ord_rapida(secuencia, inicio, f);  // Recursividad para ordenar la subsecuencia del inicio original al fin
    }
    if (i < fin){  // Si el inicio no ha rebasado el fin original...
        if (MODO == demostracion){
            cout << "\nOrdenando nueva subsecuencia...\n" << endl;
        }
        sub_ord_rapida(secuencia, i, fin);  // Recursividad para ordenar la subsecuencia del inicio al fin original
    }
}

template <class T>
vector<T> ordenacion_rapida (vector<T> secuencia, int size){
    sub_ord_rapida(secuencia, 0, size-1);
    return secuencia;
}


//////////////////// ORDENACION POR INCREMENTOS ////////////////////
template <class T>
vector<T> ordenacion_incrementos (vector<T> secuencia, int size, int delta){
    int j;  // Iterador
    T aux;
    while (delta >= 1){  // Mientras delta sea mayor o igual a 1...
        if (MODO == demostracion){
            cout << "Desplazamiento delta: " << delta << endl;
        }
        // Se ordenan las subsecuencias generadas de detrás hacia delante
        for (int i=delta; i<size; i++){
            j = i - delta;
            if (MODO == demostracion){
                comparando(secuencia, j, j+delta);
            }
            // Mientras el iterador no se salga de la secuencia y el valor de la izquierda sea mayor el de la derecha...
            while ((j>=0) && (secuencia[j]>secuencia[j+delta])){
                if (MODO == demostracion){
                    getchar();
                    cout << "Intercambiando posiciones " << j << " - " << j+delta << endl;
                }
                // Se intercambian ambos valores
                aux = secuencia[j];
                secuencia[j] = secuencia[j+delta];
                secuencia[j+delta] = aux;
                j -= delta;  // Se disminuye el iterador para comparar los siguientes elementos
            }
        }
        delta = delta / 2;  // Se disminuye la delta a la mitad
    }
    return secuencia;
}
