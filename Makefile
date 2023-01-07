a.out:
	gcc multithreadsol.c

clean:
	rm hello

test: a.out
	bash testavg.sh
