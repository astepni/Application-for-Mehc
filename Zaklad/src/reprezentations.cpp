#include <iostream>
#include "include/db_operations.h"
#include <cstdlib>


void Menu(void){
    std::cout<< "+---------------------------------------------------------------------------+"<<std::endl;
    std::cout<< "| /Witamy w zakładzie mechanicznym , prosimy o wybór opcji/                 |"<<std::endl;
    std::cout<< "| -Podgląd kartotek Klientów oraz Mechaników                           [1]  |"<<std::endl;
    std::cout<< "| -Edycja Kartoteki Klientów i Mechaników                              [2]  |"<<std::endl;
    std::cout<< "| -Przypisz mechaników do zlecenia                                     [3]  |"<<std::endl;
    std::cout<< "| -Podgląd napływających zleceń                                        [4]  |"<<std::endl;
    std::cout<< "| -Wyceny zleceń                                                       [5]  |"<<std::endl;
    std::cout<< "| -Wyszukaj potrzebne części w kartotece części zastępczych            [6]  |" <<std::endl;
    std::cout<< "| -Sprawdz historie napraw samochodu klienta po jego numerze telefonu  [7]  |" <<std::endl;
    std::cout<< "| -Pokaż dane statystyczne dla bazy danych                             [8]  |" <<std::endl;
    std::cout<< "+---------------------------------------------------------------------------+"<<std::endl;
    
}


void clearTerminal(void){

    int returnC;
    
    #ifdef _WIN32
        returnC = system("cls");
    #else
        returnC = system("clear");
    #endif
    
    if(returnC!=0)
        std::cerr<<"unable to clear termianl"<<std::endl;
    
    
}