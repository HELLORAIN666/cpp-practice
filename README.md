# C++ 课程练习 / C++ Coursework Practice

机械电子工程专业本科课程《C++ 程序设计》的练习代码，重点在 **类与对象 · 封装 · 构造与析构**。

Practice code for an undergraduate C++ course, focused on **classes, encapsulation, and object lifecycle**.

- 编译工具链：MinGW-w64 GCC 15.3.0（WinLibs, x86_64-ucrt-posix-seh）
- 编辑器：Visual Studio Code
- 语言标准：C++17

---

## 文件说明

| 文件 | 主题 |
|---|---|
| `4.1.cpp` | **类与封装**：getter / setter，只读属性与只写属性的实现方式 |
| `4.2.cpp` | **对象生命周期**：无参构造、有参构造、析构函数、拷贝构造；三种初始化写法（括号法 / 显示法 / 隐式转换法） |
| `T10_Library.cpp` | **T10 图书管理系统**：`Book` + `Library` 两个类，用 `vector` 做增删改查与排序，实践单一职责原则与封装 |
| `t1.cpp` | 基础练习：整数除法与类型转换（元角换算） |
| `4.2.2.cpp`、`t10.cpp` | 学习过程中留下的草稿，未完成 |

## 一些笔记

写在代码注释里，方便回看：

- **封装的意义**：成员变量设为 `private`，外部不能直接改（比如 `stock = -100`），只能走 `borrow()` 这类接口，接口里能做合法性检查。像银行柜台——不能自己进金库拿钱。
- **只读属性的坑**：只打印不赋值的成员变量必须给默认值，否则读出来是垃圾值。
- **为什么分两个类**：`Book` 只管"我是什么"，`Library` 只管"怎么管这一堆书"。全塞进 `main` 就变成一坨不敢碰的面条代码。

## 怎么编译运行

仓库里不含编译产物（`.exe` 已由 `.gitignore` 排除）。

用 g++ 手动编译：

```bash
mkdir -p output
g++ -Wall -std=c++17 <源文件>.cpp -o output/<源文件>.exe
```

在 VS Code 中，本仓库使用 **C/C++ Compile Run** 扩展，输出目录为 `output/`；
`tasks.json` 也提供了一条等效的构建任务（`Ctrl+Shift+B`）。

Windows 下编译选项含 `-fexec-charset=GBK` 以正确显示中文，`-static` 便于在未安装 MinGW 的机器上直接运行。
