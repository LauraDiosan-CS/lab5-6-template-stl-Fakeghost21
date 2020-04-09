#pragma once
#include "Service.h"
class UI {
private:
    Service service;
    void displayMenu();
    void AddPrajitura(int id, const string nume, const string ingrediente, double pret);
    void ShowAllCandy();
    void UpdateByID(int id, const string newName, const string newIngrediente, double newPret);
    void DeleteByID(int id);
    void ShowALLMonede();
public:
    UI();
    UI(Service& service);
    void runUI();
};