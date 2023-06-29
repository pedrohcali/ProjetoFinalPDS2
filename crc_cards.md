## Classe Tarefa

- Class name: Tarefa
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Armazenar detalhes da tarefa (título, descrição, data de vencimento).
    2. Permitir a modificação dos detalhes da tarefa.
- Collaborators: Quadro

## Classe Quadro

- Class name: Quadro
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Armazenar uma lista de tarefas.
    2. Permitir a adição, remoção e modificação de tarefas.
    3. Permitir a visualização de todas as tarefas no quadro.
- Collaborators: Tarefa

## Classe GerenciadorDeTarefas

- Class name: GerenciadorDeTarefas
- Superclasses: None
- Subclasses: None
- Class type: Normal
- Responsibilities:
    1. Manter uma lista de quadros.
    2. Permitir a adição, remoção e modificação de quadros.
    2. Permitir a movimentação de tarefas entre quadros.
- Collaborators: Quadro, Tarefa
