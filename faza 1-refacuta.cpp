//Negulescu Razvan-George, Seria B, grupa 1047
//Domeniul:Geografie
#include <iostream>
#include <cstdlib>
#include <iomanip>
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

    Golf(string nume_golf, int adancime_apa, float temp_apa, int nr_insule, string* nume_insule) : id(nr_golfuri) { //constructor 1
        nr_golfuri++;
        this->nume_golf = nume_golf;
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

    Golf operator=(const Golf &gn) { //supraincarcare de operator =
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

    ~Golf() {
        if (nume_insule != NULL) {
            delete[]this->nume_insule;
        }
    }

    void AfisareGolf() {
        cout << "Golful " << nume_golf << " (ID: " << id+1 << ") cu adancimea de " << adancime_apa << " metri si temperatura de " << temp_apa << " grade Celsius." << endl;
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
    cout << "Insulele Goflului " << g.id+1 << " ,respectiv Golful " << g.nume_golf << " ,sunt:";
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

    Rau(const Rau& rn) : id(nr_rauri++) {
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

    Rau operator=(const Rau& rn) {
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

    ~Rau() {
        if (this->tari != NULL) {
            delete[]this->tari;
        }
    }

    void AfisareRau() {
        cout << "Raul " << nume_rau << " (ID: " << id+1 << ") are o lungime de " << lungime << " kilometri si un debit de apa de " << debit << " metri cubi pe secunda." << endl;
        cout << "Are delta: " << (are_delta ? "Da" : "Nu") << endl;
        cout << "Numarul de tari prin care trece: " << nr_tari << endl <<"Numele tarilor: " << endl;
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
    void setDebit(const float& dbt){
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
private:
    string nume;
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

    Natiune operator=(const Natiune& nn) { //supraincarcare operator
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

    ~Natiune() { //destructor
        if (this->nume_vecin != NULL) {
            delete[]this->nume_vecin;
        }
    }

    void afisareInfoNatiune() { //afisare
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

    friend string getSirTari(const Natiune& n);
    friend float mediaPopulatiei(const Natiune& tara1, const Natiune& tara2); 
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

    golf1.AfisareGolf();
    golf2.AfisareGolf();
    golf3.AfisareGolf();
    golf4.AfisareGolf();
    golf5.AfisareGolf();
    golf6.AfisareGolf();

    int var = golf4.getNrInsule();

    cout << golf4.getNumeGolf() << endl << golf3.getAdancimeApa() << endl << golf4.getTempApa() << endl << golf4.getNrInsule() << endl;
    int i = 0;
    while (i < var) {
        cout << *(golf4.getNumeInsule()+i) << " ";
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

    cout << endl << "Au fost create " << Golf::getnr_golfuri() << " golfuri";

    cin.ignore();
    system("cls");

    //--------------------------------

    string tariVolga[] = { "Rusia", "Moldova", "Kazakhstan" };
    string tariIalomita[] = { "Romania" };
    string CapitaleVolga[] = { "Moscova", "Chisinau", "Astana" };
    string CapitaleIalomita[] = { "Bucuresti" };

    Rau rau1(true, 3, tariVolga);
    Rau rau2;
    Rau rau3("Ialomita", 400, 234.3, true, 1, tariIalomita);
    Rau rau4=rau3;
    Rau rau5;
    Rau rau6;
    rau6 = rau5 = rau1;

    rau1.AfisareRau();
    rau2.AfisareRau();
    rau3.AfisareRau();
    rau4.AfisareRau();
    rau5.AfisareRau();
    rau6.AfisareRau();

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
    cout << "Capitalele tarilor prin care trece raul " << rau1.getNumeRau() <<" sunt:" << endl << capitaleTariV;
    string capitaleIalomita = getCapitalaTari(rau3, CapitaleIalomita);
    cout << "Capitalele tarilor prin care trece raul " << rau3.getNumeRau() <<" sunt:" << endl << capitaleIalomita;
    
    cout << getSirTari(rau1) << endl;

    cout << endl << "Au fost create " << Rau::getnumar_rauri() << " rauri";

    cin.ignore();
    system("cls");

    //----------------------------------

    string nume_veciniRO[] = { "Ungaria", "Ucraina", "Moldova", "Serbia", "Bulgaria" };
    string nume_veciniLH[] = { "Elvetia", "Austria" };

    cout << "Tara despre care se vorbeste va fi highlighted cu verde"<<endl;

    Natiune natiune1;
    Natiune natiune2(2, nume_veciniLH);
    Natiune natiune3("Romania", 19000000, 5, nume_veciniRO);
    Natiune natiune4=natiune3;
    Natiune natiune5;
    Natiune natiune6;
    natiune6 = natiune5 = natiune2;
    
    natiune1.afisareInfoNatiune();
    natiune2.afisareInfoNatiune();
    natiune3.afisareInfoNatiune();
    natiune4.afisareInfoNatiune();
    natiune5.afisareInfoNatiune();
    natiune6.afisareInfoNatiune();

    cout << natiune4.getMarimeNatiune() << endl << natiune4.getNumeNatiune() << endl << natiune4.getNrVecini() << endl;
    int varN = natiune4.getNrVecini();
    int Na = 0;
    while (Na < varN)
    {
        cout << "->" << * (natiune4.getNumeVecini() + Na) << endl;
        Na++;
    }
    natiune2.setMarimeNatiune(69803);
    natiune2.setNumeNatiune("Liechtenstein");
    natiune2.setVecini(1, nume_veciniLH);
    cout << endl;
    natiune2.afisareInfoNatiune();
    
    cout << getSirTari(natiune4) << endl;
    cout << "Media populatiei dintre " << natiune1.getNumeNatiune() << " si " << natiune2.getNumeNatiune() << " este de " << fixed << setprecision(2) << mediaPopulatiei(natiune1, natiune2) << endl;
    cout << endl << "Au fost create " << Natiune::getnr_natiuni() << " natiuni" << endl;

    return 0;
}