KERNEL_SOURCE:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
obj-m:=mq.o
mq-objs:=main.o

.PHONY: all
all: modules send_msg recv_msg testmutex 
 
.PHONY: modules
modules:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) modules
 
.PHONY: clean
clean:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) clean
	rm -f testmutex recv_msg send_msg

USER_CFLAGS:=-O2 -ansi -pedantic -Wall -Werror
send_msg: send_msg.c
	gcc $(USER_CFLAGS) -o $@ $<
recv_msg: recv_msg.c
	gcc $(USER_CFLAGS) -o $@ $<
testmutex: testmutex.c
	gcc $(USER_CFLAGS) -o $@ $< -lpthread

.PHONY: insmod
insmod:
	sudo insmod ./mq.ko
	sleep 1
	sudo chmod 666 /dev/mq*

.PHONY: rmmod
rmmod:
	sudo rmmod mq

.PHONY: test_insrmmod
VARIABLE := number

test_insrmmod:
	@for number in $$(seq 1 100);\
	do \
	sudo insmod mq.ko;\
	sleep 0.1;\
	(number=number+1);\
	sudo rmmod mq;\
	echo $$number;\
	done

.PHONY: test_all