#include <iostream>
#include "driver.hh"

int
main (int argc, char *argv[])
{
   octetos::toolkit::Version ver;    
  int res = 0;
  driver drv(ver);
  for (int i = 1; i < argc; ++i)
    if (argv[i] == std::string ("-p"))
      drv.trace_parsing = true;
    else if (argv[i] == std::string ("-s"))
      drv.trace_scanning = true;
    else if (!drv.parse (argv[i]))
      std::cout << ver.toString()<< '\n';
    else
      res = 1;
  return res;
}
