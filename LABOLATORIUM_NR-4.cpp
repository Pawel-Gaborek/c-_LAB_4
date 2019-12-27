//
//  LABOLATORIUM_NR-4.cpp
//  LABOLATORIUM_NR-4
//
//  Created by Paweł Gaborek on 15/04/2019.
//  Copyright © 2019 Paweł Gaborek. All rights reserved.
//


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <istream>
#include <ctime>

using namespace std;



/////////////////////////////////////////////////////////////////////////
////---------------klasa dla pojedynczego zawodnika------------------////
class PersonalOfPlayer
{
public:
    string PlayerName;
    string PlayerSurname;
    string PlayerHeight;
    string PlayerAge;
    string PlayerPosition;
    //ponizej tworze metode przypisania do struktury odpowiednich danych
    PersonalOfPlayer(string getName, string getSurname, string getHeight, string getAge, string getPosition)
    {
        this -> PlayerName = getName;
        this -> PlayerSurname = getSurname;
        this -> PlayerHeight = getHeight;
        this -> PlayerAge = getAge;
        this -> PlayerPosition = getPosition;
    }
    
    PersonalOfPlayer (){};
    
    PersonalOfPlayer (const PersonalOfPlayer &source)
    {
        PlayerName=source.PlayerName;
        PlayerSurname=source.PlayerSurname;
        PlayerHeight=source.PlayerHeight;
        PlayerAge=source.PlayerAge;
        PlayerPosition=source.PlayerPosition;
    }
private:
protected:
};

/////////////////////////////////////////////////////////////////////////
////------------------------klasa dla zespolu------------------------////

class Team
{
    
    
public:
    PersonalOfPlayer player_;
    
    Team (string Name_, string Surname_, string Height_, string Age_, string Position_):player_(Name_, Surname_, Height_, Age_, Position_)
    {
        
    };
    
    Team(){}
    
    Team (const Team &source)
    {
        player_.PlayerName=source.player_.PlayerName;
        player_.PlayerSurname=source.player_.PlayerSurname;
        player_.PlayerHeight=source.player_.PlayerHeight;
        player_.PlayerAge=source.player_.PlayerAge;
        player_.PlayerPosition=source.player_.PlayerPosition;
        
    }
    
    void get_memory(){}
    
    void get_player_to_vector(){}
    
    void print_team_(){}
    
    void modify_player(){}
    
    void from_file_to_team_vector(){}
    
    void write_team_to_file(){}
    
    
private:
protected:
};



/////////////////////////////////////////////////////////////////////////
////-------------------metoda dla alokacji pamieci-------------------////

void get_memory(vector<Team> *&team_vector)
{
    team_vector= new vector<Team>;
};

/////////////////////////////////////////////////////////////////////////
////------------metoda do pobrania zawodnika do vectora--------------////

void get_to_vector(vector<Team> *&team_vector, Team player)
{
    team_vector -> push_back(player);
};

/////////////////////////////////////////////////////////////////////////
////-----------------metoda do wypisania zawodnikow------------------////

void print_team_(vector<Team> *&team_vector, int team_number, int player_numbers)
{
    cout << "\n\n\n";
    for (int i=0 ; i<player_numbers ; i++)
    {
        
        cout << "\n" << "Druzyna: " << team_number << ", zawodnik nr: " << i+1 << ", nazwisko: " << (*team_vector)[i].player_.PlayerName << ", imie: " << (*team_vector)[i].player_.PlayerSurname << ", wzrost: " << (*team_vector)[i].player_.PlayerHeight << ", wiek: " << (*team_vector)[i].player_.PlayerAge << ", pozycja: " << (*team_vector)[i].player_.PlayerPosition << "\n";
    }
    cout << "\n\n\n";
};

/////////////////////////////////////////////////////////////////////////
////-------------------metoda czyszczenia pamieci--------------------////

void delete_memory(vector<Team> *&vector)
{
    //delete &vector;
    //vector = nullptr ;
};


/////////////////////////////////////////////////////////////////////////
////------------------------kopiowanie vectora-----------------------////

void copy_vector(vector<Team> *&team_basic, vector<Team> *&team_to_copy, int players_number)
{
    for (int i=0 ; i<players_number ; i++)
    {
        Team player_temp((*team_basic)[i]);
        team_to_copy -> push_back(player_temp);
    }
};

/////////////////////////////////////////////////////////////////////////
////------------------metoda modyfikacji zawodnika-------------------////

void modify_player(vector<Team> *&team_to_modify, int players_number)
{
    int player_to_modify;
    int choice;
    string new_value;
    cout << "Podaj numer zawodnika do modyfikacji:\n";
    cin >> player_to_modify;
    if (!(player_to_modify>players_number))
    {
        cout << "Podaj jaki parametr chcesz zmodyfokowac. Nazwisko - 1, Imie - 2, Wzrost - 3, Wiek - 4, Pozycje - 5.\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Podaj nowe nazwisko:\n";
                cin >> new_value;
                (*team_to_modify)[player_to_modify-1].player_.PlayerName=new_value;
                break;
            case 2:
                cout << "Podaj nowe imie:\n";
                cin >> new_value;
                (*team_to_modify)[player_to_modify-1].player_.PlayerSurname=new_value;
                break;
            case 3:
                cout << "Podaj nowy wzrost:\n";
                cin >> new_value;
                (*team_to_modify)[player_to_modify-1].player_.PlayerHeight=new_value;
                break;
            case 4:
                cout << "Podaj nowy wiek:\n";
                cin >> new_value;
                (*team_to_modify)[player_to_modify-1].player_.PlayerAge=new_value;
                break;
            case 5:
                cout << "Podaj nowa pozycje:\n";
                cin >> new_value;
                (*team_to_modify)[player_to_modify-1].player_.PlayerPosition=new_value;
                break;
            default:
                break;
        }
    }
    else
    {
        cout << "Niestety nie ma takiego zawodnika";
    }
};


/////////////////////////////////////////////////////////////////////////
////------------------------klasa dla plikow-------------------------////

class file_
{
public:
    string file_line;
    
    file_(){}
    
    file_ (string temp_line): file_line(temp_line){}
    
    void get_from_file(){}
    
    void get_memory_for_file(){}
    
    
private:
protected:
};


/////////////////////////////////////////////////////////////////////////
////----------------metoda pobrania danych z pliku-------------------////

using namespace std;

void get_from_file(vector<string> *&file_lines_vector)
{
    string file_name;
    string templine;
    fstream name_file;
    file_name = "tournament";
    name_file.open(file_name+=".txt", ios::in);
    if(name_file.good()==false)
    {
        cout << "Przykro mi! Jednak program nie mogl odnalezc pliku o takiej nazwie.";
        cout << "Program teraz utworzy nowy plik o nazwie ''tournament.txt''";
        name_file.open("tournament.txt", ios::out | ios::app);
    }
    else
    {
        while(getline(name_file, templine))
        {
            file_lines_vector -> push_back(templine);
        }
    }
    name_file.close();
};

/////////////////////////////////////////////////////////////////////////
////--------alokacja pamieci dla vectora z zawodnikami z pliku-------////

void get_memory_for_file(vector<string> *&file_lines_vector)
{
    file_lines_vector = new vector<string>;
};


/////////////////////////////////////////////////////////////////////////
////--metoda zamiany elementow z pliku na dane zawodnikow w vectorze-////


void from_file_to_team_vector(vector<string> *&file_lines_vector, vector<Team> *&team_from_file, int players_number)
{
    
    for (int i=0 ; i<players_number ; i++)
        
    {
        string array[5];
        string tempstring;
        string temp_value;
        tempstring=(*file_lines_vector)[i];
        cout << tempstring;
        for (int j=0 ; j<5 ; j++)
        {
            cout << "Iteracja nr: " << i+1 << "\n";
            temp_value=tempstring;
            cout << tempstring.length() << "\n";
            cout << tempstring << "\n";
            tempstring.erase(tempstring.find(';'), tempstring.length());
            array[j]=tempstring;
            cout << "\n\n\n" << tempstring;
            if (j<4)
            {
                temp_value.replace(0,temp_value.find(';')+1, "");
                cout << "\n" << temp_value << "\n";
                tempstring=temp_value;
            }
            
        }
        
        Team player_temp(array[0], array[1], array[2], array[3], array[4]);
        get_to_vector(team_from_file, player_temp);
    }
};


/////////////////////////////////////////////////////////////////////////
////-----------------metoda zapisu druzyn do pliku-------------------////

string get_time()
{
    time_t rawtime;
    string time_to_return;
    struct tm * timeinfo;
    char time_table [100];
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    strftime (time_table,100,"%F_%I:%M%p",timeinfo);
    time_to_return=time_table;
    return time_to_return;
}


void write_team_to_file(vector<Team> *&team_vector, int players_number, string team_name)
{
    string time_from_return;
    time_from_return=get_time();
    fstream file_export;
    string file_name=team_name;
    file_export.open(file_name+"_"+time_from_return+=".txt", ios::out | ios::app);
    for (int j=0 ; j<players_number ; j++)
    {
        file_export << (*team_vector)[j].player_.PlayerName << ";" << (*team_vector)[j].player_.PlayerSurname << ";" << (*team_vector)[j].player_.PlayerHeight << ";" << (*team_vector)[j].player_.PlayerAge << ";" << (*team_vector)[j].player_.PlayerPosition << ";\n";
    }
    file_export.close();
}


/////////////////////////////////////////////////////////////////////////
////---------------------funkcja glowna programu---------------------////
int main()
{
    using namespace std;
    
    int exit = 0;
    char continuation;
    string teamTeam;
    string name;
    
    
    while(exit==0)
    {
        cout << "Super ! Wlasnie uruchomiles program do labolatorium nr 4 na kierunku Informatyka\n";
        cout << "Program umozliwi Ci stworzenie kilku druzyn.\n";
        
        ////----------------
        ////----druzyna nr 1
        
        ////-------------------tworze obiekty dla pilkarzy z druzyny nr 1
        
        Team player_1_1("Messi", "Lionel", "160", "30", "napastnik");
        Team player_1_2("Cristiano", "Ronaldo", "180", "30", "napastnik");
        Team player_1_3("Czech", "Petr", "190", "30", "bramkarz");
        Team player_1_4("Lewandowski", "Robert", "180", "30", "napastnik");
        Team player_1_5("Lampard", "Frank", "180", "30", "pomocnik");
        
        ////-------------------tworze wskaznik dla zespolu nr 1
        vector<Team> *team_1_;
        ////-------------------alokuje pamiec dla zespolu nr 1
        get_memory(team_1_);
        ////-------------------przekazuje obiekty do wektora
        get_to_vector(team_1_, player_1_1);
        get_to_vector(team_1_, player_1_2);
        get_to_vector(team_1_, player_1_3);
        get_to_vector(team_1_, player_1_4);
        get_to_vector(team_1_, player_1_5);
        ////-------------------wyswietlam zawodnikow dla zespolu nr 1
        print_team_(team_1_, 1, 5);
        
        
        
        ////----------------
        ////----druzyna nr 2
        
        Team player_2_1("Majewski", "Radoslaw", "190", "33", "bramkarz");
        Team player_2_2("Wieteska", "Mateusz", "180", "33", "obronca");
        Team player_2_3("Astiz", "Inaki", "180", "33", "obronca");
        Team player_2_4("Jedrzejczyk", "Artur", "180", "33", "obronca");
        Team player_2_5("Cavani", "Edison", "180", "33", "napastnik");
        vector<Team> *team_2_;
        get_memory(team_2_);
        get_to_vector(team_2_, player_2_1);
        get_to_vector(team_2_, player_2_2);
        get_to_vector(team_2_, player_2_3);
        get_to_vector(team_2_, player_2_4);
        get_to_vector(team_2_, player_2_5);
        print_team_(team_2_, 2, 5);
        
        
        
        ////----------------
        ////----druzyna nr 3
        
        vector<Team> *team_3_;
        get_memory(team_3_);
        ////-------------------kopiuje vector
        copy_vector(team_2_, team_3_, 5);
        print_team_(team_3_, 3, 5);
        modify_player(team_3_, 5);
        
        print_team_(team_3_, 3, 5);
        
        
        
        ////----------------
        ////----druzyna nr 4
        
        ////-------------------tworze wskaznik dla vectora w ktorym beda przechowywane linie z danymi zawodnikow
        vector<string>*team_from_file;
        ////-------------------tworze vector tupu string z danymi z pliku
        get_memory_for_file(team_from_file);
        get_from_file(team_from_file);
        
        ////-------------------wyswietlam linie dla sprawdzenia
        cout << (*team_from_file)[0] << "\n";
        cout << (*team_from_file)[1] << "\n";
        cout << (*team_from_file)[2] << "\n";
        cout << (*team_from_file)[3] << "\n";
        cout << (*team_from_file)[4] << "\n";
        
        ////-------------------tworze wskaznik dla druzyny nr 4 i alokuje pamiec
        vector<Team> *team_4_;
        get_memory(team_4_);
        ////-------------------konwertuje za pomoca metody dane do vectora duzyny
        from_file_to_team_vector(team_from_file, team_4_, 5);
        print_team_(team_4_, 4, 5);
        
        write_team_to_file(team_1_, 5, "Druzyna_1");
        write_team_to_file(team_2_, 5, "Druzyna_2");
        write_team_to_file(team_3_, 5, "Druzyna_3");
        write_team_to_file(team_4_, 5, "Druzyna_4");
        
        delete_memory(team_1_);
        delete_memory(team_2_);
        delete_memory(team_3_);
        delete_memory(team_4_);
        
        
        
        
        if (team_1_ == nullptr)
            cout << "Pamiec pomyslnie skasowana.\n";
        
        
        while(1)
        {
            cout << "\nProgram wlasnie zakonczyl swoje dzialanie";
            cout << "Czy chcesz uruchomic program ponownie ??";
            cout << "W przypadku ponownego uruchomienia wpisz litere ''t'', w przerciwnym razie wpisz litere ''n''.";
            cout << "Pamietaj ze wielkosc liter ma zmaczenie.\n\n\n";
            cin >> continuation;
            if(continuation=='t')
            {
                break;
            }
            else
            {
                cout << "Niestety podales bledna litere";
                cout << "Sproboj jeszcze raz";
            }
        }
        cout << "Szkoda ze nie chcesz ponownie uruchomic programu";
        cout << "Moze nastepnycm razem. Powodzenia !!!";
    }
    return 0;
}
