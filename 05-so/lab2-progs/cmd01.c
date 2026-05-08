/*
**  file: cmd01.c
**
**  Paulo Shirley @ UAb
**  v2009/03/12
*/

/*
|--------------------------------------------------------------------------
| Bibliotecas utilizadas
|--------------------------------------------------------------------------
|
| stdio.h  -> permite usar printf()
| stdlib.h -> permite usar system()
|
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*
   |--------------------------------------------------------------------------
   | Comando Linux que será executado
   |--------------------------------------------------------------------------
   |
   | "ps -f" mostra os processos em formato detalhado.
   |
   | O comando é armazenado dentro de uma string.
   |
   */

   char cmd[]= "ps -f";

   /*
   |--------------------------------------------------------------------------
   | Comando alternativo (comentado)
   |--------------------------------------------------------------------------
   |
   | Mostra apenas informações específicas:
   |
   | pid   -> ID do processo
   | ppid -> ID do processo pai
   | user -> utilizador dono do processo
   | state -> estado do processo
   | time -> tempo de CPU
   | comm -> nome do comando/programa
   |
   */

   /* char cmd[]= "ps -o pid,ppid,user,state,time,comm"; */

   /*
   |--------------------------------------------------------------------------
   | Mostra mensagem antes de executar o comando
   |--------------------------------------------------------------------------
   |
   | %s substitui o conteúdo da string cmd.
   |
   */

   printf("\nExecutando o comando \"%s\"\n",cmd);

   /*
   |--------------------------------------------------------------------------
   | Executa o comando Linux
   |--------------------------------------------------------------------------
   |
   | system() pede ao sistema operativo para executar
   | o comando armazenado na variável cmd.
   |
   | Internamente:
   |
   | programa C -> shell -> comando ps
   |
   | O programa fica bloqueado até o comando terminar.
   |
   */

   system(cmd);

   /*
   |--------------------------------------------------------------------------
   | Mensagem final após o comando terminar
   |--------------------------------------------------------------------------
   */

   printf("*** Fim ***\n");

   /*
   |--------------------------------------------------------------------------
   | Termina o programa com sucesso
   |--------------------------------------------------------------------------
   */

   return 0;
}