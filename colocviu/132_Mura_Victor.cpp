/* Mura Victor 132
g++ -std=c++17
Marian Lupascu */
#include <iostream>
#include <unordered_map>

class Exception {
    std::string msg;
public:
    Exception(std::string  msg): msg(std::move(msg)){}
    std::string getMessage() const {
        return msg;
    }
};

class Masca {
    std::string tip_masca;
    std::string culoare;
    int nr_pliuri;
public:
    Masca();
    Masca(std::string tip_masca, std::string culoare, int nr_pliuri);
    ~Masca();
    friend std::ostream &operator<<(std::ostream &os, const Masca &masca);
    friend std::istream &operator>> (std::istream &in, Masca &masca);

    virtual int get_price();
};
Masca::Masca() {}
Masca::~Masca() {}
Masca::Masca(std::string tip_masca, std::string culoare, int nr_pliuri)
        : tip_masca(std::move(tip_masca))
        , culoare(std::move(culoare))
        , nr_pliuri(nr_pliuri)
{}

std::ostream &operator<<(std::ostream &os, const Masca &masca) {
    os << "Tip masca: " << masca.tip_masca <<"\n"<< "Culoare: " << masca.culoare << "\n" << "Nr pliuri: "
       << masca.nr_pliuri << '\n';
    return os;
}

std::istream & operator >> (std::istream &in, Masca &masca){
    in >> masca.tip_masca;

    if(masca.tip_masca == " " || (masca.tip_masca != "ffp0" && masca.tip_masca != "ffp1" && masca.tip_masca !="ffp2" && masca.tip_masca != "ffp3"))
        throw Exception("Tip masca incorect, introduce-ti unul din tipurile (ffp1, ffp2, ffp3) "
                        "sau alegeti adaugarea unei masti din policarbonat. ");
    in >> masca.culoare;
    in >> masca.nr_pliuri;
    return in;
}
int Masca::get_price() {
    if(tip_masca=="ffp1"){
        return 5;
    } else if (tip_masca=="ffp2"){
        return 10;
    } else if (tip_masca=="ffp3") {
        return 15;
    }
    return 0;
}

class MascaPolicarbonat: public Masca{
    std::string tip_prindere;
public:
    MascaPolicarbonat();
    ~MascaPolicarbonat();

    friend std::ostream &operator<<(std::ostream &os, const MascaPolicarbonat &masca);
    friend std::istream &operator>> (std::istream &in, MascaPolicarbonat &masca);

    virtual int get_price();
};
MascaPolicarbonat::MascaPolicarbonat() {}
MascaPolicarbonat::~MascaPolicarbonat() {}

std::istream & operator >> (std::istream &in, MascaPolicarbonat &masca){
    in >> static_cast<Masca &>(masca);
    in >> masca.tip_prindere;
    return in;
}

std::ostream &operator<<(std::ostream &os, const MascaPolicarbonat &masca) {
    os << static_cast<const Masca &>(masca) << "\nTip prindere: " << masca.tip_prindere;
    return os;
}

int MascaPolicarbonat::get_price() {
    return 20;
}

class Dezinfectant {
    std::string tip_dezinfectant;
    int nr_specii_ucise;
    std::string ingrediente;
    std::string tipuri_de_suprafete;
public:
    Dezinfectant();
    Dezinfectant(std::string tip_dezinfectant, int nr_specii_ucise, std::string ingrediente, std::string tipuri_de_suprafete);
    ~Dezinfectant();
    friend std::ostream &operator<<(std::ostream &os, const Dezinfectant &dezinfectant);
    friend std::istream &operator>> (std::istream &in, Dezinfectant &dezinfectant);
    virtual double eficienta();
    virtual int get_price();
};
Dezinfectant::Dezinfectant() {};
Dezinfectant::~Dezinfectant() {};
Dezinfectant::Dezinfectant(std::string tip_dezinfectant, int nr_specii_ucise, std::string ingrediente, std::string tipuri_de_suprafete)
        : tip_dezinfectant(std::move(tip_dezinfectant))
        ,nr_specii_ucise(nr_specii_ucise)
        , ingrediente(std::move(ingrediente))
        , tipuri_de_suprafete(std::move(tipuri_de_suprafete))
{}

std::ostream &operator<<(std::ostream &os, const Dezinfectant &dezinfectant) {
    os << "Tip dezinfectant" << dezinfectant.tip_dezinfectant << "\n"
    <<"Numarul de specii de organisme ucise: " << dezinfectant.nr_specii_ucise <<"\n"
    << "Ingrediente: " << dezinfectant.ingrediente << "\n"
    << "Tipuri de suprafete: "<< dezinfectant.tipuri_de_suprafete << '\n';
    return os;
}

std::istream & operator >> (std::istream &in, Dezinfectant &dezinfectant){
    in >> dezinfectant.tip_dezinfectant;

    if(dezinfectant.tip_dezinfectant != "bacterie" && dezinfectant.tip_dezinfectant != "fung" && dezinfectant.tip_dezinfectant != "virus")
        throw Exception("Numarul speciilor ucise este mai mic sau egal cu 0, introduce-ti un numar mai mare de 0");
    in >> dezinfectant.nr_specii_ucise;
    in >> dezinfectant.ingrediente;
    in >> dezinfectant.tipuri_de_suprafete;
    return in;
}

double Dezinfectant::eficienta () {
    const double total_bacterii = 1000000000;
    const double total_fungi    = 1500000;
    const double total_virusi   = 100000000;
    if(tip_dezinfectant=="bacterie"){
        return nr_specii_ucise/total_bacterii;
    } else if (tip_dezinfectant == "fung") {
        return nr_specii_ucise/total_fungi;
    } else if (tip_dezinfectant == "virus") {
        return nr_specii_ucise/total_virusi;
    }
    return 0;
}
int Dezinfectant::get_price() {
    if (eficienta()*100 < 90){
        return 10;
    } else if (eficienta()*100 < 95) {
        return 20;
    } else if (eficienta()*100 < 97.5) {
        return 30;
    } else if (eficienta()*100 < 99 ) {
        return 40;
    } else {
        return 50;
    }
}

class Data {
    int zi;
    int luna;
    int an;
public:
    Data();
    Data(int zi, int luna, int an);

    inline int get_zi(){return zi;};
    inline int get_luna(){return luna;};
    inline int get_an(){return an;};

    friend std::ostream &operator<<(std::ostream &os, const Data &data);
    friend std::istream &operator>> (std::istream &in, Data &data);
};
Data::Data() {};
Data::Data(int zi, int luna, int an): zi(zi), luna(luna), an(an){}
std::ostream &operator<<(std::ostream &os, const Data &data) {
    os << data.zi << "/"<<data.luna<<"/"<<data.an;
    return os;
}

std::istream & operator >> (std::istream &in, Data &data){
    in >> data.zi;
    in >> data.luna;
    in >> data.an;

    if (data.zi > 31 || data.zi < 0 || data.luna > 12 || data.luna < 0 ){
        throw Exception("Data este introdusa incorect");
    }
    return in;
}

class Achizitie {
    std::string nume_client;
    Data* data;
public:
    Achizitie();
    Achizitie(std::string nume_client, Data* data);
    friend std::ostream &operator<<(std::ostream &os, const Achizitie &achizitie);
    friend std::istream &operator>> (std::istream &in, Achizitie &achizitie);

};
Achizitie::Achizitie() {};
Achizitie::Achizitie(std::string nume_client, Data* data):nume_client(std::move(nume_client)), data(data) {}

std::ostream &operator<<(std::ostream &os, const Achizitie &achizitie) {
    os << "Nume client: " << achizitie.nume_client << "\n";
    return os;
}

std::istream & operator >> (std::istream &in, Achizitie &achizitie){
    in >> achizitie.nume_client;
    if(achizitie.nume_client == " "){
        throw Exception("Numele clientului este gol, incercati din nou operatiunea");
    }
    in >> reinterpret_cast<Data &>(achizitie);
    return in;
}

int main() {
    std::string command;
    Masca stockMasti[100];
    int sm_pos = 0;
    MascaPolicarbonat stockPoliMasti[100];
    int smp_pos = 0;
    Dezinfectant stockDezinfectanti[100];
    int sd_pos = 0;
    Achizitie achizitii[100];
    int ac_pos = 0;
    while (true) {
        std::cout << "Introdu comanda (+mascaChir / +mascaPoli / +dezinf / +achizitie /"
                     " max_eficient / afisare_stockuri/ afisare_achizitii / iesire): " ;
        std::cin >> command;
        try {
        if (command == "iesire") {
            break;
        } else if (command == "+mascaChir"){
            std::cout << "Introduceti datele despre masca (tip masca / culoare / nr_pliuri ): ";
            std::cin >> stockMasti[sm_pos];
            ++sm_pos;
        } else if (command == "+mascaPoli"){
            std::cout << "Introduceti datele despre masca (tip masca(ffp0) / culoare / nr pliuri / tip prindere ): ";
            std::cin >> stockPoliMasti[smp_pos];
            ++smp_pos;
        } else if (command == "+dezinf") {
            std::cout << "Introduceti datele despre dezinfectanti: ";
            std::cin >> stockDezinfectanti[sd_pos];
            ++sd_pos;
        } else if (command == "+achizitie") {
            std::cout << "Introduceti datele despre achizitie: ";
            std::cin >> achizitii[ac_pos];
            ++ac_pos;
        } else if (command == "max_eficient"){
            Dezinfectant max_dez = stockDezinfectanti[0];
            double max_ef = max_dez.eficienta();
            for (int i=1; i < sd_pos; i++){
                if (stockDezinfectanti[i].eficienta() > max_ef){
                    max_ef = stockDezinfectanti[i].eficienta();
                    max_dez = stockDezinfectanti[i];
                }
            }
            std::cout << max_dez;
        } else if (command == "afisare_stockuri"){
            for (int i=0; i < sm_pos; i++){
                std::cout << stockMasti[i];
            }
            for (int i=0; i < smp_pos; i++){
                std::cout << stockPoliMasti[i];
            }
            for (int i=0; i < sd_pos; i++){
                std::cout << stockDezinfectanti[i];
            }
        } else if (command == "afisare_achizitii"){
            for (int i=0; i < ac_pos; i++){
                std::cout << achizitii[i];
            }
        } else {
            continue;
        }
        } catch (Exception &e) {
            std::cout << e.getMessage();
        }
    }
    return 0;
}
