급하게 파일 만들필요 있을 경우
 echo "hello world " > hello.txt



directed access 

파일을 읽으면서 순차적으로 접근하는 것이 아니라 
원하는 block으로 직접 접근 ( lseek, seek )

page cache
-> disk 접근 시간을 절약하기 위해 중간에서 cache하는 커널 내부 기법

page write-back
page cache에 변경된 내용을 disk에 반영하는 것 
반영하는 시기는 커널이 결정
즉시 반영이 필요할 경우 ( fsync )
