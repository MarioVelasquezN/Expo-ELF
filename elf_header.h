#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <iostream>
#include <fstream>
#include <inttypes.h>
using namespace std;

#pragma pack(push,1)
struct ELF_HEADER{
    char E_ident[2];//estos 4 bytes constituyen el numero magico. //el tipo de ejecutable EI_NIDENT = 16 = size of e_ident[] | ET_EXEC=2=Executable file.
    uint32_t e_type;//Identifica el tipo de archivo.
    uint32_t e_machine;//si es de 32 o 64 bits//Especifica objetivo de la arquitectura del conjunto de instrucciones
    uint32_t e_version;//la version del ejecutable
    uint32_t e_entry;//el tipo de sistema operativo que espera
    // proporciona la direccion virtual a la que el sistema primero transfiere el control,si no tiene un punto de entrada asociando tiene cero.
    uint32_t e_phoff;// el tipo de procesador que espera//Este miembro contiene el desplazamiento del archivo de la tabla de encabezado del programa en bytes
    uint32_t e_shoff;// el tipo de ejecutable: core liberia, binario o un relocable
    uint32_t e_flags;//Este miembro contiene indicadores específicos del procesador asociados con el archivo.
    uint32_t e_ehsize;//Esta miembro tiene el tamaño del encabezado ELF en bytes. if 32bits es 52bytes.
    uint32_t e_phentsize;//Este miembro tiene el tamaño en bytes de una entrada en la tabla de encabezado del programa del archivo.
    uint32_t e_phnum;//Este miembro contiene el número de entradas en la tabla de encabezado del programa. 
    //Por lo tanto, el producto ofe_phentsizeande_phnum da el tamaño de la tabla en bytes. 
    //Si un archivo no tiene una tabla de encabezado de programa, e_phnumholds el valor cero.
    uint32_t e_shentsize;//
    uint32_t e_shnum;//
    uint32_t e_shstrndx;//

};
#pragma pack(pop);

class MyELF{
private:
    char* file_name;
    ifstream file_elf;
    ELF_HEADER reg_header;

    void ReadHeader();

public:
    void openELF(const char*);
    void print_header();
};

#endif
