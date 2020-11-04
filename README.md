# knn-algorithm

O trabalho tem como objetivo a implementação do algoritmo `k-nearest-neighbors` em duas linguagens distintas para comparar algumas características entre as mesmas.

## Baixar a base no google classroom (ppioo) e depois descompacta-la ela na raiz do projeto

- O .gitignore vai bloquear ela ao subir pra branch remota porque ela tá com mais de 200mb

## Instruções para execução do código em JS

- Instale o node: *v14.14.0* (Versão utilizada para teste)
  - Link do tutorial de instalação do `node`: https://nodejs.org/en/download/package-manager/
- Abra o diretório `/js-knn`
- Execute o algoritmo utilizando o seguinte comando: </br>
  `node main.js train_path test_path k` </br>
  **Ex:** `node main.js ../bases/train_59.data ../bases/test_59_small.data 100`

## Instruções para execução do código em C++

- Instale o compilador g++: *9.3* (Versão utilizada no teste)
  - Link do tutorial de instalação do `g++`: https://linuxconfig.org/how-to-install-g-the-c-compiler-on-ubuntu-18-04-bionic-beaver-linux
- Abra o diretório `/cpp-knn`
- Certifique-se de que os arquivos de `bases` estejam na raíz do projeto
  - Ex: `../bases/test_59.data` e `../bases/train_59.data`
- Execute o algoritmo utilizando os seguintes comandos: </br>
  ```
  g++ main.cpp
  ./a.out k
  ```
  **Ex:** </br>
  ```
  g++ main.cpp
  ./a.out 100
  ```
  
