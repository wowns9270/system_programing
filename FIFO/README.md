

FIFO file

- mkfifo -m 0644 pipeFile

- FIFO file을 만든다. ( FIFO라는 특수한 파일 )

- write ->  pipe  -> read 

- write를 하고 read 할 때까지 block된다. 