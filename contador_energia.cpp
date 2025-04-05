#include "contador_energia.h"

/**
 * @brief Constructor de la clase contador_energia.
 *
 * Inicializa un contador de energía con un ID único y una cuenta bancaria asociada.
 *
 * @param id Identificador único del contador.
 * @param cuenta Puntero a la cuenta bancaria asociada.
 */
contador_energia::contador_energia(int id, CuentaBancaria *cuenta)
{
    this->id = id;
    this->cuenta = cuenta;
    consumoTotal = 0.0;
}

/**
 * @brief Registra el consumo de energía y realiza el cargo correspondiente en la cuenta bancaria.
 *
 * Si no hay suficiente saldo en la cuenta bancaria asociada, el consumo registrado se revierte.
 *
 * @param consumo Cantidad de energía consumida.
 * @param costoPorUnidad Costo por unidad de energía consumida.
 */
void contador_energia::registrarConsumo(float consumo, float costoPorUnidad)
{
    consumoTotal += consumo;
    float costoTotal = consumo * costoPorUnidad;
    if (!cuenta->retirar(costoTotal))
    {
        // Si no hay suficiente saldo, revertimos el consumo registrado
        consumoTotal -= consumo;
    }
}

/**
 * @brief Obtiene el consumo total registrado por el contador.
 *
 * @return float Consumo total de energía.
 */
float contador_energia::obtenerConsumo() const
{
    return consumoTotal;
}

/**
 * @brief Obtiene el identificador único del contador.
 *
 * @return int ID del contador.
 */
int contador_energia::obtenerID() const
{
    return id;
}

/**
 * @brief Obtiene la cuenta bancaria asociada al contador.
 *
 * @return CuentaBancaria* Puntero a la cuenta bancaria asociada.
 */
CuentaBancaria *contador_energia::obtenerCuenta() const
{
    return cuenta;
}
