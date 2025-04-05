### Project Overview ###
***Description:***
A console-based application to manage student records using linked lists for storage.

***Key Features:***

Add, view, search, and delete student records.

Automatic calculation of total marks and percentage.

Dynamic memory management.

***file_structure***


your_project/
├── include/
│   └── linked_list.h
|      ├── Node structure
|      |__functions
|       ├── createNode()
│       ├── insertNode()
│       ├── searchNode()
│       ├── deleteNode()
│       ├── freeList()
│       └── displayList()
└── src/
    └── student_record.c
    ├── Data Structures
        │   └── Student
        │
        ├── Core Functions
        │   ├── createStudentRecord()
        │   ├── calculateStudentStats()
        │   └── cloneStudentRecord()
        │
        └── Callback Functions
            ├── displayStudent()
            ├── compareStudents()
            ├── compareStudentsCaseInsensitive()
            └── freeStudent()


sequenceDiagram
    participant Main
    participant StudentRecord
    participant LinkedList
    
    Main->>StudentRecord: createStudentRecord()
    StudentRecord->>StudentRecord: calculateStudentStats()
    Main->>LinkedList: insertNode()
    
    Main->>LinkedList: searchNode()
    LinkedList->>StudentRecord: compareStudents()
    
    Main->>LinkedList: displayList()
    LinkedList->>StudentRecord: displayStudent()
    
    Main->>LinkedList: deleteNode()
    LinkedList->>StudentRecord: compareStudents()
    LinkedList->>StudentRecord: freeStudent()
    
    Main->>LinkedList: freeList()
    LinkedList->>StudentRecord: freeStudent()

+---------------------+
|       NODE          |
+---------------------+
|                     |
|  void* data         |━━━━━━━┓
|                     |       ┃
|  struct Node* next  |━━━━━━━┛
|                     |
+---------------------+
       ▲
       ┃
       ┗━━━━━━━━━━━━━━━━━━━━━━━━━┓
                                 ┃






+---------------------+
|      STUDENT        |
+---------------------+
|                     |
|  char name[50]      |
|                     |
|  int web_design     |
|  int data_structure |
|  int data_science   |
|                     |
|  int total          |
|  float percentage   |
|                     |
+---------------------+
       ▲
       ┃
       ┗━━━━━━ (Pointed to by Node's void* data)









+---------------------+
|   STUDENT LIST      |
+---------------------+
|                     |
|  Node* head         |━━━━━┓
|                     |     ┃
+---------------------+     ┃
                            ▼
                    +---------------------+
                    |       NODE          |
                    +---------------------+
                    |                     |
                    |  Student* data      |━━━━> STUDENT
                    |                     |
                    |  Node* next  -------|━━━┓
                    |                     |   ┃
                    +---------------------+   ┃
                                              ▼
                                      +---------------------+
                                      |       NODE          |
                                      +---------------------+
                                      |                     |
                                      |  Student* data      |━━━━> STUDENT
                                      |                     |
                                      |  Node* next = NULL  |
                                      |                     |
                                      +---------------------+
                                                                                   
                                                                                                 
                                 


            

