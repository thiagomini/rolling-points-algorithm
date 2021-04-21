#include <ctime>
#include <functional>
#include "constructive-heuristic.h"
#include "data_structures/data-read.h"
#include "utils/distance.h"
#include "iostream"
#include "utils/string-utils.h"
#include <string>
#include <cstring>
#include "data_structures/distance-matrix.h"
#include "data_structures/solution.h"
#include "utils/array.h"
#include "neighborhoods/swap.h"
#include "neighborhoods/reinsertion.h"

#include "heuristic.h"
#include "neighborhoods/neighborhood-generator.h"
#include "neighborhoods/or-opt.h"
#include "data_structures/edge.h"
#include "neighborhoods/2-optimal.h"
#include "data_structures/OptSolution.h"

using namespace std;

void execute_tests();
void calculate_time();

/**
 * Realiza a otimização de um problema MLP, utilizando uma heurística passada como parâmetro
 * @param heuristic - O número que representa a heurística. Verificar o arquivo <b>configurations.h</b> para mais detalhes
 * @param file_path - O caminho para o arquivo que contém os nós do problema. Atenção: sempre informar o caminho com "../" antes da
 * sua localização relativa ao projeto.
 * @param number_of_nodes - O número de nós que o problema contempla
 * @throws Erro caso a heurística passada não seja encontrada
 * @example
 *  execute_heuristic(ROLLING_POINTS_ALGORITHM, "../instances/test_tsp_euc_2d.tsp", 3);
 *
 */
void execute_heuristic(int heuristic, const char * file_path, size_t number_of_nodes);

/**
 * Realiza a otimização de um problema MLP utilizando a heurística dos Pontos Rolantes
 * @param file_path - O caminho para o arquivo que contém os nós do problema. Atenção: sempre informar o caminho com "../" antes da
 * sua localização relativa ao projeto.
 * @param number_of_nodes - O número de nós que o problema contempla
 * @param population O número de "pontos" que será criado na fase exploratória inicial da heurística.
 * @param times - O número de vezes que o algoritmo deverá ser executado
 */
void execute_rolling_points(const char * file_path, size_t number_of_nodes, size_t population = 50, int times = 100);

/**
 * Realiza a otimização de um problema MLP utilizando uma heurística simples de geração e comparação de soluções aleatórias
 * @param file_path - O caminho para o arquivo que contém os nós do problema. Atenção: sempre informar o caminho com "../" antes da
 * sua localização relativa ao projeto.
 * @param number_of_nodes - O número de nós que o problema contempla
 */
void execute_random_heuristic(const char * file_path, size_t number_of_nodes);

/**
 * Exibe no console as métricas da heurística executada, sendo elas:
 * <ol>
 *  <li>Média do tempo de Execução</li>
 *  <li>Média do valor da Função Objetivo</li>
 *  <li>Tempo de execução da Melhor FO</li>
 *  <li>Valor da Melhor FO</li>
 * </ol>
 * @param solutions - Lista de soluções que foram geradas pela execução de uma heurística
 * @param times - O número de vezes que a heurística foi executada
 */
void print_heuristic_metrics(Solution *solutions, int times);

int main() {
    srand(time(NULL));

    execute_tests();

//    execute_heuristic(ROLLING_POINTS_ALGORITHM, "../instances/st70.tsp", 70);
//    calculate_time();

    return EXIT_SUCCESS;

}

void calculate_time() {
    clock_t begin, end;
    double time_spent;
    unsigned int i;
    unsigned int vertices[10] = {
            1,2,3,4,5,6,7,8,9,10
    };

    unsigned int * solution;

    begin = clock();

    end = clock() - begin;
    time_spent = ((double) end) / CLOCKS_PER_SEC;

    printf("Tempo Gasto em Segundos: %f", time_spent);
}

void execute_tests() {
    cout << "Iniciando Rotina de Testes...\n";
    test_distance();
    test_string_utils();
    test_data_read();
    test_distance_matrix();
    test_array();
    test_solution();
    test_edge();
    test_constructive_heuristic();
    test_swap();
    test_reinsert();
    test_or_opt();
    test_two_optimal();
    test_neighborhood_generator();
    test_heuristic();
    test_opt_solution();
}

void execute_heuristic(int heuristic, const char * file_path, size_t number_of_nodes) {
    switch (heuristic) {
        case ROLLING_POINTS_ALGORITHM:
            execute_rolling_points(file_path, number_of_nodes);
            break;

        case RANDOM_HEURISTIC_ALGORITHM:
            execute_random_heuristic(file_path, number_of_nodes);
            break;

        default:
            cerr << "Algoritmo " << heuristic << " nao registrado!";
    }
}

void execute_rolling_points(const char * file_path, size_t number_of_nodes, size_t population, int times) {
    node_2d * nodes = read_nodes_euc_2d(file_path);
    int calculated_distance_matrix[number_of_nodes][number_of_nodes];
    int ** distance_matrix_pointer = build_distance_matrix(reinterpret_cast<node_2d *>(nodes), number_of_nodes);
    Solution solutions[times];


    for (int iteration = 0; iteration < times; iteration++) {
        // Preenche a matrix com os valores retornados pelo ponteiro da função
        for (int i = 0; i < number_of_nodes; i++) {
            for (int j =0; j < number_of_nodes; j++) {
                calculated_distance_matrix[i][j] = distance_matrix_pointer[i][j];
            }
        }
        clock_t begin, end;
        begin = clock();

        solutions[iteration] = rolling_points_heuristic(reinterpret_cast<const int *>(calculated_distance_matrix), number_of_nodes, population);
//        print_solution(&best_solution);

        end = clock() - begin;
        solutions[iteration].time_spent = ((double) end) / CLOCKS_PER_SEC;
//        printf("Tempo Gasto em Segundos: %f", time_spent);
    }

    delete distance_matrix_pointer;
    print_heuristic_metrics(solutions, times);
}

void execute_random_heuristic(const char * file_path, size_t number_of_nodes) {

}

void print_heuristic_metrics(Solution *solutions, int times) {
    qsort(solutions, times, sizeof(Solution), reinterpret_cast<int (*)(const void *, const void *)>(compare));
    double mean_fo = calculate_mean_fo(solutions, times);
    double mean_time_spent = calculate_mean_time(solutions, times);

    cout << "Media de FO: " << mean_fo << endl;
    cout << "Media de tempo gasto: " << mean_time_spent << endl;
    cout << "------ Melhor Solucao -------" << endl;
    cout << "Tempo gasto: " << solutions[0].time_spent << endl;
    print_solution(&solutions[0]);
}