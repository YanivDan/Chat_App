#include <iostream>
#include <sys/time.h>
using namespace std;


string Get_time_to_present(){
    // Declaring argument of time() - to print it with the msg
    time_t my_time = time(NULL); 

    // Return the time
    char a = time(&my_time);
}
