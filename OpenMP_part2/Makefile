all: sec_helloworld sections task_linkedlist task_fib task_array hybrid_helloworld hybrid_pi

sec_helloworld: sec_helloworld.c sec_helloworld.f90
	icc -O0 -qopenmp -o sec_helloworld_c sec_helloworld.c
	ifort -O0 -qopenmp -o sec_helloworld_f sec_helloworld.f90

sections: sections.c sections.f90
	icc -O0 -qopenmp -o sections_c sections.c -lm
	ifort -O0 -qopenmp -o sections_f sections.f90 -lm 

task_linkedlist: task_linkedlist.c task_linkedlist.f90
	icc -O0 -qopenmp -o task_linkedlist_c task_linkedlist.c
	ifort -O0 -qopenmp -o task_linkedlist_f task_linkedlist.f90

task_fib: task_fib.c task_fib.f90
	icc -O0 -qopenmp -o task_fib_c task_fib.c
	ifort -O0 -qopenmp -o task_fib_f task_fib.f90

task_array: task_array.c task_array.f90
	icc -O0 -qopenmp -o task_array_c task_array.c
	ifort -O0 -qopenmp -o task_array_f task_array.f90

hybrid_helloworld: hybrid_helloworld.c hybrid_helloworld.f90
	mpiicc -O0 -qopenmp -o hybrid_helloworld_c hybrid_helloworld.c 
	mpiifort -O0 -qopenmp -o hybrid_helloworld_f hybrid_helloworld.f90 

hybrid_pi: hybrid_pi.c hybrid_pi.f90
	mpiicc -O0 -qopenmp -o hybrid_pi_c hybrid_pi.c -lm
	mpiifort -O0 -qopenmp -o hybrid_pi_f hybrid_pi.f90 -lm
      
clean:
	rm -f sec_helloworld_c sec_helloworld_f sections_c sections_f task_fib_c task_fib_f task_array_c task_array_f hybrid_helloworld_c hybrid_helloworld_f hybrid_pi_c hybrid_pi_f task_linkedlist_c task_linkedlist_f
