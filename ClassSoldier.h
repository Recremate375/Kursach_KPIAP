#include"HumanClass.h"

class Soldier : public Human
{
private:
    bool Status_; //информация, годен ли солдат к службе в армии или нет
    bool Servicestatus_; //информация, служит сейчас солдат или нет
    string rank_; //статус человека
    int HealthGraph_; //Содержит информацию о графе, в которой находится мед.карта призывника 
public:
    Soldier();
    Soldier(int ID, string name, string surname, string midname, int day, int mounth, int year, string job, string education, string place_of_study, int HealthGraph, bool Status, bool ServiceStatus, string rank);
    Soldier(int ID, string name, string surname, string midname);
    int get_id();
    int get_HealthGraph();
    int get_day();
    int get_mounth();
    int get_year();
    bool get_Status();
    bool get_ServiceStatus();
    string get_rank();
    string get_name();
    string get_surname();
    string get_midname();
    string get_job();
    string get_education();
    string get_place_of_study();
    void set_id(int);
    void set_day(int);
    void set_mounth(int);
    void set_year(int);
    void set_name(string);
    void set_surname(string);
    void set_midname(string);
    void set_job(string);
    void set_education(string);
    void set_place_of_study(string);
    void set_HealthGraph(int);
    void set_rank(string);
    void set_Status(bool);
    void set_ServiceStatus(bool);
    friend bool operator ==(const Soldier &soldier1, const Soldier &soldier2);
    void show() const;
    friend ostream & operator<< (ostream &out, Soldier &soldier);
    ~Soldier();
};