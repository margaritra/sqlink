obj-m+=dev_null.o

KDIR?=/lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(CURDIR) modules
	$(CC) testebbchar.c -o test
clean:
	make -C -C $(KDIR) M=$(CURDIR) clean
	rm test
