default: 
	gcc -O2 -fopenmp -DOPENMP -foffload=nvptx-none -Wall -o targeting_c targeting.c
	gfortran -O2 -fopenmp -DOPENMP -foffload=nvptx-none -Wall -o targeting_f targeting.f90
clean: 
	rm targeting_c targeting_f
