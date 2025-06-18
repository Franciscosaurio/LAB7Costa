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

/** @file test_reloj.c
 ** @brief plantilla de pruebas para el reloj.
 **/

/* === Headers files inclusions ==================================================================================== */

#include "unity.h"
#include "clock.h"
/* === Macros definitions ========================================================================================== */
#define CLOCK_TICKS_PER_SECOND 5 // Define cuántos ticks por segundo simula el reloj
/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */
void simulate_seconds(clock_t clock, uint8_t seconds) {
    // Simula el avance del reloj en segundos
    for (uint32_t i = 0; i < 5*seconds; i++) {
        // Aquí se debería implementar la lógica para avanzar el reloj un segundo
        // Por ejemplo, incrementar los segundos y manejar el desbordamiento de minutos y horas
        clock_new_tick(clock);
    }
}
/* === Private function definitions ================================================================================ */

/* === Public function implementation ============================================================================== */
/**
 -al iniciar el reloj está en 00:00 y con hora invalida
 -al ajustar la hora el reloj queda en hora y en valida
 -despues de n ciclos de reloj la hora avanza un segundo, diez segundos, un minuto
 -
 */

 clock_time_t current_time = {
        .bcd = {1,2,3,4,5,6}, 
    };
void test_set_up_with_invalid_time(void){
    //le asigno un valor inicial para no tener cualquier cosa paracuando se inicialice
    

    clock_t clock=clock_create(CLOCK_TICKS_PER_SECOND); //creo el reloj con un valor de 5 segundos para simular el avance
    TEST_ASSERT_FALSE(clock_time_is_valid(clock));
    //clock_get_time(clock, &current_time);
    TEST_ASSERT_EACH_EQUAL_UINT8(0, current_time.bcd, sizeof(clock_time_t));
    
}
//al ajustar la hora el reloj queda en hora y en valida
void test_set_up_and_adjust_with_valid_time(void){
    static const clock_time_t new_time = {
        .time={
            .seconds={4,5},
            .minutes={3,0},
            .hours={1,4},
        }
    };
    clock_t clock = clock_create(CLOCK_TICKS_PER_SECOND); //creo el reloj con un valor de 5 segundos para simular el avance
    TEST_ASSERT_TRUE(clock_set_time(clock, &new_time));
    TEST_ASSERT_TRUE(clock_get_time(clock, &current_time));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(new_time.bcd, current_time.bcd, sizeof(clock_time_t));

}
    
void test_clock_advance_one_second(void){
    clock_time_t current_time ={0};//inicializo el tiempo actual a 0
    static const clock_time_t expected_value = {
        .time={
            .seconds={0,1}, //segundos
            .minutes={0,0}, //minutos
            .hours={0,0}, //horas
        }
    };
    clock_t clock = clock_create(CLOCK_TICKS_PER_SECOND); //creo el reloj con un valor de 5 segundos para simular el avance
    clock_set_time(clock, &(clock_time_t){0});//establezco el tiempo actual a 0
    simulate_seconds(clock, 1); //simulo el avance del reloj en 1 segundo
    clock_get_time(clock, &current_time);// obtengo el tiempo actual del reloj
    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected_value.bcd, current_time.bcd, 6);
    // ^ verifico que el tiempo actual sea el esperado

}
    


/* === End of documentation ======================================================================================== */