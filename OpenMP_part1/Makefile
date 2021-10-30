all: helloworld forsin mult pi
helloworld: 
	icc -O0 -qopenmp -o helloworld_c helloworld.c
	ifort -O0 -qopenmp -o helloworld_f helloworld.f90

forsin:
	icc -O0 -qopenmp -o forsin_c forsin.c -lm
	ifort -O0 -qopenmp -o forsin_f forsin.f90 -lm

mult:
	icc -O0 -qopenmp -o mult_c mult.c
	ifort -O0 -qopenmp -o mult_f mult.f90
pi:
	icc -O0 -qopenmp -o pi_c pi.c
	ifort -O0 -qopenmp -o pi_f pi.f90

clean:
	rm helloworld_c helloworld_f forsin_c forsin_f pi_c pi_f mult_c mult_f
