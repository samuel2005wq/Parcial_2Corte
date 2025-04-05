/**
 * @file main.cpp
 * @brief Programa principal para simular el consumo de energía y generar un reporte.
 *
 * Este programa crea cuentas bancarias, las asocia a contadores de energía,
 * registra consumos y genera un reporte en un archivo de texto con los datos
 * de consumo y saldo restante.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "contador_energia.h"
#include "cuenta.h"

using namespace std;

/**
 * @brief Función principal del programa.
 *
 * Crea cuentas bancarias y contadores de energía, registra consumos y genera
 * un reporte en un archivo de texto.
 *
 * @return int Código de salida del programa (0 si se ejecuta correctamente).
 */
int main()
{
    // Crear cuentas bancarias
    /**
     * @var cuenta1
     * @brief Cuenta bancaria con un saldo inicial de 500.
     */
    CuentaBancaria cuenta1("12345678", 500);

    /**
     * @var cuenta2
     * @brief Cuenta bancaria con un saldo inicial de 300.
     */
    CuentaBancaria cuenta2("93230182", 300);

    /**
     * @var cuenta3
     * @brief Cuenta bancaria con un saldo inicial de 700.
     */
    CuentaBancaria cuenta3("94400248", 700);

    // Crear contadores de energía asociados a cuentas bancarias
    /**
     * @var medidores
     * @brief Vector que almacena los contadores de energía asociados a las cuentas bancarias.
     */
    std::vector<contador_energia> medidores;
    medidores.push_back(contador_energia(101, &cuenta1));
    medidores.push_back(contador_energia(102, &cuenta2));
    medidores.push_back(contador_energia(103, &cuenta3));

    // Simular registro de consumo con un costo por unidad de energía
    /**
     * @var costoPorUnidad
     * @brief Costo por unidad de energía consumida.
     */
    float costoPorUnidad = 2.5;

    medidores[0].registrarConsumo(50.5, costoPorUnidad);
    medidores[1].registrarConsumo(30.2, costoPorUnidad);
    medidores[2].registrarConsumo(75.8, costoPorUnidad);

    // Generar reporte en archivo
    /**
     * @var archivo
     * @brief Archivo de salida donde se genera el reporte.
     */
    std::ofstream archivo("reporte.txt");
    if (archivo.is_open())
    {
        // Encabezado con formato de tabla
        archivo << std::left << std::setw(10) << "ID"
                << std::setw(15) << "Consumo Total"
                << std::setw(20) << "Número de cuenta"
                << std::setw(15) << "Saldo Restante" << "\n";

        for (const auto &medidor : medidores) // Iterar sobre los medidores
        {
            auto cuenta = medidor.obtenerCuenta(); // Obtener la cuenta asociada
            if (cuenta != nullptr)                 // Verificar si la cuenta es válida
            {
                // Escribir en el archivo con formato de tabla
                archivo << std::left << std::setw(10) << medidor.obtenerID()
                        << std::setw(15) << medidor.obtenerConsumo()
                        << std::setw(20) << cuenta->numeroCuenta
                        << std::setw(15) << cuenta->obtenerSaldo() << "\n";
            }
            else
            {
                // Si no hay cuenta asociada, escribir "Cuenta no disponible"
                archivo << std::left << std::setw(10) << medidor.obtenerID()
                        << std::setw(15) << medidor.obtenerConsumo()
                        << std::setw(20) << "Cuenta no disponible"
                        << std::setw(15) << "N/A" << "\n";
            }
        }
        archivo.close();
        std::cout << "Archivo 'reporte.txt' generado correctamente.\n";
    }
    else
    {
        std::cout << "Error al crear el archivo.\n";
    }

    return 0;
}