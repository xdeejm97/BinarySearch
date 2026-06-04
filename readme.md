

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

<img width="1657" height="856" alt="obraz" src="https://github.com/user-attachments/assets/1d3043d8-1d9b-495e-b242-8ab20bb74c3a" />

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

# 4.	Implementacja

## Kod poleceń DDL

(dla każdej tabeli należy wkleić kod DDL polecenia tworzącego tabelę)

```sql
-- SUPPLIERS

CREATE TABLE [dbo].[suppliers_zad] (
    supplier_id INT PRIMARY KEY IDENTITY(1,1),
    company_name VARCHAR(100) NOT NULL,
    contact_person VARCHAR(100),
    phone VARCHAR(20),
    email VARCHAR(100),
    address VARCHAR(255),
    nip VARCHAR(15) UNIQUE,
    created_at DATETIME DEFAULT GETDATE()
);

-- CLIENTS
CREATE TABLE [dbo].[clients_zad](
    [client_id] [int] IDENTITY(1,1) NOT NULL,
    [first_name] [varchar](50) NOT NULL,
    [last_name] [varchar](50) NOT NULL,
    [phone] [varchar](20) NULL,
    [email] [varchar](100) NULL,
    [address] [varchar](255) NULL,
    [postal_code] [varchar](10) NULL,
    [city] [varchar](50) NULL,
    [created_at] [datetime] DEFAULT GETDATE(),
PRIMARY KEY CLUSTERED ([client_id] ASC)
) ON [PRIMARY]
GO

-- EMPLOYEES
CREATE TABLE [dbo].[employees_zad](
    [employee_id] [int] IDENTITY(1,1) NOT NULL,
    [first_name] [varchar](50) NOT NULL,
    [last_name] [varchar](50) NOT NULL,
    [position] [varchar](50) NULL,
    [phone] [varchar](20) NULL,
    [email] [varchar](100) NULL,
    [salary] [decimal](10,2) NULL,
    [hire_date] [date] NULL,
    [status] [varchar](30) NULL,
PRIMARY KEY CLUSTERED ([employee_id] ASC)
) ON [PRIMARY]
GO

--  CAR_MODELS
CREATE TABLE [dbo].[car_models_zad](
    [car_models_id] [int] IDENTITY(1,1) NOT NULL,
    [brand] [varchar](50) NOT NULL,
    [model] [varchar](50) NOT NULL,
    [engine] [varchar](50) NOT NULL,
    [fuel_type] [varchar](30) NOT NULL,
PRIMARY KEY CLUSTERED ([car_models_id] ASC),
CONSTRAINT UQ_car_models_zad UNIQUE ([brand], [model], [engine], [fuel_type])
) ON [PRIMARY]
GO

-- CLIENT VEHICLES
CREATE TABLE [dbo].[client_vehicles_zad](
    [vehicle_id] [int] IDENTITY(1,1) NOT NULL,
    [client_id] [int] NOT NULL,
    [car_models_id] [int] NOT NULL,
    [production_year] [int] NOT NULL,
    [vin] [varchar](50) UNIQUE,
    [registration_number] [varchar](20) UNIQUE,
    [mileage] [int] NULL,
PRIMARY KEY CLUSTERED ([vehicle_id] ASC),
FOREIGN KEY ([client_id]) REFERENCES [dbo].[clients_zad]([client_id]),
FOREIGN KEY ([car_models_id]) REFERENCES [dbo].[car_models_zad]([car_models_id])
) ON [PRIMARY]
GO

-- CLIENT_WORK_ORDERS
CREATE TABLE [dbo].[client_work_orders_zad](
    [client_work_order_id] [int] IDENTITY(1,1) NOT NULL,
    [client_id] [int] NOT NULL,
    [vehicle_id] [int] NOT NULL,
    [employee_id] [int] NULL,
    [date_created] [datetime] DEFAULT GETDATE(),
    [date_completed] [datetime] NULL,
    [status] [varchar](30) NULL,
    [problem_description] [varchar](255) NULL,
    [repair_description] [varchar](255) NULL,
    [total_cost] [decimal](10,2) NULL,
    [description] [varchar](255) NULL,
PRIMARY KEY CLUSTERED ([client_work_order_id] ASC),
FOREIGN KEY ([client_id]) REFERENCES [dbo].[clients_zad]([client_id]),
FOREIGN KEY ([vehicle_id]) REFERENCES [dbo].[client_vehicles_zad]([vehicle_id]),
FOREIGN KEY ([employee_id]) REFERENCES [dbo].[employees_zad]([employee_id])
) ON [PRIMARY]
GO

-- SERVICES_DETAILS   
CREATE TABLE [dbo].[services_details_zad](
    [service_id] [int] IDENTITY(1,1) NOT NULL,
    [name] [varchar](100) NOT NULL,
    [description] [varchar](255) NULL,
    [price] [decimal](10,2) NOT NULL,
    [estimated_time] [int] NULL,
PRIMARY KEY CLUSTERED ([service_id] ASC)
) ON [PRIMARY]
GO

-- WORK_SERVICES
CREATE TABLE [dbo].[work_services_zad](
    [work_service_id] [int] IDENTITY(1,1) NOT NULL,
    [client_work_order_id] [int] NOT NULL,
    [service_id] [int] NOT NULL,
    [quantity] [int] NOT NULL DEFAULT 1,
    [description] [varchar](255) NULL,
    [created_at] [datetime] DEFAULT GETDATE(),
PRIMARY KEY CLUSTERED ([work_service_id] ASC),
FOREIGN KEY ([client_work_order_id]) 
    REFERENCES [dbo].[client_work_orders_zad]([client_work_order_id]),
FOREIGN KEY ([service_id]) 
    REFERENCES [dbo].[services_details_zad]([service_id])
) ON [PRIMARY]
GO

-- CAR_PARTS
CREATE TABLE [dbo].[car_parts_zad](
    [part_id] [int] IDENTITY(1,1) NOT NULL,
    [name] [varchar](100) NOT NULL,
    [category] [varchar](50) NULL,
    [manufacturer] [varchar](100) NULL,
    [part_number] [varchar](50) UNIQUE,
    [quantity_in_stock] [int] DEFAULT 0,
    [purchase_price] [decimal](10,2) NULL,
    [selling_price] [decimal](10,2) NULL,
    [supplier_id] [int] NULL,
    [location] [varchar](100) NULL,
    [created_at] [datetime] DEFAULT GETDATE(),
PRIMARY KEY CLUSTERED ([part_id] ASC),
FOREIGN KEY ([supplier_id]) REFERENCES [dbo].[suppliers_zad]([supplier_id])
) ON [PRIMARY]
GO

-- USED_PARTS
CREATE TABLE [dbo].[used_parts_zad](
    [used_part_id] [int] IDENTITY(1,1) NOT NULL,
    [client_work_order_id] [int] NOT NULL,
    [part_id] [int] NOT NULL,
    [quantity_used] [int] NOT NULL DEFAULT 1,
    [description] [varchar](255) NULL,
PRIMARY KEY CLUSTERED ([used_part_id] ASC),
FOREIGN KEY ([client_work_order_id]) 
    REFERENCES [dbo].[client_work_orders_zad]([client_work_order_id]),
FOREIGN KEY ([part_id]) 
    REFERENCES [dbo].[car_parts_zad]([part_id])
) ON [PRIMARY]
GO

-- COMPANY_ORDERS
CREATE TABLE [dbo].[company_orders_zad](
    [order_id] [int] IDENTITY(1,1) NOT NULL,
    [supplier_id] [int] NOT NULL,
    [employee_id] [int] NOT NULL,
    [order_date] [date] NOT NULL,
    [delivery_date] [date] NULL,
    [status] [varchar](30) NULL,
    [total_amount] [decimal](10,2) NULL,
    [description] [varchar](255) NULL,
PRIMARY KEY CLUSTERED ([order_id] ASC),
FOREIGN KEY ([supplier_id]) 
    REFERENCES [dbo].[suppliers_zad]([supplier_id]),
FOREIGN KEY ([employee_id]) 
    REFERENCES [dbo].[employees_zad]([employee_id])
) ON [PRIMARY]
GO

-- COMPANY_ORDER_ITEMS
CREATE TABLE [dbo].[company_order_items_zad](
    [order_item_id] [int] IDENTITY(1,1) NOT NULL,
    [order_id] [int] NOT NULL,
    [part_id] [int] NOT NULL,
    [quantity] [int] NOT NULL DEFAULT 1,
    [purchase_price] [decimal](10,2) NULL,
PRIMARY KEY CLUSTERED ([order_item_id] ASC),
FOREIGN KEY ([order_id])
    REFERENCES [dbo].[company_orders_zad]([order_id]),
FOREIGN KEY ([part_id])
    REFERENCES [dbo].[car_parts_zad]([part_id])
) ON [PRIMARY]
GO

-- PAYMENTS
CREATE TABLE [dbo].[payments_zad](
    [payment_id] [int] IDENTITY(1,1) NOT NULL,
    [client_work_order_id] [int] NOT NULL,
    [payment_date] [datetime] DEFAULT GETDATE(),
    [amount] [decimal](10,2) NOT NULL,
    [payment_method] [varchar](50) NULL,
    [status] [varchar](30) NULL,
    [transaction_number] [varchar](100) NULL,
PRIMARY KEY CLUSTERED ([payment_id] ASC),
FOREIGN KEY ([client_work_order_id]) REFERENCES [dbo].[client_work_orders_zad]([client_work_order_id])
) ON [PRIMARY]
GO
```

## Widoki

(dla każdego widoku należy wkleić kod polecenia definiującego widok wraz z komentarzem)


## Procedury/funkcje

(dla każdej procedury/funkcji należy wkleić kod polecenia definiującego procedurę wraz z komentarzem)

## Triggery

(dla każdego triggera należy wkleić kod polecenia definiującego trigger wraz z komentarzem)





