#include <utility>

using namespace std;

using uint = unsigned int;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

class Juego {
  // Completar
    public:
        Juego(uint casilleros, Pos pos_inicial);
        Pos posicion_jugador();
        uint turno_actual();
        void mover_jugador(char dir);
        void ingerir_pocion(uint movimientos, uint turnos);

    private:
    uint _casilleros;
    Pos _posicion_jugador;
    uint _turno_actual;
    char _dir;
};

Juego::Juego(uint casilleros, Pos pos_inicial): _casilleros(casilleros), _posicion_jugador(pos_inicial), _turno_actual(0){};

Pos Juego::posicion_jugador() {
    return _posicion_jugador;

}

uint Juego::turno_actual() {
    return _turno_actual;
}

void Juego::mover_jugador(char dir) {
    bool enRango = false;
    if (dir == ARRIBA && _posicion_jugador.first > 0){
        _posicion_jugador.first--;
        enRango = true;
    }
    else if (dir == ABAJO && _posicion_jugador.first < _casilleros - 1){
        _posicion_jugador.first++;
        enRango = true;
    }
    else if (dir == DERECHA && _posicion_jugador.second < _casilleros - 1){
        _posicion_jugador.second++;
        enRango = true;
    }
    else if (dir == IZQUIERDA && _posicion_jugador.second > 0){
        _posicion_jugador.second--;
        enRango = true;
    }
    if (enRango) {
        _turno_actual++;
    }
}

void Juego::ingerir_pocion(uint movimientos, uint turnos) {
   if (_movimientos > 0){

   }
    turnos--;
}