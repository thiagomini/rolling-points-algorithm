//
// Módulo de definição de geração de números aleatórios
//

#ifndef ALGORITMO_TCC_RANDOMIZER_H
#define ALGORITMO_TCC_RANDOMIZER_H

/**
 * Retorna um número inteiro entre <b>lower</b> e <b>upper</b>
 * @param lower Limite inferior
 * @param upper Limite superior
 * @return Um número aleatório entre os limites informados
 */
#define RANDOM_BETWEEN(lower, upper) ((lower) == 0) ? rand() % (upper) : ((rand() % ((upper) - (lower) + 1)) + 1)


#endif //ALGORITMO_TCC_RANDOMIZER_H
