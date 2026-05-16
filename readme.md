

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

Po zatwierdzeniu naprawy system umożliwia przypisanie zadań mechanikom, monitorowanie postępu prac oraz aktualizowanie statusu zlecenia (np. „przyjęty”, „w trakcie naprawy”, „oczekiwanie na części”, „gotowy do odbioru”). Po zakończeniu usługi generowany jest rachunek lub faktura zawierająca wykonane czynności oraz wykorzystane części zamienne.

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

(diagram (rysunek) przedstawiający schemat bazy danych) 

## Opis poszczególnych tabel

(Dla każdej tabeli opis w formie tabelki)


Nazwa tabeli: (nazwa tabeli)
- Opis: (opis tabeli, komentarz)

| Nazwa atrybutu | Typ  | Opis/Uwagi |
|----------------|------|------------|
| Atrybut 1 …    |      |            |
| Atrybut 2 …    |      |            |


# 4.	Implementacja

## Kod poleceń DDL

(dla każdej tabeli należy wkleić kod DDL polecenia tworzącego tabelę)

```sql
create table tab1 (
   a int,
   b varchar(10)
)
```

## Widoki

(dla każdego widoku należy wkleić kod polecenia definiującego widok wraz z komentarzem)


## Procedury/funkcje

(dla każdej procedury/funkcji należy wkleić kod polecenia definiującego procedurę wraz z komentarzem)

## Triggery

(dla każdego triggera należy wkleić kod polecenia definiującego trigger wraz z komentarzem)




