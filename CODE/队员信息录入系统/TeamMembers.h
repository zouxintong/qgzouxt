#pragma once
#ifndef TEAM_MEMBERS_H
#define TEAM_MEMBERS_H

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

struct TeamMember {
    int id;
    string name;
    int age;
    string phoneNumber;
    TeamMember* next;
};

class TeamMemberManager {
public:
    TeamMemberManager();
    ~TeamMemberManager();
    void addMember();
    void deleteMember();
    void findMemberByName();
    void modifyMember();
    void displayAllMembers();
    void sortMembersById();
    void fuzzySearchByName();
    void saveToFile();
    void loadFromFile();

private:
    TeamMember* head;
};

#endif // TEAM_MEMBERS_H
