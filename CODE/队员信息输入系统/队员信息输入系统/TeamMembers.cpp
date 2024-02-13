#include "TeamMembers.h"

TeamMemberManager::TeamMemberManager() {
    head = nullptr;
}

TeamMemberManager::~TeamMemberManager() {
    // 释放单链表的内存
    while (head != nullptr) {
        TeamMember* temp = head;
        head = head->next;
        delete temp;
    }
}

void TeamMemberManager::addMember() {
    TeamMember* newMember = new TeamMember();

    // 输入队员信息
    cout << "请输入队员编号: ";
    cin >> newMember->id;
    cout << "请输入队员姓名: ";
    cin >> newMember->name;
    cout << "请输入队员年龄: ";
    cin >> newMember->age;
    cout << "请输入队员电话号码: ";
    cin >> newMember->phoneNumber;

    newMember->next = nullptr;

    if (head == nullptr) {
        head = newMember;
    }
    else {
        TeamMember* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newMember;
    }

    cout << "队员已添加成功！" << endl;
}

void TeamMemberManager::deleteMember() {
    int memberId;

    // 输入要删除的队员的编号
    cout << "请输入要删除的队员编号: ";
    cin >> memberId;

    TeamMember* current = head;
    TeamMember* previous = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->id == memberId) {
            found = true;
            if (previous != nullptr) {
                previous->next = current->next;
            }
            else {
                head = current->next;
            }
            delete current;
            cout << "队员已成功删除！" << endl;
            break;
        }
        previous = current;
        current = current->next;
    }

    if (!found) {
        cout << "未找到指定队员。" << endl;
    }
}

void TeamMemberManager::findMemberByName() {
    string name;

    // 输入要查找的队员姓名
    cout << "请输入要查找的队员姓名: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            found = true;
            cout << "找到队员：编号 " << current->id << "，姓名 " << current->name
                << "，年龄 " << current->age << "，电话号码 " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "未找到匹配的队员。" << endl;
    }
}

void TeamMemberManager::modifyMember() {
    int memberId;

    // 输入要修改的队员的编号
    cout << "请输入要修改的队员编号: ";
    cin >> memberId;

    TeamMember* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->id == memberId) {
            found = true;
            cout << "请输入新的队员信息:" << endl;
            cout << "姓名: ";
            cin >> current->name;
            cout << "年龄: ";
            cin >> current->age;
            cout << "电话号码: ";
            cin >> current->phoneNumber;
            cout << "队员信息已成功修改！" << endl;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "未找到指定队员。" << endl;
    }
}

void TeamMemberManager::displayAllMembers() {
    if (head == nullptr) {
        cout << "队员信息为空。" << endl;
    }
    else {
        cout << "所有队员信息：" << endl;
        TeamMember* current = head;
        while (current != nullptr) {
            cout << "编号: " << current->id << "，姓名: " << current->name
                << "，年龄: " << current->age << "，电话号码: " << current->phoneNumber << endl;
            current = current->next;
        }
    }
}

void TeamMemberManager::sortMembersById() {
    if (head == nullptr) {
        cout << "队员信息为空。无法排序。" << endl;
        return;
    }

    TeamMember* sortedHead = nullptr;
    TeamMember* current = head;

    while (current != nullptr) {
        TeamMember* next = current->next;
        if (sortedHead == nullptr || current->id < sortedHead->id) {
            current->next = sortedHead;
            sortedHead = current;
        }
        else {
            TeamMember* search = sortedHead;
            while (search->next != nullptr && current->id > search->next->id) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = next;
    }

    head = sortedHead;
    cout << "队员已按编号排序。" << endl;
}

void TeamMemberManager::fuzzySearchByName() {
    string name;

    // 输入要模糊搜索的队员姓名
    cout << "请输入要模糊搜索的队员姓名: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name.find(name) != string::npos) {
            found = true;
            cout << "找到队员：编号 " << current->id << "，姓名 " << current->name
                << "，年龄 " << current->age << "，电话号码 " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "未找到匹配的队员。" << endl;
    }
}

void TeamMemberManager::saveToFile() {
    ofstream file("C:\\Users\win11\\qgzouxt\\CODE\\队员信息输入系统\\team_members.txt");
    if (file.is_open()) {
        TeamMember* current = head;
        while (current != nullptr) {
            file << current->id << " " << current->name << " " << current->age << " " << current->phoneNumber << endl;
            current = current->next;
        }
        file.close();
        cout << "队员信息已保存到文件。" << endl;
    }
    else {
        cout << "无法打开文件以保存队员信息。" << endl;
    }
}

void TeamMemberManager::loadFromFile() {
    ifstream file("C:\\Users\\win11\\qgzouxt\\CODE\\队员信息输入系统\\team_members.txt");
    if (file.is_open()) {
        head = nullptr; // 清空当前的队员信息，以便加载新信息
        TeamMember* current = nullptr;

        while (!file.eof()) {
            TeamMember* newMember = new TeamMember();
            file >> newMember->id >> newMember->name >> newMember->age >> newMember->phoneNumber;
            newMember->next = nullptr;

            if (head == nullptr) {
                head = newMember;
                current = head;
            }
            else {
                current->next = newMember;
                current = current->next;
            }
        }
        file.close();
        cout << "从文件加载队员信息成功。" << endl;
    }
    else {
        cout << "无法打开文件以加载队员信息。" << endl;
    }
}