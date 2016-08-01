target = HNotes
object = main.o hn_dbLogin.o hn_mysqlOperation.o hn_memoryManager.o hn_duLinkList.o hn_editor.o
mysql  = -lmysqlclient   -L /usr/lib/mysql   -I /usr/include/mysql 
dependency = $(mysql) -lncursesw -L /usr/lib

$(target):$(object)
	gcc $(object) -o $(target) $(dependency) 

main.o:main.c hn_globalDependency.h 
	gcc -c main.c -o main.o  $(dependency) 
 
hn_dbLogin.o:hn_dbLogin.c hn_globalDependency.h 
	gcc -c hn_dbLogin.c -o hn_dbLogin.o  $(dependency) 

hn_mysqlOperation.o:hn_mysqlOperation.c hn_globalDependency.h 
	gcc -c hn_mysqlOperation.c -o hn_mysqlOperation.o  $(dependency) 

hn_memoryManager.o:hn_memoryManager.c hn_memoryManager.h
	gcc -c hn_memoryManager.c -o hn_memoryManager.o  $(dependency) 

hn_duLinkList.o:hn_duLinkList.c hn_duLinkList.h
	gcc -c hn_duLinkList.c -o hn_duLinkList.o  $(dependency) 

hn_editor.o:hn_editor.c hn_globalDependency.h 
	gcc -c hn_editor.c -o hn_editor.o  $(dependency) 


clean:
	rm -rf  $(object) $(target)