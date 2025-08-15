build:
	if [[ ! -d target ]]; then mkdir target; fi
	clang -c vec.c -o target/vec.o -std=c23
	ar r target/libvec.a target/vec.o

clean:
	rm -rf target
