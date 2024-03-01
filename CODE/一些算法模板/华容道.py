import random

# 初始化游戏界面
def initialize_board():
    return [[1, 2, 3],
            [4, 5, 6],
            [7, 8, ' ']]

# 打印游戏界面
def print_board(board):
    for row in board:
        print('|', end='')
        for cell in row:
            print(cell, end='|')
        print()

# 检查是否完成游戏
def check_win(board):
    return board == [[1, 2, 3],
                     [4, 5, 6],
                     [7, 8, ' ']]

# 移动数字
def move_number(board, number):
    for i in range(3):
        for j in range(3):
            if board[i][j] == number:
                if i > 0 and board[i - 1][j] == ' ':
                    board[i][j], board[i - 1][j] = board[i - 1][j], board[i][j]
                    return True
                elif i < 2 and board[i + 1][j] == ' ':
                    board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]
                    return True
                elif j > 0 and board[i][j - 1] == ' ':
                    board[i][j], board[i][j - 1] = board[i][j - 1], board[i][j]
                    return True
                elif j < 2 and board[i][j + 1] == ' ':
                    board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]
                    return True
    return False

# 主游戏函数
def main():
    board = initialize_board()
    random.shuffle(board[0])
    random.shuffle(board[1])
    random.shuffle(board[2])
    while not check_win(board):
        print_board(board)
        number = int(input('请输入要移动的数字(1-8): '))
        if 1 <= number <= 8:
            if not move_number(board, number):
                print('无法移动这个数字，请选择其他数字移动。')
        else:
            print('请输入有效的数字(1-8)。')
    print('恭喜！你赢了游戏。')

# 运行游戏
if __name__ == "__main__":
    main()

