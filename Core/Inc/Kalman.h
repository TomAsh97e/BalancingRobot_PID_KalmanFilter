/*
 * Kalman.h
 *
 *  Created on: 23 Mar 2026
 *      Author: tomek
 */

#ifndef INC_KALMAN_H_
#define INC_KALMAN_H_
typedef struct {
    float Q_angle;
    float Q_bias;
    float R_measure;

    float angle;
    float bias;

    float P[2][2];
} Kalman_t;
float Kalman_GetAngle(Kalman_t *klm, float newAngle, float newRate, float dt);
void Kalman_Init(Kalman_t *klm);

#endif /* INC_KALMAN_H_ */
