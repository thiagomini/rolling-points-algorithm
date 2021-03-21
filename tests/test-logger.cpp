//
// Created by Thiago on 21/03/2021.
//

#include "test-logger.h"
#include "iostream"

using namespace std;

void print_test_begin(const string& module_name) {
    if (module_name.empty()) {
        cout << "Erro: Deve ser informado o nome do modulo";
        exit(EXIT_FAILURE);
    }
    cout << "[" << module_name << "] Iniciando Testes...\n";
}

void print_test_end(const string& module_name) {
    if (module_name.empty()) {
        cout << "Erro: Deve ser informado o nome do modulo";
        exit(EXIT_FAILURE);
    }
    cout << "[" << module_name << "] Todos os testes passaram com sucesso!\n" << endl;
}

void print_sub_test_begin(const string& function_name, const string& description) {
    if (function_name.empty()) {
        cout << "Erro: Deve ser informado o nome da funcao!";
        exit(EXIT_FAILURE);
    }
    cout << "\t[" << function_name << "] " << description << "...";
}

void print_sub_test_end() {
    cout << " Sucesso!\n";
}