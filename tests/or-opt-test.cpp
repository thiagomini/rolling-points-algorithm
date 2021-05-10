//
// Created by Thiago on 02/04/2021.
//

#include <cassert>
#include "../neighborhoods/or-opt.h"
#include "test-logger.h"
#include "../utils/string-utils.h"

// 0, 1, 2, 3
// 0, 1, 3, 2
// 0, 3, 1, 2

/**
 * Caso 1<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 2<br>
 * resultado esperado: [0, 3, 1, 2, 4]
 * @return
 */
int test_or_switch() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 para dois vertices no meio");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    // Act
    or_switch(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix), 2, 5);


    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 3);
    assert(solution.vertices[2] == 1);
    assert(solution.vertices[3] == 2);
    assert(solution.vertices[4] == 4);

    print_sub_test_end();

    return EXIT_SUCCESS;

}

/**
 * Caso 2<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 3, 4<br>
 * nova posicao: 1<br>
 * resultado esperado: [0, 3, 4, 1, 2]
 * @return
 */
int test_or_switch_before() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 movendo para posicao anterior");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    // Act
    or_switch(solution, 3, 1, reinterpret_cast<const int *>(distance_matrix), 2, 5);


    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 3);
    assert(solution.vertices[2] == 4);
    assert(solution.vertices[3] == 1);
    assert(solution.vertices[4] == 2);

    print_sub_test_end();

    return EXIT_SUCCESS;

}

/**
 * Caso 3 - Não deve ser possível mover dois vértices adjacentes para a última posição do vetor<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 4
 * resultado esperado: Erro, posição inválida
 * @return
 */
int test_or_switch_last_index() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 movendo para ultima posicao");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    // Act
    try {
        or_switch(solution, 1, 4, reinterpret_cast<const int *>(distance_matrix), 2, 5);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 4 - Não deve ser possível mover o V0 da solução<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 0, 1<br>
 * nova posicao: 2
 * resultado esperado: Erro, posição inválida
 * @return
 */
int test_or_switch_first_index() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 movendo os primeiros vertices");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };
    // Act
    try {
        or_switch(solution, 0, 2, reinterpret_cast<const int *>(distance_matrix), 2, 5);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 5 - Não deve ser possível mover outros vértices da solução para a posição do V0<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 3, 4<br>
 * nova posicao: 0
 * resultado esperado: Erro, posição inválida
 * @return
 */
int test_or_switch_to_first_index() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 movendo vertices para V0");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    // Act
    try {
        or_switch(solution, 3, 0, reinterpret_cast<const int *>(distance_matrix), 2,5);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 6 - Movendo os últimos vértices para uma posição anterior<br>
 * vertices: [0, 1, 2, 3, 4, 5]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 2<br>
 * resultado esperado: [0, 3, 1, 2, 4, 5]
 * @return
 */
int test_or_switch_position_after() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 para uma posicao na frente");

    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    // Act
    or_switch(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix), 2, 6);

    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 3);
    assert(solution.vertices[2] == 1);
    assert(solution.vertices[3] == 2);
    assert(solution.vertices[4] == 4);
    assert(solution.vertices[5] == 5);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Caso 7 - Movendo vértices adjacentes de modo que um vértice posterior terá que ser realocado para trás<br>
 * vertices: [0, 1, 2, 3, 4, 5]<br>
 * vertices escolhidos: 4, 5<br>
 * nova posicao: 1<br>
 * resultado esperado: [0, 4, 5, 1, 2, 3]
 * @return
 */
int test_or_switch_last_vertices() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 selecionando os ultimos vertices");

    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    // Act
    or_switch(solution, 4, 1, reinterpret_cast<const int *>(distance_matrix), 2,6);

    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 4);
    assert(solution.vertices[2] == 5);
    assert(solution.vertices[3] == 1);
    assert(solution.vertices[4] == 2);
    assert(solution.vertices[5] == 3);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Caso 8 - Erro, não é possível realizar esse movimento com apenas 3 vértices<br>
 * vertices: [0, 1, 2]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 2<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_three_vertices_array() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 para um array de 3 posicoes");

    // Arrange
    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 3,
            .vertices = {0, 1, 2}
    };

    // Act
    try {
        or_switch(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix), 2,3);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 9 - Erro, não é possível inserir os vértices em uma posição maior que o tamanho do array<br>
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 4<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_invalid_greater_index() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 com a nova posicao maior que o limite");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    // Act
    try {
        or_switch(solution, 1, 4, reinterpret_cast<const int *>(distance_matrix), 2,4);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 10 - Erro, não é possível inserir os vértices em posição negativa<br>
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: -1<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_invalid_negative_index() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 com a nova posicao negativa");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    // Act
    try {
        or_switch(solution, 1, -1, reinterpret_cast<const int *>(distance_matrix), 2,4);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 11 - Erro, não é possível inserir os vértices na mesma posição<br>
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 1<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_same_position() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 com nova posicao igual a posicao inicial");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    // Act
    try {
        or_switch(solution, 1, 1, reinterpret_cast<const int *>(distance_matrix), 2,4);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 12<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2, 3<br>
 * nova posicao: 2<br>
 * resultado esperado: [0, 4, 1, 2, 3]
 * @return
 */
int test_or_switch_3() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt3 para tres vertices do meio");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    // Act
    or_switch(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix), 3, 5);


    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 4);
    assert(solution.vertices[2] == 1);
    assert(solution.vertices[3] == 2);
    assert(solution.vertices[4] == 3);

    print_sub_test_end();

    return EXIT_SUCCESS;

}

/**
 * Caso 13 - Erro, não é possível inserir os vértices em uma posição maior que o tamanho do array<br>
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2, 3<br>
 * nova posicao: 4<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_3_invalid_greater_index() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt3 com a nova posicao maior que o limite");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    // Act
    try {
        or_switch(solution, 1, 4, reinterpret_cast<const int *>(distance_matrix), 3, 4);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 14 - Não deve ser possível mover três vértices adjacentes para a penúltima posição do vetor<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2, 3<br>
 * nova posicao: 3
 * resultado esperado: Erro, posição inválida
 * @return
 */
int test_or_switch_3_last_index() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 movendo para ultima posicao");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    // Act
    try {
        or_switch(solution, 1, 3, reinterpret_cast<const int *>(distance_matrix), 3, 5);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

int test_or_switch_random_positions() {
    print_sub_test_begin("or_switch", "Testando o movimento Or-Opt2 com posicoes aleatorias");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };
    int objective_function = solution.objective_function;

    or_switch(solution, reinterpret_cast<const int *>(distance_matrix), 2, 4);

    // Prepare-Response
    bool same_order = solution.vertices[0] == 0 &&
                      solution.vertices[1] == 1 &&
                      solution.vertices[2] == 2 &&
                      solution.vertices[3] == 3 &&
                      solution.vertices[4] == 4;

    bool same_objective_function = solution.objective_function == objective_function;

    // Assert
    assert(same_order == false);
    assert(same_objective_function == false);
    assert(solution.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_or_opt2_local_search() {
    print_sub_test_begin("or_opt_n", "Testando a busca local Or-Opt2");
    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = CLASSICAL_PROBLEM ? 284 : 461,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    int best_fo = CLASSICAL_PROBLEM ? 199 : 366;

    // Act
    Solution best_solution = or_opt_n(solution, reinterpret_cast<const int *>(distance_matrix), 2, 4);

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.objective_function == best_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_or_opt2_local_search_first_improvement() {
    print_sub_test_begin("or_opt_n", "Testando a busca local Or-Opt2 (primeira melhora)");
    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = CLASSICAL_PROBLEM ? 302 : 469,
            .size_of_solution = 4,
            .vertices = {0, 2, 1, 3}
    };

    int best_fo = CLASSICAL_PROBLEM ? 247 : 424;

    // Act
    Solution best_solution = or_opt_n(solution, reinterpret_cast<const int *>(distance_matrix), 2, 4, FIRST_IMPROVEMENT);

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 3);
    assert(best_solution.vertices[2] == 2);
    assert(best_solution.vertices[3] == 1);
    assert(best_solution.objective_function == best_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_or_opt3_local_search() {
    print_sub_test_begin("or_opt_n", "Testando a busca local Or-Opt3");
    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    Solution solution = {
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 6);

    int first_fo = solution.objective_function;

    // Act
    Solution best_solution = or_opt_n(solution, reinterpret_cast<const int *>(distance_matrix), 3, 6);

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.objective_function < first_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_or_opt3_local_search_first_improvement() {
    print_sub_test_begin("or_opt_n", "Testando a busca local Or-Opt3 (primeira melhora)");
    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    Solution solution = {
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 6);

    int best_fo = CLASSICAL_PROBLEM ? 502 : 750;

    // Act
    Solution best_solution = or_opt_n(solution, reinterpret_cast<const int *>(distance_matrix), 3, 6, FIRST_IMPROVEMENT);

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 4);
    assert(best_solution.vertices[2] == 1);
    assert(best_solution.vertices[3] == 2);
    assert(best_solution.vertices[4] == 3);
    assert(best_solution.vertices[5] == 5);
    assert(best_solution.objective_function == best_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_or_opt() {
    print_test_begin("or-opt2.cpp");
    test_or_switch();
    test_or_switch_before();
    test_or_switch_last_index();
    test_or_switch_first_index();
    test_or_switch_to_first_index();
    test_or_switch_position_after();
    test_or_switch_last_vertices();
    test_or_switch_three_vertices_array();
    test_or_switch_invalid_greater_index();
    test_or_switch_invalid_negative_index();
    test_or_switch_same_position();
    test_or_switch_random_positions();
    test_or_opt2_local_search();
    test_or_switch_3();
    test_or_switch_3_invalid_greater_index();
    test_or_switch_3_last_index();
    test_or_opt3_local_search();
    test_or_opt2_local_search_first_improvement();
    test_or_opt3_local_search_first_improvement();
    print_test_end("or-opt2.cpp");
    return EXIT_SUCCESS;
}