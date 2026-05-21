#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{
    string name;

    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    cout << "Name des Spielers: ";
    cin >> name;

    return name;
}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.
        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // Wie funktioniert die funktion rand?
        // Warum wird hier modulo 3 verwendet?

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{
    // Abhängig vom vorliegenden Objekt einen entsprechenden String zurückgeben.
    // z.B: Wenn object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben
    if(object == Object::ROCK) {
        return "Stein";
    }
    else if(object == Object::SCISSORS) {
        return "Schere";
    }
    else{
        return "Papier";
    }
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{
    // Auf der Konsole ausgeben, für welches Objekt sich der Spieler entschieden hat.
    cout << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt" << endl;
}

// Die Wahl des Spielers abfragen
Object choose()
{
    int wahl;

    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    do{
        cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
        cin >> wahl;
    } while(wahl < 1 || wahl > 3);

    return static_cast<Object>(wahl - 1);;
}

Result determine_result(Player player_1, Player player_2)
{
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    if( (player_1.choice == Object::ROCK && player_2.choice == Object::SCISSORS) ||
        (player_1.choice == Object::SCISSORS && player_2.choice == Object::PAPER) ||
        (player_1.choice == Object::PAPER && player_2.choice == Object::ROCK)) {
        return Result::PLAYER_ONE_WINS;
    }
    else if(player_1.choice == player_2.choice) {
        return Result::DRAW;
    }
    else{
        return Result::PLAYER_TWO_WINS;
    }
}

void print_result(Player player_1, Player player_2)
{
    Result ergebnis = determine_result(player_1, player_2);
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    if(ergebnis == Result::PLAYER_ONE_WINS){
        cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
    }
    else if(ergebnis == Result::PLAYER_TWO_WINS) {
        cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
    }
    else{
        cout << "Unentschieden" << endl;
    }

}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = choose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}