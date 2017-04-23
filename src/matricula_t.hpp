#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


class matricula_t
{
private:
    char valor_ [8];  // Cadena de aracteres que guardará los valores de la matrícula

public:
    matricula_t (void);  // Constructor por defecto
    matricula_t (string valor);  // Constructor parametrizado
    ~matricula_t (void);  // Destructor

    operator int (void);  // Sobrecarga del operador int
    bool operator == (const matricula_t &matricula) const;  // Sobrecarga del operador ==
    bool operator < (const matricula_t &matricula) const;  // Sobrecarga del operador <
    bool operator > (const matricula_t &matricula) const;  // Sobrecarga del operador >
    bool operator <= (const matricula_t &matricula) const;  // Sobrecarga del operador <=
    bool operator >= (const matricula_t &matricula) const;  // Sobrecarga del operador >=

    ostream& write (ostream& os) const;  // Se muestra la matrícula formateada por la salida especificada
};
