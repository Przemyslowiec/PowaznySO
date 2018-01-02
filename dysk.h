#pragma once
#include <array>
#include "iwezel.h"
#include "katalog.h"
#include "wpisKatalogowy.h"
class dysk 
{
public:
	dysk ();
#pragma region obsluga plikow
	void utworzPlik(std::string nazwa, std::string rozszerzenie, std::string nazwaFolderu = "Dysk"); // Tworzy pusty plik i zajmuje jeden blok dyskowy.
	void zapiszDoPliku(std::string nazwa, std::string rozszerzenie,std::string dane, std::string nazwaFolderu ="Dysk"); //Pozwala na dopisywanie danych na ko�cu pliku.
	std::string pobierzDane(std::string nazwa, std::string rozszerzenie, std::string nazwaFolderu = "Dysk"); // Zwraca dane z pliku.
	void otowrzStratnie(std::string nazwa, std::string rozszerzenie, std::string nazwaFolderu = "Dysk"); // Czy�wi plik, zwalnia bloki poza pierwszym blokiem.
	void usunPlik(std::string nazwa, std::string rozszerzenie, std::string nazwaFolderu = "Dysk"); // Zwalnia bloki, czy�ci wpis na dysku
	void zmienNazwePliku(std::string nazwa, std::string rozszerzenie, std::string nowaNazwa, std::string nazwaFolderu = "Dysk"); // Zmiania nazw� pliku
#pragma  endregion obsluga plikow

#pragma region obsluga folderow
	void utworzFolder(std::string nazwa, std::string nazwaNadrzednego = "Dysk"); // Tworzy folder podrz�dny w zadanym folderze 
	void dodajPlikDoKatalogu(std::string nazwaDolcelowego, std::string nazwaPliku, std::string rozszerzenie, std::string nazwaFolderuZPlikiem = "Dysk"); //Do sko�czenie
	void usunFolder(int pozycja); // Usuwa folder o zadanej pozycji nale�y wywol�ywa� w po��czniu z znajdzFolder, prawid�owy przyk�ad: dysk.usunFolder(dysk.znajdzFolder("Folder"));
	short znajdzFolder(std::string nazwa);
#pragma endregion obsluga folderow

#pragma region wpypisywanie elementow dyskowych
	void wypiszDrzewo(); // Wypisuje "drzewo" plik�w i katalog�w na dysku.
	void wypiszDysk(); // Wypisuje na ekran sam� tablic� dyskow�.
	void wypiszWektorBitowy();
	void wypiszTabliceIwezelow();
	void wypiszTabliceWpisow();
#pragma endregion  wpypisywanie elementow dyskowych
	
private:
	std::array<iWezel, 32> tablicaIwezlow; // Tablica w kt�rej przechowywane s� iWezel
	std::array<char, 1024> tablicaDysk; // Tablica na dane
	std::array<katalog, 1024> tablicaKatalogow; // Tablica z danymi katalog�w
	std::array<wpis, 32> tablicaWpisow; 
	std::array<bool, 32> wektorBitowy; // 1 Blok wolny, 0 Blok zaj�ty

	short wielkoscBloku;
	int wielkoscDysku;
	short wolneBloki;
	int ileFolderow;

	void ileWolnych();
	short znajdzPlik(std::string nazwa, std::string rozszerzenie); // Metoda zwraca numer iWez�a w kolekcji w kt�rym znajduje si� plik, je�li pliku nie odnazleziono zwraca -1
	short znajdzWolnyBlok(); // Metoda zwraca numer pierwszego wolnego bloku na dysku, je�li brak zwraca -1
	short znajdzIwezel(); // Metoda zwraca numer pierwszego wolnego iW�z�a, je�li brak zwraca -1
	std::string pobierzNazweFolder(short poz);
};
