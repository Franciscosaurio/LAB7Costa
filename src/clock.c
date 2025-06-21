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
struct clock_s{
    clock_time_t current_time; //almacena el tiempo actual del reloj
    bool valid; //indica si el tiempo del reloj es válido
};
/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function definitions ============================================================================== */


clock_t clock_create(uint16_t ticks_per_second) {
    (void) ticks_per_second; //no lo uso pero tengo que castear la variable para que no de warning
    // Implementación de la creación del reloj
    // Aquí se puede inicializar el reloj y devolver un puntero a la estructura del reloj
    static struct clock_s self[1]; //crea un espacio de memoria para el reloj
    memset(&self->current_time, 0, sizeof(clock_time_t));//inicializa el tiempo actual del reloj a 0

    //memset(self, 0, sizeof(struct clock_s)); //inicializa la memoria del reloj a 0
    self->valid = false; //inicializa el reloj como no válido
    //memset(&self->current_time, 0, sizeof(self->current_time)); //inicializa el tiempo actual del reloj a 0

    return self; 
}
bool clock_time_is_valid(clock_t clock) {
    // Implementación de la verificación de la validez del tiempo del reloj
    // Aquí se puede verificar si el reloj tiene un tiempo válido
    //como no lo necesito pero uso un puntero tengo que castear la variable
    //con void le digo que no se usa
    (void) clock;
    return false; 
}
bool clock_get_time(clock_t self, clock_time_t *result) {
    // Implementación de la obtención del tiempo actual del reloj
    // Aquí se puede llenar current_time con el tiempo actual del reloj
    memcpy(result, &self->current_time, sizeof(clock_time_t)); //copia el tiempo actual al resultado
    return self->valid; //devuelve si el reloj es válido
}

bool clock_set_time(clock_t self, const clock_time_t *new_time){
    // Implementación de la configuración del tiempo del reloj
    // Aquí se puede establecer el nuevo tiempo en el reloj
    self->valid = true; //marca el reloj como válido
    memcpy(&self->current_time, new_time, sizeof(clock_time_t)); //copia el nuevo tiempo al reloj
    (void) new_time; //no lo uso
    return self->valid; //indica que no se ha podido establecer el tiempo
}

void clock_new_tick(clock_t self){
    static uint8_t tick_counter = 0;

    tick_counter++;
    if (tick_counter >= 5) { // 5 ticks = 1 segundo
        tick_counter = 0;

        // Incrementar segundos BCD
        self->current_time.bcd[0]++; // unidades de segundos
        if (self->current_time.bcd[0] > 9) {
            self->current_time.bcd[0] = 0;
            self->current_time.bcd[1]++; // decenas de segundos

            if (self->current_time.bcd[1] > 5) {
                self->current_time.bcd[1] = 0;
                self->current_time.bcd[2]++; // unidades de minutos
                // Y así sucesivamente...
            }
        }
    }
}

/* === End of documentation ======================================================================================== */