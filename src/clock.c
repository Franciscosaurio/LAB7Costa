/*********************************************************************************************************************
Copyright (c) 2025, Costa Francisco Lucas Sebastian.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

/** @file clock.c
 ** @brief clock para la creación de archivos de código fuente en lenguaje C
 **/

/* === Headers files inclusions ==================================================================================== */

#include "clock.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function definitions ============================================================================== */


clock_t clock_create(void) {
    // Implementación de la creación del reloj
    // Aquí se puede inicializar el reloj y devolver un puntero a la estructura del reloj
    return NULL; 
}
bool clock_time_is_valid(clock_t clock) {
    // Implementación de la verificación de la validez del tiempo del reloj
    // Aquí se puede verificar si el reloj tiene un tiempo válido
    //como no lo necesito pero uso un puntero tengo que castear la variable
    //con void le digo que no se usa
    (void) clock;
    return false; 
}
bool clock_get_time(clock_t clock, clock_time_t *result) {
    // Implementación de la obtención del tiempo actual del reloj
    // Aquí se puede llenar current_time con el tiempo actual del reloj
    memset(result, 0, 6/*sizeof(*clock_time_t)"*/); //rellena el espacio apuntado por clock time con 0s
    (void) clock;
    return false;
}
/* === End of documentation ======================================================================================== */