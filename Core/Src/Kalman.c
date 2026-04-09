/*
 * Kalman.c
 *
 *  Created on: 23 Mar 2026
 *      Author: tomek
 */

#include <math.h>
#include "Kalman.h"


// --- INICJALIZACJA FILTRA ---
void Kalman_Init(Kalman_t *klm) {

    klm->Q_angle = 0.01f;
    klm->Q_bias = 0.003f;
    klm->R_measure = 0.01f;

    klm->angle = 0.0f;
    klm->bias = 0.0f;

    klm->P[0][0] = 0.0f; klm->P[0][1] = 0.0f;
    klm->P[1][0] = 0.0f; klm->P[1][1] = 0.0f;
}


float Kalman_GetAngle(Kalman_t *klm, float newAngle, float newRate, float dt) {

    klm->angle += dt * (newRate - klm->bias);

    klm->P[0][0] += dt * (dt * klm->P[1][1] - klm->P[0][1] - klm->P[1][0] + klm->Q_angle);
    klm->P[0][1] -= dt * klm->P[1][1];
    klm->P[1][0] -= dt * klm->P[1][1];
    klm->P[1][1] += klm->Q_bias * dt;


    float y = newAngle - klm->angle;
    float S = klm->P[0][0] + klm->R_measure;

    float K[2];
    K[0] = klm->P[0][0] / S;
    K[1] = klm->P[1][0] / S;

    klm->angle += K[0] * y;
    klm->bias += K[1] * y;

    float P00_temp = klm->P[0][0];
    float P01_temp = klm->P[0][1];

    klm->P[0][0] -= K[0] * P00_temp;
    klm->P[0][1] -= K[0] * P01_temp;
    klm->P[1][0] -= K[1] * P00_temp;
    klm->P[1][1] -= K[1] * P01_temp;

    return klm->angle;
}


