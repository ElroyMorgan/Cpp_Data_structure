# 顺序表实现项目

**此项目是我仅用来学习数据结构**

## 项目结构

```
learn_structure/
├── include/        头文件目录
│   ├── list.h     顺序表声明
│   └── head.h    公共头文件
├── src/           源文件目录
│   ├── list.cpp  顺序表实现
│   └── main.cpp  测试程序
└── CMakeLists.txt 构建配置
```

## 实现原理

包含两种顺序表实现：

1. 静态分配顺序表（SqList）
    - 固定大小数组存储
    - 支持插入/删除/查找操作
2. 动态分配顺序表（SeqList）
    - 动态内存管理
    - 支持容量扩展

## 核心功能

- 初始化/销毁顺序表
- O(n)时间复杂度插入删除
- 元素值/位置查找
- 自动容量管理（动态版本）

## 编译运行

```bash
mkdir build && cd build
cmake ..
make
./learn_structure
```

## 注意事项

1. 静态表最大容量100
2. 插入位置需满足 1 ≤ i ≤ length+1
3. 动态表需手动调用IncreaseSize扩容