# Digitalni medicinski karton

Interaktivna C++14 konzolna aplikacija koja modeluje rad jednostavnog digitalnog medicinskog kartona. Sistem omogućava unos pacijenata i doktora, vođenje istorije bolesti, unos lekova, kao i zakazivanje termina uz osnovnu validaciju i obradu grešaka.

## Funkcionalnosti

- unos podataka o pacijentima (lični podaci, istorija bolesti) i doktorima (lični podaci, specijalnost)
- vođenje liste lekova i njihovo povezivanje sa bolestima koje leče
- interaktivno zakazivanje termina pacijentu kod izabranog doktora uz proveru dostupnosti termina
- preporuka dostupnih lekova prema istoriji bolesti pacijenta
- pregled celokupnog stanja sistema (osobe, lekovi, statistika)
- robusnije upravljanje greškama kroz prilagođene `exception` klase za pogrešan unos pacijenta, doktora, termina ili leka

## Arhitektura

- `Osoba` – apstraktna baza za `Pacijent` i `Doktor`, čuva opšte podatke.
- `Pacijent` – proširuje osobu istorijom bolesti i propisanim lekovima; sadrži logiku zakazivanja termina.
- `Doktor` – čuva specijalnost i mapu termina (08–13h), uz metode za zakazivanje i predlaganje lekova.
- `Lek` – opisuje lek i bolesti na koje se primenjuje.
- `medicinskaIstorija` – lista hroničnih bolesti pacijenta.
- `sistemZdravstva` – centralni kontroler koji orkestrira kolekcije pacijenata, doktora i lekova i sadrži menije.
- `datum` – pomoćna klasa za unos datuma rođenja.
- `*_Exception` datoteke – personalizovane poruke grešaka za ključne domene.

Svi izvori se nalaze u `code/`, dok je jednostavan CMake projekat postavljen onder direktorijuma `build/`.

## Kako pokrenuti projekat

Zahtevi:

- CMake ≥ 3.10
- g++ (ili drugi C++14 kompatibilan kompajler)

Koraci (iz korenskog direktorijuma projekta):

```bash
mkdir -p out
cmake -S build -B out
cmake --build out
./out/exe
```

Alternativno, možete direktno kompajlirati sve `.cpp` fajlove из `code/` pomoću g++:

```bash
g++ -std=c++14 code/*.cpp -o exe
./exe
```

## Upotreba aplikacije

Pokretanjem izvršnog fajla dobija se tekstualni meni:

1. dodavanje pacijenta
2. dodavanje doktora
3. dodavanje leka
4. zakazivanje termina jednom pacijentu
5. zakazivanje termina svim pacijentima (bulk režim)
6. pregled celog sistema (statistika + detalji o osobama i lekovima)
7. izlaz

Unos podataka se obavlja putem konzole. Aplikacija obrađuje osnovne greške (npr. pogrešan izbor stavke menija, zauzet termin ili nepostojeći pacijent/doktor) i vraća informativne poruke iz odgovarajućih `exception` klasa, tako da korisnik može ponoviti unos.

## Struktura direktorijuma

- `code/` – C++ izvorni fajlovi i zaglavlja
- `build/` – CMakeLists i (po želji) privremeni build artefakti
- `DigitalniMedicinskiKartonPrezentacija.pptx` – prateća prezentacija projekta
- `DokumentacijaZaDigitalniMedicinskiKarton.docx` – tekstualna dokumentacija
- `UML Dijagram Vladimir Dumanovic.png`, `umlKod.txt` – vizuelna i tekstualna UML specifikacija

## Dalji pravci razvoja

- trajno skladištenje podataka (datoteka ili baza) i učitavanje stanja pri pokretanju
- proširenje termina na datum/vreme i rad sa kalendarom
- uvođenje autentifikacije i različitih korisničkih rola
- dodavanje automatizovanih testova i proširenje exception hijerarhije

Aplikacija je kreirana za potrebe završnog projekta iz predmeta Programiranje objektnim pristupom i demonstrira primenu osnovnih OO principa u C++ okruženju.

