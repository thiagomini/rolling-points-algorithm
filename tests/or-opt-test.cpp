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
    assert(solution.objective_function == (CLASSICAL_PROBLEM ? 263 : 437));

    print_sub_test_end();

    return EXIT_SUCCESS;

}

int test_or_switch_just_before() {
    print_sub_test_begin(
            "or_switch",
            "Testando o movimento Or-Opt2 movendo para posicao imediatamente anterior"
    );

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
    or_switch(solution, 3, 2, reinterpret_cast<const int *>(distance_matrix), 2, 5);

    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 1);
    assert(solution.vertices[2] == 3);
    assert(solution.vertices[3] == 4);
    assert(solution.vertices[4] == 2);
    assert(solution.objective_function == (CLASSICAL_PROBLEM ? 475 : 736));

    print_sub_test_end();

    return EXIT_SUCCESS;

}


/**
 * Caso 3 - N??o deve ser poss??vel mover dois v??rtices adjacentes para a ??ltima posi????o do vetor<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 4
 * resultado esperado: Erro, posi????o inv??lida
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
 * Caso 4 - N??o deve ser poss??vel mover o V0 da solu????o<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 0, 1<br>
 * nova posicao: 2
 * resultado esperado: Erro, posi????o inv??lida
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
 * Caso 5 - N??o deve ser poss??vel mover outros v??rtices da solu????o para a posi????o do V0<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 3, 4<br>
 * nova posicao: 0
 * resultado esperado: Erro, posi????o inv??lida
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
 * Caso 6 - Movendo os ??ltimos v??rtices para uma posi????o anterior<br>
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
 * Caso 7 - Movendo v??rtices adjacentes de modo que um v??rtice posterior ter?? que ser realocado para tr??s<br>
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
 * Caso 8 - Erro, n??o ?? poss??vel realizar esse movimento com apenas 3 v??rtices<br>
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
 * Caso 9 - Erro, n??o ?? poss??vel inserir os v??rtices em uma posi????o maior que o tamanho do array<br>
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
 * Caso 10 - Erro, n??o ?? poss??vel inserir os v??rtices em posi????o negativa<br>
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
 * Caso 11 - Erro, n??o ?? poss??vel inserir os v??rtices na mesma posi????o<br>
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
 * Caso 13 - Erro, n??o ?? poss??vel inserir os v??rtices em uma posi????o maior que o tamanho do array<br>
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
 * Caso 14 - N??o deve ser poss??vel mover tr??s v??rtices adjacentes para a pen??ltima posi????o do vetor<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2, 3<br>
 * nova posicao: 3
 * resultado esperado: Erro, posi????o inv??lida
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
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    Solution solution = {
            .objective_function = CLASSICAL_PROBLEM ? 705 : 1020,
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    int best_fo = CLASSICAL_PROBLEM ? 388 : 574;

    // Act
    Solution best_solution = or_opt_n(solution, reinterpret_cast<const int *>(distance_matrix), 2, 6);

    // Prepare-Response
    int expected_array[6] = { 0, 3, 4, 1, 2, 5 };

    // Assert
    assert(arrays_are_equal(best_solution.vertices, expected_array, 6));
    assert(best_solution.objective_function == best_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_or_opt2_local_search_optimized() {
    print_sub_test_begin("or_opt_n_2", "Testando a busca local Or-Opt2 (OptimizedSolution)");
    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    int vertices[6] = {0, 1, 2, 3, 4, 5};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 6);

    int best_fo = CLASSICAL_PROBLEM ? 388 : 574;

    // Act
    Solution final_solution = or_opt_n_2(reinterpret_cast<const int *>(distance_matrix), opt_matrix, 2, BEST_IMPROVEMENT);

    // Prepare-Response
    int expected_vertices[6] = {0, 3, 4, 1, 2, 5};

    // Assert
    assert(arrays_are_equal(expected_vertices, final_solution.vertices, 6));
    assert(final_solution.objective_function == best_fo);

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

int test_or_opt2_local_search_first_improvement_optimized() {
    print_sub_test_begin("or_opt_n_2", "Testando a busca local Or-Opt2 (primeira melhora) (OptimizedSolution)");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    int vertices[4] = {0, 1, 2, 3};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 4);

    int best_fo = CLASSICAL_PROBLEM ? 199 : 366;

    // Act
    Solution best_solution = or_opt_n_2(reinterpret_cast<const int *>(distance_matrix), opt_matrix, 2, FIRST_IMPROVEMENT);

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 3);
    assert(best_solution.vertices[2] == 1);
    assert(best_solution.vertices[3] == 2);
    assert(best_solution.objective_function == best_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_or_opt3_local_search_optimized() {
    print_sub_test_begin("or_opt_n_2", "Testando a busca local Or-Opt3 (OptimizedSolution)");
    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    int vertices[6] = {0, 1, 2, 3, 4, 5};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 6);

    int best_fo = CLASSICAL_PROBLEM ? 502 : 750;

    // Act
    Solution final_solution = or_opt_n_2(reinterpret_cast<const int *>(distance_matrix), opt_matrix, 3, BEST_IMPROVEMENT);

    // Prepare-Response
    int expected_vertices[6] = {0, 4, 1, 2, 3, 5};

    // Assert
    assert(arrays_are_equal(expected_vertices, final_solution.vertices, 6));
    assert(final_solution.objective_function == best_fo);
    assert(final_solution.size_of_solution == 6);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_or_opt3_local_search_first_improvement_optimized() {
    print_sub_test_begin("or_opt_n_2", "Testando a busca local Or-Opt3 (primeira melhora) (OptimizedSolution)");
    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    int vertices[6] = {0, 1, 2, 3, 4, 5};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 6);
    int best_fo = CLASSICAL_PROBLEM ? 502 : 750;

    // Act
    Solution best_solution = or_opt_n_2(reinterpret_cast<const int *>(distance_matrix), opt_matrix, 3, FIRST_IMPROVEMENT);

    // Prepare-Response
    int expected_vertices[6] = {0, 4, 1, 2, 3, 5};

    // Assert
    assert(arrays_are_equal(expected_vertices, best_solution.vertices, 6));
    assert(best_solution.objective_function == best_fo);
    assert(best_solution.size_of_solution == 6);

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

/**
 * Caso 2<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 3, 4<br>
 * nova posicao: 1<br>
 * resultado esperado: [0, 3, 4, 1, 2]
 * @return
 */
int test_build_or_opt_n_before() {
    print_sub_test_begin(
            "build_or_opt_n",
            "Testando o movimento Or-Opt2 movendo para posicao anterior (OptimizedSolution)"
    );

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    int vertices[5] = { 0, 1, 2, 3, 4 };
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 5);

    // Act
    OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 3, 1, reinterpret_cast<const int *>(distance_matrix), 2);

    // Prepare-Response
    int result_array[5] = {0, 3, 4, 1, 2};

    // Assert
    assert(arrays_are_equal(result_array, final_solution.vertices, 5));
    assert(final_solution.C == (CLASSICAL_PROBLEM ? 263 : 437));
    assert(final_solution.T == (CLASSICAL_PROBLEM ? 101 : 129));
    assert(final_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));
    assert(final_solution.size == 5);

    print_sub_test_end();

    return EXIT_SUCCESS;

}

/**
 * Caso 3 - N??o deve ser poss??vel mover dois v??rtices adjacentes para a ??ltima posi????o do vetor<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 4
 * resultado esperado: Erro, posi????o inv??lida
 * @return
 */
int test_build_or_opt_n_last_index() {
    print_sub_test_begin(
            "build_or_opt_n",
            "Testando o movimento Or-Opt2 movendo para ultima posicao (OptimizedSolution)"
    );

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    int vertices[5] = { 0, 1, 2, 3, 4 };
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 5);

    // Act
    try {
        OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 1, 4, reinterpret_cast<const int *>(distance_matrix), 2);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 4 - N??o deve ser poss??vel mover o V0 da solu????o<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 0, 1<br>
 * nova posicao: 2
 * resultado esperado: Erro, posi????o inv??lida
 * @return
 */
int test_build_or_opt_first_index() {
    print_sub_test_begin("build_or_opt_n", "Testando o movimento Or-Opt2 movendo os primeiros vertices (OptimizedSolution)");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    int vertices[5] = { 0, 1, 2, 3, 4 };
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 5);


    // Act
    try {
        OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 0, 2, reinterpret_cast<const int *>(distance_matrix), 2);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 5 - N??o deve ser poss??vel mover outros v??rtices da solu????o para a posi????o do V0<br>
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 3, 4<br>
 * nova posicao: 0
 * resultado esperado: Erro, posi????o inv??lida
 * @return
 */
int test_build_or_opt_to_first_index() {
    print_sub_test_begin("build_or_opt_n", "Testando o movimento Or-Opt2 movendo vertices para V0 (OptimizedSolution)");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    int vertices[5] = { 0, 1, 2, 3, 4 };
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 5);


    // Act
    try {
        OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 3, 0, reinterpret_cast<const int *>(distance_matrix), 2);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 6 - Movendo os ??ltimos v??rtices para uma posi????o anterior<br>
 * vertices: [0, 1, 2, 3, 4, 5]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 2<br>
 * resultado esperado: [0, 3, 1, 2, 4, 5]
 * @return
 */
int test_build_or_opt_n_position_after() {
    print_sub_test_begin(
            "build_or_opt_n",
            "Testando o movimento Or-Opt2 para uma posicao na frente (OptimizedSolution)"
    );

    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    int vertices[6] = { 0, 1, 2, 3, 4, 5 };
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 6);

    // Act
    OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 1, 2, reinterpret_cast<const int *>(distance_matrix), 2);

    // Prepare-Response
    int result_array[6] = {0, 3, 1, 2, 4, 5};

    // Assert
    assert(arrays_are_equal(result_array, final_solution.vertices, 6));
    assert(final_solution.C == (CLASSICAL_PROBLEM ? 602 : 908));
    assert(final_solution.T == (CLASSICAL_PROBLEM ? 245 : 306));
    assert(final_solution.W == (CLASSICAL_PROBLEM ? 5 : 6));
    assert(final_solution.size == 6);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Caso 7 - Movendo v??rtices adjacentes de modo que um v??rtice posterior ter?? que ser realocado para tr??s<br>
 * vertices: [0, 1, 2, 3, 4, 5]<br>
 * vertices escolhidos: 4, 5<br>
 * nova posicao: 1<br>
 * resultado esperado: [0, 4, 5, 1, 2, 3]
 * @return
 */
int test_build_or_opt_n_last_vertices() {
    print_sub_test_begin(
            "build_or_opt_n",
            "Testando o movimento Or-Opt2 selecionando os ultimos vertices (OptimizedSolution)"
    );

    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    int vertices[6] = { 0, 1, 2, 3, 4, 5 };
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 6);

    // Act
    OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 4, 1, reinterpret_cast<const int *>(distance_matrix), 2);

    // Prepare-Response
    int result_array[6] = {0, 4, 5, 1, 2, 3};

    // Assert
    assert(arrays_are_equal(result_array, final_solution.vertices, 6));
    assert(final_solution.C == (CLASSICAL_PROBLEM ? 721 : 996));
    assert(final_solution.T == (CLASSICAL_PROBLEM ? 245 : 306));
    assert(final_solution.W == (CLASSICAL_PROBLEM ? 5 : 6));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Caso 8 - Erro, n??o ?? poss??vel realizar esse movimento com apenas 3 v??rtices<br>
 * vertices: [0, 1, 2]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 2<br>
 * resultado esperado: Erro
 * @return
 */
int test_build_or_opt_three_vertices_array() {
    print_sub_test_begin("build_or_opt_n", "Testando o movimento Or-Opt2 para um array de 3 posicoes (OptimizedSolution)");

    // Arrange
    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int vertices[3] = {0, 1, 2};
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 3);

    // Act
    try {
        OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 1, 2, reinterpret_cast<const int *>(distance_matrix), 3);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 9 - Erro, n??o ?? poss??vel inserir os v??rtices em uma posi????o maior que o tamanho do array<br>
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 4<br>
 * resultado esperado: Erro
 * @return
 */
int test_build_or_opt_n_invalid_greater_index() {
    print_sub_test_begin("build_or_opt_n", "Testando o movimento Or-Opt2 com a nova posicao maior que o limite (OptimizedSolution)");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    int vertices[4] = {0, 1, 2, 3};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 4);

    // Act
    try {
        OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 1, 4, reinterpret_cast<const int *>(distance_matrix), 2);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 10 - Erro, n??o ?? poss??vel inserir os v??rtices em posi????o negativa<br>
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: -1<br>
 * resultado esperado: Erro
 * @return
 */
int test_build_or_opt_invalid_negative_index() {
    print_sub_test_begin(
            "build_or_opt_n",
            "Testando o movimento Or-Opt2 com a nova posicao negativa (OptimizedSolution)"
    );

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };


    int vertices[4] = {0, 1, 2, 3};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 4);

    // Act
    try {
        OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 1, -1, reinterpret_cast<const int *>(distance_matrix), 2);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 11 - Erro, n??o ?? poss??vel inserir os v??rtices na mesma posi????o<br>
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 1<br>
 * resultado esperado: Erro
 * @return
 */
int test_build_or_opt_same_position() {
    print_sub_test_begin(
            "build_or_opt_n",
            "Testando o movimento Or-Opt2 com nova posicao igual a posicao inicial (OptimizedSolution)"
    );

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    int vertices[4] = {0, 1, 2, 3};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 4);

    // Act
    try {
        OptimizedSolution final_solution = build_or_opt_n(opt_matrix, 1, 1, reinterpret_cast<const int *>(distance_matrix), 2);
    } catch (const char * error) {
        // Assert
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

int test_or_opt() {
    print_test_begin("or-opt2.cpp");
    test_or_switch();
    test_or_switch_before();
    test_or_switch_just_before();
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

    // Testes com OptimizedSolution
    test_build_or_opt_n_position_after();
    test_build_or_opt_n_before();
    test_build_or_opt_n_last_vertices();
    test_build_or_opt_n_last_index();
    test_build_or_opt_first_index();
    test_build_or_opt_to_first_index();
    test_build_or_opt_three_vertices_array();
    test_build_or_opt_n_invalid_greater_index();
    test_build_or_opt_invalid_negative_index();
    test_build_or_opt_same_position();
    test_or_opt2_local_search_optimized();
    test_or_opt2_local_search_first_improvement_optimized();
    test_or_opt3_local_search_optimized();
    test_or_opt3_local_search_first_improvement_optimized();
    print_test_end("or-opt2.cpp");
    return EXIT_SUCCESS;
}