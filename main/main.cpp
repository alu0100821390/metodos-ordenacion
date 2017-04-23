#include <climits>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

#include "../src/modo_ejecucion.hpp"
modo_ejecucion MODO;  // Variabla global que contendrá el modo de ejecución del programa
int contador;  // Variable global que contendrá el número de comparaciones por iteración de cada algoritmo
#include "../src/matricula_t.hpp"
#include "../src/ordenacion.hpp"


// Estructura en la que se guardarán las estadísticas
struct estadisticas_t {
    int min = INT_MAX;
    int med = 0;
    int max = INT_MIN;
};

int main (void)
{
    int opcion = 0;  // Opción para el menú principal
    int N;  // Tamáño de las secuencias
    double alpha = -1;  // alpha para la ordenación ShellSort
    double med_aux;  // Variable auxiliar para calcular el número medio de comparaciones de cada algoritmo
    char matricula[8];  // Variable auxiliar para crear los objetos matricula_t
    vector<matricula_t> secuencia_ord;  // Vector auxiliar para guardar las secuencias ordenadas

    //  Menú principal del programa
    while (opcion != 3){  // Mientras no se elija la opción para salir...
        cout << endl;
        cout << "----- MENU -----" << endl;
        cout << "\t1. Modo demostracion" << endl;
        cout << "\t2. Modo estadistico" << endl;
        cout << "\t3. Salir" << endl;
        cout << "Elija el modo de ejecucion: ";
        cin >> opcion;
        cout << endl;

        // Se procede según la opción introducida
        switch (opcion){
            case 1:{  // Si se ha elegido el modo demostración...
                MODO = demostracion;  // Se establece el modo de ejecución a demostracion
                srand(time(NULL));  // Se crea la semilla para la generación de números aleatorios

                vector<matricula_t> secuencia;  // Vector que guardará la secuencia a ordenar

                cout << "----- MODO DEMOSTRACION -----" << endl;
                cout << "\nTamaño de la secuencia a ordenar: ";
                cin >> N;
                secuencia.clear();
                secuencia.resize(N);  // Se redimensiona el vector con N elementos

                // Se rellena la secuencia a ordenar con matrículas aleatorias
                for (int i=0; i<secuencia.size(); i++){
                    // Se generan las 4 letras de la matrícula
                    for (int j=0; j<4; j++){
                        matricula[j] = rand() % 10 + 48;
                    }
                    // Se generan los 3 números de la matrícula
                    for (int j=4; j<7; j++){
                        matricula[j] = rand() % 26 + 65;
                    }
                    matricula_t aux(matricula);  // Se crea un objeto matricula_t
                    secuencia[i] = aux;  // Se asigna el objeto creado a la posición correspondiente de la secuencia a ordenar
                }

                int ord_opcion = 0;  // Opción para el menú de algoritmos de ordenación
                while ((ord_opcion < 1) || (ord_opcion > 7)){  // Mientras no se introduzca una opción válida...
                    cout << endl;
                    cout << "----- ALGORITMO DE ORDENACION -----" << endl;
                    cout << "\t1. Ordenacion por selección" << endl;
                    cout << "\t2. Ordenacion binsort" << endl;
                    cout << "\t3. Ordenacion burbuja" << endl;
                    cout << "\t4. Ordenacion por sacudida" << endl;
                    cout << "\t5. Ordenacion por mezcla" << endl;
                    cout << "\t6. Ordenacion rapida" << endl;
                    cout << "\t7. Ordenacion por incrementos decrecientes" << endl;
                    cout << "Elija el algoritmo de ordenacion: ";
                    cin >> ord_opcion;
                    cout << endl;
                }
                system("clear");

                ////////////////////////////// SECUENCIA ORIGINAL //////////////////////////////
                cout << "\n--- SECUENCIA ORIGINAL ---\n" << endl;
                // Se muestra por pantalla la secuencia original a ordenar
                for (int i=0; i<secuencia.size(); i++){
                    secuencia[i].write(cout);
                }

                // Se procede según la opción introducida
                switch (ord_opcion){
                    case 1:{  // Si se ha elegido la ordenación por selección...
                        ////////////////////////////// SELECCION //////////////////////////////
                        cout << "\n\n--- ORDENACION POR SELECCION ---" << endl;
                        // Se llama a la función que ordena por selección
                        secuencia_ord = ordenacion_seleccion(secuencia, N);  // Se guarda la salida de la función
                        break;                                               // es decir, la secuencia ordenada
                    }
                    case 2:{  // Si se ha elegido la ordenación BinSort
                        ////////////////////////////// BINSORT //////////////////////////////
                        cout << "\n\n--- ORDENACION BINSORT ---" << endl;
                        // Se llama a la función que ordena por BinSort
                        secuencia_ord = ordenacion_binsort(secuencia, N);  // Se guarda la salida de la función
                        break;                                             // es decir, la secuencia ordenada
                    }
                    case 3:{  // Si se ha elegido la ordenación burbuja
                        ////////////////////////////// BURBUJA //////////////////////////////
                        cout << "\n\n--- ORDENACION BURBUJA ---" << endl;
                        // Se llama a la función que ordena por burbuja
                        secuencia_ord = ordenacion_burbuja(secuencia, N);  // Se guarda la salida de la función
                        break;                                             // es decir, la secuencia ordenada
                    }
                    case 4:{  // Si se ha elegido la ordenación por sacudida
                        ////////////////////////////// SACUDIDA //////////////////////////////
                        cout << "\n\n--- ORDENACION POR SACUDIDA ---" << endl;
                        // Se llama a la función que ordena por sacudida
                        secuencia_ord = ordenacion_sacudida(secuencia, N);  // Se guarda la salida de la función
                        break;                                              // es decir, la secuencia ordenada
                    }
                    case 5:{  // Si se ha elegido la ordenación por mezcla
                        ////////////////////////////// MEZCLA //////////////////////////////
                        cout << "\n\n--- ORDENACION POR MEZCLA ---" << endl;
                        // Se llama a la función que ordena por mezcla
                        secuencia_ord = ordenacion_mezcla(secuencia, N);  // Se guarda la salida de la función
                        break;                                            // es decir, la secuencia ordenada
                    }
                    case 6:{  // Si se ha elegido la ordenación rápida
                        ////////////////////////////// RAPIDA //////////////////////////////
                        cout << "\n\n--- ORDENACION RAPIDA ---" << endl;
                        // Se llama a la función que ordena por ordenación rápida
                        secuencia_ord = ordenacion_rapida(secuencia, N);  // Se guarda la salida de la función
                        break;                                            // es decir, la secuencia ordenada
                    }
                    case 7:{  // Si se ha elegido la ordenación por incrementos decrecientes
                        ////////////////////////////// INCREMENTOS //////////////////////////////
                        alpha = -1;
                        // Se pide la constante de reducción
                        while ((alpha < 0.1) || (alpha > 1)){
                            cout << "\n\nIntroduzca la constante de reducción para la ordenación por incrementos en el intervalo [0.1 - 1]: ";
                            cin >> alpha;
                        }
                        cout << "\n\n--- ORDENACION POR INCREMENTOS ---" << endl;
                        // Se llama a la función que ordena por incrementos decrecientes
                        secuencia_ord = ordenacion_incrementos(secuencia, N, alpha*N);  // Se guarda la salida de la función
                        break;                                                          // es decir, la secuencia ordenada
                    }
                }

                bool ordenado = true;
                int i = 0;
                while (i < secuencia_ord.size()-2){  // Mientras no se hayan comparado todos los elementos...
                    if (secuencia_ord[i] > secuencia_ord[i+1]){  // Si el elemento anterior es mayor que el siguiente...
                        ordenado = false;
                        i = secuencia_ord.size()-2;  // Se sale del bucle
                    }
                    i ++;
                }
                if (ordenado){
                    cout << "La secuencia ha sido ordenada!\nResultado: ";
                }
                else{
                    cout << "La secuencia NO ha sido ordenada!\nResultado: ";
                }

                for (int i=0; i<secuencia_ord.size(); i++){
                    secuencia_ord[i].write(cout);
                }

                cout << endl;
                break;
            }
            case 2:{  // Si se ha elegido el modo estadístico...
                MODO = estadistico;  // Se establece el modo de ejecución a demostracion
                int nPruebas;  // Número de pruebas
                vector<vector<matricula_t> > banco_pruebas;  // Banco de pruebas que contendrá las secuencias a ordenar
                vector<estadisticas_t> estadisticas(7);  // Vector en el que se guardarán las estadísticas de los diferentes algoritmos

                cout << "----- MODO ESTADISTICO -----" << endl;
                cout << "\nTamaño de la secuencia a ordenar: ";
                cin >> N;
                cout << "Numero de pruebas: ";
                cin >> nPruebas;

                banco_pruebas.clear();
                banco_pruebas.resize(nPruebas, vector<matricula_t>(N));  // Se redimensiona el banco de pruebas con nPruebas vectores

                // Se rellena la secuencia a ordenar con matrículas aleatorias
                for (int i=0; i<nPruebas; i++){
                    for (int j=0; j<N; j++){
                        // Se generan las 4 letras de la matrícula
                        for (int k=0; k<4; k++){
                            matricula[k] = rand() % 10 + 48;
                        }
                        // Se generan los 3 números de la matrícula
                        for (int k=4; k<7; k++){
                            matricula[k] = rand() % 26 + 65;
                        }
                        matricula_t aux(matricula);  // Se crea un objeto matricula_t
                        banco_pruebas[i][j] = aux;  // Se asigna el objeto creado a la posición correspondiente de la secuencia a ordenar
                    }
                }

                med_aux = 0;
                for (int i=0; i<nPruebas; i++){
                    contador = 0;
                    secuencia_ord = ordenacion_seleccion(banco_pruebas[i], N);
                    if (contador < estadisticas[0].min){  // Si el nuevo contador es menor que el mínimo
                        estadisticas[0].min = contador;  // El contador pasa a ser el nuevo mínimo
                    }
                    if (contador > estadisticas[0].max){  // Si el nuevo contador es mayor que el máximo
                        estadisticas[0].max = contador;  // El contador pasa a ser el nuevo máximo
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                estadisticas[0].med = med_aux / nPruebas;  // Se guarda el valor medio de comparaciones

                med_aux = 0;
                for (int i=0; i<nPruebas; i++){
                    contador = 0;
                    secuencia_ord = ordenacion_binsort(banco_pruebas[i], N);
                    if (contador < estadisticas[1].min){  // Si el nuevo contador es menor que el mínimo
                        estadisticas[1].min = contador;  // El contador pasa a ser el nuevo mínimo
                    }
                    if (contador > estadisticas[1].max){  // Si el nuevo contador es mayor que el máximo
                        estadisticas[1].max = contador;  // El contador pasa a ser el nuevo máximo
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                estadisticas[1].med += med_aux / nPruebas;  // Se guarda el valor medio de comparaciones

                med_aux = 0;
                for (int i=0; i<nPruebas; i++){
                    contador = 0;
                    secuencia_ord = ordenacion_burbuja(banco_pruebas[i], N);
                    if (contador < estadisticas[2].min){  // Si el nuevo contador es menor que el mínimo
                        estadisticas[2].min = contador;  // El contador pasa a ser el nuevo mínimo
                    }
                    if (contador > estadisticas[2].max){  // Si el nuevo contador es mayor que el máximo
                        estadisticas[2].max = contador;  // El contador pasa a ser el nuevo máximo
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                estadisticas[2].med += med_aux / nPruebas;  // Se guarda el valor medio de comparaciones

                med_aux = 0;
                for (int i=0; i<nPruebas; i++){
                    contador = 0;
                    secuencia_ord = ordenacion_sacudida(banco_pruebas[i], N);
                    if (contador < estadisticas[3].min){  // Si el nuevo contador es menor que el mínimo
                        estadisticas[3].min = contador;  // El contador pasa a ser el nuevo mínimo
                    }
                    if (contador > estadisticas[3].max){  // Si el nuevo contador es mayor que el máximo
                        estadisticas[3].max = contador;  // El contador pasa a ser el nuevo máximo
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                estadisticas[3].med += med_aux / nPruebas;  // Se guarda el valor medio de comparaciones

                med_aux = 0;
                for (int i=0; i<nPruebas; i++){
                    contador = 0;
                    secuencia_ord = ordenacion_mezcla(banco_pruebas[i], N);
                    if (contador < estadisticas[4].min){  // Si el nuevo contador es menor que el mínimo
                        estadisticas[4].min = contador;  // El contador pasa a ser el nuevo mínimo
                    }
                    if (contador > estadisticas[4].max){  // Si el nuevo contador es mayor que el máximo
                        estadisticas[4].max = contador;  // El contador pasa a ser el nuevo máximo
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                estadisticas[4].med += med_aux / nPruebas;  // Se guarda el valor medio de comparaciones

                med_aux = 0;
                for (int i=0; i<nPruebas; i++){
                    contador = 0;
                    secuencia_ord = ordenacion_rapida(banco_pruebas[i], N);
                    if (contador < estadisticas[5].min){  // Si el nuevo contador es menor que el mínimo
                        estadisticas[5].min = contador;  // El contador pasa a ser el nuevo mínimo
                    }
                    if (contador > estadisticas[5].max){  // Si el nuevo contador es mayor que el máximo
                        estadisticas[5].max = contador;  // El contador pasa a ser el nuevo máximo
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                estadisticas[5].med += med_aux / nPruebas;  // Se guarda el valor medio de comparaciones

                med_aux = 0;
                alpha = -1;
                while ((alpha < 0.1) || (alpha > 1)){
                    cout << "Introduzca la constante de reducción para la ordenación por incrementos en el intervalo [0.1 - 1]: ";
                    cin >> alpha;
                }
                for (int i=0; i<nPruebas; i++){
                    contador = 0;
                    secuencia_ord = ordenacion_incrementos(banco_pruebas[i], N, alpha*N);
                    if (contador < estadisticas[6].min){  // Si el nuevo contador es menor que el mínimo
                        estadisticas[6].min = contador;  // El contador pasa a ser el nuevo mínimo
                    }
                    if (contador > estadisticas[6].max){  // Si el nuevo contador es mayor que el máximo
                        estadisticas[6].max = contador;  // El contador pasa a ser el nuevo máximo
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                estadisticas[6].med += med_aux / nPruebas;  // Se guarda el valor medio de comparaciones

                cout << "\n\t\t----- NUMERO DE COMPARACIONES -----\n" << endl;
                cout << setw(15) << "" << setw(10) << "MINIMO" << setw(10) << "MEDIO" << setw(10) << "MAXIMO" << endl;
                cout << setw(15) << "Seleccion" << setw(10) << estadisticas[0].min << setw(10) << estadisticas[0].med << setw(10) << estadisticas[0].max << endl;
                cout << setw(15) << "BinSort" << setw(10) << estadisticas[1].min << setw(10) << estadisticas[1].med << setw(10) << estadisticas[1].max << endl;
                cout << setw(15) << "Burbuja" << setw(10) << estadisticas[2].min << setw(10) << estadisticas[2].med << setw(10) << estadisticas[2].max << endl;
                cout << setw(15) << "Sacudida" << setw(10) << estadisticas[3].min << setw(10) << estadisticas[3].med << setw(10) << estadisticas[3].max << endl;
                cout << setw(15) << "Mezcla" << setw(10) << estadisticas[4].min << setw(10) << estadisticas[4].med << setw(10) << estadisticas[4].max << endl;
                cout << setw(15) << "Rapida" << setw(10) << estadisticas[5].min << setw(10) << estadisticas[5].med << setw(10) << estadisticas[5].max << endl;
                cout << setw(15) << "Incrementos" << setw(10) << estadisticas[6].min << setw(10) << estadisticas[6].med << setw(10) << estadisticas[6].max << endl;
                cout << endl;

                break;
            }
            case 3:{  // Si se ha elegido el modo Salir...
                break;
            }
            default:{  // Si no se ha elegido una opción de entre las del menú...
                cerr << "OPCION INCORRECTA!" << endl;
            }
        }
    }

    return 0;
}
