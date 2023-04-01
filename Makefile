include app.mk

all: main.o os_system.o router.o
	cc -o all main.o os_system.o router.o $(CFLAGS) $(LDFLAGS)

main.o : main.c
	cc -c main.c -I$(INC_DIR) $(CFLAGS) $(LDFLAGS)

os_system.o: source/lib/os_system.c
	make -C source/lib

router.o: source/network/router.c
	make -C source/network

.PHONY : clean
clean:
	make -C source/lib clean
	make -C source/network clean
	-rm all main.o os_system.o router.o
