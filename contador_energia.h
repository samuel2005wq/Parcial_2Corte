#ifndef contador_energia_h
#define contador_energia_h

#include <iostream>
#include <string>
#include "cuenta.h"

using namespace std;

/**
 * @class contador_energia
 * @brief Representa un contador de energía asociado a una cuenta bancaria.
 *
 * Esta clase permite registrar el consumo de energía, calcular el costo asociado
 * y mantener una relación con una cuenta bancaria para realizar cargos.
 */
class contador_energia
{
private:
    /**
     * @var id
     * @brief Identificador único del contador de energía.
     */
    int id;

    /**
     * @var consumoTotal
     * @brief Cantidad total de energía consumida.
     */
    float consumoTotal;

    /**
     * @var cuenta
     * @brief Puntero a la cuenta bancaria asociada al contador.
     */
    CuentaBancaria *cuenta;

public:
    /**
     * @brief Constructor de la clase contador_energia.
     *
     * Inicializa un contador de energía con un ID único y una cuenta bancaria asociada.
     *
     * @param id Identificador único del contador.
     * @param cuenta Puntero a la cuenta bancaria asociada.
     */
    contador_energia(int id, CuentaBancaria *cuenta);

    /**
     * @brief Registra el consumo de energía y realiza el cargo correspondiente en la cuenta bancaria.
     *
     * @param consumo Cantidad de energía consumida.
     * @param costoPorUnidad Costo por unidad de energía consumida.
     */
    void registrarConsumo(float consumo, float costoPorUnidad);

    /**
     * @brief Obtiene el consumo total registrado por el contador.
     *
     * @return float Consumo total de energía.
     */
    float obtenerConsumo() const;

    /**
     * @brief Obtiene el identificador único del contador.
     *
     * @return int ID del contador.
     */
    int obtenerID() const;

    /**
     * @brief Obtiene la cuenta bancaria asociada al contador.
     *
     * @return CuentaBancaria* Puntero a la cuenta bancaria asociada.
     */
    CuentaBancaria *obtenerCuenta() const;
};

#endif