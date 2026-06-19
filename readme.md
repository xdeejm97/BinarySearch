

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

<img width="1414" height="1012" alt="image" src="https://github.com/user-attachments/assets/bd6a8204-c5ae-49a5-b678-b05df1bcaec4" />

## Opis poszczególnych tabel

### Nazwa tabeli: suppliers

Opis: Tabela przechowująca dane dostawców części samochodowych i materiałów do warsztatu.

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



### Nazwa tabeli: client_vehicles

Opis: Tabela przechowująca dane pojazdów klientów.

| Nazwa atrybutu      | Typ         | Opis/Uwagi                          |
| ------------------- | ----------- | ----------------------------------- |
| vehicle_id          | INT         | Klucz główny, identyfikator pojazdu |
| client_id           | INT         | Klucz obcy do tabeli clients        |
| car_models_id       | INT         | Klucz obcy do tabeli car_models     |
| production_year     | INT         | Rok produkcji                       |
| vin                 | VARCHAR(50) | Numer VIN                           |
| registration_number | VARCHAR(20) | Numer rejestracyjny                 |
| mileage             | INT         | Aktualny przebieg                   |

### Nazwa tabeli: car_models

Opis: Tabela zawiera dane modeli samochodów.

| Nazwa atrybutu      | Typ         | Opis/Uwagi                          |
| ------------------- | ----------- | ----------------------------------- |
| car_models_id       | INT         | Klucz główny, identyfikator Modelu  |
| brand               | VARCHAR(50) | Marka pojazdu                       |
| model               | VARCHAR(50) | Model pojazdu                       |
| engine              | VARCHAR(50) | Typ silnika                         |
| fuel_type           | VARCHAR(30) | Rodzaj paliwa                       |

### Nazwa tabeli: work_services

Opis: Tabela łączy zlecenia napraw z konkretnymi usługami wykonanymi w ramach danego zlecenia.

| Nazwa atrybutu       | Typ           | Opis/Uwagi                             |
| -------------------- | ------------- | -------------------------------------- |
| work_service_id      | INT           | Klucz główny, identyfikator usługi     |
| client_work_order_id | INT           | Klucz obcy do tabeli client_work_order |
| service_id           | INT           | Klucz obcy do tabeli services_details  |
| quantity             | INT           | Ilość wykonanej usługi                 |
| description          | VARCHAR(255)  | Opis usługi                            |
| created_at           | DATETIME      | Czas wykonania usługi                  |

### Nazwa tabeli: services_details

Opis: Tabela przechowująca usługi oferowane przez warsztat.

| Nazwa atrybutu | Typ           | Opis/Uwagi                         |
| -------------- | ------------- | ---------------------------------- |
| service_id     | INT           | Klucz główny, identyfikator usługi |
| name           | VARCHAR(100)  | Nazwa usługi                       |
| description    | VARCHAR(255)  | Opis usługi                        |
| price          | DECIMAL(10,2) | Cena usługi                        |
| estimated_time | INT           | Szacowany czas wykonania           |
 


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


### Nazwa tabeli: used_parts

Opis: Tabela zapisuje części użyte podczas realizacji konkretnego zlecenia naprawy.

| Nazwa atrybutu       | Typ           | Opis/Uwagi                                  |
| -------------------- | ------------- | ------------------------------------------- |
| used_part_id         | INT           | Klucz główny, identyfikator użytej części   |
| client_work_order_id | INT           | Klucz obcy do tabeli client_work_orders_zad |
| part_id              | INT           | Klucz obcyd do tabeli car_parts             |
| quantity_used        | INT           | Ilość użytych części                        |
| description          | VARCHAR(255)  | Krótki opis użytej części                   |
 
### Nazwa tabeli: company_orders

Opis: Tabela przechowująca zamówienia składane u dostawców części.

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



### Nazwa tabeli: company_order_items

Opis: Tabela zawiera pozycje części znajdujących się w zamówieniach do dostawców.

| Nazwa atrybutu      | Typ           | Opis/Uwagi                           |
| ------------------- | ------------- | ------------------------------------ |
| order_item_id       | INT           | Klucz główny, identyfikator zlecenia |
| client_id           | INT           | Klucz obcy do tabeli clients_zad     |
| vehicle_id          | INT           | Klucz obcy do tabeli vehicles_zad    |
| employee_id         | INT           | Klucz obcy do tabeli employees_zad   |
| date_created        | DATETIME      | Data utworzenia zlecenia             |
| date_completed      | DATETIME      | Data zakończenia zlecenia            |
| status              | VARCHAR(30)   | Status realizacji                    |
| problem_description | VARCHAR(255)  | Opis problemu                        |
| repair_description  | VARCHAR(255)  | Opis wykonanej naprawy               |
| total_cost          | DECIMAL(10,2) | Łączny koszt naprawy                 |


### Nazwa tabeli: payments

Opis: Tabela przechowująca informacje o płatnościach za wykonane usługi.

| Nazwa atrybutu       | Typ           | Opis/Uwagi                              |
| -------------------- | ------------- | --------------------------------------- |
| payment_id           | INT           | Klucz główny, identyfikator płatności   |
| client_work_order_id | INT           | Klucz obcy do tabeli client_work_orders |
| payment_date         | DATETIME      | Data płatności                          |
| amount               | DECIMAL(10,2) | Kwota płatności                         |
| payment_method       | VARCHAR(50)   | Metoda płatności                        |
| status               | VARCHAR(30)   | Status płatności                        |
| transaction_number   | VARCHAR(100)  | Numer transakcji                        |

# 4.	Implementacja

## Kod poleceń DDL

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
PRIMARY KEY CLUSTERED ([client_work_order_id] ASC),
FOREIGN KEY ([client_id]) REFERENCES [dbo].[clients_zad]([client_id]),
FOREIGN KEY ([vehicle_id]) REFERENCES [dbo].[client_vehicles_zad]([vehicle_id]),
FOREIGN KEY ([employee_id]) REFERENCES [dbo].[employees_zad]([employee_id])
) ON [PRIMARY]

-- SERVICES_DETAILS   
CREATE TABLE [dbo].[services_details_zad](
    [service_id] [int] IDENTITY(1,1) NOT NULL,
    [name] [varchar](100) NOT NULL,
    [description] [varchar](255) NULL,
    [price] [decimal](10,2) NOT NULL,
    [estimated_time] [int] NULL,
PRIMARY KEY CLUSTERED ([service_id] ASC)
) ON [PRIMARY]

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
```

## Widoki
1. Widoki
  
---- Widok 1 - Historia zleceń klientów ----
 
Widok pokazuje historię klienta, pojazd, mechanika i status zlecenia. Widok nadaje się do podstawowego raportu z napraw wykonanych lub realizowanych dla klientów.
```sql   
CREATE VIEW vw_client_work_orders AS
SELECT
    cwo.client_work_order_id,
    c.first_name + ' ' + c.last_name AS client_name,
    cm.brand,
    cm.model,
    cv.registration_number,
    e.first_name + ' ' + e.last_name AS employee_name,
    cwo.date_created,
    cwo.date_completed,
    cwo.status,
    cwo.total_cost
FROM client_work_orders_zad cwo
JOIN clients_zad c
    ON cwo.client_id = c.client_id
JOIN client_vehicles_zad cv
    ON cwo.vehicle_id = cv.vehicle_id
JOIN car_models_zad cm
    ON cv.car_models_id = cm.car_models_id
LEFT JOIN employees_zad e
    ON cwo.employee_id = e.employee_id;

 ```
 
---- Widok 2 - Stan magazynowy części ----

Widok przedstawia podstawowy stan magazynowy części. Jest to prostsza wersja widoku magazynowego, przydatna do szybkiego sprawdzenia dostępności części.

 ```sql
CREATE VIEW vw_parts_stock AS
SELECT
    cp.part_id,
    cp.name,
    cp.category,
    cp.manufacturer,
    cp.quantity_in_stock,
    cp.purchase_price,
    cp.selling_price,
    s.company_name AS supplier
FROM car_parts_zad cp
LEFT JOIN suppliers_zad s
    ON cp.supplier_id = s.supplier_id;
```

---- Widok 3 - aktualne zamówienia części ----

Widok przedstawia aktualne zamówienia części u dostawców. Widok pomaga śledzić, które zamówienia nie zostały jeszcze dostarczone.
```sql
CREATE OR ALTER VIEW dbo.vw_pending_company_orders_zad AS
SELECT
    co.order_id, co.order_date, co.delivery_date, DATEDIFF(DAY, CAST(GETDATE() AS DATE), co.delivery_date) AS days_to_delivery, co.status, s.supplier_id, s.company_name AS supplier_name,
    s.contact_person, s.phone AS supplier_phone, s.email AS supplier_email, e.employee_id, e.first_name + ' ' + e.last_name AS ordered_by,
    COUNT(coi.order_item_id) AS items_count, SUM(coi.quantity) AS total_parts_quantity, SUM(CAST(coi.quantity AS DECIMAL(10,2)) * ISNULL(coi.purchase_price, 0)) AS calculated_total_amount,
    co.total_amount, co.description
FROM dbo.company_orders_zad co
JOIN dbo.suppliers_zad s ON co.supplier_id = s.supplier_id
JOIN dbo.employees_zad e ON co.employee_id = e.employee_id
LEFT JOIN dbo.company_order_items_zad coi ON co.order_id = coi.order_id
WHERE ISNULL(co.status, '') NOT IN ('Dostarczone', 'Anulowane')
GROUP BY
    co.order_id, co.order_date, co.delivery_date, co.status, s.supplier_id, s.company_name, s.contact_person, s.phone, s.email, e.employee_id, e.first_name, e.last_name, co.total_amount, co.description;
```

## Procedury/funkcje

---- Funkcja 1 - Liczba zleceń klienta ----
Funkcja zwraca liczbę zleceń przypisanych do danego klienta. Na podstawie identyfikatora klienta sprawdza, ile razy korzystał on z usług warsztatu. Może być używana do prostych statystyk, na przykład do sprawdzenia aktywności klienta lub historii jego wizyt.
```sql
CREATE FUNCTION fn_ClientWorkOrdersCount
(
    @client_id INT
)
RETURNS INT
AS
BEGIN
    DECLARE @result INT;
    SELECT @result = COUNT(*)
    FROM client_work_orders_zad
    WHERE client_id = @client_id;
    RETURN @result;
 
END;
```

Przykład:
SELECT dbo.fn_ClientWorkOrdersCount(1);

---- Funkcja 2 - całkowity koszt zlecenia ----

Funkcja oblicza całkowity koszt zlecenia naprawy. Sumuje koszt usług oraz koszt użytych części. Jest przydatna do automatycznego aktualizowania pola total_cost w zleceniu oraz do przygotowania rozliczenia dla klienta.
```sql
CREATE OR ALTER FUNCTION dbo.fn_work_order_total_cost_zad
(
    @client_work_order_id INT
)
RETURNS DECIMAL(10,2)
AS
BEGIN
    DECLARE @result DECIMAL(10,2);

    SET @result =
        ISNULL(dbo.fn_work_order_services_cost_zad(@client_work_order_id), 0)
        + ISNULL(dbo.fn_work_order_parts_cost_zad(@client_work_order_id), 0);

    RETURN ISNULL(@result, 0);
END;
```
---- Procedura 1 - przyjęcie dostawy i zwiększenie magazynu ----

Procedura służy do przyjęcia dostawy części od dostawcy. Po jej wykonaniu zwiększany jest stan magazynowy części na podstawie pozycji zamówienia, a samo zamówienie otrzymuje status Dostarczone. Procedura zapisuje także datę dostawy i przelicza wartość zamówienia.
```sql
CREATE OR ALTER PROCEDURE dbo.sp_receive_company_order_zad
    @order_id INT,
    @delivery_date DATE = NULL
AS
BEGIN
    SET NOCOUNT ON;
    SET XACT_ABORT ON;

    BEGIN TRANSACTION;

    IF NOT EXISTS (
        SELECT 1
        FROM dbo.company_orders_zad
        WHERE order_id = @order_id
          AND ISNULL(status, '') <> 'Dostarczone'
    )
    BEGIN
        ROLLBACK TRANSACTION;
        THROW 50017, 'Zamówienie nie istnieje albo zostało już przyjęte.', 1;
    END;

    IF NOT EXISTS (
        SELECT 1
        FROM dbo.company_order_items_zad
        WHERE order_id = @order_id
    )
    BEGIN
        ROLLBACK TRANSACTION;
        THROW 50018, 'Nie można przyjąć zamówienia bez pozycji.', 1;
    END;

    ;WITH items AS (
        SELECT
            part_id,
            SUM(quantity) AS quantity_to_add
        FROM dbo.company_order_items_zad
        WHERE order_id = @order_id
        GROUP BY part_id
    )
    UPDATE cp
    SET quantity_in_stock = ISNULL(cp.quantity_in_stock, 0) + items.quantity_to_add
    FROM dbo.car_parts_zad cp
    JOIN items
        ON cp.part_id = items.part_id;

    UPDATE dbo.company_orders_zad
    SET
        status = 'Dostarczone',
        delivery_date = ISNULL(@delivery_date, CAST(GETDATE() AS DATE)),
        total_amount = dbo.fn_company_order_total_zad(@order_id)
    WHERE order_id = @order_id;

    COMMIT TRANSACTION;

    SELECT *
    FROM dbo.company_orders_zad
    WHERE order_id = @order_id;
END;
```

## Triggery


---- Trigger 1 - Aktualizacja stanu magazynowego po użyciu części ----
 
Trigger uruchamia się po dodaniu użytej części do tabeli used_parts_zad. Jego zadaniem jest automatyczne zmniejszenie stanu magazynowego danej części o ilość wykorzystaną w naprawie. Dzięki temu magazyn jest aktualizowany bez ręcznego poprawiania liczby części.
```sql
CREATE TRIGGER trg_UpdateStockAfterPartUsage
ON used_parts_zad
AFTER INSERT
AS
BEGIN
    UPDATE cp
    SET cp.quantity_in_stock =
        cp.quantity_in_stock - i.quantity_used
    FROM car_parts_zad cp
    INNER JOIN inserted i
        ON cp.part_id = i.part_id;
 
END;
 ```
---- Trigger 2 - Kontrola stanu magazynowego ----
 
Trigger sprawdza, czy przed dodaniem użytej części do zlecenia dostępna jest wystarczająca ilość tej części w magazynie. Jeżeli mechanik próbuje zużyć więcej części, niż znajduje się na stanie, operacja zostaje zablokowana i pojawia się komunikat o braku części. Trigger chroni bazę przed zejściem stanu magazynowego poniżej zera.
```sql
CREATE TRIGGER trg_CheckStock
ON used_parts_zad
INSTEAD OF INSERT
AS
BEGIN
    IF EXISTS
    (
        SELECT 1
        FROM inserted i
        JOIN car_parts_zad cp
            ON i.part_id = cp.part_id
        WHERE i.quantity_used > cp.quantity_in_stock
    )
    BEGIN
        RAISERROR('Brak wystarczajacej ilosci czesci na magazynie.',16,1);
        RETURN;
    END
    INSERT INTO used_parts_zad
    (
        client_work_order_id,
        part_id,
        quantity_used,
        description
    )
    SELECT
        client_work_order_id,
        part_id,
        quantity_used,
        description
    FROM inserted;
 
END;
```
