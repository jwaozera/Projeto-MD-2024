# Projeto de Criptografia RSA

Este projeto implementa um sistema de criptografia RSA, utilizando uma interface de API em Node.js para facilitar operações de geração de chaves, encriptação e decriptação de mensagens. A lógica de criptografia é escrita em C, utilizando a biblioteca GMP para manipulação de números grandes.

## Funcionalidades

- **Geração de Chaves**: Gera uma chave pública RSA a partir de dois números primos e um expoente.
- **Encriptação de Mensagens**: Encripta mensagens utilizando uma chave pública e um expoente fornecidos.
- **Decriptação de Mensagens**: Decripta mensagens criptografadas utilizando os números primos e expoente originais.

## Estrutura do Projeto

- **api.js**: Servidor Node.js que expõe uma API para interagir com a criptografia RSA.
- **RSA.c**: Implementação das funções de criptografia e decriptação em C.
- **frontend**: Diretório que pode conter o frontend (não incluído neste projeto).

## Tecnologias Utilizadas

- **Node.js** e **Express**: Para criação da API e comunicação com o código C.
- **GMP (GNU Multiple Precision Arithmetic Library)**: Biblioteca em C para manipulação de números grandes usados na criptografia RSA.

## Instalação

### Pré-requisitos

- [Node.js](https://nodejs.org) (versão 14 ou superior).
- [GMP Library](https://gmplib.org) A biblioteca GMP é necessária para manipulação de números grandes e precisa estar instalada no sistema antes da compilação do código em C.

### Passos para Instalação

1. Clone o repositório:
   ```bash
   git clone https://github.com/jwaozera/Projeto-MD-2024.git
   cd Projeto-MD-2024
2. Após baixar e instalar o node.js instale o express
   ```bash
     node install express

3. Compile o código em C (CERTIFIQUE-SE DE TER BAIXADO E INSTALADO ANTERIORMENTE O GMP)
   ```bash
   gcc RSA.c -o RSA -lgmp

4. Inicie o servidor.
   ```bash
   node backend/api.js

5. O servidor estará disponível em http://localhost:3001


## OBSERVAÇÕES

É importante manter os arquivos como o executavel na pasta backend junto de api.js e os arquivos html na pasta frontend caso contrario pode ser necessário alterar essa linha de código.
![image](https://github.com/user-attachments/assets/a9cbbc78-b64e-4382-a2b7-b3ce9926b28c)

## TESTES E USO

Se o objetivo é apenas para testes basta baixa-lo em releases ou clonar o repositório que vem com um executável já compilado do código RSA.c, no entanto ainda é necessário ter o node e a depedência express para iniciar o servidor.



