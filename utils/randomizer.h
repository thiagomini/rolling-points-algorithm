//
// Created by Thiago on 21/03/2021.
//

#ifndef ALGORITMO_TCC_RANDOMIZER_H
#define ALGORITMO_TCC_RANDOMIZER_H

/**
 * Retorna um número inteiro entre <b>lower</b> e <b>upper</b>
 * @param lower Limite inferior
 * @param upper Limite superior
 * @return Um número aleatório entre os limites informados
 */
#define RANDOM_BETWEEN(lower, upper) ((rand() % ((upper) - (lower) + 1)) + 1)


#endif //ALGORITMO_TCC_RANDOMIZER_H
