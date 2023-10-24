#include <iostream>
#include <cstdlib>
#define HORIZONTAL_BAR cout<<"-------"
#define NOT_AVAILABLEr cout<<"-------N/A"
#define NOT_AVAILABLEl cout<<"N/A-------"
using namespace std;

class GPU {
public:
    string producator;
    int vram;
    float latime;
    int nr_porturi;
    string* nume_porturi;
    static int nr_gpu;
    const int id;

    static int getnr_gpu() {
        return nr_gpu;
    }

    GPU(string producator, int vram, float latime, int nr_porturi, const string* nume_porturi):id(nr_gpu)
    {
        nr_gpu++;
        this->producator = producator;
        this->vram = vram;
        this->latime = latime;
        this->nr_porturi = nr_porturi;
        this->nume_porturi = new string[nr_porturi];
        for (int i = 0; i < nr_porturi; i++)
        {
            this->nume_porturi[i] = nume_porturi[i];
        }
    }

    GPU(string producator, int nr_porturi, string* nume_porturi) :id(nr_gpu) {
        nr_gpu++;
        this->producator = producator;
        this->vram = 24;
        this->latime = 12.9;
        this->nr_porturi = nr_porturi;
        this->nume_porturi = new string[nr_porturi];
        for (int i = 0; i < nr_porturi; i++)
        {
            this->nume_porturi[i] = nume_porturi[i];
        }
    }

    GPU() :id(nr_gpu) {
        nr_gpu++;
        this->producator = "AMD";
        this->vram = 8;
        this->latime = 14;
        this->nr_porturi = 0;
        this->nume_porturi = NULL;
        
    }

    ~GPU() {
        if (this->nume_porturi != NULL)
        {
            delete[]this->nume_porturi;
        }
    }

    void AfisareGPU() {
        cout << "Placa video cu ID-ul "<<id+1<<" este de la producatorul " << producator << ", are o capacitate VRAM de "  << vram << " GB si are o latime de " <<
            latime << ". Prezinta " << nr_porturi << " porturi, respectiv: ";
        if (nr_porturi > 0)
        {
            for (int i = 0; i < nr_porturi; i++)
            {
                cout << nume_porturi[i] << " ";
            }
        }
        else cout << "N/A";
        cout << endl << endl;
    }
};

class RAM {
public:
    int ddr;
    string producator;
    float frecventa;
    bool kit;
    static int numar_ram;
    const int id_ram;
    int* capacitate;

    static int getnumar_ram()
    {
        return numar_ram;
    }

    RAM() :id_ram(numar_ram) {
        numar_ram++;
        this->ddr = 4;
        this->producator = "Corsair";
        this->frecventa = 4.2;
        this->kit = true;
        capacitate = new int;
    }

    RAM(int ddr, string producator, float frecventa, bool kit) :id_ram(numar_ram) {
        numar_ram++;
        this->ddr = ddr;
        this->producator = producator;
        this->frecventa = frecventa;
        this->kit = kit;
        capacitate = new int;
    }

    RAM(float frecventa, bool kit) :id_ram(numar_ram) {
        numar_ram++;
        this->ddr = 5;
        this->producator = "HyperX";
        this->frecventa = frecventa;
        this->kit = kit;
        capacitate = new int;
    }

    ~RAM() {
        delete[]this->capacitate;
    }

    void setPointerValue(int value) {
        *capacitate = value;
    }

    int getPointerValue() const {
        return *capacitate;
    }

    void afisareRAM() {
        cout << endl << "Placuta de RAM cu ID-ul "<<id_ram+1 << " de la producatorul " << producator << " este de generatia DDR" << ddr << " si are o frecventa de " << frecventa << " GHz si";
        if (kit == true)
        {
            cout << " apartine unui kit, cu o memorie totala de ";
        }
        else
            cout << " nu apartine unui kit, cu o memorie totala de ";
    }

};

class NodM {
public:
    string nume;
    int marime_nod;
    int ncnx;
    string* nume_cnx;
    static int nr_nod;
    const int id_nod;

    static int getNr_noduri()
    {
        return nr_nod;
    }

    NodM(string nume, int marime_nod, int ncnx, string* nume_cnx):id_nod(nr_nod) {
        nr_nod++;
        this->nume = nume;
        this->marime_nod = marime_nod;
        this->ncnx = ncnx;
        this->nume_cnx = new string[ncnx];
        for (int i = 0; i < ncnx; i++)
        {
            this->nume_cnx[i] = nume_cnx[i];
        }

    }

    NodM(int ncnx, string* nume_cnx) :id_nod(nr_nod) {
        nr_nod++;
        this->nume = "X";
        this->marime_nod = 230;
        this->ncnx = ncnx;
        this->nume_cnx = new string[ncnx];
        for (int i = 0; i < ncnx; i++)
        {
            this->nume_cnx[i] = nume_cnx[i];
        }

    }

    NodM() : id_nod(nr_nod) {
        nr_nod++;
        this->nume = "SOUTH_BRIDGE";
        this->marime_nod = 200;
        this->ncnx = 0;
        this->nume_cnx = NULL;
    }

    ~NodM() {
        if (this->nume_cnx != NULL) {
            delete[]this->nume_cnx;
        }
    }

    void afisareInfoNodM() {
        cout << "Nodul " << nume <<" cu ID-ul "<<id_nod+1<< " are o marime de " << marime_nod << " unitati si este conectat la " << ncnx << " alte noduri respectiv, nodurile: "<< endl;
        if (ncnx > 0)
        {
            
            for (int i = 0; i < ncnx/2; i++)
            {
                cout << nume_cnx[i]; HORIZONTAL_BAR;
            }
            cout << nume;
            for (int i = ncnx / 2; i < ncnx; i++)
            {
                HORIZONTAL_BAR; cout << nume_cnx[i];
            }
        }
        else { NOT_AVAILABLEl; cout << nume; NOT_AVAILABLEr; }
        cout << endl << endl;
    }

};

int NodM::nr_nod = 0;
int GPU::nr_gpu = 0;
int RAM::numar_ram = 0;

int main() {
    GPU gpu1;
    gpu1.AfisareGPU();

    string* nume_porturi = new string[4];
    nume_porturi[0] = "HDMI";
    nume_porturi[1] = "Display Port";
    nume_porturi[2] = "DVI";
    nume_porturi[3] = "Mini HDMI";

    GPU gpu2("AMD", 8, 12.9, 3, nume_porturi);
    gpu2.AfisareGPU();

    GPU gpu3("Intel", 2, nume_porturi);
    gpu3.AfisareGPU();

    cout << "Au fost creeate " << GPU::getnr_gpu() << " placi video.";

    cin.ignore();
    system("cls");

    RAM ram1;
    ram1.setPointerValue(16);
    ram1.afisareRAM();
    cout << ram1.getPointerValue() << " GB" << endl;

    RAM ram2(4, "G.Skill", 3.6, false);
    ram2.setPointerValue(32);
    ram2.afisareRAM();
    cout << ram2.getPointerValue() << " GB" << endl;

    RAM ram3(5, true);
    ram3.setPointerValue(64);
    ram3.afisareRAM();
    cout << ram3.getPointerValue() << " GB" << endl;

    cout << "Au fost create " << RAM::getnumar_ram() << " placute de memorie.";

    cin.ignore();
    system("cls");

    string* nume_noduri = new string[4];
    nume_noduri[0] = "I/O";
    nume_noduri[1] = "SATA";
    nume_noduri[2] = "FP_USB";
    nume_noduri[3] = "USB_h";

    NodM nod1;
    nod1.afisareInfoNodM();

    NodM nod2("NORTH_BRIDGE", 222, 4, nume_noduri);
    nod2.afisareInfoNodM();

    NodM nod3(2, nume_noduri);
    nod3.afisareInfoNodM();

    cout << "Au fost create " << NodM::getNr_noduri() << " noduri de magistrale.";
}