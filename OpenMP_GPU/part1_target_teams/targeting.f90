
program targeting
implicit none

integer::isHost
integer::numDevices
integer::numTeams
integer::omp_is_initial_device
integer::omp_get_num_devices
integer::omp_get_num_teams  

 isHost=0
 numDevices=0
 numTeams=0

! To check GPU devices is connected from main board  
  isHost = omp_is_initial_device()
  numDevices=omp_get_num_devices()

! Get number of teams on GPU
  numTeams=omp_get_num_teams()

  if (isHost < 0) then
     write(6,*) 'Runtime error, isHost= ', isHost
  else
     write(6,*) 'Number of devices ',numDevices
     write(6,*) 'Number of teams ',numTeams
  end if
   
	
end program targeting
