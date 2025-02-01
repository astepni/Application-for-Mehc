#include <iostream>
#include <ostream>
#include "include/db_operations.h"

int main() {
    int choice;
    std::string T= "tak";
    
    while (T == "tak"){
        clearTerminal();
        Menu();
        std::cout<<"wybierz operacje dostepne powyżej"<<std::endl;
        std::cin>>choice;
        std::string handler = "";
        switch (choice){
            case 1:{
                
                std::cout<<"Którą kartotekę chcesz podejżeć M-mechanicy K-klienci?"<<std::endl;
                std::cin>>handler;
                if (handler=="M"){
                    ShowClientsormechanics("mechanicy");
                }else if(handler=="K"){
                    ShowClientsormechanics("Klienci");
                }
                break;
            }
            case 2:{
                std::cout<<"Z jakiej kartoteki chcesz korzystać przy edycji M-mechanicy K-klienci?"<<std::endl;
                std::cin>>handler;
                int option;
                std::string imie = "";
                std::string nazwisko = "";
                int id;
                if (handler=="M"){    
                    std::cout<<"1-dodanie , 2-uaktualnienie"<<std::endl;
                    std::cin>>option;
                    
                    switch (option) {
                        case 1:
                            ShowClientsormechanics("mechanicy");
                            std::cout<<"\npodaj imie mechanika"<<std::endl;
                            std::cin>> imie;
                            std::cout<<"\npodaj nazwisko mechanika"<<std::endl;
                            std::cin>> nazwisko;
                            addMechanic(imie.c_str(), nazwisko.c_str());
                            ShowClientsormechanics("mechanicy");
                            break;
                            /* 
                        case 2:
                            ShowClientsormechanics("mechanicy");
                            std::cout<<"\npodaj id mechanika którego chcesz usunąć"<<std::endl;
                            std::cin>>id;
                            DeleteFromDb(id, "mechanicy", "id");
                            ShowClientsormechanics("mechanicy");
                            break;
                           */
                        case 2:
                            ShowClientsormechanics("mechanicy");
                            std::cout<<"\njeśli chcesz zachować poprzednie dane , to wpisz stare infromacje"<<std::endl;
                            std::cout<<"\npodaj nowe imie mechanika"<<std::endl;
                            std::cin>> imie;
                            std::cout<<"\npodaj nowe nazwisko mechanika"<<std::endl;
                            std::cin>> nazwisko;
                            std::cout<<"\npodaj id mechanika którego dane chcesz zmienić"<<std::endl;
                            std::cin>>id;
                            updateMechanic(id, imie.c_str(), nazwisko.c_str());
                            ShowClientsormechanics("mechanicy");
                            break;
                        default:
                            break;
                         
                    }
                }else if(handler=="K"){
                    
                    std::cout<<"1-dodanie , 2-uaktualnienie"<<std::endl;
                    std::cin>>option;
                    std::string imie = "";
                    std::string nazwisko = "";
                    std::string nr_telefonu = "";
                    int id;
                    switch (option) {
                        case 1:
                            ShowClientsormechanics("Klienci");
                            std::cout<<"\npodaj imie klienta"<<std::endl;
                            std::cin>> imie;
                            std::cout<<"\npodaj nazwisko klienta"<<std::endl;
                            std::cin>> nazwisko;
                            std::cout<<"\npodaj nr_telefonu klienta"<<std::endl;
                            std::cin>> nr_telefonu;
                            addClient(imie.c_str(), nazwisko.c_str(), nr_telefonu.c_str());
                            ShowClientsormechanics("Klienci");
                            break;
                        case 2:
                            ShowClientsormechanics("Klienci");
                            std::cout<<"\njeśli chcesz zachować poprzednie dane , to wpisz stare infromacje"<<std::endl;
                            std::cout<<"\npodaj nowe imie Klienta"<<std::endl;
                            std::cin>> imie;
                            std::cout<<"\npodaj nowe nazwisko Klienta"<<std::endl;
                            std::cin>> nazwisko;
                            std::cout<<"\npodaj nowe nr_telefonu Klienta"<<std::endl;
                            std::cin>> nr_telefonu;
                            std::cout<<"\npodaj id Klienta którego dane chcesz zmienić"<<std::endl;
                            std::cin>>id;
                            updateClient(id, imie.c_str(), nazwisko.c_str(), nr_telefonu.c_str());
                            ShowClientsormechanics("Klienci");
                            break;
                        default:
                            break;
                         
                    }
                }
                break;
            }
            case 3:{
                int id_m , id_z;
                ShowClientsormechanics("zlecenia");
                ShowClientsormechanics("mechanicy");
                ShowClientsormechanics("zlecenia_mechanicy");
                std::cout<<"\nPo wyżej widoczne są dostępne zlecenia oraz mechanicy, możesz przypisać mechanika do więcej niż jednego zlecenia"<<std::endl;
                std::cout<<"podaj id zlecenia"<<std::endl;
                std::cin>>id_z;
                std::cout<<"podaj id mechanika"<<std::endl;
                std::cin>>id_m;
                if(add_an_order(id_m, id_z, "Edition")){
                    std::cout<<"Przypisano mechanika do zlecenia"<<std::endl;
                    ShowClientsormechanics("zlecenia_mechanicy");
                }
                /*
                std::cout<<"\n Chcesz może przypisać innego mechanika do jakiegoś zlecenia? wpisz id zlecenia do którego chcesz zmienić powinnictwo, jeśli nie chcesz wpisz 0"<<std::endl;
                std::cin>>id_z;
                
                if (id_z!=0){
                    std::cout<<"\n Wpisz id mechanika"<<std::endl;
                    std::cin>>id_z;
                    add_an_order(id_m, id_z, "UPdate");
                }
                */

                break;
            }
            case 4:
                ShowClientsormechanics("zlecenia");
                break;
            case 5:{
                int id_k;
                std::cout<<"wpisz id klienta dla którego chcesz uzyskać wycene"<<std::endl;
                std::cin>>id_k;
                valuations(id_k);
                break;
            }
            case 6:{
                std::string marka;
                std::cout<<"części do jakiej marki samochodu potrzebujesz?"<<std::endl;
                std::cin>>marka;
                getfromdb("marka_pojazdu","Czesci_zamienne",marka.c_str());
            }
            case 7:{
                std::string nr_tel;
                std::cout<<"jeśli chcesz możesz uzyskać historie napraw samochodu , podaj numer telefonu klienta którego samochód chcesz sprawdzić "<<std::endl;
                ShowClientsormechanics("Klienci");
                std::cin>>nr_tel;
                
                car_info(nr_tel.c_str());
                break;
            }
            case 8:{
                MYSQL* conn = connectToDatabase("localhost", "root", "Margonem96", "Zaklad_mechaniczny");
                std::cout<<"Dane statystyczne dla zakładu mechanicznego"<<std::endl;
                std::cout<<"+---------------------------+"<<std::endl;
                made_repairs(conn);
                std::cout<<"+---------------------------+"<<std::endl;
                Most_commonServices(conn);
                std::cout<<"+---------------------------+"<<std::endl;
                Most_Used_Parts(conn);
                std::cout<<"+---------------------------+"<<std::endl;
                Mechanics_ranking(conn);
                std::cout<<"+---------------------------+"<<std::endl;
                break;
            }
        }

        std::cout<<"chcesz kontynuować operacje ?"<<std::endl;
        std::cin>>T;
    }




    return 0;
}

