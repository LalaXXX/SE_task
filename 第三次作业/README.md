班级学生多胞胎自动识别
===
主要功能模块设计
---
班级学生多胞胎自动识别程序由7个功能模块组成：录入学生信息、添加学生信息、文件读入学生信息、识别多胞胎学生信息、删除已有学生信息、查找已有学生信息、修改已有学生信息。

主要算法描述
---
程序分三种输入学生信息的方法，其中首次批量创建学生信息采用链表尾插法创建节点，另外两种添加学生信息和文件读入学生信息采用链表的头插法创建节点。
在程序的重要函数StuIdentify()即多胞胎的自动识别函数中，用了两次冒泡排序，因为是对链表进行排序操作，所有在链表头记录了链表长度(学生数量)，两次排序分别是在多胞胎识别之前按照父母姓名排序，和多胞胎识别之后对每组多胞胎按照学生姓名排序。将所有学生按照父母姓名排序之后，相同父母姓名的学生应在一起，建立结构体数组存储每组多胞胎头节点，该节点指针指向第一个多胞胎节点，当遇到父母姓名不同、出生时刻相差大于5分钟的学生则将数组下标加一