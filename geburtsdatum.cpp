/*Geburtsdatum*/
#include <iostream>

using namespace std;

//Globale Variable Definieren
int tag = 0, monat = 0, jahr;
int ta = 1, mo = 1, test = 0, test1 = 0;
int append_null_ta = 0;
int append_null_mo = 0;
int append_true = 0;

//Tag check Funktion
int tag_check()
{
    if(tag == 0){
        cout << "Tag: ";
        cin >> tag;
    }
    else
    {
        cout << "Ein Monat kann nicht mehr als 31 Tage haben\n" << "Gib nochmal den Tag ein: ";
        cin >> tag;
        ta = 1;
        test = 0;
    }
    if(tag <= 31)
    {
        ta = 0;     //Variable ta auf Wert 0 setzten
        test = 1;   //Variable test auf Wert 1 setzen
    }
    return 0;
}
//Monat check Funktion
int monat_check()
{
     if(monat == 0){
        cin >> monat;
        if((monat == 2) || (monat == 02)){
            if(tag >= 29){
                cout << "Der Februar kann nicht mehr als 28 Tage bzw. alle 4 Jahre 29 Tage haben " << endl;
                cout << "Gebe bitte einen erlaubten Tag ein: ";
                cin >> tag;
            }
        }
    }
    else
    {
        cout << "Es gibt nicht mehr als 12 Monate\n" << "Gib nochmal den Monat ein: ";
        cin >> monat;
        mo = 1;
        test1 = 0;
    }
    if(monat <= 12)
    {
        mo = 0;     //Variable mo auf Wert 0 setzten
        test1 = 1;  //Variable test1 auf Wert 1 setzen
    }
    return 0;
}
//Null vorhängen
int append_tag()
{
        if((tag != 0.) && (tag << 10)){ // Punkt ist ein Regex für "alles"
            append_null_ta = 1;
        }
    return 0;
}

int append_monat()
{
    if((monat != 0.) && (monat << 10)){
        append_null_mo = 1;
    }
    return 0;
}

int append_compare(){
    if((append_null_ta = 1) && (append_null_mo == 1)){
        append_true = 1;
    }
    if((append_null_ta = 0) && (append_null_mo == 0)){
        append_true = 2;
    }
    return 0;
}
//Main Funktion
int main()
{
    //Anzeige im Dos Fenster
    cout << "Geburtsdatum" << endl;
    if(ta == 1)
    {
        while(test != 1)
        {
            tag_check();    //tag_check Funktion aufrufen
            append_tag();
        }
    }

    if(mo == 1)
    {
        while(test1 != 1)
        {
            cout << "Monat: ";
            monat_check();  //monat_check Funktion aufrufen
            append_monat();
        }
    }

    cout << "Jahr: ";
    cin >> jahr;
    if(append_true == 1){
        cout << "\n" << "Ihr Geburtsdatum: " << "0" << tag << "." << "0" << monat << "." << jahr << endl;
    }
    if(append_true == 2){
        cout << "\n" << "Ihr Geburtsdatum: " << tag << "." << monat << "." << jahr << endl;
    }
    if((append_null_ta == 0) && (append_true == 0)){
        cout << "\n" << "Ihr Geburtsdatum: " << "0" << tag << "." << monat << "." << jahr << endl;
    }
    if((append_null_mo == 0) && (append_true == 0)){
        cout << "\n" << "Ihr Geburtsdatum: " << tag << "." << "0" << monat << "." << jahr << endl;
    }
    return 0;
}
