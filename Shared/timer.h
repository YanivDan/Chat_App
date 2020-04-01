#include <iostream>
#include <ctime>

using namespace std;

string GetTimeLocal() {
   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);
   string s(dt);
   return s.substr (11,24);
}