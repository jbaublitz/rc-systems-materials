obj-m += hello.o

all: hello.o
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean 

hello.o: hello.c
	gcc -c hello.c -mcmodel=kernel -fno-pic
