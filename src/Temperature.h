// This is start of the header guard.  ADD_H can be any unique name.  By convention, we use the name of the header file.
#ifndef TEMPERATURE
#define TEMPERATURE
#include <OneWire.h>

// This is the content of the .h file, which is where the declarations go
String getTemperature(OneWire ds); // function prototype for add.h -- don't forget the semicolon!

// This is the end of the header guard
#endif
