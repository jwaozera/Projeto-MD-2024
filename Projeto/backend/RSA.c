#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>  // Biblioteca GNU para aritmética de precisão múltipla (GMP)

// Declaração das funções principais
void decryptMessage(mpz_t firstPrime, mpz_t secondPrime, mpz_t exponent, char* message);
void encryptMessage(char* message, mpz_t publicKey, mpz_t exponent);
void createPublicKey(mpz_t firstPrime, mpz_t secondPrime, mpz_t exponent);
int ehPrimo(unsigned long int n);  // Função para verificar se um número é primo

int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos passados é suficiente
    if (argc < 2) {
        printf("Uso: ./RSA <Operação> <parâmetros...>\n");
        printf("Operações: generate_key, encrypt, decrypt\n");
        return 1;  // Retorna com erro se o formato estiver incorreto
    }

    // Verifica se a operação solicitada é para gerar uma chave pública
    if (strcmp(argv[1], "generate_key") == 0) {
        if (argc < 5) {
            printf("Uso: ./RSA generate_key <p> <q> <e>\n");  // Formato esperado
            return 1;
        }
        mpz_t firstPrime, secondPrime, exponent;
        mpz_inits(firstPrime, secondPrime, exponent, NULL);  // Inicializa variáveis mpz_t

        // Configura as variáveis a partir dos argumentos de linha de comando
        mpz_set_str(firstPrime, argv[2], 10);
        mpz_set_str(secondPrime, argv[3], 10);
        mpz_set_str(exponent, argv[4], 10);

        // Verifica se os números fornecidos são primos
        if (!ehPrimo(mpz_get_ui(firstPrime)) || !ehPrimo(mpz_get_ui(secondPrime))) {
            printf("Numeros devem ser primos.\n");
            fprintf(stderr, "Números devem ser primos!\n");
            return 1;  // Retorna com erro se não forem primos
        }

        // Chama a função para criar a chave pública
        createPublicKey(firstPrime, secondPrime, exponent);
        mpz_clears(firstPrime, secondPrime, exponent, NULL);  // Libera a memória

    // Verifica se a operação solicitada é para criptografar uma mensagem
    } else if (strcmp(argv[1], "encrypt") == 0) {
        if (argc < 5) {
            printf("Uso: ./RSA encrypt <mensagem> <chave publica> <expoente>\n");
            return 1;
        }
        mpz_t publicKey, exponent;
        mpz_inits(publicKey, exponent, NULL);

        // Configura as variáveis de chave pública e expoente
        mpz_set_str(publicKey, argv[3], 10);
        mpz_set_str(exponent, argv[4], 10);

        // Chama a função para criptografar a mensagem
        encryptMessage(argv[2], publicKey, exponent);
        mpz_clears(publicKey, exponent, NULL);  // Libera a memória

    // Verifica se a operação solicitada é para descriptografar uma mensagem
    } else if (strcmp(argv[1], "decrypt") == 0) {
        if (argc < 6) {
            printf("Uso: ./RSA decrypt <mensagem> <p> <q> <e>\n");
            return 1;
        }
        mpz_t firstPrime, secondPrime, exponent;
        mpz_inits(firstPrime, secondPrime, exponent, NULL);

        // Configura as variáveis a partir dos argumentos de linha de comando
        mpz_set_str(firstPrime, argv[3], 10);
        mpz_set_str(secondPrime, argv[4], 10);
        mpz_set_str(exponent, argv[5], 10);

        // Chama a função para descriptografar a mensagem
        decryptMessage(firstPrime, secondPrime, exponent, argv[2]);
        mpz_clears(firstPrime, secondPrime, exponent, NULL);  // Libera a memória

    } else {
        printf("Operação inválida\n");  // Se a operação não for reconhecida, exibe mensagem de erro
        return 1;
    }

    return 0;  // Finaliza o programa com sucesso
}

// Função para criar uma chave pública a partir de dois primos e um expoente
void createPublicKey(mpz_t firstPrime, mpz_t secondPrime, mpz_t exponent) {
    mpz_t public_key, totient, gcd;
    mpz_inits(public_key, totient, gcd, NULL);

    // Calcula n = p * q
    mpz_mul(public_key, firstPrime, secondPrime);

    // Calcula o totiente: (p-1) * (q-1)
    mpz_t p_menos_1, q_menos_1;
    mpz_inits(p_menos_1, q_menos_1, NULL);
    mpz_sub_ui(p_menos_1, firstPrime, 1);
    mpz_sub_ui(q_menos_1, secondPrime, 1);
    mpz_mul(totient, p_menos_1, q_menos_1);

    // Verifica se o expoente é coprimo com o totiente
    mpz_gcd(gcd, exponent, totient);
    if (mpz_cmp_ui(gcd, 1) != 0) {
        printf("Erro: O expoente não é coprimo com o totiente. Escolha um expoente diferente.\n");
        mpz_clears(public_key, totient, gcd, p_menos_1, q_menos_1, NULL);
        return;
    }

    // Imprime e salva a chave pública
    mpz_mul(public_key, firstPrime, secondPrime);
    gmp_printf("Chave pública gerada: %Zd\n", public_key);
    gmp_printf("Expoente: %Zd\n", exponent);

    // Salva a chave pública em um arquivo
    FILE *file = fopen("chave_publica.txt", "w");
    FILE *private = fopen("chave_privada.txt", "w");
    if (file != NULL) {
        gmp_fprintf(file, "Chave Pública: %Zd\n", public_key);
        gmp_fprintf(file, "Expoente: %Zd\n", exponent);
        gmp_fprintf(private, "%Zd %Zd", firstPrime, secondPrime);
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

    mpz_clear(public_key);
}

// Função para criptografar uma mensagem
void encryptMessage(char* message, mpz_t publicKey, mpz_t exponent) {
    mpz_t value, result;
    mpz_inits(value, result, NULL);

    // Abre um arquivo para salvar a mensagem criptografada
    FILE *file = fopen("mensagem_encriptada.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Criptografa cada caractere da mensagem
    for (size_t i = 0; i < strlen(message); i++) {
        mpz_set_ui(value, (unsigned long) message[i]);  // Converte caractere para valor ASCII
        mpz_powm(result, value, exponent, publicKey);   // Calcula (valor^expoente) mod publicKey
        gmp_printf("%Zd ", result);
        gmp_fprintf(file, "%Zd ", result);  // Salva no arquivo
    }

    printf("\n");
    fclose(file);
    mpz_clears(value, result, NULL);  // Libera a memória
}

// Função para descriptografar uma mensagem
void decryptMessage(mpz_t firstPrime, mpz_t secondPrime, mpz_t exponent, char* message) {
    mpz_t D, totient, N, num, t;
    mpz_inits(D, totient, N, num, t, NULL);

    // Calcula o totiente (p-1)(q-1)
    mpz_sub_ui(totient, firstPrime, 1);
    mpz_t temp;
    mpz_init(temp);
    mpz_sub_ui(temp, secondPrime, 1);
    mpz_mul(totient, totient, temp);
    mpz_clear(temp);

    // Calcula N = p * q
    mpz_mul(N, firstPrime, secondPrime);

    // Calcula o inverso modular de `exponent` mod `totient`
    if (!mpz_invert(D, exponent, totient)) {
        printf("Erro: Não foi possível encontrar o inverso modular.\n");
        mpz_clears(D, totient, N, num, t, NULL);
        return;
    }

    // Abre o arquivo para salvar a mensagem descriptografada
    FILE *file = fopen("mensagem_desencriptada.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        mpz_clears(D, totient, N, num, t, NULL);
        return;
    }

    // Lê e descriptografa a mensagem dividida por espaços
    char* token = strtok(message, " ");
    while (token != NULL) {
        mpz_set_str(num, token, 10);  // Converte o token para mpz_t
        mpz_powm(t, num, D, N);       // Calcula (num^D) mod N
        printf("%c", (char)mpz_get_ui(t));  // Imprime o caractere correspondente
        token = strtok(NULL, " ");    // Vai para o próximo token
        fprintf(file, "%c", (char)mpz_get_ui(t));  // Salva no arquivo
    }
    printf("\n");

    fclose(file);
    mpz_clears(D, totient, N, num, t, NULL);  // Libera a memória
}

// Função para verificar se um número é primo
int ehPrimo(unsigned long int n) {
    if (n == 2 || n == 3) return 1;    // 2 e 3 são primos
    if (n < 2 || n % 2 == 0) return 0; // Números menores que 2 ou pares não são primos
    for (unsigned long int i = 3; i * i <= n; i += 2) { // Verifica divisores ímpares até a raiz quadrada de n
        if (n % i == 0) return 0;      // Se encontrar divisor, não é primo
    }
    return 1;                          // É primo
}
