#pragma once
#include<vector>

#include"ClassSoldier.h"

class SoldierBaseService
{
public:
    SoldierBaseService();
    ~SoldierBaseService();
    string Split(string &s, string delimiter);
    int LoadData();
    int SaveData();
    void ReadSoldiers();
    void FindSoldier();
    void SortSoldier(int);
    void DeleteSoldier();
    void show();
    void UpdateSoldier();
    void UpdateSoldierService();
    void UpdateSoldierHealth();
    void ReadSoldierHealth();
    void CreateSoldier();
private:
    string path_;
    vector<Soldier> soldier_;
};
