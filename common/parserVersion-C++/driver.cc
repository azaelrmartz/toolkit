#include "driver.hh"
#include "parser.hh"


octetos::toolkit::Version& driver::getVersion()
{
    return *version;
}
driver::driver (octetos::toolkit::Version& version)
  : trace_parsing (false), trace_scanning (false)
{
  variables["one"] = 1;
  variables["two"] = 2;
  this->version = &version;
}

int
driver::parse (const std::string &f)
{
  file = f;
  location.initialize (&file);
  scan_begin ();
  yy::parser parse (*this);
  parse.set_debug_level (trace_parsing);
  int res = parse ();
  scan_end ();
  return res;
}
