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

# 基本步骤

## 数据分析相关步骤

1. **定义问题**：
    - 首先明确定义分析的目标和问题，以便确定需要收集和分析的数据类型。
    

2. **收集数据**：
    - 收集与问题相关的数据，这可以通过调查、实验、数据库查询、API调用等方式进行。

    ```
    # 收集数据
    import pandas as pd
    # 从文件中读取数据
    data = pd.read_csv("data.csv")
    ```

3. **数据清洗**：
    - 对数据进行清理，包括处理缺失值、异常值、重复值，以及进行数据格式转换等操作，以确保数据的质量和准确性。

    ```
    # 处理缺失值
    data.dropna(inplace=True)

    # 处理异常值
    data = data[data["age"] > 0]

    # 处理重复值
    data.drop_duplicates(inplace=True)

    # 数据格式转换
    data["date"] = pd.to_datetime(data["date"])
    ```

4. **探索性数据分析（EDA）**：
    - 对数据进行初步探索，包括统计描述、可视化分析等，以发现数据的分布、趋势、关联性等特征，为后续分析提供指导。

    ```
    # 探索性数据分析
    import matplotlib.pyplot as plt

    # 统计描述
    print(data.describe())

    # 可视化分析
    plt.hist(data["age"], bins=20)
    plt.xlabel("Age")
    plt.ylabel("Frequency")
    plt.title("Distribution of Age")
    plt.show()
    ```

5. **特征工程**：
    - 根据业务需求和探索性分析的结果，对原始数据进行特征提取、转换、选择等操作，以创建能够更好地描述数据的特征。

   ```
   # 特征提取
   data["month"] = data["date"].dt.month

   # 特征转换
   data["gender"] = data["gender"].map({"Male": 1, "Female": 0})

   # 特征选择
   selected_features = ["age", "gender", "income"]
   X = data[selected_features]
   ```

    


6. **建模和分析**：
    - 根据问题的性质选择合适的分析方法和模型，例如统计分析、机器学习模型等，对数据进行建模和分析。

```
from sklearn.linear_model import LogisticRegression

# 初始化模型
model = LogisticRegression()

# 拟合模型
model.fit(X, y)
```

7. **模型评估**：
    - 对建立的模型进行评估，包括模型性能指标的计算、交叉验证等，以评估模型的预测能力和泛化能力。

```
from sklearn.metrics import accuracy_score

# 预测
y_pred = model.predict(X)

# 计算准确率
accuracy = accuracy_score(y, y_pred)
print("Accuracy:", accuracy)
```

8. **解释结果**：
    - 根据分析和建模结果，解释和理解数据背后的含义和规律，提出结论并对结果进行解释。

```
# 解释模型系数
coefficients = model.coef_
```

9. **报告和可视化**：
    - 将分析过程、结果和结论整理成报告或可视化图表，向相关利益相关者传达分析的结果和建议。

```
import seaborn as sns

# 可视化模型系数
sns.barplot(x=selected_features, y=coefficients[0])
plt.xlabel("Features")
plt.ylabel("Coefficient")
plt.title("Coefficients of Logistic Regression Model")
plt.show()
```

