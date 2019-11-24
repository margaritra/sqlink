obj-m+=messageModule.o

KDIR?=/lib/modules/$(shell uname -r)/build
modules:
	make -C $(KDIR) M=$(CURDIR) modules
clean:
	make -C -C $(KDIR) M=$(CURDIR) clean
	rm -f *.stamp
