# Git 学习笔记

## 1. 什么是Git？

Git是一个分布式版本控制系统，用于跟踪项目的变化并协同开发。是一种高效、灵活、快速的版本控制工具。Git广泛应用于软件开发，支持多人协同工作，追踪文件变更，以及管理项目的完整历史。

## 2. Git基本概念

### 2.1 仓库（Repository）

仓库是Git用于存储项目文件、历史记录和元数据的地方。可以存在于本地（本地仓库）或远程服务器上（远程仓库）。每个仓库都包含一个`.git`目录，用于保存版本控制信息。

### 2.2 提交（Commit）

提交是对项目进行快照的操作，每个提交都包含了一组文件的状态以及对这些文件所做的修改。提交的时候，需要提供清晰的提交信息，以便后续追溯。

```bash
git add your file
git commit -m "Initial commit"
```

### 2.3 分支（Branch）

分支是用于独立开发某个特性或解决问题的工作流。主分支通常是master，而其他分支则是在主分支的基础上进行的开发或修复。

```bash
git branch feature-branch
git checkout feature-branch
```

### 2.4 合并（Merge）

合并是将一个分支的修改整合到另一个分支的过程。常用的有普通合并和快进合并。

```bash
# 普通合并
git merge feature-branch

# 快进合并
git merge --ff-only feature-branch
```

### 2.5 远程仓库（Remote）

远程仓库是位于网络上的Git仓库，例如GitHub、GitLab、Bitbucket等。通过远程仓库，多人可以协同开发，并实现代码的共享与备份。

```bash
# 添加远程仓库
git remote add origin https://github.com/user/repo.git

# 推送到远程仓库
git push -u origin master
```

## 3. 常用Git命令

### 3.1 初始化仓库

```bash
git init
```

### 3.2 克隆仓库

```bash
git clone https://github.com/user/repo.git
```

### 3.3 查看文件状态

```bash
git status
```

### 3.4 暂存文件

```bash
git add filename
```

### 3.5 查看提交历史

```bash
git log
```

### 3.6 撤销修改

```bash
git checkout -- filename
```

### 3.7 创建分支

```bash
git branch branch-name
```

### 3.8 切换分支

```bash
git checkout branch-name
```

### 3.9 删除分支

```bash
git branch -d branch-name
```

### 3.10 拉取远程更新
```bash
git pull origin master
```

### 3.11 推送到远程仓库

```bash
git push origin master
```

## 4. 高级Git使用

### 4.1 变基（Rebase）

变基是将一系列提交按照日期重新应用在另一分支上，它可以产生整洁的提交历史。

```bash
git rebase master
```

### 4.2 子模块（Submodule）

子模块允许你将另一个Git仓库作为你的一个子目录。

```bash
git submodule add https://github.com/user/repo.git path/to/submodule
```

### 4.3 交互式重写历史

```bash
git rebase -i HEAD~3
```

## 5. Git常见问题及解决方案

### 5.1 解决合并冲突

在合并分支或者变基时可能会遇到冲突，需要手动解决冲突后再进行提交.

### 5.2 恢复误删文件

```bash
git checkout -- filename
```

### 5.3 撤销提交

```bash
git reset HEAD~1
```

o(〃＾▽＾〃)o

