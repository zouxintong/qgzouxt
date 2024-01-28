# Numpy库学习

## 1. 基于列表构建矩阵

Numpy 提供了 numpy.array() 函数，可以将列表转换为矩阵。

```python
import numpy as np

# 通过列表创建矩阵
matrix_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix = np.array(matrix_list)
print(matrix)
```

## 2. 特殊矩阵构建

```python
# 创建零矩阵
zero_matrix = np.zeros((3, 3))
print(zero_matrix)

# 创建单位矩阵
identity_matrix = np.eye(3)
print(identity_matrix)
```

## 3. 矩阵乘法

使用 numpy.dot() 函数进行矩阵乘法。

```python
matrix1 = np.array([[1, 2], [3, 4]])
matrix2 = np.array([[5, 6], [7, 8]])

result_matrix = np.dot(matrix1, matrix2)
print(result_matrix)
```

## 4. 矩阵广播机制

Numpy 支持矩阵广播，可以在不同形状的数组之间进行运算。

```python
matrix = np.array([[1, 2, 3], [4, 5, 6]])
scalar = 2

result_matrix = matrix * scalar
print(result_matrix)
```

## 5. 矩阵转置

使用 .T 属性进行矩阵转置。

```python
matrix = np.array([[1, 2, 3], [4, 5, 6]])
transposed_matrix = matrix.T
print(transposed_matrix)
```

## 6. 矩阵的逆

使用 numpy.linalg.inv() 函数计算矩阵的逆。

```python
matrix = np.array([[1, 2], [3, 4]])
inverse_matrix = np.linalg.inv(matrix)
print(inverse_matrix)
```

## 7. 矩阵存取

通过索引和切片操作可以访问矩阵的元素。

```python
matrix = np.array([[1, 2, 3], [4, 5, 6]])

# 访问元素
element = matrix[0, 1]
print(element)

# 切片操作
row_slice = matrix[1, :]
column_slice = matrix[:, 2]
print(row_slice)
print(column_slice)
```

# Pandas库学习

## 1. 初步学习读取数据

Pandas 提供了 pandas.read_csv() 函数用于从 CSV 文件中读取数据。

```python
import pandas as pd
# 读取 CSV 文件
data = pd.read_csv('data.csv')
print(data)
```

## 2. 简单的数据清洗

Pandas 提供了一系列的数据清洗方法，比如处理缺失值、重复值等。

```python
# 处理缺失值
data.dropna(inplace=True)
# 处理重复值
data.drop_duplicates(inplace=True)
```

# Matplotlib 库学习

## 1. 学会基础的绘图语法

Matplotlib 提供了多种绘图函数，比如 plt.scatter()、plt.plot()、plt.bar()、plt.pie() 等。

```python
import matplotlib.pyplot as plt

# 散点图
plt.scatter(x_data, y_data)

# 曲线图
plt.plot(x_data, y_data)

# 条形图
plt.bar(x_categories, y_values)

# 扇形图
plt.pie(sizes, labels=labels, autopct='%1.1f%%')
```

## 2. 不同绘图之前差异较大

不同类型的图表有不同的参数和语法，需要根据具体需求选择合适的绘图函数和设置参数。

```python
# 不同类型的图表绘制
plt.figure(figsize=(8, 6))

# 绘制柱状图
plt.bar(x_categories, y_values, color='blue')

# 设置标题和标签
plt.title('Bar Chart')
plt.xlabel('Categories')
plt.ylabel('Values')

# 显示图例
plt.legend(['Values'])

# 显示图表
plt.show()
```
