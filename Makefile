a.out:
	gcc multithreadsol.c

clean:
	rm hello

testavg: a.out
	bash testavg.sh
	
testmin: a.out
	bash testmin.sh
	
testmax: a.out
	bash testmax.sh
