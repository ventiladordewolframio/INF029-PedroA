#include "interface_cadastro.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ansi_escapes.h"
#include "interface_main.h"

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
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" não existe\n", op);
                break;
        }
    }
}

void inputNome(bool EDITAR_DADOS, char *OBJ_nome) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        printf("\x1b[0;36m[INPUT]:            Nome: \x1b[0;0m");
        char nome[MAX_char_nome];
        fgets(nome, MAX_char_nome, stdin);

        if (nome[0] == '\n') {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERRO]: Nome não pode ser vazio\x1b[0;0m\n");
                continue;
            } else {
                printf("\x1b[0;36m[INFO]: Nome não sera modificado\x1b[0;0m\n");
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
        printf("\x1b[0;36m[INPUT]:       Sexo(M/F): \x1b[0;0m");  //* INSERIR SEXO (lá ele)
        char sexo = getchar();
        clear();

        if (sexo == '\n') {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERRO]: Sexo não pode ser vazio\x1b[0;0m\n");
                continue;
            } else {
                printf("\x1b[0;36m[INFO]: Sexo não sera modificado\x1b[0;0m\n");
                break;
            }
        }

        if (sexo == 'm' || sexo == 'f') {
            sexo = toupper(sexo);
        }

        if (!(sexo == 'M' || sexo == 'F')) {
            printf("\x1b[0;31m[ERRO]: Sexo invalido, insira (M/F)\x1b[0;0m\n");
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
            printf("\x1b[0;36m[INFO]: Digite \"0\" para não alterar o valor\x1b[0;0m\n");  //! precisa disso por causa do SCANF()
        }
        printf("\x1b[0;36m[INPUT]: Nascimento(ano): \x1b[0;0m");  //* INSERIR NASCIMENTO (ANO)
        int ano;
        scanf(" %d", &ano);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();
        if (ano == 0) {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERRO]: DATA INVÁLIDA: Ano não pode ser zero\x1b[0;0m\n");
                continue;
            } else {
                printf("\x1b[0;36m[INFO]: Ano não sera modificado\x1b[0;0m\n");
                break;
            }
        }
        *OBJ_ano = ano;

        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Digite \"0\" para não alterar o valor\x1b[0;0m\n");  //! precisa disso por causa do SCANF()
        }
        printf("\x1b[0;36m[INPUT]: Nascimento(mes): \x1b[0;0m");  //* INSERIR NASCIMENTO (MES)
        int mes;
        scanf(" %d", &mes);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();
        if (mes == 0) {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERRO]: DATA INVÁLIDA: Mês não pode ser zero\x1b[0;0m\n");
                *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
                continue;
            } else {
                printf("\x1b[0;36m[INFO]: Mês não sera modificado\x1b[0;0m\n");
                break;
            }
        }
        if (mes < 1 || mes > 12) {
            printf("\x1b[0;31m[ERRO]: DATA INVÁLIDA: Mês inválido\x1b[0;0m\n");
            *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
            continue;
        }
        *OBJ_mes = mes;

        if (EDITAR_DADOS) {
            printf("\x1b[0;36m[INFO]: Digite \"0\" para não alterar o valor\x1b[0;0m\n");  //! precisa disso por causa do SCANF()
        }
        printf("\x1b[0;36m[INPUT]: Nascimento(dia): \x1b[0;0m");  //* INSERIR NASCIMENTO (DIA)
        int dia;
        scanf(" %d", &dia);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();
        if (dia == 0) {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERRO]: DATA INVÁLIDA: Dia não pode ser zero\x1b[0;0m\n");
                *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
                *OBJ_mes = 0;  // lembrar zerar variáveis assim que errar algo
                continue;
            } else {
                printf("\x1b[0;36m[INFO]: Dia não sera modificado\x1b[0;0m\n");
                break;
            }
        }
        if (!(validarData(dia, mes, ano))) {
            printf("\x1b[0;31m[ERRO]: DATA INVÁLIDA: Dia não existe\x1b[0;0m\n");
            *OBJ_ano = 0;  // lembrar zerar variáveis assim que errar algo
            *OBJ_mes = 0;  // lembrar zerar variáveis assim que errar algo
            continue;
        }
        *OBJ_dia = dia;
        break;
    }
}

void inputCPF(bool EDITAR_DADOS, char *OBJ_cpf) {  // se verdadeiro entradas vazias serão consideradas como "não modificar os dados da variavel"
    while (true) {
        printf("\x1b[0;36m[INPUT]:             CPF: \x1b[0;0m");  //* INSERIR CPF
        char cpf[12];
        fgets(cpf, 12, stdin);
        clear();
        if (cpf[0] == '\n') {
            if (EDITAR_DADOS == false) {
                printf("\x1b[0;31m[ERRO]: CPF não pode ser vazio\x1b[0;0m\n");
                continue;
            } else {
                printf("\x1b[0;36m[INFO]: CPF não sera modificado\x1b[0;0m\n");
                break;
            }
        }

        cpf[strcspn(cpf, "\n")] = 0;
        bool CPF_CARACTERES_INVALIDOS = false;
        for (int i = 0; i < 11; i++) {
            char c = cpf[i];
            // printf("%d / ", c); //! precisei de printar os valores brutos dos char pq tava tendo problema com os valores não inicializados quando não é inserido um cpf do tamanho total
            if (!((c >= '0') && (c <= '9'))) {
                CPF_CARACTERES_INVALIDOS = true;
            };
        }

        if (CPF_CARACTERES_INVALIDOS) {
            printf("\x1b[0;31m[ERRO]: CPF contém caracteres que não são números\x1b[0;0m\n");
            continue;
        }

        // todo ADICIONAR AQUI CÓDIGO VERIFICAÇÃO DE CPF SEGUNDO A NORMA

        strcpy(OBJ_cpf, cpf);  // TODO adicionar algoritimo de verificação de cpf (vamos precisar de templates validos p testar) (sao sei se e melhor interpretar como inteiro ou string, talvez string para poder ignorar o "-" se o usuario botar)
        break;
    }
}

int inputID(int MAX_num, char ID_name[]) {
    while (true) {
        printf("\x1b[0;36m[INPUT]: %s: \x1b[0;0m",ID_name);
        int id;
        scanf(" %d", &id);  // seria bom uma opção mais limpa que o scanf mas se funciona entao funciona.
        clear();

        if (!((id < MAX_num) && (id >= 0))) {
            printf("\x1b[0;31m[ERRO]: %s inválida, não existente\x1b[0;0m\n",ID_name);
            continue;
        }

        //! verificar se ela é realmente um numero

        printf("\x1b[0;36m[INFO]: Insira os novos valores das variáveis e deixe em branco caso não deseje altera-los\x1b[0;0m\n");

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

            case 'i':  // inserir dados de uma nova matricula
                if (qtd_aluno == MAX_num_alunos) {
                    break;
                }
                printf("\x1b[0;36m[INFO]:        Matricula: \"%d\"\x1b[0;0m\n", qtd_aluno);
                inputNome(false, alunos[qtd_aluno].nome);
                inputSexo(false, &alunos[qtd_aluno].sexo);
                inputNascimento(false, &alunos[qtd_aluno].nascimento.ano, &alunos[qtd_aluno].nascimento.mes, &alunos[qtd_aluno].nascimento.dia);
                inputCPF(false, alunos[qtd_aluno].cpf);
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                qtd_aluno++;
                break;

            case 'e':  // editar dados de uma matricula
                int tmp_matricula = inputID(MAX_num_alunos,"Matricula");
                inputNome(true, alunos[tmp_matricula].nome);
                inputSexo(true, &alunos[tmp_matricula].sexo);
                inputNascimento(true, &alunos[tmp_matricula].nascimento.ano, &alunos[tmp_matricula].nascimento.mes, &alunos[tmp_matricula].nascimento.dia);
                inputCPF(true, alunos[tmp_matricula].cpf);
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;

            case 'l':  // listar matriculas
                // printf("\x1b[0;36m[INFO]: mostrando os dados dos alunos: \x1b[0;0m\n");
                printAlunosObj();
                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" não existe\n", op);
                break;
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

            case 'i':  // inserir dados de uma nova matricula
                if (qtd_professor == MAX_num_professores) {
                    break;
                }
                printf("\x1b[0;36m[INFO]:        Matricula: \"%d\"\x1b[0;0m\n", qtd_professor);
                inputNome(false, professores[qtd_professor].nome);
                inputSexo(false, &professores[qtd_professor].sexo);
                inputNascimento(false, &professores[qtd_professor].nascimento.ano, &professores[qtd_professor].nascimento.mes, &professores[qtd_professor].nascimento.dia);
                inputCPF(false, professores[qtd_professor].cpf);
                qtd_professor++;
                break;

            case 'e':  // editar dados de uma matricula
                int tmp_matricula = inputID(MAX_num_professores,"Matricula");
                inputNome(true, professores[tmp_matricula].nome);
                inputSexo(true, &professores[tmp_matricula].sexo);
                inputNascimento(true, &professores[tmp_matricula].nascimento.ano, &professores[tmp_matricula].nascimento.mes, &professores[tmp_matricula].nascimento.dia);
                inputCPF(true, professores[tmp_matricula].cpf);
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;

            case 'l':  // listar matriculas
                // printf("\x1b[0;36m[INFO]: mostrando os dados dos alunos: \x1b[0;0m\n");
                printProfessoresObj();
                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" não existe\n", op);
                break;
        }
    }
}

int interfaceCadDisciplina() {
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

            case 'i':  // inserir dados de uma nova matricula
                if (qtd_aluno == MAX_num_alunos) {
                    break;
                }
                printf("\x1b[0;36m[INFO]:        Matricula: \"%d\"\x1b[0;0m\n", qtd_aluno);
                // inputNome(false, alunos[qtd_aluno].nome);
                // inputSexo(false, qtd_aluno);
                // inputNascimento(false, qtd_aluno);
                // inputCPF(false, qtd_aluno);
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                qtd_aluno++;
                break;

            case 'e':  // editar dados de uma matricula
                int tmp_matricula = inputID(MAX_num_disciplinas,"Código");
                // inputNome(true, alunos[qtd_aluno].nome);
                // inputSexo(true, tmp_matricula);
                // inputNascimento(true, tmp_matricula);
                // inputCPF(true, tmp_matricula);
                printf("\x1b[0;32m[CONCLUIDO]\x1b[0;0m\n");
                break;

            case 'l':  // listar matriculas
                // printf("\x1b[0;36m[INFO]: mostrando os dados dos alunos: \x1b[0;0m\n");
                printAlunosObj();
                break;

            default:  // erro na operacao escolhida
                printf("\x1b[0;31m[ERRO]: Escolha \"%c\" não existe\n", op);
                break;
        }
    }
}
