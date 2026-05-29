

<!-- <style>
 p,li {
    font-size: 12pt;
  }
</style>  -->

<!-- <style>
 pre {
    font-size: 8pt;
  }
</style>  -->

**Temat:** Warsztat samochodowy

**Autorzy:** Mikołaj Stolarczyk i Damian Nieśmiałowski 

--- 

# 1.  Zakres i krótki opis systemu

Zakres i krótki opis systemu

System obejmuje kompleksową obsługę warsztatu samochodowego zajmującego się **diagnostyką, naprawą oraz serwisowaniem pojazdów**. Jego głównym celem jest usprawnienie organizacji pracy warsztatu, zarządzania klientami i pojazdami oraz kontrolowania **przebiegu realizacji usług od momentu przyjęcia samochodu aż do jego wydania właścicielowi.**

Proces działania systemu rozpoczyna się od rejestracji klienta oraz pojazdu w bazie danych. Następnie pracownik warsztatu tworzy zlecenie naprawy, w którym zapisywane są zgłoszone usterki, data przyjęcia pojazdu oraz przewidywany termin realizacji usługi. Kolejnym etapem jest przeprowadzenie diagnostyki pojazdu, podczas której mechanik identyfikuje problemy techniczne i określa zakres koniecznych napraw.

Po zatwierdzeniu naprawy system umożliwia przypisanie zadań mechanikom, monitorowanie postępu prac oraz aktualizowanie statusu zlecenia. Po zakończeniu usługi generowany jest rachunek lub faktura zawierająca wykonane czynności oraz wykorzystane części zamienne.

System przechowuje również historię serwisową pojazdów, dzięki czemu możliwe jest sprawdzenie wcześniejszych napraw, wymienionych części i dat wizyt klienta w warsztacie. Pozwala to na lepszą organizację pracy oraz szybszą obsługę klientów w przyszłości.

# 2.	Wymagania i funkcje systemu

System powinien umożliwiać:

- rejestrację klientów i pojazdów,
- przechowywanie danych kontaktowych klientów,
- przyjmowanie pojazdów do warsztatu,
- tworzenie i edycję zleceń naprawy,
- prowadzenie diagnostyki pojazdów,
- przypisywanie zadań mechanikom,
- zarządzanie realizacją usług serwisowych,
- śledzenie statusu napraw,
- ewidencję części zamiennych wykorzystanych podczas napraw,
- określanie kosztów usług i części,
- wystawianie rachunków lub faktur,
- informowanie o terminie odbioru pojazdu,
- przegląd historii serwisowej pojazdów,
- wyszukiwanie klientów, pojazdów i zleceń,
- generowanie podstawowych raportów dotyczących wykonanych usług i napraw.

# 3.	Projekt bazy danych

## Schemat bazy danych

<img width="1681" height="860" alt="873db2fb-c16d-4d2f-88cb-fe46325e36e2" src="https://github.com/user-attachments/assets/0c5d571a-ef37-457b-a9dc-44f5ecc458a1" />

## Opis poszczególnych tabel

### Nazwa tabeli: suppliers

Opis: Tabela przechowująca dane dostawców części i materiałów do warsztatu.

| Nazwa atrybutu | Typ          | Opis/Uwagi                           |
| -------------- | ------------ | ------------------------------------ |
| supplier_id    | INT          | Klucz główny, identyfikator dostawcy |
| company_name   | VARCHAR(100) | Nazwa firmy dostawcy                 |
| contact_person | VARCHAR(100) | Osoba kontaktowa                     |
| phone          | VARCHAR(20)  | Numer telefonu                       |
| email          | VARCHAR(100) | Adres e-mail                         |
| address        | VARCHAR(255) | Adres dostawcy                       |
| nip            | VARCHAR(15)  | Numer NIP dostawcy                   |
| created_at     | DATETIME     | Data dodania rekordu                 |



### Nazwa tabeli: clients

Opis: Tabela przechowująca dane klientów warsztatu.

| Nazwa atrybutu | Typ          | Opis/Uwagi                          |
| -------------- | ------------ | ----------------------------------- |
| client_id      | INT          | Klucz główny, identyfikator klienta |
| first_name     | VARCHAR(50)  | Imię klienta                        |
| last_name      | VARCHAR(50)  | Nazwisko klienta                    |
| phone          | VARCHAR(20)  | Numer telefonu                      |
| email          | VARCHAR(100) | Adres e-mail                        |
| address        | VARCHAR(255) | Adres zamieszkania                  |
| postal_code    | VARCHAR(10)  | Kod pocztowy                        |
| city           | VARCHAR(50)  | Miasto                              |
| created_at     | DATETIME     | Data dodania klienta                |



### Nazwa tabeli: employees

Opis: Tabela przechowująca dane pracowników warsztatu.

| Nazwa atrybutu | Typ           | Opis/Uwagi                             |
| -------------- | ------------- | -------------------------------------- |
| employee_id    | INT           | Klucz główny, identyfikator pracownika |
| first_name     | VARCHAR(50)   | Imię pracownika                        |
| last_name      | VARCHAR(50)   | Nazwisko pracownika                    |
| position       | VARCHAR(50)   | Stanowisko                             |
| phone          | VARCHAR(20)   | Numer telefonu                         |
| email          | VARCHAR(100)  | Adres e-mail                           |
| salary         | DECIMAL(10,2) | Wynagrodzenie                          |
| hire_date      | DATE          | Data zatrudnienia                      |
| status         | VARCHAR(30)   | Status pracownika                      |



### Nazwa tabeli: vehicles

Opis: Tabela przechowująca dane pojazdów klientów.

| Nazwa atrybutu      | Typ         | Opis/Uwagi                          |
| ------------------- | ----------- | ----------------------------------- |
| vehicle_id          | INT         | Klucz główny, identyfikator pojazdu |
| client_id           | INT         | Klucz obcy do tabeli clients_zad    |
| brand               | VARCHAR(50) | Marka pojazdu                       |
| model               | VARCHAR(50) | Model pojazdu                       |
| year                | INT         | Rok produkcji                       |
| engine              | VARCHAR(50) | Typ silnika                         |
| fuel_type           | VARCHAR(30) | Rodzaj paliwa                       |
| vin                 | VARCHAR(50) | Numer VIN                           |
| registration_number | VARCHAR(20) | Numer rejestracyjny                 |
| mileage             | INT         | Aktualny przebieg                   |



### Nazwa tabeli: services

Opis: Tabela przechowująca usługi oferowane przez warsztat.

| Nazwa atrybutu | Typ           | Opis/Uwagi                         |
| -------------- | ------------- | ---------------------------------- |
| service_id     | INT           | Klucz główny, identyfikator usługi |
| name           | VARCHAR(100)  | Nazwa usługi                       |
| description    | VARCHAR(255)  | Opis usługi                        |
| price          | DECIMAL(10,2) | Cena usługi                        |
| estimated_time | INT           | Szacowany czas wykonania           |
| is_active      | BIT           | Status aktywności usługi           |



### Nazwa tabeli: car_parts

Opis: Tabela przechowująca części samochodowe znajdujące się w magazynie warsztatu.

| Nazwa atrybutu    | Typ           | Opis/Uwagi                         |
| ----------------- | ------------- | ---------------------------------- |
| part_id           | INT           | Klucz główny, identyfikator części |
| name              | VARCHAR(100)  | Nazwa części                       |
| category          | VARCHAR(50)   | Kategoria części                   |
| manufacturer      | VARCHAR(100)  | Producent części                   |
| part_number       | VARCHAR(50)   | Numer katalogowy części            |
| quantity_in_stock | INT           | Ilość na stanie                    |
| purchase_price    | DECIMAL(10,2) | Cena zakupu                        |
| selling_price     | DECIMAL(10,2) | Cena sprzedaży                     |
| supplier_id       | INT           | Klucz obcy do tabeli suppliers_zad |
| location          | VARCHAR(100)  | Lokalizacja w magazynie            |
| created_at        | DATETIME      | Data dodania części                |



### Nazwa tabeli: orders

Opis: Tabela przechowująca zamówienia składane do dostawców.

| Nazwa atrybutu | Typ           | Opis/Uwagi                             |
| -------------- | ------------- | -------------------------------------- |
| order_id       | INT           | Klucz główny, identyfikator zamówienia |
| supplier_id    | INT           | Klucz obcy do tabeli suppliers_zad     |
| employee_id    | INT           | Klucz obcy do tabeli employees_zad     |
| order_date     | DATE          | Data złożenia zamówienia               |
| delivery_date  | DATE          | Data dostawy                           |
| status         | VARCHAR(30)   | Status zamówienia                      |
| total_amount   | DECIMAL(10,2) | Łączna wartość zamówienia              |
| description    | VARCHAR(255)  | Opis zamówienia                        |



### Nazwa tabeli: work_orders

Opis: Tabela przechowująca zlecenia napraw wykonywanych dla klientów.

| Nazwa atrybutu      | Typ           | Opis/Uwagi                           |
| ------------------- | ------------- | ------------------------------------ |
| work_order_id       | INT           | Klucz główny, identyfikator zlecenia |
| client_id           | INT           | Klucz obcy do tabeli clients_zad     |
| vehicle_id          | INT           | Klucz obcy do tabeli vehicles_zad    |
| employee_id         | INT           | Klucz obcy do tabeli employees_zad   |
| date_created        | DATETIME      | Data utworzenia zlecenia             |
| date_completed      | DATETIME      | Data zakończenia zlecenia            |
| status              | VARCHAR(30)   | Status realizacji                    |
| problem_description | VARCHAR(255)  | Opis problemu                        |
| repair_description  | VARCHAR(255)  | Opis wykonanej naprawy               |
| total_cost          | DECIMAL(10,2) | Łączny koszt naprawy                 |
| description         | VARCHAR(255)  | Dodatkowy opis                       |



### Nazwa tabeli: reservations

Opis: Tabela przechowująca rezerwacje wizyt klientów.

| Nazwa atrybutu   | Typ          | Opis/Uwagi                             |
| ---------------- | ------------ | -------------------------------------- |
| reservation_id   | INT          | Klucz główny, identyfikator rezerwacji |
| client_id        | INT          | Klucz obcy do tabeli clients_zad       |
| vehicle_id       | INT          | Klucz obcy do tabeli vehicles_zad      |
| service_id       | INT          | Klucz obcy do tabeli services_zad      |
| employee_id      | INT          | Klucz obcy do tabeli employees_zad     |
| reservation_date | DATETIME     | Termin rezerwacji                      |
| status           | VARCHAR(30)  | Status rezerwacji                      |
| description      | VARCHAR(255) | Opis lub uwagi                         |



### Nazwa tabeli: payments

Opis: Tabela przechowująca informacje o płatnościach za wykonane usługi.

| Nazwa atrybutu     | Typ           | Opis/Uwagi                            |
| ------------------ | ------------- | ------------------------------------- |
| payment_id         | INT           | Klucz główny, identyfikator płatności |
| work_order_id      | INT           | Klucz obcy do tabeli work_orders_zad  |
| payment_date       | DATETIME      | Data płatności                        |
| amount             | DECIMAL(10,2) | Kwota płatności                       |
| payment_method     | VARCHAR(50)   | Metoda płatności                      |
| status             | VARCHAR(30)   | Status płatności                      |
| transaction_number | VARCHAR(100)  | Numer transakcji                      |


