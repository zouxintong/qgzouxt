#include "TeamMembers.h"

TeamMemberManager::TeamMemberManager() {
    head = nullptr;
}

TeamMemberManager::~TeamMemberManager() {
    // �ͷŵ�������ڴ�
    while (head != nullptr) {
        TeamMember* temp = head;
        head = head->next;
        delete temp;
    }
}

void TeamMemberManager::addMember() {
    TeamMember* newMember = new TeamMember();

    // ������Ϣ
    cout << "��������: ";
    cin >> newMember->id;
    cout << "����������: ";
    cin >> newMember->name;
    cout << "����������: ";
    cin >> newMember->age;
    cout << "������绰����: ";
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

    cout << "�û�����ӳɹ���" << endl;
}

void TeamMemberManager::deleteMember() {
    int memberId;

    // ����Ҫɾ�����û��ı��
    cout << "������Ҫɾ�����û����: ";
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
            cout << "�û��ѳɹ�ɾ����" << endl;
            break;
        }
        previous = current;
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ָ���û���" << endl;
    }
}

void TeamMemberManager::findMemberByName() {
    string name;

    // ����Ҫ���ҵ��û�����
    cout << "������Ҫ���ҵ��û�����: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            found = true;
            cout << "�ҵ��û������ " << current->id << "������ " << current->name
                << "������ " << current->age << "���绰���� " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ƥ����û���" << endl;
    }
}

void TeamMemberManager::modifyMember() {
    int memberId;

    // ����Ҫ�޸ĵ��û��ı��
    cout << "������Ҫ�޸ĵ��û����: ";
    cin >> memberId;

    TeamMember* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->id == memberId) {
            found = true;
            cout << "�������µ��û���Ϣ:" << endl;
            cout << "����: ";
            cin >> current->name;
            cout << "����: ";
            cin >> current->age;
            cout << "�绰����: ";
            cin >> current->phoneNumber;
            cout << "��Ϣ�ѳɹ��޸ģ�" << endl;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ָ���û���" << endl;
    }
}

void TeamMemberManager::displayAllMembers() {
    if (head == nullptr) {
        cout << "�û���ϢΪ�ա�" << endl;
    }
    else {
        cout << "�����û���Ϣ��" << endl;
        TeamMember* current = head;
        while (current != nullptr) {
            cout << "���: " << current->id << "������: " << current->name
                << "������: " << current->age << "���绰����: " << current->phoneNumber << endl;
            current = current->next;
        }
    }
}

void TeamMemberManager::sortMembersById() {
    if (head == nullptr) {
        cout << "�û���ϢΪ�ա��޷�����" << endl;
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
    cout << "�Ѱ��������" << endl;
}

void TeamMemberManager::fuzzySearchByName() {
    string name;

    // ����Ҫģ���������û�����
    cout << "������Ҫģ���������û�����: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name.find(name) != string::npos) {
            found = true;
            cout << "�ҵ��û������ " << current->id << "������ " << current->name
                << "������ " << current->age << "���绰���� " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ƥ����û���" << endl;
    }
}

void TeamMemberManager::saveToFile() {
    ofstream file("C:\\Users\\win11\\qgzouxt\\CODE\\�û���Ϣ¼��ϵͳ\\team_members.txt");
    if (file.is_open()) {
        TeamMember* current = head;
        while (current != nullptr) {
            file << current->id << " " << current->name << " " << current->age << " " << current->phoneNumber << endl;
            current = current->next;
        }
        file.close();
        cout << "�û���Ϣ�ѱ��浽�ļ���" << endl;
    }
    else {
        cout << "�޷����ļ��Ա�����Ϣ��" << endl;
    }
}

void TeamMemberManager::loadFromFile() {
    ifstream file("C:\\Users\\win11\\qgzouxt\\CODE\\�û���Ϣ¼��ϵͳ\\team_members.txt");
    if (file.is_open()) {
        head = nullptr; // ��յ�ǰ����Ϣ���Ա��������Ϣ
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
        cout << "���ļ������û���Ϣ�ɹ���" << endl;
    }
    else {
        cout << "�޷����ļ��Լ����û���Ϣ��" << endl;
    }
}