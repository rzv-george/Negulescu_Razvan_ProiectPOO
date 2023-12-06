//Negulescu Razvan-George, Seria B, grupa 1047
//Domeniul:Geografie
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#define HORIZONTAL_BAR cout<<"-------"
#define NOT_AVAILABLEr cout<<"-------N/A"
#define NOT_AVAILABLEl cout<<"N/A-------"
#define GREEN    "\033[32m"
#define RESET   "\033[0m"
#define VERTICAL_BAR cout<<endl << "   |" << endl<<"   |" << endl<<"   |" << endl<<"   |" << endl<<"   |" << endl 
#define SW cout<<" //"<< endl << "//" << endl << "||"<< endl << "||"<< endl << "||"
#define NE cout<<"//" << endl << " //" << endl << " ||"<< endl << " ||"<< endl << " ||"
#define SE cout<<"\\" << endl << " \\" << endl << " ||"<< endl << " ||"<< endl << " ||"
#define NW cout<<" \\"<< endl << "\\" << endl << "||"<< endl << "||"<< endl << "||"
using namespace std;

class Golf {
private:
    string nume_golf;
    int adancime_apa;
    float temp_apa;
    int nr_insule;
    string* nume_insule;
    static int nr_golfuri;
    const int id;

public:

    Golf(string num_golf, int adancime_apa, float temp_apa, int nr_insule, string* nume_insule) : id(nr_golfuri) { //constructor 1
        nr_golfuri++;
        nume_golf = num_golf;
        this->adancime_apa = adancime_apa;
        this->temp_apa = temp_apa;
        this->nr_insule = nr_insule;
        this->nume_insule = new string[nr_insule];
        for (int i = 0; i < nr_insule; ++i) {
            this->nume_insule[i] = nume_insule[i];
        }

    }

    Golf() : id(nr_golfuri) {//constrcutor2
        nr_golfuri++;
        this->nume_golf = "Persic";
        this->adancime_apa = 8;
        this->temp_apa = 14.3;
        this->nr_insule = 0;
        this->nume_insule = NULL;

    }

    Golf(string nume_golf, int nr_insule, string* nume_insule) :id(nr_golfuri) {//constructor3
        nr_golfuri++;
        this->nume_golf = nume_golf;
        this->nr_insule = nr_insule;
        this->nume_insule = new string[nr_insule];
        for (int i = 0; i < nr_insule; ++i) {
            this->nume_insule[i] = nume_insule[i];
        }
        this->temp_apa = 27.9;
        this->adancime_apa = 204;
    }

    Golf(const Golf& gn) :id(nr_golfuri++) { //constructor de copiere
        this->nume_golf = gn.nume_golf;
        this->adancime_apa = gn.adancime_apa;
        this->temp_apa = gn.temp_apa;
        this->nr_insule = gn.nr_insule;
        this->nume_insule = new string[gn.nr_insule];
        for (int i = 0; i < gn.nr_insule; i++)
        {
            this->nume_insule[i] = gn.nume_insule[i];
        }
    }

    Golf operator=(const Golf& gn) { //supraincarcare de operator =
        if (this != &gn) {
            delete[]this->nume_insule;
            this->nume_golf = gn.nume_golf;
            this->adancime_apa = gn.adancime_apa;
            this->temp_apa = gn.temp_apa;
            this->nr_insule = gn.nr_insule;
            if (this->nume_insule != NULL) {
                delete[]this->nume_insule;
            }
            this->nume_insule = new string[gn.nr_insule];
            for (int i = 0; i < gn.nr_insule; i++) {
                this->nume_insule[i] = gn.nume_insule[i];
            }
        }
        nr_golfuri--; //linie pentru a scadea nr de golfuri create; in cazul in care se face atribuire in cascada, acesta va avea +#de atribuiri in cascada, daca nu ar fi ac. linie
        return *this;
    }

    Golf operator-(const Golf& gm) const{//supraincarcare de -
        Golf aux = *this;
        aux.nume_golf = this->nume_golf + " si " + gm.nume_golf;
        aux.adancime_apa = this->adancime_apa - gm.adancime_apa;
        aux.temp_apa = this->temp_apa - gm.temp_apa;
        aux.nr_insule = this->nr_insule - gm.nr_insule;
        if (aux.nume_insule != NULL) {
            delete[]aux.nume_insule;
        }
        aux.nume_insule = new string[aux.nr_insule];
        if (aux.nr_insule < 0) {
            for (int i = 0; i < -(aux.nr_insule); i++) {
                aux.nume_insule[i] = gm.nume_insule[i];
            }
        }
        else if (aux.nr_insule > 0) {
            for (int j = 0; j < aux.nr_insule; j++) {
                aux.nume_insule[j] = this->nume_insule[j];
            }
        }
        return aux;
    }

    Golf operator++(int) {//supraincarcare de ++
        this->adancime_apa++;
        this->temp_apa++;
        nr_golfuri--;
        return *this;
    }

    friend istream& operator>>(istream& intr, Golf& gi) {//supraincarcare de citire
        cout << "Numele: ";
        intr >> gi.nume_golf;
        cout << "Adancimea: ";
        intr >> gi.adancime_apa;
        cout << "Temperatura: ";
        intr >> gi.temp_apa;
        cout << "Numarul de insule: ";
        intr >> gi.nr_insule;
        if (gi.nume_insule != NULL) {
            delete[]gi.nume_insule;
        }
        cout << "Insulele sunt: ";
        gi.nume_insule = new string[gi.nr_insule];
        for (int i = 0; i < gi.nr_insule; i++) {
            intr >> gi.nume_insule[i];
        }
        return intr;
    }

    friend ostream& operator<<(ostream& output, const Golf& Gout) {
        output << "Numele Golfului: " << Gout.nume_golf << endl;
        output << "Adancimea Golfului: " << Gout.adancime_apa << endl;
        output << "Temperatura Golfului: " << Gout.temp_apa << endl;
        output << "Numarul de insule: " << Gout.nr_insule << endl;
        string insule = " ";
        output << "Numele insulelor: " << endl;
        for (int i = 0; i < Gout.nr_insule; i++) {
            insule += Gout.nume_insule[i];
            output << Gout.nume_insule[i] << " ";
        }
        output << endl << endl;
        return output;
    }

    ~Golf() { //destructor
        if (nume_insule != NULL) {
            delete[]this->nume_insule;
        }
    }

    void AfisareGolf() const {
        cout << "Golful " << nume_golf << " (ID: " << id + 1 << ") cu adancimea de " << adancime_apa << " metri si temperatura de " << temp_apa << " grade Celsius." << endl;
        cout << "Numarul de insule: " << nr_insule << ", Numele insulelor: ";
        if (nr_insule > 0) {
            for (int i = 0; i < nr_insule; ++i) {
                cout << nume_insule[i] << " ";
            }
        }
        else {
            cout << "N/A";
        }
        cout << endl << endl;
    }

    friend ifstream& operator>>(ifstream& cit, Golf& gcf) {
        cit >> gcf.nume_golf;
        cit >> gcf.temp_apa;
        cit >> gcf.adancime_apa;
        cit >> gcf.nr_insule;
        if (gcf.nume_insule != NULL) {
            delete[]gcf.nume_insule;
        }
        gcf.nume_insule = new string[gcf.nr_insule];
        for (int i = 0; i < gcf.nr_insule; i++) {
            cit >> gcf.nume_insule[i];
        }
        return cit;
    }

    friend ofstream& operator<< (ofstream& output, const Golf& Gout) {
        output << Gout.nume_golf << " ";
        output << Gout.temp_apa << " ";
        output << Gout.adancime_apa << " ";
        output << Gout.nr_insule << " ";
        string insule = " ";
        for (int i = 0; i < Gout.nr_insule; i++) {
            insule += Gout.nume_insule[i];
            output << Gout.nume_insule[i] << " ";
        }
        return output;
    }
    //-------getteri--------
    string getNumeGolf() {
        return nume_golf;
    }
    int getAdancimeApa() {
        return adancime_apa;
    }
    float getTempApa() {
        return temp_apa;
    }
    int getNrInsule() {
        return nr_insule;
    }
    string* getNumeInsule() const {
        return nume_insule;
    }
    static int getnr_golfuri() { //functie statica
        return nr_golfuri;
    }
    //-------setteri--------
    void setNumeGolf(const string& nume) {
        nume_golf = nume;
    }
    void setAdancimeApa(const int& adancime) {
        adancime_apa = adancime;
    }
    void setTempApa(const float& temperatura) {
        temp_apa = temperatura;
    }
    void setNrInsule(const int& nr) {
        nr_insule = nr;
    }
    void setInsule(const int nr_insule, string* nume_insule) {
        if (nr_insule > 0) {
            if (this->nume_insule != NULL) {
                delete[] this->nume_insule;
            }
            this->nr_insule = nr_insule;
            this->nume_insule = new string[nr_insule];
            for (int i = 0; i < nr_insule; i++) {
                this->nume_insule[i] = nume_insule[i];
            }
        }
    }
    friend string getSirInsule(const Golf& g);
    friend bool compGolf(const Golf& golf1, const Golf& golf2);
};

string getSirInsule(const Golf& g) {
    string auxI = " ";
    for (int i = 0; i < g.nr_insule; i++) {
        auxI += g.nume_insule[i] + ',';
    }
    cout << "Insulele Goflului " << g.id + 1 << " ,respectiv Golful " << g.nume_golf << " ,sunt:";
    return auxI;
}

bool compGolf(const Golf& golf1, const Golf& golf2) {
    return (golf1.nume_golf == golf2.nume_golf &&
        golf1.adancime_apa == golf2.adancime_apa &&
        golf1.temp_apa == golf2.temp_apa);
}

class Rau {
private:
    string nume_rau;
    int lungime;
    float debit;
    bool are_delta;
    int nr_tari;
    string* tari;
    static int nr_rauri;
    const int id;

public:

    Rau() : id(nr_rauri) { //constructor 1
        nr_rauri++;
        this->nume_rau = "Huang";
        this->lungime = 14;
        this->debit = 19.3;
        this->are_delta = false;
        this->nr_tari = 0;
        this->tari = NULL;
    }

    Rau(string nume_rau, int lungime, float debit, bool are_delta, int nr_tari, string* tari) : id(nr_rauri) { //constructor 2
        nr_rauri++;
        this->nume_rau = nume_rau;
        this->lungime = lungime;
        this->debit = debit;
        this->are_delta = are_delta;
        this->nr_tari = nr_tari;
        this->tari = new string[nr_tari];
        for (int i = 0; i < nr_tari; i++) {
            this->tari[i] = tari[i];
        }
    }

    Rau(bool are_delta, int nr_tari, string* tari) : id(nr_rauri) { //constructor 3
        nr_rauri++;
        this->nume_rau = "Volga";
        this->lungime = 879;
        this->debit = 20000;
        this->are_delta = true;
        this->nr_tari = nr_tari;
        this->tari = new string[nr_tari];
        for (int i = 0; i < nr_tari; i++) {
            this->tari[i] = tari[i];
        }
    }

    Rau(const Rau& rn) : id(nr_rauri++) { //constructor de copiere
        this->nume_rau = rn.nume_rau;
        this->lungime = rn.lungime;
        this->debit = rn.debit;
        this->are_delta = rn.are_delta;
        this->nr_tari = rn.nr_tari;
        this->tari = new string[rn.nr_tari];
        for (int i = 0; i < rn.nr_tari; i++) {
            this->tari[i] = rn.tari[i];
        }
    }

    Rau operator=(const Rau& rn) { //supraincarcare de operator =
        this->nume_rau = rn.nume_rau;
        this->lungime = rn.lungime;
        this->debit = rn.debit;
        this->are_delta = rn.are_delta;
        this->nr_tari = rn.nr_tari;
        if (this->tari != NULL) {
            delete[]this->tari;
        }
        this->tari = new string[rn.nr_tari];
        for (int i = 0; i < rn.nr_tari; i++) {
            this->tari[i] = rn.tari[i];
        }
        nr_rauri--;
        return *this;
    }

    Rau operator+(const Rau& rpl) const { //supraincarcare de operator+
        Rau aux = *this;
        aux.nume_rau = this->nume_rau + " si " + rpl.nume_rau;
        aux.lungime = this->lungime + rpl.lungime;
        aux.debit = this->debit + rpl.debit;
        aux.nr_tari = this->nr_tari + rpl.nr_tari;
        if (aux.tari != NULL) {
            delete[]aux.tari;
        }
        aux.tari = new string[aux.nr_tari];
        for (int i = 0; i < this->nr_tari; i++) {
            aux.tari[i] = this->tari[i];
        }
        for (int i = this->nr_tari; i < rpl.nr_tari; i++) {
            aux.tari[i] = rpl.tari[i - this->nr_tari];
        }
        return aux;
    }

    friend ostream& operator<<(ostream& afis, const Rau& Ro) { //supraincarcare de operator <<
        afis << "Numele raului: " << Ro.nume_rau << endl;
        afis << "Debitul raului: " << Ro.debit << endl;
        afis << "Lungimea raului: " << Ro.lungime << endl;
        afis << "Verificam daca raul are delta(1-da, 0-nu): " << Ro.are_delta << endl;
        afis << "Numarul tarilor prin care raul trece: " << Ro.nr_tari << endl;
        string tari = " ";
        afis << "Numele tarilor prin care raul trece: " << endl;
        for (int i = 0; i < Ro.nr_tari; i++) {
            tari += Ro.tari[i];
            afis << Ro.tari[i] << " ";
        }

        afis << endl << endl;
        nr_rauri--;
        return afis;
    }

    friend ofstream& operator<<(ofstream& afis, const Rau& Ro) {
        afis << Ro.nume_rau << " ";
        afis << Ro.debit << " ";
        afis << Ro.lungime << " ";
        afis << Ro.are_delta << " ";
        afis << Ro.nr_tari << " ";
        string tari = " ";
        for (int i = 0; i < Ro.nr_tari; i++) {
            tari += Ro.tari[i];
            afis << Ro.tari[i] << " ";
        }
        nr_rauri--;
        return afis;
    }

    friend istream& operator>>(istream& cit, Rau& rr) {
        cout << "Numele: ";
        cit >> rr.nume_rau;
        cout << "Debit: ";
        cit >> rr.debit;
        cout << "Lungime: ";
        cit >> rr.lungime;
        cout << "Are delta: ";
        cit >> rr.are_delta;
        cout << "Numarul de tari prin care trece este: ";
        cit >> rr.nr_tari;
        if (rr.tari != NULL) {
            delete[]rr.tari;
        }
        cout << "Tarile sunt: ";
        rr.tari = new string[rr.nr_tari];
        for (int i = 0; i < rr.nr_tari; i++) {
            cit >> rr.tari[i];
        }
        return cit;
    }

    friend ifstream& operator>>(ifstream& cit, Rau& rr) {
        cit >> rr.nume_rau;
        cit >> rr.debit;
        cit >> rr.lungime;
        cit >> rr.are_delta;
        cit >> rr.nr_tari;
        if (rr.tari != NULL) {
            delete[]rr.tari;
        }
        rr.tari = new string[rr.nr_tari];
        for (int i = 0; i < rr.nr_tari; i++) {
            cit >> rr.tari[i];
        }
        return cit;
    }

    bool operator<(Rau& r) { //supraincarcare de operator < pentru atributul de lungime
        nr_rauri--;
        return this->lungime < r.lungime;
    }

    ~Rau() { //destructor
        if (this->tari != NULL) {
            delete[]this->tari;
        }
    }

    void AfisareRau() const { //metoda de afisare
        cout << "Raul " << nume_rau << " (ID: " << id + 1 << ") are o lungime de " << lungime << " kilometri si un debit de apa de " << debit << " metri cubi pe secunda." << endl;
        cout << "Are delta: " << (are_delta ? "Da" : "Nu") << endl;
        cout << "Numarul de tari prin care trece: " << nr_tari << endl << "Numele tarilor: " << endl;
        if (nr_tari > 0) {
            for (int i = 0; i < nr_tari; ++i) {
                cout << "->" << tari[i] << endl;
            }
        }
        else {
            cout << "N/A";
        }
        cout << endl << endl;
    }

    //-----getteri-----
    string getNumeRau() {
        return nume_rau;
    }
    int getLungime() {
        return lungime;
    }
    float getDebit() {
        return debit;
    }
    bool getAreDelta() {
        return are_delta;
    }
    int getNrTari() {
        return nr_tari;
    }
    static int getnumar_rauri() {
        return nr_rauri;
    }
    string* getTari() const {
        return tari;
    }
    //-----setteri-----
    void setNumeRau(const string& nume) {
        nume_rau = nume;
    }
    void setLungime(const int& length) {
        lungime = length;
    }
    void setDebit(const float& dbt) {
        debit = dbt;
    }
    void setAreDelta(const bool& delta) {
        are_delta = delta;
    }
    void setTari(const int nr_tari, string* tari) {
        if (nr_tari > 0) {
            if (this->tari != NULL) {
                delete[] this->tari;
            }
            this->nr_tari = nr_tari;
            this->tari = new string[nr_tari];
            for (int i = 0; i < nr_tari; i++) {
                this->tari[i] = tari[i];
            }
        }
    }
    friend string getSirTari(const Rau& r);
    friend string getCapitalaTari(const Rau& r, const string capitale[]);
};

string getSirTari(const Rau& r) {
    string auxR = " ";
    for (int i = 0; i < r.nr_tari; i++) {
        auxR += r.tari[i] + ',';
    }
    cout << "Tarile prin care Raul " << r.id + 1 << " ,respectiv raul " << r.nume_rau << " , trece sunt:";
    return auxR;
}

string getCapitalaTari(const Rau& r, const string capitale[]) {
    string result = " ";
    for (int i = 0; i < r.nr_tari; ++i) {
        if (i < r.nr_tari) {
            result += r.getTari()[i] + ": " + capitale[i] + "\n";
        }
        else {
            result += r.getTari()[i] + ": Capitala necunoscuta\n";
        }
    }
    return result;
}

class Natiune {
public:
    string nume;
private:
    int marime_natiune;
    int nr_vecini;
    string* nume_vecin;
    static int nr_natiune;
    const int id_natiune;

public:

    Natiune(string nume, int marime_natiune, int nr_vecini, string* nume_vecin) :id_natiune(nr_natiune) { //c1
        nr_natiune++;
        this->nume = nume;
        this->marime_natiune = marime_natiune;
        this->nr_vecini = nr_vecini;
        this->nume_vecin = new string[nr_vecini];
        for (int i = 0; i < nr_vecini; i++)
        {
            this->nume_vecin[i] = nume_vecin[i];
        }

    }

    Natiune(int nr_vecini, string* nume_vecin) :id_natiune(nr_natiune) { // c2
        nr_natiune++;
        this->nume = "Liechtenstein";
        this->marime_natiune = 78290;
        this->nr_vecini = nr_vecini;
        this->nume_vecin = new string[nr_vecini];
        for (int i = 0; i < nr_vecini; i++)
        {
            this->nume_vecin[i] = nume_vecin[i];
        }

    }

    Natiune() : id_natiune(nr_natiune) { //c3
        nr_natiune++;
        this->nume = "Australia";
        this->marime_natiune = 12000000;
        this->nr_vecini = 0;
        this->nume_vecin = NULL;
    }

    Natiune(const Natiune& nn) : id_natiune(nr_natiune++) { //constructor de copiere
        this->nume = nn.nume;
        this->marime_natiune = nn.marime_natiune;
        this->nr_vecini = nn.nr_vecini;
        this->nume_vecin = new string[nn.nr_vecini];
        for (int i = 0; i < nn.nr_vecini; i++) {
            this->nume_vecin[i] = nn.nume_vecin[i];
        }
    }

    Natiune operator=(const Natiune& nn) { //supraincarcare operator =
        this->nume = nn.nume;
        this->marime_natiune = nn.marime_natiune;
        this->nr_vecini = nn.nr_vecini;
        if (nume_vecin != NULL) {
            delete[]this->nume_vecin;
        }
        this->nume_vecin = new string[nn.nr_vecini];
        for (int i = 0; i < nn.nr_vecini; i++) {
            this->nume_vecin[i] = nn.nume_vecin[i];
        }
        nr_natiune--;
        return *this;
    }

    friend ostream& operator<<(ostream& o, const Natiune& no) {
        o << "Numele Natiunii: " << no.nume << endl;
        o << "Marimea Natiunii: " << no.marime_natiune << endl;
        o << "Numarul de vecini: " << no.nr_vecini << endl;
        o << "Numele Vecinilor este: " << endl;
        string vecini = " ";
        for (int i = 0; i < no.nr_vecini; i++) {
            vecini += no.nume_vecin[i];
            o << no.nume_vecin[i] << " ";
        }
        o << endl << endl;
        return o;
    }
    friend ofstream& operator<<(ofstream& o, const Natiune& no) {
        o << no.nume << endl;
        o << no.marime_natiune << endl;
        o << no.nr_vecini << endl;
        o << endl;
        string vecini = " ";
        for (int i = 0; i < no.nr_vecini; i++) {
            vecini += no.nume_vecin[i];
            o << no.nume_vecin[i] << " ";
        }
        o << endl << endl;
        return o;
    }

    ~Natiune() { //destructor
        if (this->nume_vecin != NULL) {
            delete[]this->nume_vecin;
        }
    }

    void afisareInfoNatiune() const { //afisare
        cout << "Tara " << nume << " cu ID-ul (" << id_natiune + 1 << ") are o populatie de " << marime_natiune << " oameni si este conectata la " << nr_vecini << " alte tari: " << endl;
        if (nr_vecini > 0)
        {

            for (int i = 0; i < nr_vecini / 2; i++)
            {
                cout << nume_vecin[i]; HORIZONTAL_BAR;
            }
            cout << GREEN << nume << RESET;
            for (int i = nr_vecini / 2; i < nr_vecini; i++)
            {
                HORIZONTAL_BAR; cout << nume_vecin[i];
            }
        }
        else { NOT_AVAILABLEl; cout << GREEN << nume << RESET; NOT_AVAILABLEr; }
        cout << endl << endl;
    }
    //-----getteri-----
    string getNumeNatiune() {
        return nume;
    }
    int getMarimeNatiune() {
        return marime_natiune;
    }
    int getNrVecini() {
        return nr_vecini;
    }
    string* getNumeVecini() {
        return nume_vecin;
    }
    static int getnr_natiuni() {
        return nr_natiune;
    }
    //-----setteri-----
    void setNumeNatiune(string nume) {
        this->nume = nume;
    }
    void setMarimeNatiune(int marime) {
        this->marime_natiune = marime;
    }
    void setVecini(const int nr_vecini, string* vecin) {
        if (nr_vecini > 0) {
            if (this->nume_vecin != NULL) {
                delete[]this->nume_vecin;
            }
            this->nr_vecini = nr_vecini;
            this->nume_vecin = new string[nr_vecini];
            for (int i = 0; i < nr_vecini; i++) {
                this->nume_vecin[i] = vecin[i];
            }
        }
    }

    friend istream& operator>>(istream& intr, Natiune& n) { //supraincarcare de citire
        cout << "Numele natiunii: ";
        intr >> n.nume;
        cout << "Marimea Populatiei: ";
        intr >> n.marime_natiune;
        cout << "Numar de vecini: ";
        intr >> n.nr_vecini;
        if (n.nume_vecin != NULL) {
            delete[]n.nume_vecin;
        }
        cout << "Vecinii sunt:";
        n.nume_vecin = new string[n.nr_vecini];
        for (int i = 0; i < n.nr_vecini; i++) {
            intr >> n.nume_vecin[i];
            cout << n.nume_vecin[i];
        }
        return intr;
    }

    friend ifstream& operator>>(ifstream& intr, Natiune& n) { //supraincarcare de citire
        intr >> n.nume;
        intr >> n.marime_natiune;
        intr >> n.nr_vecini;
        if (n.nume_vecin != NULL) {
            delete[]n.nume_vecin;
        }
        n.nume_vecin = new string[n.nr_vecini];
        for (int i = 0; i < n.nr_vecini; i++) {
            intr >> n.nume_vecin[i];
            cout << n.nume_vecin[i];
        }
        return intr;
    }

    string& operator[](int i) { //supraincarcare de indexare
        if (i >= 0 && i < this->nr_vecini) {
            return nume_vecin[i];
        }
    }

    explicit operator int() {
        return this->marime_natiune;
    }

    friend string getSirTari(const Natiune& n);
    friend float mediaPopulatiei(const Natiune& tara1, const Natiune& tara2);
};

class Continent {
private:
    string nume;
    int marime_continent;
    Natiune natiune;
public:
    Continent() {
        this->nume = "Africa";
        this->marime_continent = 123455;
    }
    Continent(string nume, int marime_continent, Natiune& nat){
        this->nume = nume;
        this->marime_continent = marime_continent;
        this->natiune = nat;
    }
    Continent(Natiune& nat) {
        this->nume = "Africa";
        this->marime_continent = 6969;
        this->natiune = nat;
    }
    void afisareContinet() {
        cout << "Numele Continentului este: " << nume << endl << "Marimea Continentului este de: " << marime_continent << endl;
        natiune.afisareInfoNatiune();
    }
    void setNume(string nume) {
        this->nume = nume;
    }
    void setMarimeCont(int marime_continent) {
        this->marime_continent = marime_continent;
    }
    string getNume() {
        return nume;
    }
    int getMarimeContinent(){
        return marime_continent;
    }
    int GetNatCont() {
        cout << "Tara " << natiune.getNumeNatiune() << " apartine continentului " << nume << ", continent cu o marime de ";
        return marime_continent;
    }
    void setNatCont(Natiune& natiune) {
        this->natiune = natiune;
    }
    Continent operator=(const Continent& cc) { //supraincarcare operator =
        this->nume = cc.nume;
        this->marime_continent = cc.marime_continent;
        this->natiune = cc.natiune;
        return *this;
    }
    friend ostream& operator<<(ostream& afis, const Continent& co) {
        afis << "Numele cont: " << co.nume << endl;
        afis << "Marimea cont: " << co.marime_continent << endl;
        afis << "INFORMATII DESPRE NATIUNE: " << co.natiune;
        return afis;
    }
    friend ofstream& operator<<(ofstream& afis, const Continent& co) {
        afis << co.nume << endl;
        afis << co.marime_continent << endl;
        afis << co.natiune;
        return afis;
    }
    friend ifstream& operator>>(ifstream& cit, Continent& ci) {
        cit >> ci.nume;
        cit >> ci.marime_continent;
        cit >> ci.natiune;
        return cit;
    }
};

string getSirTari(const Natiune& n) {
    string auxN = " ";
    for (int i = 0; i < n.nr_vecini; i++) {
        auxN += n.nume_vecin[i] + ", ";
    }
    cout << "Tarile Vecine pentru Tara " << n.nume << " ,respectiv tara cu ID-ul "
        << n.id_natiune + 1 << ", sunt:";
    return auxN;
}

float mediaPopulatiei(const Natiune& tara1, const Natiune& tara2) {
    float media = (tara1.marime_natiune + tara2.marime_natiune) / 2;
    return media;
}

class TaraInsulara : public Natiune{
private:
    string ocean;
    int nrInsule;
public:
    string nume[1] = {" "};
    TaraInsulara() : Natiune() {
        this->ocean = "Pacific";
        this->nrInsule = 456;
    }
    TaraInsulara(string ocean, int nrInsule) : Natiune("Filipine", 170834809, 0, nume) {
        this->ocean = ocean;
        this->nrInsule = nrInsule;
    }
    TaraInsulara(const TaraInsulara& ti) : Natiune(ti){
        this->ocean = ti.ocean;
        this->nrInsule = ti.nrInsule;
    }
    TaraInsulara operator=(const TaraInsulara& ti) {
        if (this != &ti) {
            (Natiune)*this = (Natiune)ti;
            this->ocean = ti.ocean;
            this->nrInsule = ti.nrInsule;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const TaraInsulara& t) {
        out << (Natiune)t << endl;
        out << "Tara se afla in oceanul " << t.ocean << " si are " << t.nrInsule << " insule." << endl;
        return out;
    }
    string getOcean() {
        return ocean;
    }
    int getnrInsule() {
        return nrInsule;
    }
    void setOcean(string ocean) {
        this->ocean = ocean;
    }
    void setNrInsule(int nr) {
        this->nrInsule = nr;
    }
};

class RauriRomanesti : public Rau {
private:
    char* numeJudetIZV;
    int nrJudete;
    bool extraNational;
public:
    string rom[3] = {"Romania", "Moldova"};
    RauriRomanesti() : Rau(false, 1, rom) {
        this->nrJudete = 7;
        this->numeJudetIZV = new char[strlen("Dambovita") + 1];
        strcpy_s(this->numeJudetIZV, strlen("Dambovita") + 1, "Dambovita");
        this->extraNational = false;
    }
    RauriRomanesti(const char* numeIzv, int judete, bool exnat) : Rau(false, 2, rom) {
        this->nrJudete = judete;
        this->numeJudetIZV = new char[strlen(numeIzv) + 1];
        strcpy_s(this->numeJudetIZV, strlen(numeIzv) + 1, numeIzv);
        this->extraNational = exnat;
    }
    RauriRomanesti(const RauriRomanesti& r) :Rau(r) {
        this->numeJudetIZV = new char[strlen(r.numeJudetIZV) + 1];
        strcpy_s(this->numeJudetIZV, strlen(r.numeJudetIZV) + 1, r.numeJudetIZV);
        this->nrJudete = r.nrJudete;
        this->extraNational = r.extraNational;
    }
    RauriRomanesti operator=(const RauriRomanesti& r) {
        if (this != &r) {
            (Rau)*this = (Rau)r;
            if (this->numeJudetIZV != NULL) {
                delete[]this->numeJudetIZV;
            }
            this->numeJudetIZV = new char[strlen(r.numeJudetIZV) + 1];
            strcpy_s(this->numeJudetIZV, strlen(r.numeJudetIZV) + 1, r.numeJudetIZV);
            this->nrJudete = r.nrJudete;
            this->extraNational = r.extraNational;
        }
        return *this;
    }
    ~RauriRomanesti() {
        if (this->numeJudetIZV) {
            delete[]this->numeJudetIZV;
        }
    }
    friend ostream& operator<<(ostream& out, const RauriRomanesti& rr) {
        out << (Rau)rr << endl;
        out << "Raul Romanesc trece prin " << rr.nrJudete << " judete, izvorand din " << rr.numeJudetIZV;
        out << endl << (rr.extraNational ? "Raul se afla si in alte tari decat Romania" : "Raul se afla numai in Romania");
        return out;
    }
    int getNrJudete() {
        return nrJudete;
    }
    void setNrJudete(int jud) {
        this->nrJudete = jud;
    }
};

int Rau::nr_rauri = 0;
int Golf::nr_golfuri = 0;
int Natiune::nr_natiune = 0;

int main() {
    string nume_insule[] = { "Insula1", "Insula2", "Insula3" };
    Golf golf1("Mexic", 1200, 25.5, 3, nume_insule);
    Golf golf2;
    Golf golf3("Arctic", 2, nume_insule);
    Golf golf4(golf3);
    Golf golf5;
    Golf golf6;
    golf6 = golf5 = golf1;
    Golf golf7;
    golf7 = golf3 - golf2; //op -
    Golf golf8;
    //cin >> golf8; //op >>

    golf1.AfisareGolf();
    golf2.AfisareGolf();
    golf3.AfisareGolf();
    golf4.AfisareGolf();
    golf5.AfisareGolf();
    golf6.AfisareGolf();
    golf7.AfisareGolf();
    golf8.AfisareGolf();

    int var = golf4.getNrInsule();

    cout << golf4.getNumeGolf() << endl << golf3.getAdancimeApa() << endl << golf4.getTempApa() << endl << golf4.getNrInsule() << endl;
    int i = 0;
    while (i < var) {
        cout << *(golf4.getNumeInsule() + i) << " ";
        i++;
    }
    cout << endl;
    golf5.setNumeGolf("JOKI");
    golf5.setAdancimeApa(890);
    golf5.setTempApa(33.5);
    golf5.setInsule(3, nume_insule);
    golf5.AfisareGolf();

    cout << getSirInsule(golf1) << endl;
    if (compGolf(golf1, golf2)) {
        cout << "Golf A este la fel ca Golf B." << endl;
    }
    else {
        cout << "Golf A este diferit de Golf B." << endl;
    }

    golf3++; //op ++
    golf3.AfisareGolf();

    cout << endl << endl;
    /*const int numar_obiecteG = 2;
    vector<Golf> vectorGolf(numar_obiecteG);

    for (int i = 0; i < numar_obiecteG; ++i) {
        cout << "Introduceti datele pentru obiectul Golf la pozitia " << i << ":\n";
        cin >> vectorGolf[i];
    }
    cout << endl << endl;
    for (int i = 0; i < numar_obiecteG; ++i) {
        cout << "Afisare obiect Golf la pozitia " << i << ":\n";
        cout << vectorGolf[i];
    }

    const int numar_linii = 2;
    const int numar_coloane = 2;

    Golf matriceGolf[numar_linii][numar_coloane];

    for (int i = 0; i < numar_linii; ++i) {
        for (int j = 0; j < numar_coloane; ++j) {
            cout << "Introduceti datele pentru obiectul Golf la pozitia [" << i << "][" << j << "]:\n";
            cin >> matriceGolf[i][j];
            cout << endl;
        }
    }

    for (int i = 0; i < numar_linii; ++i) {
        for (int j = 0; j < numar_coloane; ++j) {
            cout << "Afisare obiect Golf la pozitia [" << i << "][" << j << "]:\n";
            cout << matriceGolf[i][j];
        }
    }*/

    /*ofstream afisare("textGolf.txt", ios::out);
    afisare << golf1;
    afisare.close();
    ifstream intrare("textGolf.txt", ios::in);
    Golf g1;
    intrare >> g1;
    cout << g1;
    intrare.close();*/

    cout << endl << "Au fost create " << Golf::getnr_golfuri() << " golfuri";
    cout << endl << endl << endl << endl;
    cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/--/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-";
    cout << endl << endl << endl << endl;
    //--------------------------------

    string tariVolga[] = { "Rusia", "Moldova", "Kazakhstan" };
    string tariIalomita[] = { "Romania" };
    string CapitaleVolga[] = { "Moscova", "Chisinau", "Astana" };
    string CapitaleIalomita[] = { "Bucuresti" };

    Rau rau1(true, 3, tariVolga);
    Rau rau2;
    Rau rau3("Ialomita", 400, 234.3, true, 1, tariIalomita);
    Rau rau4 = rau3;
    Rau rau5;
    Rau rau6;
    rau6 = rau5 = rau1;
    Rau rau7;
    rau7 = rau3 + rau2; //op +

    rau1.AfisareRau();
    rau2.AfisareRau();
    rau3.AfisareRau();
    rau4.AfisareRau();
    rau5.AfisareRau();
    rau6.AfisareRau();
    rau7.AfisareRau();

    cout << rau1; //op <<

    cout << rau3.getDebit() << endl << "(Daca este 1, are delta , daca este 0 este nu are delta): " << rau3.getAreDelta() << endl
        << rau3.getLungime() << endl << rau3.getNumeRau() << endl << rau3.getNrTari() << endl;
    int varR = rau3.getNrTari();
    int j = 0;
    while (j < varR) {
        cout << *(rau3.getTari() + j) << endl;
        j++;
    }
    cout << endl;
    rau1.setAreDelta(0);
    rau1.setDebit(789.34555);
    rau1.setLungime(568);
    rau1.setNumeRau("Kaztok");
    rau1.setTari(2, tariVolga);
    rau1.AfisareRau();

    string capitaleTariV = getCapitalaTari(rau1, CapitaleVolga);
    cout << "Capitalele tarilor prin care trece raul " << rau1.getNumeRau() << " sunt:" << endl << capitaleTariV;
    string capitaleIalomita = getCapitalaTari(rau3, CapitaleIalomita);
    cout << "Capitalele tarilor prin care trece raul " << rau3.getNumeRau() << " sunt:" << endl << capitaleIalomita;

    cout << getSirTari(rau1) << endl;

    cout << endl;

    if (rau1 < rau2) { //op <
        cout << "Raul " << rau2.getNumeRau() << " este mai lung";
    }
    else
        cout << "Raul " << rau1.getNumeRau() << " este mai lung";
    cout << endl << endl;
    /*const int numar_obiecteR = 2;
    vector <Rau> vectorRau(numar_obiecteR);

    for (int i = 0; i < numar_obiecteR; ++i) {
        cout << "Introduceti datele pentru obiectul Rau la pozitia " << i << ":\n";
        cin >> vectorRau[i];
    }
    cout << endl << endl;
    for (int i = 0; i < numar_obiecteR; ++i) {
        cout << "Afisare obiect Rau la pozitia " << i << ":\n";
        cout << vectorRau[i];
    }*/

   /* ofstream afisareR("textRau.txt", ios::out);
    afisareR << rau1;
    afisareR.close();
    ifstream intrareR("textRau.txt", ios::in);
    Rau r2;
    intrareR >> r2;
    cout << r2;
    intrareR.close()*/;

    cout << endl << "Au fost create " << Rau::getnumar_rauri() << " rauri";

    cout << endl << endl << endl << endl;
    cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/--/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-";
    cout << endl << endl << endl << endl;

    //----------------------------------

    string nume_veciniRO[] = { "Ungaria", "Ucraina", "Moldova", "Serbia", "Bulgaria" };
    string nume_veciniLH[] = { "Elvetia", "Austria" };

    cout << "Tara despre care se vorbeste va fi highlighted cu verde" << endl;

    Natiune natiune1;
    Natiune natiune2(2, nume_veciniLH);
    Natiune natiune3("Romania", 19000000, 5, nume_veciniRO);
    Natiune natiune4 = natiune3;
    Natiune natiune5;
    Natiune natiune6;
    natiune6 = natiune5 = natiune2;
    Natiune natiune7;
    //cin >> natiune7;

    natiune1.afisareInfoNatiune();
    natiune2.afisareInfoNatiune();
    natiune3.afisareInfoNatiune();
    natiune4.afisareInfoNatiune();
    natiune5.afisareInfoNatiune();
    natiune6.afisareInfoNatiune();
    natiune7.afisareInfoNatiune();

    cout << natiune4.getMarimeNatiune() << endl << natiune4.getNumeNatiune() << endl << natiune4.getNrVecini() << endl;
    int varN = natiune4.getNrVecini();
    int Na = 0;
    while (Na < varN)
    {
        cout << "->" << *(natiune4.getNumeVecini() + Na) << endl;
        Na++;
    }
    natiune2.setMarimeNatiune(69803);
    natiune2.setNumeNatiune("Liechtenstein");
    natiune2.setVecini(1, nume_veciniLH);
    cout << endl;
    natiune2.afisareInfoNatiune();

    cout << getSirTari(natiune4) << endl;
    cout << "Media populatiei dintre " << natiune1.getNumeNatiune() << " si " << natiune2.getNumeNatiune() << " este de " << fixed << setprecision(2) << mediaPopulatiei(natiune1, natiune2) << endl;
    cout << natiune3[0] << endl;
    int valIn = 10;
    valIn = (int)natiune3;
    cout << valIn;
    cout << endl << endl;
    /* const int numar_obiecteN = 2;
     vector <Natiune> vectorNatiuni(numar_obiecteN);

     for (int i = 0; i < numar_obiecteN; ++i) {
         cout << "Introduceti datele pentru obiectul Natiune la pozitia " << i << ":\n";
         cin >> vectorNatiuni[i];
     }
     cout << endl << endl;
     for (int i = 0; i < numar_obiecteN; ++i) {
         cout << "Afisare obiect Natiune la pozitia " << i << ":\n";
         cout << vectorNatiuni[i];
     }*/
    Natiune nat;
    /*fstream natiuneAfis("NatiuniOut.bin", ios::out | ios::binary);
    natiuneAfis.write((char*)&nat, sizeof(Natiune));
    natiuneAfis.close();*/

    cout << endl << "Au fost create " << Natiune::getnr_natiuni() << " natiuni" << endl;

    cout << endl << endl << endl << endl;
    cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/--/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-";
    cout << endl << endl << endl << endl;

    Continent continent("Europa", 12345, natiune3);
    Continent continent2(natiune1);
    Continent continent3(natiune2);
    Continent continent4(natiune5);
    Continent continent5(natiune6);
    Continent c6;
    continent5 = continent;
    continent.afisareContinet();
    continent2.getNume();
    cout << continent.GetNatCont() << endl;
    continent.afisareContinet();
    continent2.afisareContinet();
    cout << endl << endl;
    cout << continent3;
    //cin >> continent4;
    cout << continent4;
    cout << continent5;
    Continent cont6;
    /*fstream contAfis("ContinenteOut.bin", ios::out | ios::binary);
    contAfis.write((char*)&cont6, sizeof(Natiune));
    contAfis.close();*/
    
    cout << endl << endl << endl << endl;
    cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-TARI INSULARE-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-";
    cout << endl << endl << endl << endl;

    TaraInsulara ti1("Indian", 36854);
    cout << ti1 << endl;
    TaraInsulara ti2;
    cout << ti2;
    TaraInsulara ti3 = ti2;
    TaraInsulara ti4;
    ti4 = ti2;

    cout << endl << endl << endl << endl;
    cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-RAURI ROMANESTI-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-";
    cout << endl << endl << endl << endl;

    RauriRomanesti r1;
    r1.setNumeRau("Dambovita");
    RauriRomanesti r2("Brasov", 8, true);
    r2.setNumeRau("Prut");
    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
   
}