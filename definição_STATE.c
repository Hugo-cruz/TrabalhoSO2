/* Used in tsk->state: */
   #define TASK_RUNNING            0       // Processo em execução ou na fila para rodar.
   #define TASK_INTERRUPTIBLE      1       // Processo bloqueado, esperando algum recurso.
                                               // Muda para a fila de prontos ao receber um sinal
   #define TASK_UNINTERRUPTIBLE    2       // Também está bloqueado, 
                                               // mas não muda para a fila de prontos ao receber o sinal.
   #define __TASK_STOPPED          4       // Execução do processo está congelada (Não está executando e nem pode executar).
   #define __TASK_TRACED           8       // Execução do processo parada por um debugger.
   /* Used in tsk->exit_state: */
   #define EXIT_DEAD               16      // Processo sendo removido do sistema.
   #define EXIT_ZOMBIE             32      // Processo terminado, esperando a chamada wait() do processo pai.
   #define EXIT_TRACE              (EXIT_ZOMBIE | EXIT_DEAD)
   /* Used in tsk->state again: */
   #define TASK_DEAD               64
   #define TASK_WAKEKILL           128
   #define TASK_WAKING             256
   #define TASK_PARKED             512
   #define TASK_NOLOAD             1024
   #define TASK_NEW                2048
   #define TASK_STATE_MAX          4096