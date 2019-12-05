obj-m:=tiny.o
tiny-objs:=main.o
 
USER_CFLAGS:=-g
tiny: tiny.c
	gcc $(USER_CFLAGS) -o $@ $<

.PHONY: clean
clean:
	@rm -f tiny
