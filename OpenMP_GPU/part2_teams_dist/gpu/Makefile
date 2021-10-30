default: 
	gcc -O2 -fopenmp -DOPENMP -foffload=nvptx-none -Wall -o array1_c array1.c
	gfortran -O2 -fopenmp -DOPENMP -foffload=nvptx-none -Wall -o array1_f array1.f90
clean: 
	rm array1_c array1_f
