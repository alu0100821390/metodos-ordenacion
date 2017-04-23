#include "matricula_t.hpp"
#include "modo_ejecucion.hpp"

extern int contador;  // Se importa la variable global contador como variable externa
extern modo_ejecucion MODO;  // Se importa la variable global MODO como variable externa

// Constructor por defecto
matricula_t::matricula_t (void)
{
    for (int i=0; i<7; i++){
        valor_[i] = 0;
    }
}

// Constructor parametrizado
matricula_t::matricula_t (string valor)
{
    contador ++;
    for (int i=0; i<7; i++){
        valor_[i] = valor[i];
    }
}

// Destructor
matricula_t::~matricula_t (void)
{

}

// Sobrecarga del operador int
matricula_t::operator int (void)
{
    int aux = 0;
    for (int i=0; i<7; i++){
        aux += valor_[i] * (i + 1);
    }

    return aux;
}

// Sobrecarga del operador ==
bool matricula_t::operator == (const matricula_t &matricula) const
{
    bool iguales = true;
    int i = 0;
    // Se comprueba que los valores de las matrículas, en la misma posición, coincidan
    while ((i < 7) && (iguales == true)){
        if (valor_[i] != matricula.valor_[i]){
            iguales = false;
        }
        i ++;
    }

    if (MODO == estadistico){  // Si se está ejecutando el programa en modo estadístico...
        contador ++;  // Se aumenta el contador
    }
    return iguales;
}

// Sobrecarga del operador <
bool matricula_t::operator < (const matricula_t &matricula) const
{
    int a = 0;
    int b = 0;
    // Se guardan las matrículas como sus correspondientes valores enteros
    for (int i=0; i<7; i++){
        a += valor_[i] * (i + 1);
        b += matricula.valor_[i] * (i + 1);
    }

    if (MODO == estadistico){  // Si se está ejecutando el programa en modo estadístico...
        contador ++;  // Se aumenta el contador
    }
    return a < b;
}

// Sobrecarga del operador >
bool matricula_t::operator > (const matricula_t &matricula) const
{
    int a = 0;
    int b = 0;
    // Se guardan las matrículas como sus correspondientes valores enteros
    for (int i=0; i<7; i++){
        a += valor_[i] * (i + 1);
        b += matricula.valor_[i] * (i + 1);
    }

    if (MODO == estadistico){  // Si se está ejecutando el programa en modo estadístico...
        contador ++;  // Se aumenta el contador
    }
    return a > b;
}

// Sobrecarga del operador <=
bool matricula_t::operator <= (const matricula_t &matricula) const
{
    int a = 0;
    int b = 0;
    // Se guardan las matrículas como sus correspondientes valores enteros
    for (int i=0; i<7; i++){
        a += valor_[i] * (i + 1);
        b += matricula.valor_[i] * (i + 1);
    }

    if (MODO == estadistico){  // Si se está ejecutando el programa en modo estadístico...
        contador ++;  // Se aumenta el contador
    }
    return a <= b;
}

// Sobrecarga del operador >=
bool matricula_t::operator >= (const matricula_t &matricula) const
{
    int a = 0;
    int b = 0;
    // Se guardan las matrículas como sus correspondientes valores enteros
    for (int i=0; i<7; i++){
        a += valor_[i] * (i + 1);
        b += matricula.valor_[i] * (i + 1);
    }

    if (MODO == estadistico){  // Si se está ejecutando el programa en modo estadístico...
        contador ++;  // Se aumenta el contador
    }
    return a >= b;
}

// Se muestra la matrícula formateada por la salida especificada
ostream& matricula_t::write (ostream& os) const
{
    if (valor_[0] == '\0'){  // Si la matrícula no contiene ningún valor...
        os << setw(10) << "N/A";
    }
    else{
        cout << "   ";
        for (int i=0; i<7; i++){
            os << valor_[i];
        }
    }
    return os;
}
