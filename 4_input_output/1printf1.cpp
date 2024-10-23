//dessa forma consigo usar a linguagem C dentro do C++ puxando suas bibliotecas.
#include <iostream>
extern "C" {
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
};