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

    // �����Ա��Ϣ
    cout << "�������Ա���: ";
    cin >> newMember->id;
    cout << "�������Ա����: ";
    cin >> newMember->name;
    cout << "�������Ա����: ";
    cin >> newMember->age;
    cout << "�������Ա�绰����: ";
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

    cout << "��Ա����ӳɹ���" << endl;
}

void TeamMemberManager::deleteMember() {
    int memberId;

    // ����Ҫɾ���Ķ�Ա�ı��
    cout << "������Ҫɾ���Ķ�Ա���: ";
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
            cout << "��Ա�ѳɹ�ɾ����" << endl;
            break;
        }
        previous = current;
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ָ����Ա��" << endl;
    }
}

void TeamMemberManager::findMemberByName() {
    string name;

    // ����Ҫ���ҵĶ�Ա����
    cout << "������Ҫ���ҵĶ�Ա����: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            found = true;
            cout << "�ҵ���Ա����� " << current->id << "������ " << current->name
                << "������ " << current->age << "���绰���� " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ƥ��Ķ�Ա��" << endl;
    }
}

void TeamMemberManager::modifyMember() {
    int memberId;

    // ����Ҫ�޸ĵĶ�Ա�ı��
    cout << "������Ҫ�޸ĵĶ�Ա���: ";
    cin >> memberId;

    TeamMember* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->id == memberId) {
            found = true;
            cout << "�������µĶ�Ա��Ϣ:" << endl;
            cout << "����: ";
            cin >> current->name;
            cout << "����: ";
            cin >> current->age;
            cout << "�绰����: ";
            cin >> current->phoneNumber;
            cout << "��Ա��Ϣ�ѳɹ��޸ģ�" << endl;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ָ����Ա��" << endl;
    }
}

void TeamMemberManager::displayAllMembers() {
    if (head == nullptr) {
        cout << "��Ա��ϢΪ�ա�" << endl;
    }
    else {
        cout << "���ж�Ա��Ϣ��" << endl;
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
        cout << "��Ա��ϢΪ�ա��޷�����" << endl;
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
    cout << "��Ա�Ѱ��������" << endl;
}

void TeamMemberManager::fuzzySearchByName() {
    string name;

    // ����Ҫģ�������Ķ�Ա����
    cout << "������Ҫģ�������Ķ�Ա����: ";
    cin >> name;

    bool found = false;

    TeamMember* current = head;
    while (current != nullptr) {
        if (current->name.find(name) != string::npos) {
            found = true;
            cout << "�ҵ���Ա����� " << current->id << "������ " << current->name
                << "������ " << current->age << "���绰���� " << current->phoneNumber << endl;
        }
        current = current->next;
    }

    if (!found) {
        cout << "δ�ҵ�ƥ��Ķ�Ա��" << endl;
    }
}

void TeamMemberManager::saveToFile() {
    ofstream file("C:\\Users\\win11\\qgzouxt\\CODE\\��Ա��Ϣ¼��ϵͳ\\team_members.txt");
    if (file.is_open()) {
        TeamMember* current = head;
        while (current != nullptr) {
            file << current->id << " " << current->name << " " << current->age << " " << current->phoneNumber << endl;
            current = current->next;
        }
        file.close();
        cout << "��Ա��Ϣ�ѱ��浽�ļ���" << endl;
    }
    else {
        cout << "�޷����ļ��Ա����Ա��Ϣ��" << endl;
    }
}

void TeamMemberManager::loadFromFile() {
    ifstream file("C:\\Users\\win11\\qgzouxt\\CODE\\��Ա��Ϣ¼��ϵͳ\\team_members.txt");
    if (file.is_open()) {
        head = nullptr; // ��յ�ǰ�Ķ�Ա��Ϣ���Ա��������Ϣ
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
        cout << "���ļ����ض�Ա��Ϣ�ɹ���" << endl;
    }
    else {
        cout << "�޷����ļ��Լ��ض�Ա��Ϣ��" << endl;
    }
}