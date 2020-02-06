#include "elf_header.h"
#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <limits>

using namespace std;

void MyELF::ReadHeader(){
file_elf.seekg(0,ios_base::beg);
file_elf.read((char *)&reg_header,sizeof(reg_header));
}

void MyELF::openELF(const char * fn){
    file_name=(char*)fn;
    file_elf.open(fn,ifstream::in | ifstream::binary);
    ReadHeader();
}

void MyELF::print_header(){
    char type[3];

    type[0]=reg_header.E_ident[0];
    type[1]=reg_header.E_ident[1];
    type[2]=reg_header.E_ident[2];
    type[3]='\0';

    cout<<"********************************************"<<endl;
    cout<<"Tipo: "<<reg_header.e_type<<endl;
    cout<<"Maquina: "<<reg_header.e_machine<<endl;
    cout<<"Version: "<<reg_header.e_version<<endl;
    cout<<"Entry: "<<reg_header.e_entry<<endl;
    cout<<"Phoff: "<<reg_header.e_phoff<<endl;
    cout<<"Shoff: "<<reg_header.e_shoff<<endl;
    cout<<"Flags: "<<reg_header.e_flags<<endl;
    cout<<"Ehsize: "<<reg_header.e_ehsize<<endl;
    cout<<"Phentsize: "<<reg_header.e_phentsize<<endl;
    cout<<"Phnum: "<<reg_header.e_phnum<<endl;
    cout<<"Shentsize: "<<reg_header.e_shentsize<<endl;
    cout<<"Shnum: "<<reg_header.e_shnum<<endl;
    cout<<"Shstrndx: "<<reg_header.e_shstrndx<<endl;
}
