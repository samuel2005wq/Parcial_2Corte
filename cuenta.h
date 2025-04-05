#ifndef CuentaBancaria_h
#define CuentaBancaria_h

#include <iostream>
#include <string>

using namespace std;

/**
 * @class CuentaBancaria
 * @brief Representa una cuenta bancaria con saldo y funcionalidad para depósitos, retiros y bloqueo de retiros.
 */
class CuentaBancaria
{
private:
    /**
     * @var saldo
     * @brief Saldo actual de la cuenta bancaria.
     */
    float saldo;

    /**
     * @var retiroBloqueado
     * @brief Indica si los retiros están bloqueados en la cuenta.
     */
    bool retiroBloqueado = false;

public:
    /**
     * @var numeroCuenta
     * @brief Número de cuenta bancaria.
     */
    string numeroCuenta;

    /**
     * @brief Constructor de la clase CuentaBancaria.
     *
     * @param numeroCuenta Número de la cuenta bancaria.
     * @param saldo Saldo inicial de la cuenta.
     */
    CuentaBancaria(string numeroCuenta, float saldo);

    /**
     * @brief Realiza un depósito en la cuenta bancaria.
     *
     * @param cantidad Monto a depositar.
     * @return float Saldo actualizado después del depósito.
     */
    float depositar(float cantidad);

    /**
     * @brief Realiza un retiro de la cuenta bancaria si es válido.
     *
     * @param cantidad Monto a retirar.
     * @return float Saldo actualizado después del retiro.
     */
    float retirar(float cantidad);

    /**
     * @brief Verifica si un retiro es válido.
     *
     * Un retiro es válido si no está bloqueado, el monto es positivo y no excede el saldo disponible.
     *
     * @param cantidad Monto a verificar.
     * @return true Si el retiro es válido.
     * @return false Si el retiro no es válido.
     */
    bool retiroValido(float cantidad);

    /**
     * @brief Bloquea los retiros de la cuenta bancaria.
     */
    void bloquearRetiro();

    /**
     * @brief Obtiene el saldo actual de la cuenta bancaria.
     *
     * @return float Saldo actual.
     */
    float obtenerSaldo() const;
};

#endif