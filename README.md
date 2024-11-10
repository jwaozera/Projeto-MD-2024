# Projeto de Criptografia RSA

Este projeto implementa um sistema de criptografia RSA, utilizando uma interface de API em Node.js para facilitar operações de geração de chaves, encriptação e decriptação de mensagens. A lógica de criptografia é escrita em C, utilizando a biblioteca GMP para manipulação de números grandes.

## Funcionalidades

- **Geração de Chaves**: Gera uma chave pública RSA a partir de dois números primos e um expoente.
- **Encriptação de Mensagens**: Encripta mensagens utilizando uma chave pública e um expoente fornecidos.
- **Decriptação de Mensagens**: Decripta mensagens criptografadas utilizando os números primos e expoente originais.
- **Salvamento automático das Mensagens**: Salva, no diretório de execução do programa, um arquivo txt com a chave pública, chave privada, mensagem encriptada e mensagem desencriptada.

## Estrutura do Projeto

- **api.js**: Servidor Node.js que expõe uma API para interagir com a criptografia RSA.
- **RSA.c**: Implementação das funções de criptografia e decriptação em C.
- **Front-end**: Feito em HTML e javascript.

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
     npm install express

3. Compile o código em C (CERTIFIQUE-SE DE TER BAIXADO E INSTALADO ANTERIORMENTE O GMP)
   ```bash
   gcc backend/RSA.c -o backend/RSA -lgmp

4. Inicie o servidor.
   ```bash
   node backend/api.js

5. O servidor estará disponível em http://localhost:3001


## OBSERVAÇÕES

É importante manter as pastas backend e frontend dentro de uma pasta principal do projeto. O arquivo executável **RSA.exe** e o **api.js** devem permanecer na pasta backend, e os arquivos HTML devem ficar na pasta frontend. Caso contrário, será necessário fazer ajustes nas referências de caminho no código.
![image](https://github.com/user-attachments/assets/a9cbbc78-b64e-4382-a2b7-b3ce9926b28c)

## TESTES E USO

Se o objetivo é apenas para testes basta baixa-lo em releases ou clonar o repositório que vem com um executável já compilado do código RSA.c, no entanto ainda é necessário ter os pré-requisitos como a biblitoeca GMP, node e a depedência express instalados corretamente.

## LIMITAÇÕES DO MÉTODO DE CRIPTOGRAFIA RSA

### COMO FUNCIONA

O RSA se baseia na dificuldade de fatorar números inteiros grandes. Uma chave pública é usada para criptografar mensagens, enquanto uma chave privada correspondente é usada para descriptografá-las.
A segurança do RSA reside na suposição de que fatorar o produto de dois números primos grandes é computacionalmente inviável.

### LIMITAÇÕES MATEMÁTICAS

1. Fatoração de Números Inteiros: A segurança do RSA se baseia na dificuldade de fatorar grandes números inteiros. Embora seja computacionalmente inviável para números primos muito grandes, o desenvolvimento de novos algoritmos de fatoração pode comprometer a segurança de chaves menores.
2. Ordem de um Grupo: A eficiência do RSA depende da escolha adequada de um grupo multiplicativo. Se a ordem desse grupo não for bem escolhida, ataques podem ser mais eficazes.
3. Ataques de Texto Cifrado Escolhido: Esses ataques exploram a estrutura matemática do RSA para recuperar a chave privada, especialmente se o atacante puder escolher os textos cifrados a serem decifrados.

### LIMITAÇÕES COMPUTACIONAIS

1. Aumento da Potência Computacional: O avanço constante da tecnologia computacional permite quebrar chaves RSA menores em menos tempo.
2. Algoritmos Quânticos: A computação quântica representa uma ameaça significativa para o RSA. Algoritmos como o de Shor podem fatorar números inteiros grandes em tempo polinomial, tornando as chaves RSA atuais vulneráveis.
3. Complexidade Computacional dos Cálculos: A criptografia RSA envolve cálculos complexos, especialmente para chaves longas. Isso pode limitar o desempenho de sistemas com recursos computacionais limitados.

### TAMANHO DAS CHAVES E AS LIMITAÇÕES

1. Chaves Pequenas: Mais vulneráveis a ataques de força bruta e algoritmos de fatoração clássicos.
2. Chaves Grandes: Mais seguras contra ataques tradicionais, mas exigem maior poder computacional para as operações de criptografia e descriptografia.
3. Tamanho Ideal: O tamanho ideal da chave varia dependendo do nível de segurança exigido e da tecnologia disponível.

### ATAQUES E VULNERABILIDADES

1. Ataques por força bruta: Embora teoricamente possível, a complexidade computacional é proibitiva para chaves RSA suficientemente grandes.
2. Ataques de fatoração: Algoritmos de fatoração aprimorados podem comprometer a segurança do RSA para chaves menores.
3. Ataques de canal lateral: Exploração de informações adicionais, como tempo de resposta ou consumo de energia, para deduzir a chave privada.
4. Problemas de implementação: Erros na implementação do algoritmo podem levar a vulnerabilidades.

### CONCLUSÃO

O RSA é um algoritmo robusto e frequentemente usado, contudo, não está livre de ataques. A seleção do tamanho da chave e a execução adequada do algoritmo são fundamentais para assegurar a segurança. Conforme a tecnologia se desenvolve, torna-se essencial seguir as mais recentes pesquisas e orientações de segurança para assegurar a proteção dos dados.

### REFERÊNCIAS

JONSSON, Fredrik; TORNKVIST, Martin. RSA authentication in Internet of Things: technical limitations and industry expectations. Technical limitations and industry expectations. 2017. Disponível em: https://www.diva-portal.org/smash/record.jsf?pid=diva2%3A1112039&dswid=-2151. Acesso em: 02 out. 2024.

RSA COMUNNITY (comp.). Políticas de acesso. 2023. Disponível em: https://community.rsa.com/s/article/Access-Policies-0f565e64. Acesso em: 02 out. 2024.

IBM. Tamanho da chave RSA mínima. 2024. Disponível em: https://www.ibm.com/docs/pt-br/i/7.5?topic=settings-minimum-rsa-key-size. Acesso em: 02 out. 2024.

ANDRADE, Rafael Santos; SILVA, Fernando dos Santos. ALGORITMO DE CRIPTOGRAFIA RSA: análise entre a segurança e velocidade. análise entre a segurança e velocidade. 2012. Disponível em: https://periodicos.unemat.br. Acesso em: 02 out. 2024.

BARBEDO, Inês. O Sistema Criptográfico RSA: ataques e variantes. Ataques e Variantes. 2003. Disponível em: https://bibliotecadigital.ipb.pt. Acesso em: 02 out. 2024.
