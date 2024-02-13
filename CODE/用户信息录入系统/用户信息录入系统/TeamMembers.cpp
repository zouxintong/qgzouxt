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

    // 输入信息
    cout << "请输入编号: ";
    cin >> newMember->id;
    cout << "请输入姓名: ";
    cin >> newMember->name;
    cout << "请输入年龄: ";
    cin >> newMember->age;
    cout << "请输入电话号码: ";
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

    cout << "用户已添加成功！" << endl;
}

void TeamMemberManager::deleteMember() {
    int memberId;

    // 输入要删除的用户的编号
    cout << "请输入要删除的用户编号: ";
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
            cout << "用户已成功删除！" << endl;
            break;
        }
        previous = current;
        current = current->next;
    }

    if (!found) {
        cout << "未找到指定用户。" << endl;
    }
}

void TeamMemberManager::findMemberByName() {
    string name;

    // 输入要查找的用户姓名
    cout << "请输入要查找的用户姓名: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            found = true;
            cout << "找到用户：编号 " << current->id << "，姓名 " << current->name
                << "，年龄 " << current->age << "，电话号码 " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "未找到匹配的用户。" << endl;
    }
}

void TeamMemberManager::modifyMember() {
    int memberId;

    // 输入要修改的用户的编号
    cout << "请输入要修改的用户编号: ";
    cin >> memberId;

    TeamMember* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->id == memberId) {
            found = true;
            cout << "请输入新的用户信息:" << endl;
            cout << "姓名: ";
            cin >> current->name;
            cout << "年龄: ";
            cin >> current->age;
            cout << "电话号码: ";
            cin >> current->phoneNumber;
            cout << "信息已成功修改！" << endl;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "未找到指定用户。" << endl;
    }
}

void TeamMemberManager::displayAllMembers() {
    if (head == nullptr) {
        cout << "用户信息为空。" << endl;
    }
    else {
        cout << "所有用户信息：" << endl;
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
        cout << "用户信息为空。无法排序。" << endl;
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
    cout << "已按编号排序。" << endl;
}

void TeamMemberManager::fuzzySearchByName() {
    string name;

    // 输入要模糊搜索的用户姓名
    cout << "请输入要模糊搜索的用户姓名: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name.find(name) != string::npos) {
            found = true;
            cout << "找到用户：编号 " << current->id << "，姓名 " << current->name
                << "，年龄 " << current->age << "，电话号码 " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "未找到匹配的用户。" << endl;
    }
}

void TeamMemberManager::saveToFile() {
    ofstream file("C:\\Users\\win11\\qgzouxt\\CODE\\用户信息录入系统\\team_members.txt");
    if (file.is_open()) {
        TeamMember* current = head;
        while (current != nullptr) {
            file << current->id << " " << current->name << " " << current->age << " " << current->phoneNumber << endl;
            current = current->next;
        }
        file.close();
        cout << "用户信息已保存到文件。" << endl;
    }
    else {
        cout << "无法打开文件以保存信息。" << endl;
    }
}

void TeamMemberManager::loadFromFile() {
    ifstream file("C:\\Users\\win11\\qgzouxt\\CODE\\用户信息录入系统\\team_members.txt");
    if (file.is_open()) {
        head = nullptr; // 清空当前的信息，以便加载新信息
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
        cout << "从文件加载用户信息成功。" << endl;
    }
    else {
        cout << "无法打开文件以加载用户信息。" << endl;
    }
}