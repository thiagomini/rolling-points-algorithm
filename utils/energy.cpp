//
// Created by Thiago on 21/07/2021.
//

#include "energy.h"

double calculate_energy(double mass, double current_fo, double last_fo) {
    double delta_S = (last_fo - current_fo) / last_fo;
    return mass * (GRAVITY * delta_S - FRICTION);
}