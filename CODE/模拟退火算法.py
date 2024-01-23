import math
import random

def objective_function(x):
    """
    定义你的目标函数，这里以一个简单的示例函数为例。
    """
    return x**2 + math.sin(5*x)

def simulated_annealing(initial_solution, temperature, cooling_rate, iterations):
    """
    模拟退火算法实现
    """
    current_solution = initial_solution
    best_solution = current_solution

    for iteration in range(iterations):
        # 生成邻近解
        neighbor_solution = current_solution + random.uniform(-0.1, 0.1)

        # 计算目标函数值
        current_cost = objective_function(current_solution)
        neighbor_cost = objective_function(neighbor_solution)

        # 判断是否接受邻近解
        if neighbor_cost < current_cost or random.random() < math.exp((current_cost - neighbor_cost) / temperature):
            current_solution = neighbor_solution

        # 更新最佳解
        if objective_function(current_solution) < objective_function(best_solution):
            best_solution = current_solution

        # 降低温度
        temperature *= 1 - cooling_rate

    return best_solution

# 设置初始解、初始温度、冷却率和迭代次数
initial_solution = 2.0
initial_temperature = 10.0
cooling_rate = 0.02
iterations = 1000

# 运行模拟退火算法
result = simulated_annealing(initial_solution, initial_temperature, cooling_rate, iterations)

print("最优解:", result)
print("目标函数值:", objective_function(result))
