#include <iostream>
#include "include/db_operations.h"

void made_repairs(MYSQL* conn) {
    std::string query = "SELECT COUNT(*) AS liczba_napraw FROM zlecenia WHERE status_naprawy = 'Zakończona'";
    mysql_query(conn, query.c_str());
    MYSQL_RES* result = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(result);
    std::cout << "Liczba wykonanych napraw: " << row[0] << std::endl;
    mysql_free_result(result);
}

void Most_commonServices(MYSQL* conn) {
    std::string query = "SELECT u.nazwa_uslugi, COUNT(w.usluga_id) AS liczba FROM wyceny w JOIN uslugi u ON w.usluga_id = u.id_uslugi GROUP BY w.usluga_id ORDER BY liczba DESC LIMIT 5";
    mysql_query(conn, query.c_str());
    MYSQL_RES* result = mysql_store_result(conn);
    MYSQL_ROW row;
    std::cout << "Najczęściej wykonywane usługi:\n";
    while ((row = mysql_fetch_row(result))) {
        std::cout << row[0] << " - " << row[1] << " razy\n";
    }
    mysql_free_result(result);
}

void Most_Used_Parts(MYSQL* conn) {
    std::string query = "SELECT c.nazwa_czesci_zamiennej, COUNT(w.czesc_id) AS liczba FROM wyceny w JOIN Czesci_zamienne c ON w.czesc_id = c.id_czesci GROUP BY w.czesc_id ORDER BY liczba DESC LIMIT 5";
    mysql_query(conn, query.c_str());
    MYSQL_RES* result = mysql_store_result(conn);
    MYSQL_ROW row;
    std::cout << "Najczęściej używane części zamienne:\n";
    while ((row = mysql_fetch_row(result))) {
        std::cout << row[0] << " - " << row[1] << " razy\n";
    }
    mysql_free_result(result);
}

void Mechanics_ranking(MYSQL* conn) {
    std::string query = "SELECT m.imie, m.nazwisko, COUNT(zm.zlecenie_id) AS liczba FROM zlecenia_mechanicy zm JOIN mechanicy m ON zm.mechanik_id = m.id GROUP BY zm.mechanik_id ORDER BY liczba DESC LIMIT 5";
    mysql_query(conn, query.c_str());
    MYSQL_RES* result = mysql_store_result(conn);
    MYSQL_ROW row;
    std::cout << "Ranking mechaników:\n";
    while ((row = mysql_fetch_row(result))) {
        std::cout << row[0] << " " << row[1] << " - " << row[2] << " napraw\n";
    }
    mysql_free_result(result);
}


