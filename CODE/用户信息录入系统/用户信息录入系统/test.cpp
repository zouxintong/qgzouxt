#include "TeamMembers.h"

int main() {
    TeamMemberManager manager;
    int choice;

    while (true) {
        // ��ʾ����ѡ��˵�
        cout << "�û���Ϣ����ϵͳ" << endl;
        cout << "1. ����û�" << endl;
        cout << "2. ɾ���û�" << endl;
        cout << "3. �����������û�" << endl;
        cout << "4. �޸��û���Ϣ" << endl;
        cout << "5. ��ʾ������ϵ����Ϣ" << endl;
        cout << "6. �û����������" << endl;
        cout << "7. �򵥵�ģ������" << endl;
        cout << "8. ���浽�ļ�" << endl;
        cout << "9. ���ļ�����" << endl;
        cout << "0. �˳�" << endl;
        cout << "����������ѡ��";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addMember();
            break;
        case 2:
            manager.deleteMember();
            break;
        case 3:
            manager.findMemberByName();
            break;
        case 4:
            manager.modifyMember();
            break;
        case 5:
            manager.displayAllMembers();
            break;
        case 6:
            manager.sortMembersById();
            break;
        case 7:
            manager.fuzzySearchByName();
            break;
        case 8:
            manager.saveToFile();
            break;
        case 9:
            manager.loadFromFile();
            break;
        case 0:
            cout << "�����˳���" << endl;
            return 0;
        default:
            cout << "��Чѡ������ԡ�" << endl;
        }
    }

    return 0;
}