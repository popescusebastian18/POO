#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<fstream>
#include<cstdio>
using namespace std;

class Camp {
private:
	string numeCamp = "";
	string tipCamp = "";
public:
	//constructor
	Camp(string nume, string tip) {
		numeCamp = nume;
		tipCamp = tip;
	}
	//constructor de copiere
	Camp(const Camp& camp) {
		numeCamp = camp.numeCamp;
		tipCamp = camp.tipCamp;
	}
	//constructor default
	Camp() {}
	//destrutor
	~Camp() {}

	//set si get pentru toate campurile
	string getnumeCamp() {
		return numeCamp;
	}
	void setnumeCamp(string nume) {
		if (nume.length() > 0)
			numeCamp = nume;
	}

	string gettipCamp() {
		return tipCamp;
	}
	void settipCamp(string tip) {
		if (tip.length() > 0)
			tipCamp = tip;
	}


	//afisare in consola
	friend ostream& operator<<(ostream& out, Camp& camp) {
		out << "Camp numeCamp: " << camp.numeCamp << endl;
		out << "Camp tipCamp: " << camp.tipCamp << endl;
		return out;
	}
	//scriere in fisier
	friend ofstream& operator<<(ofstream& out, Camp& camp) {
		out << camp.numeCamp << endl;
		out << camp.tipCamp << endl;
		return out;
	}
	//citire din consola
	friend istream& operator>>(istream& in, Camp& camp) {
		cout << "Camp numeCamp: " << endl;
		in >> camp.numeCamp;
		cout << "Camp tipCamp: " << endl;
		in >> camp.tipCamp;
		return in;
	}
	//citire din fisier
	friend ifstream& operator>>(ifstream& in, Camp& camp) {
		in >> camp.numeCamp;
		in >> camp.tipCamp;
		return in;
	}
	//modific obiectul curent cu un alt obiect
	Camp& operator=(const Camp& camp) {
		numeCamp = camp.numeCamp;
		tipCamp = camp.tipCamp;

		return *this;
	}
	//verific daca obiectele sunt egale
	bool operator==(const Camp& camp) {
		if (camp.numeCamp == numeCamp && camp.tipCamp == tipCamp) return true;
		return false;
	}
	//verific daca doua obiecte Camp sunt diferite
	bool operator!=(Camp camp) {
		if (numeCamp != camp.numeCamp || tipCamp != camp.tipCamp) return true;
		return false;
	}
};

class Element {
private:
	int numarCampuri = 0;
	string* valoriCampuri = nullptr;
public:
	//constructor
	Element(string* val, int nr) {
		numarCampuri = nr;
		valoriCampuri = new string[nr];
		for (int i = 0; i < nr; i++)
			valoriCampuri[i] = val[i];
	}
	//constructor de copiere
	Element(const Element& el) {
		numarCampuri = el.numarCampuri;
		valoriCampuri = new string[el.numarCampuri];
		for (int i = 0; i < el.numarCampuri; i++)
			valoriCampuri[i] = el.valoriCampuri[i];

	}
	//constructor default
	Element() {}
	//destructor
	~Element() {
		if (valoriCampuri != nullptr)
			delete[] valoriCampuri;
	}

	//get si set pentru toate campurile
	string* getValues() {
		return valoriCampuri;
	}
	void setValues(string* val, int nr) {
		if (valoriCampuri != nullptr) delete[] valoriCampuri;
		numarCampuri = nr;
		valoriCampuri = new string[nr];
		for (int i = 0; i < nr; i++) 
			valoriCampuri[i] = val[i];
	}

	int getNoValues() {
		return numarCampuri;
	}
	void setNoValues(int noVal) {
		if (noVal >= 0)
		{
			numarCampuri = noVal;
		}
	}
	//afisare in consola
	friend ostream& operator<<(ostream& out, Element& el) {
		out << "Numarul de campuri " << el.numarCampuri << endl;
		out << "Valorile Campurilor" << endl;
		for (int i = 0; i < el.numarCampuri; i++)
			out << el.valoriCampuri[i] << endl;
		return out;
	}
	//scriere in fisier
	friend ofstream& operator<<(ofstream& out, Element& el) {
		out  << el.numarCampuri << endl;
		for (int i = 0; i < el.numarCampuri; i++)
			out << el.valoriCampuri[i] << endl;
		return out;
	}
	//citire din consola
	friend istream& operator>>(istream& in, Element& el) {
		cout << "Numarul de campuri " << endl;
		in >> el.numarCampuri;
		cout << "Valorile Campurilor " << endl;
		for (int i = 0; i < el.numarCampuri; i++)
			in >> el.valoriCampuri[i];
		return in;
	}
	//citire din fisier
	friend ifstream& operator>>(ifstream& in, Element& el) {
		in >> el.numarCampuri;
		for (int i = 0; i < el.numarCampuri; i++)
			in >> el.valoriCampuri[i];
		return in;
	}

	//modific obiectul curent cu un alt obiect
	Element& operator=(const Element& el) {
		numarCampuri = el.numarCampuri;
		if (valoriCampuri != nullptr) delete[] valoriCampuri;
		valoriCampuri = new string[el.numarCampuri];
		for (int i = 0; i < el.numarCampuri; i++)
			valoriCampuri[i] = el.valoriCampuri[i];
		return *this;
	}
	//verificare daca doua elemente sunt diferite
	bool operator!=(Element el) {
		if (numarCampuri == el.numarCampuri) {
			bool diferite = false;
			for (int i = 0; i < numarCampuri; i++)
				if (valoriCampuri[i] != el.valoriCampuri[i]) diferite = true;
			if (diferite == true) return true;
			return false;
		}
		return true;
	}
	//valoarea pentru un anumit camp
	string& operator[](int i) {
		if (i < 0 || i > numarCampuri)  cout << "Pozitia nu exista in vector.";
		else return valoriCampuri[i];

	}
};

class Tabela
{
private:
	string numeTabela = "";
	int numarElemente = 0;
	int numarCampuri = 0;
	Element* elementeTabela = nullptr;
	Camp* campuriTabela = nullptr;

public:
	//constructor
	Tabela(string nume, int nrEl, int nrCampuri, Element* el, Camp* campuri) {
		numeTabela = nume;
		numarElemente = nrEl;
		numarCampuri = nrCampuri;
		elementeTabela = new Element[nrEl];
		for (int i = 0; i < nrEl; i++)
			elementeTabela[i] = el[i];
		campuriTabela = new Camp[nrCampuri];
		for (int j = 0; j < nrCampuri; j++)
			campuriTabela[j] = campuri[j];
	}

	//constructor pentru CREATE TABLE
	Tabela(string nume, Camp* campuri, int nrCampuri) {
		numeTabela = nume;
		numarCampuri = nrCampuri;
		campuriTabela = new Camp[nrCampuri];
		for (int j = 0; j < nrCampuri; j++)
			campuriTabela[j] = campuri[j];
	}

	//constructor pentru comenzi sql
	Tabela(string nume) {
		numeTabela = nume;
	}

	//constructor de copiere
	Tabela(const Tabela& tab) {
		numeTabela = tab.numeTabela;
		numarElemente = tab.numarElemente;
		numarCampuri = tab.numarCampuri;
		elementeTabela = new Element[tab.numarElemente];
		for (int i = 0; i < tab.numarElemente; i++)
			elementeTabela[i] = tab.elementeTabela[i];
		campuriTabela = new Camp[tab.numarCampuri];
		for (int j = 0; j < tab.numarCampuri; j++)
			campuriTabela[j] = tab.campuriTabela[j];
	}

	//constructor default
	Tabela() {}

	//destructor
	~Tabela() {
		if (elementeTabela != nullptr) delete[] elementeTabela;
		if (campuriTabela != nullptr) delete[] campuriTabela;
	}

	//set si get pentru toate campurile
	string getNumeTabela() {
		return numeTabela;
	}
	void setNumeTabela(string nume) {
		if (numeTabela.size() > 0) numeTabela = nume;
	}

	int getNumarCampuri() {
		return numarCampuri;
	}
	void setNumarCampuri(int nr) {
		if (numarCampuri > 0) numarCampuri = nr;
	}

	int getNumarElemente() {
		return numarElemente;
	}
	void setNumarElemente(int nr) {
		if (numarElemente > 0)
			numarElemente = nr;
	}

	Camp* getCampuriTabela() {
		return campuriTabela;
	}
	void setCampuriTabela(Camp* campuri, int nr) {
		if (campuriTabela != nullptr) delete[] campuriTabela;
		numarCampuri = nr;
		campuriTabela = new Camp[nr];
		for (int i = 0; i < nr; i++)
			campuriTabela[i] = campuri[i];
	}

	Element* getElementeTabela() {
		return elementeTabela;
	}
	void setElementeTabela(Element* el, int nr) {
		if (elementeTabela != nullptr) delete[] elementeTabela;
		numarElemente = nr;
		elementeTabela = new Element[nr];
		for (int i = 0; i < nr; i++)
			elementeTabela[i] = el[i];
	}

	//adaug un element in tabela
	void adaugaElementInTabela(Element el) {
		Element* temp = new Element[numarElemente + 1];
		for (int i = 0; i < numarElemente; i++)
			temp[i] = elementeTabela[i];
		temp[numarElemente] = el;
		if (elementeTabela != nullptr) delete[] elementeTabela;
		numarElemente++;
		elementeTabela = new Element[numarElemente];
		for (int i = 0; i < numarElemente; i++)
			elementeTabela[i] = temp[i];
		if (temp != nullptr)  delete[] temp;
	}
	//sterg un element din tabela
	void stergeElementDinTabela(Element el) {
		Element* temp = new Element[numarElemente - 1];
		for (int i = 0; i < numarElemente; i++)
			if (elementeTabela[i] != el)  temp[i] = elementeTabela[i];
		if (elementeTabela != nullptr) delete[] elementeTabela;
		numarElemente--;
		elementeTabela = new Element[numarElemente];
		for (int i = 0; i < numarElemente; i++)
			elementeTabela[i] = temp[i];
		if (temp != nullptr) delete[] temp;
	}
	//afisare in consola
	friend ostream& operator<<(ostream& out, Tabela& tab) {
		out << "Tabela: " << tab.numeTabela << endl;
		out << "Numar de campuri: " << tab.numarCampuri << endl;
		out << "Campurile:" << endl;
		for (int i = 0; i < tab.numarCampuri; i++)
			out << tab.campuriTabela[i] << endl;
		out << "Number of elementeTabela: " << tab.numarElemente << endl;
		out << "elementeTabela:" << endl;
		for (int j = 0; j < tab.numarElemente; j++)
			out << tab.elementeTabela[j] << endl;
		return out;
	}
	//scriere in fisier
	friend ofstream& operator<<(ofstream& out, Tabela& tab) {
		out << tab.numeTabela << endl;
		out << tab.numarCampuri << endl;
		for (int i = 0; i < tab.numarCampuri; i++)
			out << tab.campuriTabela[i] << endl;
		out << tab.numarElemente << endl;
		for (int j = 0; j < tab.numarElemente; j++)
			out << tab.elementeTabela[j] << endl;
		return out;

	}
	//citire din consola
	friend istream& operator>>(istream& in, Tabela& tab) {
		cout << "Tabela: " << endl;
		in >> tab.numeTabela;
		cout << "Number of campuri: " << endl;
		in >> tab.numarCampuri;
		cout << "Numar de elementeTabela: " << endl;
		in >> tab.numarElemente;
		for (int i = 0; i < tab.numarElemente; i++)
			in >> tab.elementeTabela[i];
		for (int i = 0; i < tab.numarCampuri; i++)
			in >> tab.campuriTabela[i];
		return in;
	}
	//citire din fisier
	friend ifstream& operator>>(ifstream& in, Tabela& tab) {
		in >> tab.numeTabela;
		in >> tab.numarCampuri;
		in >> tab.numarElemente;
		for (int i = 0; i < tab.numarElemente; i++)
			in >> tab.elementeTabela[i];
		for (int i = 0; i < tab.numarCampuri; i++)
			in >> tab.campuriTabela[i];
		return in;
	}
	//iau elementul de la o anumita pozitie si il pot modifica
	Element& operator[](int poz) {
		if (poz < 0 || poz > numarElemente)  cout << "Pozitia nu exista in vector";
		else return elementeTabela[poz];
	}
	//verific daca obiectele sunt egale
	bool operator==(Tabela tab) {
		bool campuriDiferite = true;
		if (numeTabela == tab.numeTabela && numarCampuri == tab.numarCampuri && numarElemente == tab.numarElemente) {
			for (int i = 0; i < numarCampuri; i++)
				if (campuriTabela[i] != tab.campuriTabela[i])  campuriDiferite = false;
			if (campuriDiferite) return true;
			return false;
		}
		else return false;
	}
	//verific daca nu avem elemente
	bool operator!() {
		if (elementeTabela != nullptr) return false;
		return true;
	}
	//verificam daca doua tabele sunt diferite, adica daca au nume diferite
	bool operator!=(Tabela tab) {
		if (tab.numeTabela == numeTabela) return false;
		return true;
	}
	//modific obiectul curent cu un alt obiect
	Tabela& operator=(const Tabela& tab) {
		numeTabela = tab.numeTabela;
		numarElemente = tab.numarElemente;
		numarCampuri = tab.numarCampuri;

		if (elementeTabela != nullptr) delete[] elementeTabela;
		if (campuriTabela != nullptr) delete[] campuriTabela;

		elementeTabela = new Element[tab.numarElemente];
		for (int i = 0; i < tab.numarElemente; i++)
			elementeTabela[i] = tab.elementeTabela[i];

		campuriTabela = new Camp[tab.numarCampuri];
		for (int i = 0; i < tab.numarCampuri; i++)
			campuriTabela[i] = tab.campuriTabela[i];

		return *this;
	}
};

class BazaDeDate {
private:
	int numarTabele = 0;
	Tabela* tabele = nullptr;
public:
	//constructor
	BazaDeDate(int nr, Tabela* tab) {
		numarTabele = nr;
		tabele = new Tabela[nr];
		for (int i = 0; i < nr; i++)
			tabele[i] = tab[i];
	}
	//constructor de copiere
	BazaDeDate(const BazaDeDate& bd) {
		numarTabele = bd.numarTabele;
		tabele = new Tabela[bd.numarTabele];
		for (int i = 0; i < bd.numarTabele; i++)
			tabele[i] = bd.tabele[i];
	}
	//constructor default
	BazaDeDate() {}

	//destructor
	~BazaDeDate() {
		if (tabele != nullptr) delete[] tabele;
	}

	//get si set pentru campuri
	int getNumarTabele() {
		return numarTabele;
	}
	void setNumarTabele(int nr) {
		if (nr > 0)
			numarTabele = nr;
	}

	Tabela* getTabele() {
		return tabele;
	}
	void setTabele(Tabela* tabs, int nr) {
		numarTabele = nr;
		for (int i = 0; i < nr; i++)
			tabele[i] = tabs[i];
	}

	//adaug o tabela in baza de date
	void adaugaTabelaInBD(Tabela tab) {
		Tabela* temp = new Tabela[numarTabele + 1];
		for (int i = 0; i < numarTabele; i++)
			temp[i] = tabele[i];
		temp[numarTabele] = tab;
		if (tabele != nullptr) delete[] tabele;
		numarTabele++;
		tabele = new Tabela[numarTabele];
		for (int i = 0; i < numarTabele; i++)
			tabele[i] = temp[i];

		if (temp != nullptr)  delete[] temp;
	}
	//sterg o table din baza de date
	void stergeTabelaDinBD(Tabela tab) {
		Tabela* temp = new Tabela[numarTabele - 1];
		for (int i = 0; i < numarTabele; i++)
			if (tabele[i] != tab)  temp[i] = tabele[i];
		if (tabele != nullptr) delete[] tabele;
		numarTabele--;
		tabele = new Tabela[numarTabele];
		for (int i = 0; i < numarTabele; i++)
			tabele[i] = temp[i];
		if (temp != nullptr) delete[] temp;
	}
	//afisare tabela din baza de date dupa nume
	void afiseazaTabelaDinBD(string numeTabela) {
		bool gasita = false;
		for (int i = 0; i < numarTabele; i++)
			if (numeTabela == tabele[i].getNumeTabela()) {
				cout << tabele[i];
				gasita = true;
				break;
			}
		if (gasita == false) cout << "Tabela nu exista in baza de date.";
	}
	//insereaza in tabela din bd
	void insereazaInTabelaDinBD(Element el, string numeTab) {
		for (int i = 0; i < numarTabele; i++) {
			if (tabele[i].getNumeTabela() == numeTab) {
				tabele[i].adaugaElementInTabela(el);
			}
		}
	}
	//sterge element din tabela din bd
	void stergeDinTabelaDinBD(Element el, string numeTab) {
		for (int i = 0; i < numarTabele; i++) {
			if (tabele[i].getNumeTabela() == numeTab) {
				tabele[i].stergeElementDinTabela(el);
			}
		}
	}

	//modific obiectul curent cu un alt obiect
	BazaDeDate& operator=(const BazaDeDate& bd) {
		numarTabele = bd.numarTabele;
		if (tabele != nullptr) delete[] tabele;
		tabele = new Tabela[bd.numarTabele];
		for (int i = 0; i < bd.numarTabele; i++)
			tabele[i] = bd.tabele[i];
		return *this;
	}
	//afisare in consola
	friend ostream& operator<<(ostream& out, BazaDeDate& bd) {
		out << "Numarul de tabele: " << bd.numarTabele << endl;
		out << "Tabelele: " << endl;
		for (int i = 0; i < bd.numarTabele; i++)
			out << bd.tabele[i] << endl;
		return out;
	}
	//scriere in fisier
	friend ofstream& operator<<(ofstream& out, BazaDeDate& bd) {
		out << bd.numarTabele << endl;
		for (int i = 0; i < bd.numarTabele; i++)
			out << bd.tabele[i] << endl;
		return out;
	}
	//tabela de la pozitia poz
	Tabela& operator[](int poz) {
		if (poz < 0 || poz > numarTabele)  cout << "Pozitia nu exista in vector";
		else return tabele[poz];
	}
};

class Comanda
{
private:
	string numeComanda = "";
	string corpComanda = "";
public:
	//constructor
	Comanda(string nume, string corp) {
		numeComanda = nume;
		corpComanda = corp;
	}
	//constructor default
	Comanda() {}
	//destructor
	~Comanda() {}

	//get si set
	string getNumeComanda() {
		return numeComanda;
	}
	void setNumeComanda(string nume) {
		if (nume.size() > 0) numeComanda = nume;
	}

	string getCorpComanda() {
		return corpComanda;
	}
	void setCorpComanda(string nume) {
		if (nume.size() > 0) corpComanda = nume;
	}

	//afisare la consola
	friend ostream& operator<<(ostream& out, Comanda& comanda) {
		out << "Numele comenzii: " << comanda.numeComanda << endl;
		out << "Corpul comenzii:" << comanda.corpComanda << endl;

		return out;
	}
	//scriere in fisier
	friend ofstream& operator<<(ofstream& out, Comanda& comanda) {
		out << "Numele comenzii: " << comanda.numeComanda << endl;
		out << "Corpul comenzii:" << comanda.corpComanda << endl;
		return out;
	}
	//citire din consola
	friend istream& operator>>(istream& in, Comanda& comanda) {
		cout << "Numele comenzii: " << endl;
		in >> comanda.numeComanda;
		cout << "Corpul comenzii:" << endl;
		in >> comanda.corpComanda;
		return in;
	}
	//citire din fisier
	friend ifstream& operator>>(ifstream& in, Comanda& comanda) {
		cout << "Numele comenzii: " << endl;
		in >> comanda.numeComanda;
		cout << "Corpul comenzii:" << endl;
		in >> comanda.corpComanda;
		return in;
	}
	//modific obiectul curent cu un alt obiect
	Comanda& operator=(const Comanda& comanda) {
		numeComanda = comanda.numeComanda;
		corpComanda = comanda.corpComanda;
		return *this;
	}
};

class ComandaSpeciala :Comanda {
private:
	string parametriiExtra;
public:
	//constructor
	ComandaSpeciala(string nume,string corp, string parametrii) : Comanda(nume, corp) {
		parametriiExtra = parametrii;
	}
	//constructor de copiere
	ComandaSpeciala(const ComandaSpeciala& comanda) : Comanda(comanda) {
		parametriiExtra = comanda.parametriiExtra;
	}
	//constructor default
	ComandaSpeciala():Comanda() {}
	//destructor
	~ComandaSpeciala() {}
	//set si get pentru parametrii
	string getParametriiExtra() {
		return parametriiExtra;
	}
	void setParametriiExtra(string param) {
		parametriiExtra = param;
	}

	//afisare in consola
	friend ostream& operator<<(ostream& out, ComandaSpeciala& com) {
		out << (Comanda&)com;
		out << com.parametriiExtra<< endl;
		return out;
	}
	//citire din consola
	friend istream& operator>>(istream& in, ComandaSpeciala& com) {
		in >> (Comanda&)com;
		cout << "Parametrii extra: " << endl;
		in >> com.parametriiExtra;
		return in;
	}

};

class MetodaSQL {
public:
	Comanda comanda1;
	Comanda comanda2;

	MetodaSQL(Comanda c1, Comanda c2) {
		comanda1 = c1;
		comanda2 = c2;
	}
	MetodaSQL(){}
	~MetodaSQL() {}

	//executa create
	void CreateTable(BazaDeDate& bd, string numeTabela, Camp* campuri, int numarCampuri) {
		Tabela tabela = Tabela(numeTabela, campuri, numarCampuri);
		Tabela* bazaDeDate = bd.getTabele();
		bool exista = false;
		for (int i = 0; i < bd.getNumarTabele(); i++)
			if (bazaDeDate[i].getNumeTabela() == numeTabela) exista = true;
		if (!exista)
			bd.adaugaTabelaInBD(tabela);
		else
			cout << "Tabela exista deja in baza de date!";
	}
	//executa drop
	void DropTable(BazaDeDate& bd, string numeTabela) {
		Tabela tabela = Tabela(numeTabela);
		bd.stergeTabelaDinBD(tabela);
	}
	//executa display
	void DisplayTable(BazaDeDate& bd, string numeTabela) {
		Tabela* bazaDeDate = bd.getTabele();
		bool exista = false;
		for (int i = 0; i < bd.getNumarTabele(); i++)
			if (bazaDeDate[i].getNumeTabela() == numeTabela) {
				cout << bazaDeDate[i] << endl;
				exista = true;
			}
		if (!exista) cout << "Tabela nu exista in baza de date!";
	}
	
	//executa from
	void From(BazaDeDate& bd, string camp, string numeTabela) {
		Tabela* bazaDeDate = bd.getTabele();
		bool exista = false;
		//trec prin baza de date
		for (int i = 0; i < bd.getNumarTabele(); i++)
			//daca gasesc tabela
			if (bazaDeDate[i].getNumeTabela() == numeTabela) {
				exista = true;
				if (camp == "ALL") {
					Element* elemente = bazaDeDate[i].getElementeTabela();
					for (int k = 0; k < bazaDeDate[i].getNumarElemente(); k++) {
						cout << elemente[k] << endl;
					}
				}
				else {
					//trec prin campurile tabelei
					Camp* campuri = bazaDeDate[i].getCampuriTabela();
					for (int j = 0; j < bazaDeDate[i].getNumarCampuri(); j++) {
						//daca gasesc campul
						if (campuri[j].getnumeCamp() == camp) {
							//trec prin elementele tabelei
							Element* elemente = bazaDeDate[i].getElementeTabela();
							for (int k = 0; k < bazaDeDate[i].getNumarElemente(); k++) {
								//afisez valorile de la campul respectiv pentru toate elementele
								cout << elemente[k][j] << endl;
							}
						}
					}
				}
				
			}
	}

	//creare camp din paranteza
	Camp creareCamp(string paranteza) {
		int numarVirgule = 0;
		int poz = 1;
		string cuvant = "";
		Camp camp = Camp();
		while (paranteza.at(poz) != ')') {
			if (paranteza.at(poz) != ',') {
				cuvant = cuvant + paranteza.at(poz);
			}
			else {
				numarVirgule++;
				if (numarVirgule == 1) {
					camp.setnumeCamp(cuvant);
					cuvant = "";
				}
				else if (numarVirgule == 2) {
					camp.settipCamp(cuvant);
				}
				else {
					cout << "Comanda este gresita!";
					return Camp();
				}
			}
			poz++;
		}
		return camp;
	}
	//creare element din paranteza
	Element creareElement(string paranteza) {
		int poz = 1;
		Element element;
		string cuvant = "";
		int nrCuvinte = 0;
		string* cuvinte = new string[nrCuvinte];
		while (paranteza.at(poz) != ')') {
			if (paranteza.at(poz) != ',') {
				cuvant = cuvant + paranteza.at(poz);
			}
			else {
				string* temp = new string[nrCuvinte + 1];
				for (int camp = 0; camp < nrCuvinte; camp++)
					temp[camp] = cuvinte[camp];
				if (cuvinte != nullptr) delete[] cuvinte;
				temp[nrCuvinte] = cuvant;
				nrCuvinte++;
				cuvinte = new string[nrCuvinte];
				for (int camp = 0; camp < nrCuvinte; camp++)
					cuvinte[camp] = temp[camp];
				if(temp != nullptr) delete[] temp;
				cuvant = "";
			}
			poz++;
		}
		//adaugam si ultimul element
		string* temp = new string[nrCuvinte + 1];
		for (int camp = 0; camp < nrCuvinte; camp++)
			temp[camp] = cuvinte[camp];
		if (cuvinte != nullptr) delete[] cuvinte;
		temp[nrCuvinte] = cuvant;
		nrCuvinte++;
		cuvinte = new string[nrCuvinte];
		for (int camp = 0; camp < nrCuvinte; camp++)
			cuvinte[camp] = temp[camp];
		delete[] temp;

		element = Element(cuvinte, nrCuvinte);
		return element;
	}

	//validare corp 2
	bool validareCorp2(string& corp) {
		bool parantezaGasita = false;
		bool parantezaInchisa = false;
		if (corp.at(0) != '(' ) return false;
		if (corp.at(corp.length() - 1) != ')') return false;
		return true;
	}
	//validare create
	bool validareCreate(string& corp, Camp*& campuri, int& nrCampuri) {
		bool parantezaInchisa = false;
		int pozInceputParanteza;
		int i = 0;
			if (corp.at(i) == '(') {
				//ar trebui sa avem paranteza pentru campuri
				if (corp.at(i + 1) == '(') i++;
				parantezaInchisa = false;
				pozInceputParanteza = i;
				for (int j = i + 1; j < corp.length(); j++) {
					if (corp.at(j) == ')' && corp.at(j - 1) != ')') {
						parantezaInchisa = true;
						string paranteza = corp.substr(pozInceputParanteza, j - pozInceputParanteza + 1);
						//adaugare camp in lista
						Camp* temp = new Camp[nrCampuri + 1];
						for (int camp = 0; camp < nrCampuri; camp++)
							temp[camp] = campuri[camp];
						if (campuri != nullptr) delete[] campuri;
						temp[nrCampuri] = creareCamp(paranteza);
						nrCampuri = nrCampuri + 1;
						campuri = new Camp[nrCampuri];
						for (int camp = 0; camp < nrCampuri; camp++)
							campuri[camp] = temp[camp];
						delete[] temp;
					}
					else if (corp.at(j) == '(') {
						parantezaInchisa = false;
						pozInceputParanteza = j;
					}
				}
			}
		return true;
	}


	//executare comanda sql
	void executareComanda(BazaDeDate& bd) {
		if (comanda1.getNumeComanda() == "CREATE_TABLE") {
			//validare corp metoda create
			string corp = comanda2.getNumeComanda();
			int nrCampuri = 0;
			Camp* campuri = new Camp[nrCampuri];
			if (validareCreate(corp, campuri, nrCampuri)) CreateTable(bd, comanda1.getCorpComanda(), campuri, nrCampuri);
			else cout << "Comanda este invalida!";

		}
		else if (comanda1.getNumeComanda() == "DROP_TABLE") {
			string corp = comanda1.getCorpComanda();
			DropTable(bd, corp);
		}
		else if (comanda1.getNumeComanda() == "DISPLAY_TABLE") {
			string corp = comanda1.getCorpComanda();
			DisplayTable(bd, corp);
			
		}
		else if (comanda1.getNumeComanda() == "INSERT_INTO") {
			string corp = comanda1.getCorpComanda();
			executaComanda2(bd, corp);
		}
		else if (comanda1.getNumeComanda() == "SELECT") {
			string corp = comanda1.getCorpComanda();
				executaComanda2(bd, corp);
			}
	}

	void executaComanda2(BazaDeDate& bd, string destinatie) {
		if (comanda2.getNumeComanda() == "VALUES") {
			//validare corp metoda2
			string corp = comanda2.getCorpComanda();
			if (validareCorp2(corp)) {
				bd.insereazaInTabelaDinBD(creareElement(corp), destinatie);
			}
			else cout << "Comanda este invalida!";
		}
		else if (comanda2.getNumeComanda() == "FROM") {
			string corp = comanda2.getCorpComanda();
			From(bd, destinatie, corp);
			
		}
	}

};

void main() {
	Comanda comanda1;
	string numeComanda1;
	string corpComanda1;
	Comanda comanda2;
	string numeComanda2;
	string corpComanda2;
	ComandaSpeciala comandaSpeciala;
	string paramExtra;
	MetodaSQL metoda;
	int nrTabele = 0;
	
	
	//citesc tabele din fisier
	ifstream fisierTabele;
	ofstream scriereInTabela;

	fisierTabele.open("fisierTabele.txt"); 
	if (!fisierTabele) { 
		cout << "Eroare!" << endl;
		exit(1);
	}

	fisierTabele >> nrTabele;

	Tabela* tabele = new Tabela[nrTabele];
	BazaDeDate bd = BazaDeDate(nrTabele, tabele);
	Tabela temp;
	
	while (!fisierTabele.eof()) { 
		fisierTabele >> temp; 
		bd.adaugaTabelaInBD(temp);
	}
	fisierTabele.close();
	cout << bd << endl;

	int comandaConsola = 1;
	while (comandaConsola !=  0) {
		cout << "0.Apasati 0 pentru a iesi din meniu." << endl;
		cout << "1.Apasati 1 pentru a scrie o comanda." << endl; 
		cout << "2.Apasati 2 pentru o comanda speciala." << endl;
		cout << "3.Apasati 3 pentru a salva BD in fisier." << endl;
		cin >> comandaConsola;
		switch (comandaConsola)
		{
			case 1:
				cout << "Prima comanda din secventa: ";
				cin >> numeComanda1;
				cout << "Corpul primei comenzi din secventa: ";
				cin >> corpComanda1;

				//IN CAZUL CREATE TABLE, A DOUA COMANDA DIN SECVENTA VA FI PARANTEZA PENTRU COLOANE
				cout << "A doua comanda din secventa: ";
				cin >> numeComanda2;
				cout << "Corpul celei de-a doua comenzi din secventa: ";
				cin >> corpComanda2;

				comanda1 = Comanda(numeComanda1, corpComanda1);
				comanda2 = Comanda(numeComanda2, corpComanda2);

				metoda.comanda1 = comanda1;
				metoda.comanda2 = comanda2;

				metoda.executareComanda(bd);
				break;
			case 2:
				cout << "Prima comanda din secventa: ";
				cin >> numeComanda1;
				cout << "Corpul primei comenzi din secventa: ";
				cin >> corpComanda1;
				cout << "Parametrii extra: ";
				cin >> paramExtra;
				comandaSpeciala = ComandaSpeciala(numeComanda1, corpComanda1, paramExtra);
				cout << comandaSpeciala;
				break;
			case 3:
				scriereInTabela.open("tabeleSalvate.txt");
				scriereInTabela << bd;
				scriereInTabela.close();
				break;
		}
	}
	
}

