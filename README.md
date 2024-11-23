
# Gerenciador de Tarefas - Trabalho de Estruturas de Dados

## Introdução

### Descrição

Este projeto é um gerenciador de tarefas desenvolvido em **C** como parte do trabalho da disciplina **INF0063 - AED1 (Algoritmos e Estruturas de Dados I)**. O sistema permite que o usuário adicione tarefas, acompanhe o progresso e registre as tarefas concluídas, além de calcular o **XP** ganho ao completar as tarefas. A implementação utiliza estruturas de dados como **fila** e **lista encadeada** para gerenciar as tarefas pendentes e concluídas.

![img](https://amhandmade.pt/cdn/shop/files/IMG_5474.jpg?v=1695566664&width=1445)


## Metodologia

### Funcionalidades

![img](https://midias.siteware.com.br/wp-content/uploads/2019/05/25081155/dicas-gestao-projetos.jpg)


- **Adicionar Tarefas:** O usuário pode adicionar tarefas com uma descrição e tempo estimado para a sua execução.
- **Exibir Tarefas Pendentes:** Lista todas as tarefas ainda não concluídas.
- **Concluir Tarefas:** O usuário pode marcar uma tarefa como concluída e registrar o tempo real dedicado à tarefa.
- **Exibir Tarefas Concluídas:** Exibe uma lista de tarefas já concluídas, com o tempo estimado, tempo real e XP ganho.
- **Ver XP Total:** O sistema calcula e exibe o total de XP ganho até o momento.
- **Controle de Entrada:** O sistema evita a duplicação de tarefas com a mesma descrição.

### Estruturas de Dados Utilizadas

- **Fila:** Utilizada para armazenar as tarefas pendentes. A fila segue a estrutura **FIFO** (First In, First Out), onde a tarefa que é adicionada primeiro será a primeira a ser concluída.
- **Lista Encadeada:** Utilizada para armazenar as tarefas concluídas. Cada tarefa concluída é inserida no início da lista.

### Estrutura do Código

- **Tarefa:** Estrutura que armazena os dados de cada tarefa, como descrição, XP, tempo estimado, tempo real e ponteiro para a próxima tarefa.
- **Fila:** Estrutura que mantém as tarefas pendentes. Contém ponteiros para o início (frente) e fim (traseira) da fila.
- **ListaConcluidas:** Estrutura que mantém as tarefas concluídas, com um ponteiro para o início da lista.

### Como Usar

1. **Adicionar Tarefas:** O programa pede ao usuário a descrição da tarefa e o tempo estimado para sua execução.
2. **Exibir Tarefas Pendentes:** Mostra todas as tarefas pendentes, incluindo descrição, XP acumulado, tempo estimado e tempo real.
3. **Concluir Tarefas:** O usuário seleciona uma tarefa pendente para marcar como concluída, informa o tempo real dedicado e ganha XP.
4. **Exibir Tarefas Concluídas:** Exibe uma lista das tarefas concluídas com o tempo real dedicado e o XP acumulado.
5. **Ver XP Total:** Mostra o total de XP acumulado até o momento.

### Como Compilar e Executar

1. **Compilar o código:**
   ```bash
   gcc -o Codigo Codigo.c
   ```

2. **Executar o programa:**
   ```bash
   ./Codigo.c
   ```

3. Siga as instruções no menu interativo para adicionar tarefas, concluí-las, verificar tarefas pendentes ou concluídas, e ver o XP total.

### Exemplo de Saída

```
1. Adicionar Tarefa
2. Exibir Tarefas
3. Marcar Tarefa como Concluída
4. Ver Tarefas Concluídas
5. Ver XP Total
6. Sair
Escolha uma opção: 1
Digite a descrição da tarefa: Estudar Estruturas de Dados
Digite o tempo estimado dedicado à tarefa (em minutos): 60
Deseja adicionar outra tarefa? (s/n): s
Digite a descrição da tarefa: Revisar Algoritmos
Digite o tempo estimado dedicado à tarefa (em minutos): 45
Deseja adicionar outra tarefa? (s/n): n
```

## Equipe

- **202302520 - Ana Clara Fortunado de Souza**
- **202201646 - Layssa Ribeiro Abreu Peres**
- **202206139 - Thiago Honorato Ferreira**

## Licença

Este projeto é licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.
