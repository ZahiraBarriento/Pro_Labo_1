
/** \brief Valida si un entero esta dentro de un rango de valores
 *
 * \param valor a validar
 * \param limite inferior del rango
 * \param limite superior del rango
 * \return 1 si el primer parametro esta dentro del rango. o si no lo esta
 *
 */
int validarEdadLaboral(int valor, int lInf, int lSup)
{
    int esValido=1;
    if (valor<lInf || valor>lSup)
    {
        esValido=0;
    }
    return esValido;
}
