#pragma once

int Menu(std::vector <Debt>&, std::vector <Debt>&);

void AddDebt(std::vector <Debt>&);
void DeleteDebt(std::vector <Debt>&, const enum Walker&);
void ShowDebtsList(std::vector <Debt>&, const enum Walker&);

void ShowTime();
void ShowWhoseDay(const enum Walker&);
void MsgBox(const char*, const char*);