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
