#include "include/db_operations.h"
#include "include/mysql/mysql.h"
#include <iostream>
#include <string>

struct connection C;


MYSQL* connectToDatabase(const char* host, const char* user, const char* password, const char* dbname) {
    MYSQL *conn = mysql_init(0);
    if (conn == NULL) {
        std::cerr << "MySQL initialization failed." << std::endl;
        return nullptr;
    }
    
    conn = mysql_real_connect(conn, host, user, password, dbname, 0, NULL, 0);
    if (conn == NULL) {
        std::cerr << "Connection failed: " << mysql_error(conn) << std::endl;
        return nullptr;
    }

    return conn;
}

bool updateClient(int client_id, const char* new_name, const char* new_surname, const char* new_phone) {
    MYSQL* conn = connectToDatabase("localhost", "root", "Margonem96", "Zaklad_mechaniczny");
    if (conn == NULL) {
        return false;
    }

    std::string query = "UPDATE Klienci SET imie = '" + std::string(new_name) + "', nazwisko = '" + std::string(new_surname) + "', nr_telefonu = '" + std::string(new_phone) + "' WHERE id_klienta = " + std::to_string(client_id);

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Error updating client: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return false;
    }

    std::cout << "Client updated successfully." << std::endl;
    mysql_close(conn);
    return true;
}

bool updateMechanic(int mechanic_id, const char* new_name, const char* new_surname) {
    MYSQL* conn = connectToDatabase("localhost", "root", "Margonem96", "Zaklad_mechaniczny");
    if (conn == NULL) {
        return false;
    }

    std::string query = "UPDATE mechanicy SET imie = '" + std::string(new_name) + "', nazwisko = '" + std::string(new_surname) + "' WHERE id = " + std::to_string(mechanic_id);

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Error updating Mechanic: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return false;
    }

    std::cout << "Mechanic updated successfully." << std::endl;
    mysql_close(conn);
    return true;
}




bool ShowClientsormechanics(const char* who){
    MYSQL* conn = connectToDatabase(C.host.c_str(), C.user.c_str(), C.password.c_str(), C.dbname.c_str());
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (conn == NULL) {
        return false;
    }

    std::string query = "SELECT * FROM "+std::string(who)+";";
    if(mysql_query(conn, query.c_str())){
        std::cerr <<"Failed to proceed query"<< std::endl;
        mysql_close(conn);
        return false;
    }
    res = mysql_store_result(conn);
    if (res==NULL){
        std::cerr<<"Failed to download result"<<mysql_error(conn)<<std::endl;
        return false;
    }
    int num_fields = mysql_num_fields(res);
    std::cout<<"+--------------------------+"<<std::endl;
    while((row = mysql_fetch_row(res))){
        
        for (int i = 0 ; i < num_fields;i++){
            if (row[i] == NULL){
                std::cout<<"NULL ";
            }else{
                std::cout<< std::string(row[i])<< " ";
            }
        }
        std::cout <<std::endl;
    }
    std::cout<<"+---------------------------+"<<std::endl;
    mysql_free_result(res);
    mysql_close(conn);
    return true;

}

bool addClient(const char* name , const char* surname, const char* phone_number){
    MYSQL* conn = connectToDatabase("localhost", "root", "Margonem96", "Zaklad_mechaniczny");
    
    if (conn == NULL) {
        return false;
    }
    std::string query = "INSERT INTO Klienci (imie , nazwisko , nr_telefonu) VALUES('"+std::string(name)+"', '"+std::string(surname)+"', '"+std::string(phone_number)+"' );";
    if(mysql_query(conn, query.c_str())){
        std::cerr <<"Failed to proceed query"<< std::endl;
        mysql_close(conn);
        return false;
    }

    mysql_close( conn);

    return true;
}

bool addMechanic(const char* name , const char* surname){
    MYSQL* conn = connectToDatabase("localhost", "root", "Margonem96", "Zaklad_mechaniczny");
    
    if (conn == NULL) {
        return false;
    }
    std::string query = "INSERT INTO mechanicy (imie , nazwisko) VALUES('"+std::string(name)+"', '"+std::string(surname)+"' );";
    if(mysql_query(conn, query.c_str())){
        std::cerr <<"Failed to proceed query"<< std::endl;
        mysql_close(conn);
        return false;
    }

    mysql_close( conn);

    return true;
}


bool DeleteFromDb(int id, const char* fromwhere ,const char* type_id){
    MYSQL* conn = connectToDatabase("localhost", "root", "Margonem96", "Zaklad_mechaniczny");
    
    if (conn == NULL) {
        return false;
    }
    std::string query = "DELETE FROM " + std::string(fromwhere) + " WHERE " + std::string(type_id) +" = '"+std::to_string(id) +"';";
    std::cout<<query<<std::endl;
    if(mysql_query(conn, query.c_str())){
        std::cerr <<"Failed to proceed query"<< std::endl;
        mysql_close(conn);
        return false;
    }

    mysql_close( conn);

    return true;
}


bool add_an_order(int id_mechanic, int id_zlecenia , const char* what){
    MYSQL* conn = connectToDatabase("localhost", "root", "Margonem96", "Zaklad_mechaniczny");
    std::string query = "";

    if (conn == NULL) {
        return false;
    }
    if (std::string(what) == "Edition"){
       query= "INSERT INTO zlecenia_mechanicy (zlecenie_id, mechanik_id) VALUES ('"+std::to_string(id_zlecenia)+"','"+std::to_string(id_mechanic)+"');";
    }else if(std::string(what) == "UPdate"){
       query= "UPDATE  zlecenia_mechanicy  SET mechanik_id = '"+std::to_string(id_mechanic)+"' WHERE zlecenie_id = '"+std::to_string(id_zlecenia)+";"; 
       std::cout<<query;
    }
    if(mysql_query(conn, query.c_str())){
        std::cerr <<"Failed to proceed query"<< std::endl;
        mysql_close(conn);
        return false;
    }

    mysql_close( conn);

    return true;
}


bool valuations(int clientId) {
    MYSQL *conn =connectToDatabase(C.host.c_str(), C.user.c_str(), C.password.c_str(), C.dbname.c_str());
    MYSQL_RES *res;
    MYSQL_ROW row;

    
    std::string query = 
        "SELECT k.id_klienta, k.imie, k.nazwisko, z.id AS id_zlecenia, z.opis, "
        "cz.nazwa_czesci_zamiennej, w.cena_czesci, u.nazwa_uslugi, w.cena_uslugi, "
        "(IFNULL(w.cena_czesci, 0) + IFNULL(w.cena_uslugi, 0)) AS laczna_cena "
        "FROM Klienci k "
        "JOIN zlecenia z ON k.id_klienta = z.id_klienta "
        "LEFT JOIN wyceny w ON z.id = w.zlecenie_id "
        "LEFT JOIN Czesci_zamienne cz ON w.czesc_id = cz.id_czesci "
        "LEFT JOIN uslugi u ON w.usluga_id = u.id_uslugi "
        "WHERE k.id_klienta = " + std::to_string(clientId) + ";";

    
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Błąd zapytania: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return false ;
    }

    
    res = mysql_store_result(conn);
    if (res == NULL) {
        std::cerr << "Błąd pobierania wyników: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return false ;
    }

    
    int num_fields = mysql_num_fields(res);
    
    /*
    std::cout << "+------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    std::cout << "| ID Klienta | Imię   | Nazwisko | ID Zlecenia | Opis         | Część            | Cena Części |          Usługa        |      Cena Usługi      |      Łączna Cena |\n";
    std::cout << "+------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    */
    
    std::cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            if (row[i] == NULL)
                std::cout << "NULL\t";
            else
                if (i == num_fields-1)
                    std::cout << "|"+std::string(row[i]) +"<- całkowity koszt|"<< "\t";
                else
                    std::cout << "|"+std::string(row[i]) +"|"<< "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";

    
    mysql_free_result(res);
    mysql_close(conn);


    return true;
}



bool getfromdb(const char* what , const char* fromwhere, const char* circum){
    MYSQL* conn = connectToDatabase(C.host.c_str(), C.user.c_str(), C.password.c_str(), C.dbname.c_str());
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (conn == NULL) {
        return false;
    }

    std::string query = "SELECT * FROM "+std::string(fromwhere)+" WHERE "+std::string(what)+" = '"+std::string(circum)+"';";
    if(mysql_query(conn, query.c_str())){
        std::cerr <<"Failed to proceed query"<< std::endl;
        mysql_close(conn);
        return false;
    }
    res = mysql_store_result(conn);
    if (res==NULL){
        std::cerr<<"Failed to download result"<<mysql_error(conn)<<std::endl;
        return false;
    }
    int num_fields = mysql_num_fields(res);
    std::cout<<"+--------------------------+"<<std::endl;
    while((row = mysql_fetch_row(res))){
        
        for (int i = 0 ; i < num_fields;i++){
            if (row[i] == NULL){
                std::cout<<"NULL ";
            }else{
                std::cout<< std::string(row[i])<< " ";
            }
        }
        std::cout <<std::endl;
    }
    std::cout<<"+---------------------------+"<<std::endl;
    mysql_free_result(res);
    mysql_close(conn);
    return true;

}

bool car_info(const char* phonenumber){
    MYSQL* conn = connectToDatabase(C.host.c_str(), C.user.c_str(), C.password.c_str(), C.dbname.c_str());
    MYSQL_RES *res;
    MYSQL_ROW row;

    std::string query ="SELECT "
    "k.id_klienta, "
    "k.imie, "
    "k.nazwisko, "
    "k.nr_telefonu, "
    "p.marka_pojazdu, "
    "z.id AS id_zlecenia, "
    "z.opis AS opis_naprawy, "
    "z.status_naprawy, "
    "z.data_zlecenia "
    "FROM Klienci k "
    "JOIN pojazdy p ON k.id_klienta = p.id_klienta "
    "JOIN zlecenia z ON p.id_zlecenia = z.id "
    "WHERE k.nr_telefonu = '"+std::string(phonenumber)+"';";
    //std::cout<<query;
    if(mysql_query(conn, query.c_str())){
        std::cerr <<"Failed to proceed query"<< std::endl;
        mysql_close(conn);
        return false;
    }
    res = mysql_store_result(conn);
    if (res==NULL){
        std::cerr<<"Failed to download result"<<mysql_error(conn)<<std::endl;
        return false;
    }
    int num_fields = mysql_num_fields(res);
    std::cout<<"+--------------------------+"<<std::endl;
    while((row = mysql_fetch_row(res))){
        
        for (int i = 0 ; i < num_fields;i++){
            if (row[i] == NULL){
                std::cout<<"NULL ";
            }else{
                std::cout<< std::string(row[i])<< " ";
            }
        }
        std::cout <<std::endl;
    }
    std::cout<<"+---------------------------+"<<std::endl;
    mysql_free_result(res);
    mysql_close(conn); 
    return 0;

}