#include "TeamMembers.h"

int main() {
    TeamMemberManager manager;
    int choice;

    while (true) {
        // 显示功能选择菜单
        cout << "队员信息管理系统" << endl;
        cout << "1. 添加队员" << endl;
        cout << "2. 删除队员" << endl;
        cout << "3. 按姓名查找队员" << endl;
        cout << "4. 修改队员信息" << endl;
        cout << "5. 显示所有联系人信息" << endl;
        cout << "6. 队员按编号排序" << endl;
        cout << "7. 简单的模糊搜索" << endl;
        cout << "8. 保存到文件" << endl;
        cout << "9. 从文件加载" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入您的选择：";
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
            cout << "程序退出。" << endl;
            return 0;
        default:
            cout << "无效选项，请重试。" << endl;
        }
    }

    return 0;
}