#include <iostream>
#include <string>
#include "cuenta.h"

using namespace std;

/**
 * @brief Constructor de la clase CuentaBancaria.
 *
 * Inicializa una cuenta bancaria con un número de cuenta, un saldo inicial y
 * establece que los retiros no están bloqueados.
 *
 * @param numeroCuenta Número de la cuenta bancaria.
 * @param saldo Saldo inicial de la cuenta.
 */
CuentaBancaria::CuentaBancaria(string numeroCuenta, float saldo)
    : numeroCuenta(numeroCuenta), saldo(saldo), retiroBloqueado(false) {}

/**
 * @brief Realiza un depósito en la cuenta bancaria.
 *
 * Si el monto a depositar es mayor que cero, se suma al saldo actual.
 *
 * @param cantidad Monto a depositar.
 * @return float Saldo actualizado después del depósito.
 */
float CuentaBancaria::depositar(float cantidad)
{
    if (cantidad > 0)
    {
        saldo += cantidad;
    }
    else
    {
        cout << "Error: No se puede depositar una cantidad negativa o cero." << endl;
    }
    return saldo;
}

/**
 * @brief Realiza un retiro de la cuenta bancaria si es válido.
 *
 * Si el retiro es válido (verificado por el método `retiroValido`), se resta
 * el monto del saldo actual. De lo contrario, se muestra un mensaje de error.
 *
 * @param cantidad Monto a retirar.
 * @return float Saldo actualizado después del retiro.
 */
float CuentaBancaria::retirar(float cantidad)
{
    if (retiroValido(cantidad))
    {
        saldo -= cantidad;
    }
    else
    {
        cout << "Error: Retiro no válido. Verifique el saldo o si el retiro está bloqueado." << endl;
    }
    return saldo;
}

/**
 * @brief Bloquea los retiros de la cuenta bancaria.
 *
 * Establece el estado de `retiroBloqueado` en verdadero, impidiendo que se
 * realicen retiros de la cuenta.
 */
void CuentaBancaria::bloquearRetiro()
{
    retiroBloqueado = true;
    cout << "Retiro bloqueado. No se puede realizar retiros." << endl;
}

/**
 * @brief Verifica si un retiro es válido.
 *
 * Un retiro es válido si:
 * - Los retiros no están bloqueados.
 * - El monto es mayor que cero.
 * - El monto no excede el saldo disponible.
 *
 * @param cantidad Monto a verificar.
 * @return true Si el retiro es válido.
 * @return false Si el retiro no es válido.
 */
bool CuentaBancaria::retiroValido(float cantidad)
{
    return !retiroBloqueado && (cantidad > 0 && cantidad <= saldo);
}

/**
 * @brief Obtiene el saldo actual de la cuenta bancaria.
 *
 * @return float Saldo actual de la cuenta.
 */
float CuentaBancaria::obtenerSaldo() const
{
    return saldo;
}