## Classe Dado

- Class name: Dado
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Realizar a rolagem do dado.
    2. Retornar o valor do resultado da rolagem.
- Collaborators: None (O dado em si não precisa conhecer o jogador ou o inimigo. Ele apenas realiza uma função: rolar e retornar o resultado)

## Classe Usuário/Jogador

- Class name: Usuário/Jogador
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Interagir com o jogo através de ações e decisões.
    2. Personalizar os atributos do personagem.
- Collaborators: Dado, Ficha, Narrador, Localização, Menu "Opções", Missão, Item, Inimigo

## Classe Ficha

- Class name: Ficha
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Armazenar e exibir os atributos atuais do personagem.
    2. Gerenciar o inventário do personagem.
- Collaborators: Usuário/Jogador, Item

## Classe Narrador

- Class name: Narrador
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Apresentar a história e o contexto do jogo.
    2. Descrever o estado atual do jogo e os eventos.
- Collaborators: None

## Classe Localização

- Class name: Localização
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Armazenar as informações da localização atual do jogador.
    2. Fornecer descrições de diferentes localizações.
- Collaborators: Usuário/Jogador

## Classe Menu "Opções"

- Class name: Menu "Opções"
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Exibir as opções de menu disponíveis.
    2. Permitir ao usuário selecionar e interagir com as opções de menu.
- Collaborators: Usuário/Jogador

## Classe Missão

- Class name: Missão
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Definir os objetivos da missão.
    2. Monitorar o progresso do jogador na missão.
    3. Fornecer recompensas ao jogador ao completar a missão.
- Collaborators: Usuário/Jogador, NPC

## Classe Item

- Class name: Item
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Armazenar informações sobre o item (por exemplo, tipo, valor, efeitos).
    2. Permitir ao jogador interagir com o item (por exemplo, usar, equipar, descartar).
- Collaborators: Usuário/Jogador, Ficha

## Classe Inimigo

- Class name: Inimigo
- Superclasses: Personagem
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Participar em combates com o jogador.
    2. Realizar ações e movimentos de acordo com a lógica do jogo.
    3. Perder vida ou ser derrotado quando as condições correspondentes são atendidas.
- Collaborators: Usuário/Jogador, Dado
