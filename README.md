# Tasks UFManager (Gerenciador de Tarefas - UFMG)

Este é um sistema de gerenciamento de tarefas escrito em C++. Ele permite que os usuários (apenas aqueles com domínio da UFMG) criem, excluam e movam tarefas entre diferentes quadros. As tarefas podem ser classificadas por data de adição, título (A-Z) ou data de vencimento.

## Tabela de Conteúdos

- [Recursos](#recursos)
- [Como Usar](#como-usar)
- [Pré-Requisitos](#pré-requisitos)
- [Compilação](#compilação)
- [Testes](#testes)
- [Cobertura de Código](#cobertura-de-código)
- [Doxygen](#doxygen)

## Recursos

- Criação, exclusão e movimentação de tarefas
- Ordenação de tarefas por adição, título ou data de vencimento
- Persistência de dados em um arquivo externo
- Criação e exclusão de usuários
- Criação e exclusão de quadros

## Como Usar

Depois de compilar e executar o programa, você será apresentado a um menu principal. As opções são:

1. Criar um novo usuário da UFMG
2. Excluir um usuário existente
3. Acessar um usuário existente
4. Sair

Depois de selecionar a opção de acessar um usuário existente, você verá um menu de usuário. As opções são:

1. Criar um novo quadro
2. Excluir um quadro existente
3. Acessar um quadro existente
4. Listar todos os quadros
5. Retornar ao menu principal

Depois de selecionar a opção de acessar um quadro existente, você verá um menu de quadro. As opções são:

1. Adicionar uma tarefa ao quadro
2. Remover uma tarefa do quadro
3. Mover uma tarefa para outro quadro
4. Listar todas as tarefas no quadro ordenadas por adição
5. Listar todas as tarefas no quadro ordenadas por título (A-Z)
6. Listar todas as tarefas no quadro ordenadas por data de vencimento
7. Editar uma tarefa
8. Retornar ao menu do usuário

## Pré-Requisitos

Este projeto é desenvolvido e testado em um ambiente Linux. Se você está usando Windows, recomendamos a instalação do WSL (Windows Subsystem for Linux). Para instalar o WSL, siga as instruções na [Documentação oficial da Microsoft](https://docs.microsoft.com/en-us/windows/wsl/install-win10)
.

Após a instalação do WSL, instale o g++ e o make com os seguintes comandos:

```
sudo apt update
sudo apt install g++ make
```

## Compilação

Para compilar o projeto, siga as instruções abaixo:

1. Navegue até o diretório src do projeto
```
cd src
```

2. Use o Makefile para compilar o projeto
```
make
```

3. Execute o programa com "taskufmanager" ou make run
```
./taskufmanager
```

## Testes

Para executar os testes unitários, siga as instruções abaixo:

1. Certifique-se de estar no diretório src do projeto
2. Compile os testes usando Makefile
```
make test
```

3. Execute os testes
```
./build/runtests
```

## Cobertura de Código

Usamos o gcovr para gerar relatórios de cobertura de código. 

**NOTA**: O gcovr pode não estar instalado no seu sistema. Para instalá-lo, use o seguinte comando:
```
pip install gcovr
```
ou, se estiver em um sistema Linux,
```
sudo apt install gcovr
```

Para gerar um relatório de cobertura de código, siga as etapas abaixo:

1. Certifique-se de estar no diretório do projeto
2. Compile o projeto com a opção de cobertura para checar a %
```
gcovr -r .
```

Observação: A cobertura no código está em torno de 72% (última atualização: 06/07/2023, às 23:20), tirando o arquivo test/doctest.h.

## Doxygen

Para acessar a documentação Doxygen, acesse o arquivo "index.html" na pasta html dentro da pasta "Doxygen".
