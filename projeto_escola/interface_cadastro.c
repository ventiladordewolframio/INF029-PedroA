#include "interface_cadastro.h"
 
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "ansi_escapes.h"
#include "interface_main.h"
#include "interface_relatorio.h"
 
int interfaceCadAluno();
int interfaceCadProfessor();
int interfaceCadDisciplina();
 
int interfaceCad() {
    while (true) {
        puts("\x1b[0;36m╔═══════════════════════════════════════════╗\x1b[0;0m");
        puts("\x1b[0;36m║ _____           _           _             ║   \x1b[0;0m");
        puts("\x1b[0;36m║/  __ \\         | |         | |            ║   \x1b[0;0m");
        puts("\x1b[0;36m║| /  \\/ __ _  __| | __ _ ___| |_ _ __ ___  ║   \x1b[0;0m");
        puts("\x1b[0;36m║| |    / _` |/ _` |/ _` / __| __| '__/ _ \\ ║   \x1b[0;0m");
        puts("\x1b[0;36m║| \\__/\\ (_| | (_| | (_| \\__ \\ |_| | | (_) |║  \x1b[0;0m");
        puts("\x1b[0;36m║ \\____/\\__,_|\\__,_|\\__,_|___/\\__|_|  \\___/ ║ \x1b[0;0m");
        puts("\x1b[0;36m╚═══════════════════════════════════════════╝    \x1b[0;0m");
        printf("\n");
        puts("\x1b[0;31m(s) sair - (Interface Escola)                    \x1b[0;0m");
        puts("\x1b[0;32m(a) aluno                                        \x1b[0;0m");
        puts("\x1b[0;32m(p) professor                                    \x1b[0;0m");
        puts("\x1b[0;32m(d) disciplina                                   \x1b[0;0m");
        printf("\n");
        printf("\x1b[0;36m[INFO]: Escolha:  \x1b[0;0m");  // input de dados do usuário
        char op;                                          // operação
        scanf(" %c", &op);                                // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();                                          // limpa o stdin, pois o scanf pode deixar caracteres sem seres escaneados
 
        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;
 
            case 'a':  // alunos
                interfaceCadAluno();
                break;
 
            case 'p':  // professores
                interfaceCadProfessor();
                break;
 
            case 'd':  // disciplinas
                interfaceCadDisciplina();
                break;
 
            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERROR]: Escolha \"%c\" não existe\n", op);
                break;
        }
    }
}
 
void inputNome(bool EDITAR_DADOS, char *OBJ_nome) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Pressione \"Enter\" para não alterar o valor\x1b[0;0m\n");
        }
        printf("\x1b[0;36m[INPUT]:            Nome: \x1b[0;0m");
        char nome[MAX_char_nome];
        fgets(nome, MAX_char_nome, stdin);
 
        if (nome[0] == '\n') {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERROR]: Nome não pode ser vazio\x1b[0;0m\n");
                continue;
            } else {
                printf("\n\x1b[0;33m[WARNING]: Nome não sera modificado\x1b[0;0m\n");
                break;
            }
        }
 
        nome[strcspn(nome, "\n")] = 0;  // roubei do teu replit :) obg
        strcpy(OBJ_nome, nome);
        break;
    }
}
 
void inputSexo(bool EDITAR_DADOS, char *OBJ_sexo) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Pressione \"Enter\" para não alterar o valor\x1b[0;0m\n");
        }
        printf("\x1b[0;36m[INPUT]:       Sexo(M/F): \x1b[0;0m");  //* INSERIR SEXO (lá ele)
        char sexo = getchar();
        clear();
 
        if (sexo == '\n') {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERROR]: Sexo não pode ser vazio\x1b[0;0m\n");
                continue;
            } else {
                printf("\x1b[0;33m[WARNING]: Sexo não sera modificado\x1b[0;0m\n");
                break;
            }
        }
 
        if (sexo == 'm' || sexo == 'f') {
            sexo = toupper(sexo);
        }
 
        if (!(sexo == 'M' || sexo == 'F')) {
            printf("\x1b[0;31m[ERROR]: Sexo invalido, insira (M/F)\x1b[0;0m\n");
            continue;
        }
 
        *OBJ_sexo = sexo;
        break;
    }
}
 
int verificarBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}
 
int validarData(int dia, int mes, int ano) {
    //! removi o primeiro teste daqui pois ele é mais util na hora que for testar o mes a parte da verificação completa da data
    //! essa parte está na parte de entrada de mês
 
    // Meses com 31 dias
    int max_dias_mes;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        max_dias_mes = 31;
    }
    // Meses com 30 dias
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        max_dias_mes = 30;
    }
    // Fevereiro
    else if (mes == 2) {
        int retorno;
        retorno = verificarBissexto(ano);
        if (retorno == true) {
            max_dias_mes = 29;
        } else {
            max_dias_mes = 28;
        }
    }
    if (dia >= 1 && dia <= max_dias_mes)
        return true;
    else
        return false;
}
 
void inputNascimento(bool EDITAR_DADOS, int *OBJ_ano, int *OBJ_mes, int *OBJ_dia) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Digite \"0\" para não alterar o valor\x1b[0;0m\n");
        }
        printf("\x1b[0;36m[INPUT]: Nascimento(ano): \x1b[0;0m");  //* INSERIR NASCIMENTO (ANO)
        int ano = 0;
        bool modificar_ano = true;
        int flag = scanf(" %d", &ano);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();
 
        if (flag != 1) {
            printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Data apenas pode ser um número\x1b[0;0m\n");
            continue;
        }
        if (ano == 0) {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Ano não pode ser zero\x1b[0;0m\n");
                continue;
            } else {
                printf("\n\x1b[0;33m[WARNING]: Ano não sera modificado\x1b[0;0m\n");
                modificar_ano = false;
            }
        }
        if (modificar_ano) {
            *OBJ_ano = ano;
        }
 
        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Digite \"0\" para não alterar o valor\x1b[0;0m\n");
        }
        printf("\x1b[0;36m[INPUT]: Nascimento(mes): \x1b[0;0m");  //* INSERIR NASCIMENTO (MES)
        int mes = 0;
        bool modificar_mes = true;
        flag = scanf(" %d", &mes);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();
 
        if (flag != 1) {
            printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Data apenas pode ser um número\x1b[0;0m\n");
            continue;
        }
        if (mes == 0) {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Mês não pode ser zero\x1b[0;0m\n");
                *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
                continue;
            } else {
                printf("\n\x1b[0;33m[WARNING]: Mês não sera modificado\x1b[0;0m\n");
                modificar_mes = false;
            }
        }
        if (modificar_mes) {
            if (mes < 1 || mes > 12) {
                printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Mês inválido\x1b[0;0m\n");
                *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
                continue;
            }
            *OBJ_mes = mes;
        }
 
        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Digite \"0\" para não alterar o valor\x1b[0;0m\n");
        }
        printf("\x1b[0;36m[INPUT]: Nascimento(dia): \x1b[0;0m");  //* INSERIR NASCIMENTO (DIA)
        int dia = 0;
        bool modificar_dia = true;
        flag = scanf(" %d", &dia);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();
 
        if (flag != 1) {
            printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Data apenas pode ser um número\x1b[0;0m\n");
            continue;
        }
        if (dia == 0) {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Dia não pode ser zero\x1b[0;0m\n");
                *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
                *OBJ_mes = 0;  // lembrar zerar variáveis assim que errar algo
                continue;
            } else {
                printf("\n\x1b[0;33m[WARNING]: Dia não sera modificado\x1b[0;0m\n");
                modificar_dia = false;
            }
        }
        if (modificar_dia) {
            if (!(validarData(dia, mes, ano))) {
                printf("\x1b[0;31m[ERROR]: DATA INVÁLIDA: Dia não existe\x1b[0;0m\n");
                *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
                *OBJ_mes = 0;  // lembrar zerar variáveis assim que errar algo
                continue;
            }
            *OBJ_dia = dia;
        }
        break;
    }
}
 
bool validarCpf(const char cpf[MAX_char_cpf]) {
    int dezenaVerificadora = 0;
    int unidadeVerificadora = 0;
 
    // calcular o primeiro dígito verificador (dezena)
    for (int i = 0, j = 10; i < 9; i++, j--) {
        dezenaVerificadora += (cpf[i] - '0') * j;  // - '0' para transformar char em int
    }
    dezenaVerificadora = 11 - (dezenaVerificadora % 11);
    if (dezenaVerificadora > 9) {
        dezenaVerificadora = 0;
    }
    // calcular o segundo dígito verificador (unidade)
    for (int i = 0, j = 11; i < 10; i++, j--) {
        unidadeVerificadora += (cpf[i] - '0') * j;
    }
    unidadeVerificadora = 11 - (unidadeVerificadora % 11);
    if (unidadeVerificadora > 9) {
        unidadeVerificadora = 0;
    }
 
    if (dezenaVerificadora == (cpf[9] - '0') && unidadeVerificadora == (cpf[10] - '0')) {
        return true;
    } else
        return false;
}
 
void inputCPF(bool EDITAR_DADOS, char *OBJ_cpf) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Pressione \"Enter\" para não alterar o valor\x1b[0;0m\n");
        }
        printf("\x1b[0;36m[INPUT]:             CPF: \x1b[0;0m");  //* INSERIR CPF
        char cpf[12];
        fgets(cpf, 12, stdin);
        clear();
        if (cpf[0] == '\n') {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERROR]: CPF não pode ser vazio\x1b[0;0m\n");
                continue;
            } else {
                printf("\x1b[0;33m[WARNING]: CPF não sera modificado\x1b[0;0m\n");
                break;
            }
        }
 
        cpf[strcspn(cpf, "\n")] = 0;
        bool CPF_CARACTERES_INVALIDOS = false;
        for (int i = 0; i < 11; i++) {
            char c = cpf[i];
            if (!((c >= '0') && (c <= '9'))) {
                CPF_CARACTERES_INVALIDOS = true;
            };
        }
 
        if (CPF_CARACTERES_INVALIDOS) {
            printf("\x1b[0;31m[ERROR]: CPF contém caracteres que não são números\x1b[0;0m\n");
            continue;
        }
 
        if (!validarCpf(cpf)) {
            printf("\x1b[0;31m[ERRO]: CPF inválido. CPF não segue as normas da federação! Insira um CPF válido\x1b[0;0m\n");
            continue;
        }
 
        strcpy(OBJ_cpf, cpf);
        break;
    }
}
 
void inputDisciplinas(bool EDITAR_DADOS, bool *OBJ_disciplinas, char nome_do_obj[]) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        printf("\x1b[0;36m[INPUT]:     Disciplinas: \x1b[0;0m\n");
        if (qtd_disciplina == 0) {
            printf("\x1b[0;33m[WARNING]: Nenhuma disciplina cadastrada, pulando entradas. \x1b[0;0m\n");
            break;
        }
        for (int i = 0; i < MAX_num_disciplinas; i++) {
            if (!disciplinas[i].ativo) {
                continue;
            }
 
            bool modificar_disciplina = true;
            if (EDITAR_DADOS) {
                printf("\x1b[0;36m[INFO]: Pressione \"Enter\" para não alterar o valor\x1b[0;0m\n");
            }
            printf("\x1b[0;36m[INPUT]: Insira (y/n) se o %s da disciplina %s: \x1b[0;0m", nome_do_obj, disciplinas[i].nome);
            char disciplina_bool_input = getchar();
            clear();
 
            if (disciplina_bool_input == '\n') {
                if (EDITAR_DADOS == false) {
                    printf("\x1b[0;31m[ERROR]: Entrada não pode ser vazia\x1b[0;0m\n");
                    i = 0;
                } else {
                    printf("\x1b[0;33m[WARNING]: Disciplina não sera modificada\x1b[0;0m\n");
                    modificar_disciplina = false;
                }
            }
            if (modificar_disciplina) {
                if (disciplina_bool_input == 'Y' || disciplina_bool_input == 'N') {
                    disciplina_bool_input = tolower(disciplina_bool_input);
                }
 
                if (!(disciplina_bool_input == 'y' || disciplina_bool_input == 'n')) {
                    printf("\x1b[0;31m[ERROR]: Entrada invalida, insira (y/n)\x1b[0;0m\n");
                    continue;
                }
 
                if (disciplina_bool_input == 'y') {
                    OBJ_disciplinas[i] = true;
                } else {
                    OBJ_disciplinas[i] = false;
                }
            }
        }
        break;
    }
}
 
void inputAtivo(bool EDITAR_DADOS, bool *OBJ_ativo, char texto_do_obj[]) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Pressione \"Enter\" para não alterar o valor\x1b[0;0m\n");
        }
        printf("\x1b[0;36m[INPUT]: Insira (y/n) se %s: \x1b[0;0m", texto_do_obj);
        char ativo_bool_input = getchar();
        clear();
 
        if (ativo_bool_input == '\n') {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERROR]: Entrada não pode ser vazia\x1b[0;0m\n");
                continue;
            } else {
                printf("\x1b[0;33m[WARNING]: Atividade não sera modificada\x1b[0;0m\n");
                break;
            }
        }
 
        if (ativo_bool_input == 'Y' || ativo_bool_input == 'N') {
            ativo_bool_input = tolower(ativo_bool_input);
        }
 
        if (!(ativo_bool_input == 'y' || ativo_bool_input == 'n')) {
            printf("\x1b[0;31m[ERROR]: Entrada invalida, insira (y/n)\x1b[0;0m\n");
            continue;
        }
 
        if (ativo_bool_input == 'y') {
            *OBJ_ativo = true;
        } else {
            *OBJ_ativo = false;
        }
        break;
    }
}
 
int inputID(int MAX_num, char ID_name[]) {
    while (true) {
        printf("\x1b[0;36m[INPUT]: %s: \x1b[0;0m", ID_name);
        int id;
        int flag = scanf(" %d", &id);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();
 
        if (flag != 1) {
            printf("\x1b[0;31m[ERROR]: ENTRADA INVÁLIDA: Entrada apenas pode ser um número\x1b[0;0m\n");
            continue;
        }
 
        if (!((id < MAX_num) && (id >= 0))) {
            printf("\x1b[0;31m[ERROR]: ENTRADA INVÁLIDA: não existente\x1b[0;0m\n");
            continue;
        }
 
        return id;
    }
}
 
int interfaceCadAluno() {
    while (true) {
        puts("\x1b[0;36m╔═════════════════════════════════════════════╗                    \x1b[0;0m");
        puts("\x1b[0;36m║ _____           _  ___  _                   ║                    \x1b[0;0m");
        puts("\x1b[0;36m║/  __ \\         | |/ _ \\| |                  ║                  \x1b[0;0m");
        puts("\x1b[0;36m║| /  \\/ __ _  __| / /_\\ \\ |_   _ _ __   ___  ║                 \x1b[0;0m");
        puts("\x1b[0;36m║| |    / _` |/ _` |  _  | | | | | '_ \\ / _ \\ ║                  \x1b[0;0m");
        puts("\x1b[0;36m║| \\__/\\ (_| | (_| | | | | | |_| | | | | (_) |║                  \x1b[0;0m");
        puts("\x1b[0;36m║ \\____/\\__,_|\\__,_\\_| |_/_|\\__,_|_| |_|\\___/ ║              \x1b[0;0m");
        puts("\x1b[0;36m╚═════════════════════════════════════════════╝                    \x1b[0;0m");
        printf("\n");
        printf("\x1b[0;31m(s) sair - (Cadastro)                                            \x1b[0;0m\n");
        if (qtd_aluno == MAX_num_alunos) {
            printf("\x1b[0;31m(i) Inserir dados de uma nova Matricula: (CHEIO) (%d/%d)     \x1b[0;0m\n", qtd_aluno, qtd_aluno);
        } else {
            printf("\x1b[0;32m(i) Inserir dados de uma nova Matricula: (%d)                \x1b[0;0m\n", qtd_aluno);
        }
        printf("\x1b[0;32m(e) Editar dados de uma Matricula                                \x1b[0;0m\n");
        printf("\x1b[0;32m(d) Deletar dados de uma Matricula                                \x1b[0;0m\n");
        printf("\x1b[0;32m(l) listar matriculas                                            \x1b[0;0m\n");
        printf("\n");
        printf("\x1b[0;36m[INFO]: Escolha: \x1b[0;0m");  // input de dados do usuário
        char op;                                         // operação
        scanf(" %c", &op);                               // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();                                         // limpa o stdin, pois o scanf pode deixar caracteres sem seres escaneados
 
        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;
 
            case 'i':
                {  // inserir dados de uma nova matricula
                if (qtd_aluno == MAX_num_alunos) {
                    break;
                }
                printf("\x1b[0;36m[INFO]:        Matricula: \"%d\"\x1b[0;0m\n", qtd_aluno);
                inputNome(false, alunos[qtd_aluno].nome);
                inputSexo(false, &alunos[qtd_aluno].sexo);
                inputNascimento(false, &alunos[qtd_aluno].nascimento.ano, &alunos[qtd_aluno].nascimento.mes, &alunos[qtd_aluno].nascimento.dia);
                inputCPF(false, alunos[qtd_aluno].cpf);
                inputDisciplinas(false, alunos[qtd_aluno].disciplinas, "aluno tem aula");
                alunos[qtd_aluno].ativo = true;
                printf("\x1b[0;36m[Aluno matriculado com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                qtd_aluno++;
                break;
            }
 
            case 'e':
                {// editar dados de uma matricula
                int tmp_matricula = inputID(MAX_num_alunos, "Matricula");
                inputNome(true, alunos[tmp_matricula].nome);
                inputSexo(true, &alunos[tmp_matricula].sexo);
                inputNascimento(true, &alunos[tmp_matricula].nascimento.ano, &alunos[tmp_matricula].nascimento.mes, &alunos[tmp_matricula].nascimento.dia);
                inputCPF(true, alunos[tmp_matricula].cpf);
                inputDisciplinas(true, alunos[tmp_matricula].disciplinas, "aluno tem aula");
                inputAtivo(true, &alunos[tmp_matricula].ativo, "o aluno continua matriculado na escola");
                printf("\x1b[0;36m[Aluno editado com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;
                }
            case 'd':
                {
                int tmp_matricula_delete = inputID(MAX_num_alunos, "Matricula");
                startObjAluno(tmp_matricula_delete);
                printf("\x1b[0;36m[Matricula deletada com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;
                }
            case 'l':{  // listar matriculas
                // printf("\x1b[0;36m[INFO]: mostrando os dados dos alunos: \x1b[0;0m\n");
                listarAlunos();
                break;}
 
            default:{  // erro na operacao escolhida
                printf("\x1b[0;31m[ERROR]: Escolha \"%c\" não existe\n", op);
                break;}
        }
    }
}
 
int interfaceCadProfessor() {
    while (true) {
        puts("\x1b[0;36m╔══════════════════════════════════════════════════════════════╗                    \x1b[0;0m");
        puts("\x1b[0;36m║ _____           _______           __                         ║");
        puts("\x1b[0;36m║/  __ \\         | | ___ \\         / _|                        ║");
        puts("\x1b[0;36m║| /  \\/ __ _  __| | |_/ / __ ___ | |_ ___  ___ ___  ___  _ __ ║");
        puts("\x1b[0;36m║| |    / _` |/ _` |  __/ '__/ _ \\|  _/ _ \\/ __/ __|/ _ \\| '__|║");
        puts("\x1b[0;36m║| \\__/\\ (_| | (_| | |  | | | (_) | ||  __/\\__ \\__ \\ (_) | |   ║");
        puts("\x1b[0;36m║ \\____/\\__,_|\\__,_\\_|  |_|  \\___/|_| \\___||___/___/\\___/|_|   ║");
        puts("\x1b[0;36m╚══════════════════════════════════════════════════════════════╝                    \x1b[0;0m");
        printf("\n");
        printf("\x1b[0;31m(s) sair - (Cadastro)                                            \x1b[0;0m\n");
        if (qtd_professor == MAX_num_professores) {
            printf("\x1b[0;31m(i) Inserir dados de uma nova Matricula: (CHEIO) (%d/%d)     \x1b[0;0m\n", qtd_professor, qtd_professor);
        } else {
            printf("\x1b[0;32m(i) Inserir dados de uma nova Matricula: (%d)                \x1b[0;0m\n", qtd_professor);
        }
        printf("\x1b[0;32m(e) Editar dados de uma Matricula                                \x1b[0;0m\n");
        printf("\x1b[0;32m(d) Deletar dados de uma Matricula                                \x1b[0;0m\n");
        printf("\x1b[0;32m(l) listar matriculas                                            \x1b[0;0m\n");
        printf("\n");
        printf("\x1b[0;36m[INFO]: Escolha: \x1b[0;0m");  // input de dados do usuário
        char op;                                         // operação
        scanf(" %c", &op);                               // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();                                         // limpa o stdin, pois o scanf pode deixar caracteres sem seres escaneados
 
        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;
 
            case 'i':{
                  // inserir dados de uma nova matricula
                if (qtd_professor == MAX_num_professores) {
                    break;
                }
                printf("\x1b[0;36m[INFO]:        Matricula: \"%d\"\x1b[0;0m\n", qtd_professor);
                inputNome(false, professores[qtd_professor].nome);
                inputSexo(false, &professores[qtd_professor].sexo);
                inputNascimento(false, &professores[qtd_professor].nascimento.ano, &professores[qtd_professor].nascimento.mes, &professores[qtd_professor].nascimento.dia);
                inputCPF(false, professores[qtd_professor].cpf);
                inputDisciplinas(false, professores[qtd_professor].disciplinas, "professor dá aula");
                professores[qtd_professor].ativo = true;
                qtd_professor++;
                printf("\x1b[0;36m[Professor matriculado com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;}
 
            case 'e':{  // editar dados de uma matricula
                int tmp_matricula = inputID(MAX_num_professores, "Matricula");
                inputNome(true, professores[tmp_matricula].nome);
                inputSexo(true, &professores[tmp_matricula].sexo);
                inputNascimento(true, &professores[tmp_matricula].nascimento.ano, &professores[tmp_matricula].nascimento.mes, &professores[tmp_matricula].nascimento.dia);
                inputCPF(true, professores[tmp_matricula].cpf);
                inputDisciplinas(true, professores[tmp_matricula].disciplinas, "professor dá aula");
                inputAtivo(true, &professores[tmp_matricula].ativo, "o professor continua trabalhando na escola");
                printf("\x1b[0;36m[Professor editado com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;}
 
            case 'd':{
                int tmp_matricula_delete = inputID(MAX_num_professores, "Matricula");
                startObjProfessor(tmp_matricula_delete);
                printf("\x1b[0;36m[Matricula deletada com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;}
 
            case 'l':  // listar matriculas
                // printf("\x1b[0;36m[INFO]: mostrando os dados dos alunos: \x1b[0;0m\n");
                listarProfessores();
                break;
 
            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERROR]: Escolha \"%c\" não existe\n", op);
                break;
        }
    }
}
 
int interfaceCadDisciplina() {
    while (true) {
        puts("\x1b[0;36m╔════════════════════════════════════════════════════════════╗                    \x1b[0;0m");
        puts("\x1b[0;36m║ _____           _______ _          _       _ _             ║                   \x1b[0;0m");
        puts("\x1b[0;36m║/  __ \\         | |  _  (_)        (_)     | (_)            ║                   \x1b[0;0m");
        puts("\x1b[0;36m║| /  \\/ __ _  __| | | | |_ ___  ___ _ _ __ | |_ _ __   __ _ ║                   \x1b[0;0m");
        puts("\x1b[0;36m║| |    / _` |/ _` | | | | / __|/ __| | '_ \\| | | '_ \\ / _` |║                   \x1b[0;0m");
        puts("\x1b[0;36m║| \\__/\\ (_| | (_| | |/ /| \\__ \\ (__| | |_) | | | | | | (_| |║                   \x1b[0;0m");
        puts("\x1b[0;36m║ \\____/\\__,_|\\__,_|___/ |_|___/\\___|_| .__/|_|_|_| |_|\\__,_|║                   \x1b[0;0m");
        puts("\x1b[0;36m║                                     | |                    ║                   \x1b[0;0m");
        puts("\x1b[0;36m║                                     |_|                    ║                   \x1b[0;0m");
        puts("\x1b[0;36m╚════════════════════════════════════════════════════════════╝                    \x1b[0;0m");
        printf("\n");
        printf("\x1b[0;31m(s) sair - (Cadastro)                                            \x1b[0;0m\n");
        if (qtd_disciplina == MAX_num_disciplinas) {
            printf("\x1b[0;31m(i) Inserir dados de uma nova Disciplina: (CHEIO) (%d/%d)     \x1b[0;0m\n", qtd_disciplina, qtd_disciplina);
        } else {
            printf("\x1b[0;32m(i) Inserir dados de uma nova Disciplina: (%d)                \x1b[0;0m\n", qtd_disciplina);
        }
        printf("\x1b[0;32m(e) Editar dados de uma Disciplina                                \x1b[0;0m\n");
        printf("\x1b[0;32m(d) Deletar dados de uma Disciplina                                \x1b[0;0m\n");
        printf("\x1b[0;32m(l) listar Disciplinas                                            \x1b[0;0m\n");
        printf("\n");
        printf("\x1b[0;36m[INFO]: Escolha: \x1b[0;0m");  // input de dados do usuário
        char op;                                         // operação
        scanf(" %c", &op);                               // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();                                         // limpa o stdin, pois o scanf pode deixar caracteres sem seres escaneados
 
        switch (op) {
            case 's':  // sai da aplicação
                return 0;
                break;
 
            case 'i':{  // inserir dados de uma nova matricula
                if (qtd_disciplina == MAX_num_disciplinas) {
                    break;
                }
                printf("\x1b[0;36m[INFO]:        Disciplina: \"%d\"\x1b[0;0m\n", qtd_disciplina);
                inputNome(false, disciplinas[qtd_disciplina].nome);
                disciplinas[qtd_disciplina].ativo = true;
                qtd_disciplina++;
                printf("\x1b[0;36m[Disciplina criada com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;}
 
            case 'e':{  // editar dados de uma matricula
                int tmp_id = inputID(MAX_num_disciplinas, "Código");
                inputNome(true, disciplinas[tmp_id].nome);
                inputAtivo(true, &professores[tmp_id].ativo, "a disciplina continua sendo ensinada na escola");
                printf("\x1b[0;36m[Disciplina editada com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;}
 
            case 'd':{
                int tmp_matricula_delete = inputID(MAX_num_disciplinas, "Código");
                startObjDisciplina(tmp_matricula_delete);
                printf("\x1b[0;36m[Disciplina deletada com sucesso]\x1b[0;0m\n");
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;}
 
            case 'l':  // listar matriculas
                // printf("\x1b[0;36m[INFO]: mostrando os dados dos alunos: \x1b[0;0m\n");
                listarDisciplinas();
                break;
 
            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERROR]: Escolha \"%c\" não existe\n", op);
                break;
        }
    }
}
 
