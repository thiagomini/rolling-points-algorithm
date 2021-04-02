//
// Created by Thiago on 02/04/2021.
//

#include <cassert>
#include "../neighborhoods/or-opt2.h"
#include "test-logger.h"
#include "../utils/string-utils.h"

// 0, 1, 2, 3
// 0, 1, 3, 2
// 0, 3, 1, 2

/**
 * Caso 1
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 2<br>
 * resultado esperado: [0, 3, 1, 2, 4]
 * @return
 */
int test_or_switch() {
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt para dois vertices no meio");

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
    or_switch(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix));


    // Assert
    assert(solution.vertices.at(0) == 0);
    assert(solution.vertices.at(1) == 3);
    assert(solution.vertices.at(2) == 1);
    assert(solution.vertices.at(3) == 2);
    assert(solution.vertices.at(4) == 4);

    print_sub_test_end();

    return EXIT_SUCCESS;

}

/**
 * Caso 2
 * vertices: [0, 1, 2, 3, 4]<br>
 * vertices escolhidos: 3, 4<br>
 * nova posicao: 1<br>
 * resultado esperado: [0, 3, 4, 1, 2]
 * @return
 */
int test_or_switch_before() {
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt movendo para posicao anterior");

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
    or_switch(solution, 3, 1, reinterpret_cast<const int *>(distance_matrix));


    // Assert
    assert(solution.vertices.at(0) == 0);
    assert(solution.vertices.at(1) == 3);
    assert(solution.vertices.at(2) == 4);
    assert(solution.vertices.at(3) == 1);
    assert(solution.vertices.at(4) == 2);

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
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt movendo para ultima posicao");

    // Arrange

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
        or_switch(solution, 1, 4, reinterpret_cast<const int *>(distance_matrix));
    } catch (const char * error) {
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
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt movendo os primeiros vertices");

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
        or_switch(solution, 0, 2, reinterpret_cast<const int *>(distance_matrix));
    } catch (const char * error) {
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
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt movendo vertices para V0");


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
        or_switch(solution, 3, 0, reinterpret_cast<const int *>(distance_matrix));
    } catch (const char * error) {
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
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt para uma posicao na frente");

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
    or_switch(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix));


    // Assert
    assert(solution.vertices.at(0) == 0);
    assert(solution.vertices.at(1) == 3);
    assert(solution.vertices.at(2) == 1);
    assert(solution.vertices.at(3) == 2);
    assert(solution.vertices.at(4) == 4);
    assert(solution.vertices.at(5) == 5);

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
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt selecionando os ultimos vertices");

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
    or_switch(solution, 4, 1, reinterpret_cast<const int *>(distance_matrix));

    // Assert
    assert(solution.vertices.at(0) == 0);
    assert(solution.vertices.at(1) == 4);
    assert(solution.vertices.at(2) == 5);
    assert(solution.vertices.at(3) == 1);
    assert(solution.vertices.at(4) == 2);
    assert(solution.vertices.at(5) == 3);

    print_sub_test_end();

    return EXIT_SUCCESS;

}

/**
 * Caso 8 - Erro, não é possível realizar esse movimento com apenas 3 vértices
 * vertices: [0, 1, 2]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 2<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_three_vertices_array() {
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt para um array de 3 posicoes");

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
        or_switch(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix));
    } catch (const char * error) {
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 9 - Erro, não é possível inserir os vértices em uma posição maior que o tamanho do array
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 4<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_invalid_greater_index() {
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt com a nova posicao maior que o limite");

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
        or_switch(solution, 1, 4, reinterpret_cast<const int *>(distance_matrix));
    } catch (const char * error) {
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}


/**
 * Caso 10 - Erro, não é possível inserir os vértices em posição negativa
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: -1<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_invalid_negative_index() {
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt com a nova posicao negativa");

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
        or_switch(solution, 1, -1, reinterpret_cast<const int *>(distance_matrix));
    } catch (const char * error) {
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}

/**
 * Caso 11 - Erro, não é possível inserir os vértices na mesma posição
 * vertices: [0, 1, 2, 3]<br>
 * vertices escolhidos: 1, 2<br>
 * nova posicao: 1<br>
 * resultado esperado: Erro
 * @return
 */
int test_or_switch_same_position() {
    print_sub_test_begin("or_switch", "Testando o movimento 2-Opt com nova posicao igual a posicao inicial");

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
        or_switch(solution, 1, 1, reinterpret_cast<const int *>(distance_matrix));
    } catch (const char * error) {
        assert(strings_are_equal(error, "Vertice invalido escolhido para troca"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Erro: teste nao lancou excecao como esperado!";
}




int test_or_opt2() {
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
    print_test_end("or-opt2.cpp");
    return EXIT_SUCCESS;
}