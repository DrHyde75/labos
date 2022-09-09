#include <iostream>
#include <list>
using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
            // ene, feb, mar, abr, may, jun
            31, 28, 31, 30, 31, 30,
            // jul, ago, sep, oct, nov, dic
            31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

class Fecha {
public:
    Fecha(int mes, int dia);
    int mes();
    int dia();

    bool operator==(Fecha o);

    void incrementar_dia();


private:
    int _mes;
    int _dia;
};



bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}


Fecha::Fecha(int mes, int dia): _mes(mes), _dia(dia) {};

int Fecha::mes() {
    return _mes;
}

int Fecha::dia() {
    return _dia;
}

void Fecha::incrementar_dia() {
    if ( _dia == dias_en_mes(_mes)){
        _dia = 1;
        _mes++;
    }
    else{
        _dia++;
    }
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

// Ejercicio 11, 12

class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();

    bool operator==(Horario o);

    bool operator<(Horario o);

private:
    int _hora;
    int _min;
};

bool Horario::operator==(Horario o) {
    bool igual_hora = this->hora() == o.hora();
    bool igual_minuto = this->min() == o.min();
    return igual_hora && igual_minuto;
}

bool Horario::operator<(Horario o) {
    bool igual_hora = this->hora() == o.hora();
    bool menor;
    if (igual_hora){
        menor = this->min() < o.min();
    }
    else{
        menor = this->hora() < o.hora();
    }
    return menor;
}

Horario::Horario(uint hora, uint min): _hora(hora), _min(min) {};

uint Horario::hora() {
    return _hora;
}

uint Horario::min() {
    return _min;
}


ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

// Ejercicio 13

// Clase Recordatorio

class Recordatorio {
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);
    Fecha fecha();
    Horario horario();
    string mensaje();

private:
    Fecha _fecha;
    Horario _horario;
    string _mensaje;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje): _fecha(fecha), _horario(horario), _mensaje(mensaje){}

Fecha Recordatorio::fecha() {
    return _fecha;
}

Horario Recordatorio::horario() {
    return _horario;
}

string Recordatorio::mensaje() {
    return _mensaje;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}
// Ejercicio 14

// Clase Agenda

class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    Fecha _hoy;
    list<Recordatorio> _agenda;
};

Agenda::Agenda(Fecha fecha_inicial): _hoy(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    _agenda.push_back(rec);

}
list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> dia_hoy;
    for (Recordatorio recordatorios: _agenda){
        if (recordatorios.fecha() == _hoy){
            dia_hoy.push_back(recordatorios);
        }
    }
    dia_hoy.sort([](Recordatorio a, Recordatorio b){return(a.horario() < b.horario());});
    return dia_hoy;
}

void Agenda::incrementar_dia() {
    return _hoy.incrementar_dia();
}

Fecha Agenda::hoy() {
    return _hoy;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl << "=====" << endl;
    for (Recordatorio r: a.recordatorios_de_hoy()){
        os << r << endl;
    }
    return os;
}