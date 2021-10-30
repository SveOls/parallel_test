default: 
	gcc -O2 -fopenmp -DOPENMP -foffload=nvptx-none -Wall -o array2_c array2.c
	gfortran -O2 -fopenmp -DOPENMP -foffload=nvptx-none -Wall -o array2_f array2.f90
clean: 
	rm array2_c array2_f
