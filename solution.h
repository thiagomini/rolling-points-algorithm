//
// Arquivo para definir a estrutura de uma Solução e funções relacionadas
//


#ifndef ALGORITMO_TCC_SOLUTION_H
#define ALGORITMO_TCC_SOLUTION_H

typedef struct {
    double funcao_objetivo;
    int vertices[];
} Solucao;

void calcular_fo(Solucao * solucao);

#endif //ALGORITMO_TCC_SOLUTION_H
