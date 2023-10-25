//Negulescu Razvan-George, Seria B, grupa 1047
//Domeniul:Geografie
#include <iostream>
#include <cstdlib>
#define HORIZONTAL_BAR cout<<"-------"
#define NOT_AVAILABLEr cout<<"-------N/A"
#define NOT_AVAILABLEl cout<<"N/A-------"
#define GREEN    "\033[32m"
#define RESET   "\033[0m"
using namespace std;

class Golf {
public:
    string nume_golf;
    int adancime_apa;
    float temp_apa;
    int nr_insule;
    string* nume_insule;
    static int nr_golfuri;
    const int id;

    static int getnr_golfuri() { //functie statica
        return nr_golfuri;
    }

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
};

class Rau {
public:
    string nume_rau;
    int lungime;
    float debit;
    bool are_delta;
    int nr_tari;
    string* tari;
    static int nr_rauri;
    const int id;

    static int getnumar_rauri() {
        return nr_rauri;
    }

    Rau() : id(nr_rauri) {
        nr_rauri++;
        this->nume_rau = "Huang";
        this->lungime = 14;
        this->debit = 19.3;
        this->are_delta = false;
        this->nr_tari = 0;
        this->tari = NULL;
    }

    Rau(string nume_rau, int lungime, float debit, bool are_delta, int nr_tari, string* tari) : id(nr_rauri) {
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

    Rau(bool are_delta, int nr_tari, string* tari) : id(nr_rauri) {
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
};

class Natiune {
public:
    string nume;
    int marime_natiune;
    int nr_vecini;
    string* nume_vecin;
    static int nr_natiune;
    const int id_natiune;

    static int getnr_natiuni()
    {
        return nr_natiune;
    }

    Natiune(string nume, int marime_natiune, int nr_vecini, string* nume_vecin) :id_natiune(nr_natiune) {
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

    Natiune(int nr_vecini, string* nume_vecin) :id_natiune(nr_natiune) {
        nr_natiune++;
        this->nume = "Liechtenstein";
        this->marime_natiune = 230;
        this->nr_vecini = nr_vecini;
        this->nume_vecin = new string[nr_vecini];
        for (int i = 0; i < nr_vecini; i++)
        {
            this->nume_vecin[i] = nume_vecin[i];
        }

    }

    Natiune() : id_natiune(nr_natiune) {
        nr_natiune++;
        this->nume = "Australia";
        this->marime_natiune = 200;
        this->nr_vecini = 0;
        this->nume_vecin = NULL;
    }

    ~Natiune() {
        if (this->nume_vecin != NULL) {
            delete[]this->nume_vecin;
        }
    }

    void afisareInfoNatiune() {
        cout << "Tara " << nume << " cu ID-ul (" << id_natiune + 1 << ") are o marime de " << marime_natiune << " unitati si este conectata la " << nr_vecini << " alte tari: " << endl;
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

};


int Rau::nr_rauri = 0;
int Golf::nr_golfuri = 0;
int Natiune::nr_natiune = 0;

int main() {
    string nume_insule[] = { "Insula1", "Insula2", "Insula3" };
    Golf golf1("Mexic", 1200, 25.5, 3, nume_insule);
    Golf golf2;
    Golf golf3("Arctic", 2, nume_insule);

    golf1.AfisareGolf();
    golf2.AfisareGolf();
    golf3.AfisareGolf();

    cout << endl << "Au fost create " << Golf::getnr_golfuri() << " golfuri";

    cin.ignore();
    system("cls");

    string tariVolga[] = { "Rusia", "Moldova", "Kazakhstan" };
    string tariIalomita[] = { "Romania" };

    Rau rau1(true, 3, tariVolga);
    Rau rau2;
    Rau rau3("Ialomita", 400, 234.3, true, 1, tariIalomita);

    rau1.AfisareRau();
    rau2.AfisareRau();
    rau3.AfisareRau();

    cout << endl << "Au fost create " << Rau::getnumar_rauri() << " rauri";

    cin.ignore();
    system("cls");

    string nume_veciniRO[] = { "Ungaria", "Ucraina", "Moldova", "Serbia", "Bulgaria" };
    string nume_veciniLH[] = { "Elvetia", "Austria" };

    cout << "Tara despre care se vorbeste va fi highlighted cu verde"<<endl;

    Natiune natiune1;
    Natiune natiune2(2, nume_veciniLH);
    Natiune natiune3("Romania", 400, 5, nume_veciniRO);
    
    natiune1.afisareInfoNatiune();
    natiune2.afisareInfoNatiune();
    natiune3.afisareInfoNatiune();

    cout << endl << "Au fost create " << Natiune::getnr_natiuni() << " natiuni" << endl;

    return 0;
}
