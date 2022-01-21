# 42-Minitalk Spanish

1. Debes crear un programa de comunicación de la forma cliente-servidor.
2. El servidor debe lanzarse primero, tras lanzarse debe mostrar su PID.
3. El cliente tomará como parámetros:
      ◦ El PID del servidor.
      ◦ La string que debería mandarse.
4. El cliente debe comunicar la string pasada como parámetro al servidor. Una vez la
string se haya recibido, el servidor debe mostrarla
5. La comunicación entre tus programas debe hacerse SOLO utilizando señales UNIX.
6. El servidor debe ser capaz de mostrar la string suficientemente rápido. Por rápido
queremos decir que si piensas que es muy larga, probablemente lo sea.
7. Tu servidor debe poder recibir strings de distintos clientes consecutivamente, sin
necesidad de reiniciar.

# 42-Minitalk English

1. The server must be started first. After its launch, it has to print its PID.
2. The client takes two parameters:
      ◦ The server PID.
      ◦ The string to send.
3. The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
4. The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.
5. Your server should be able to receive strings from several clients in a row without
needing to restart.
6. The communication between your client and your server has to be done only using
UNIX signals.
7. You can only use these two signals: SIGUSR1 and SIGUSR2.
