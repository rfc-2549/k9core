# This makefile is BSD compatiable: You can run it without gmake on most systems

CC = cc
PREFIX = /usr/local

compile:
	mkdir -p bin
	$(CC)	-c	*.c nouserland/*.c
	$(CC)	-o bin/cat		cat.o
	$(CC)	-o bin/chmod		chmod.o
	$(CC)	-o bin/chown		chown.o
	$(CC)	-o bin/cp		cp.o
	$(CC)	-o bin/dirname		dirname.o
	$(CC)	-o bin/echo		echo.o
	$(CC)	-o bin/exec		exec.o
	$(CC)	-o bin/false		false.o
	$(CC)	-o bin/groups		groups.o
	$(CC)	-o bin/head		head.o
	$(CC)	-o bin/hostid		hostid.o
	$(CC)	-o bin/hostname		hostname.o
	$(CC)	-o bin/id		id.o
	$(CC)	-o bin/kill		kill.o
	$(CC)	-o bin/ln		ln.o
	$(CC)	-o bin/longname		logname.o
	$(CC)	-o bin/ls		ls.o
	$(CC)	-o bin/mkdir		mkdir.o
	$(CC)	-o bin/mount		mount.o
	$(CC)	-o bin/mv		mv.o
	$(CC)	-o bin/nproc		nproc.o
	$(CC)	-o bin/pwd		pwd.o
	$(CC)	-o bin/rm		rm.o
	$(CC)	-o bin/rmdir		rmdir.o
	$(CC)	-o bin/shred		shred.o
	$(CC)	-o bin/sleep 		sleep.o
	$(CC)	-o bin/sync		sync.o
	$(CC)	-o bin/touch		touch.o
	$(CC)	-o bin/true		true.o
	$(CC)	-o bin/tty		tty.o
	$(CC)	-o bin/umount		umount.o
	$(CC)	-o bin/unlink		unlink.o
	$(CC)	-o bin/wc		wc.o
	$(CC)	-o bin/whoami		whoami.o
	$(CC)	-o bin/yes		yes.o
	$(CC) 	-o bin/uname		uname.o

clean:
	rm -f *.o
	rm -fr bin/
install:
	mkdir -p $(DESTDIR)$(PREFIX)/k9core
	cp bin/* /usr/local/k9core/
.PHONY:
	clean objclean compile
