# knn-algorithm

O trabalho tem como objetivo a implementação de uma aplicação em duas linguagens de programação para comparar algumas características entre as mesmas.

## Baixa a base no google classroom e depois descompacta ela na raiz do projeto

- O .gitignore vai bloquear ela ao subir pra branch remota porque ela tá com mais de 200mb

## Configuração do projeto JS

- Instale o node: *v12.16.1* (Versão utilizada no desenvolvimento)
- Abra o diretório `/js-knn`
- Execute o algoritmo utilizando a seguinte nomenclatura: </br>
  `node main.js train_path test_path k` </br>
  **Ex:** `node main.js ../bases/train_59.data ../bases/test_59_small.data 100`

  - Sugestão:
  Existe um arquivo nomeado de `script` que executa um caso de teste, basta transformá-la em um executável e rodar o seguinte comando no terminal `./script` (caso você esteja no mesmo diretório).
