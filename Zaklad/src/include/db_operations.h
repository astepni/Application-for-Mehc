#ifndef DB_OPERATIONS_H
#define DB_OPERATIONS_H

#include "mysql/mysql.h"
#include <string>

MYSQL* connectToDatabase(const char* host, const char* user, const char* password, const char* dbname);
bool updateClient(int client_id, const char* new_name, const char* new_surname, const char* new_phone);
bool addClient(const char* name , const char* surname, const char* phone_number);
bool updateMechanic(int mechanic_id, const char* new_name, const char* new_surname);
bool addMechanic(const char* name , const char* surname);
bool ShowClientsormechanics(const char* who);
bool DeleteFromDb(int id, const char* fromwhere, const char* type_id);
bool add_an_order(int id_mechanic, int id_zlecenia,const char* what);
bool valuations(int clientId);
bool getfromdb(const char* what, const char* fromwhere, const char* circum);
bool car_info(const char* phonenumber);
struct connection{
    std::string host ="localhost";
    std::string user ="root";
    std::string password= "Margonem96";
    std::string dbname = "Zaklad_mechaniczny";
};

/* Funkcje to formatowania wyświetlania danych etc */
void Menu(void);
void clearTerminal(void);
/* Funkcje do statystyki*/

void made_repairs(MYSQL* conn);
void Most_commonServices(MYSQL* conn);
void Most_Used_Parts(MYSQL* conn);
void Mechanics_ranking(MYSQL* conn);
#endif