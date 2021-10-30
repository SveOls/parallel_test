#include "omp.h"
#include <stdio.h>
int main(int argc , char **argv) 
{
   int isHost = 0;
   int numDevices=0;
   int numTeams=0;
  
   // To check GPU devices is connected from main board  
   isHost = omp_is_initial_device(); 
   numDevices=omp_get_num_devices();

   // Get number of teams on GPU
   numTeams=omp_get_num_teams();
   

   if (isHost < 0) 
   {
     printf("Runtime error, isHost=%d\n", isHost);
   }
   else
     printf("Number of devices %d and teams %d\n", numDevices,numTeams);
  
   return isHost;    
	
}
