#include "elf_header.h"
#include <stdio.h>
#include <fstream>
using namespace std;

int main()
{
    MyELF e;
    char filename_elf[20];
    cout<<"ELF file: "<<flush;
    cin>>filename_elf;

    e.openELF(filename_elf);
    e.print_header();

    return 0;
}
