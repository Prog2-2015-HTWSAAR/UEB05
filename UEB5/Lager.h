/**
 * @file Lager.h
 *
 * @date 23.05.2015
 * @author Andreas Schreiner & Simon Bastian
 */

#ifndef LAGER_H_
#define LAGER_H_
#include "Artikel.h"

/**
 * Standardausnahme fuer logische Fehler in der Lagerklasse
 */
class LagerException : public ArtikelException {
public:
    LagerException(const string& msg = "") : ArtikelException(msg) {}
};
/**
 * @brief Eine Lagerklasse
 */
class Lager {
public:
	Lager& operator=(const Lager&) throw();
	static const char* defaultName;
	const int ARTIKELANZAHL = 0;
	static const int defaultSize = 100;
	/**
	 * @brief Konstruktor ohne Namensangabe
	 *
	 * @param maxAnzArtikel muss positiv sein!
	 */
	//Lager(int maxAnzArtikel);
	/**
	 * @brief Konstruktor mit Namensangabe
	 * @param maxAnzArtikel muss positiv sein!
	 * @param name Name des Lagers darf nicht leer sein!
	 */
	Lager(int maxAnzArtikel = defaultSize, string name = defaultName);
	/**
	 * @brief Destructor l�scht alle Artikel
	 */
	virtual ~Lager();
	/**
	 * @brief Eintragen eines neuen Artikels ohne Bestandsangabe
	 * @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelPreis
	 */
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis);
	/**
	 * @brief Eintragen eines neuen Artikels mit Bestandsangabe
	 * @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelPreis
	 * @param bestand
	 */
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand);
	/**
	 * @brief Entfernen eines Artikels aus dem Lager
	 * @param artikelNr
	 */
	void deleteArtikel(int artikelNr);
	/**
	 *
	 */
	void bucheZugang(Artikel *artikel, int menge);
	/**
	 *
	 */
	void bucheAbgang(Artikel *artikel, int menge);
	/**
	 *
	 */
	void preiseAendern(double preisaenderung);
	string toString() const;
	friend ostream& operator<<(ostream&, const Lager&);
//	virtual string toString() const;
private:
	/**
	 *
	 */
	int findeArtikel(int artikelNr);
	/**
	 *
	 */
	void loescheAlleArtikel();
	/**
	 * @brief Initialisierung des Lagers
	 * @param maxAnzArtikel muss positiv sein!
	 * @param name darf nicht leer sein!
	 */
	//void init(int maxAnzArtikel, string name);
	string name;
	Artikel** artikelTab;
	int anzArtikel;
	int maxAnzArtikel;
};

#endif /* LAGER_H_ */
