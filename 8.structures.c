#include<stdio.h>
#include<string.h>


void showStudentData(struct student *st){
    printf("\nStudent:\n");
    printf("Name: %s\n", st->name);
    printf("Number: %d\n", st->grade);
    printf("Age: %d\n", st->age);
}   
void update_course(course *class);
void display_course(cource class);

struct student {
        int age;
        int grade;
        char name[40];
    };

struct course{
        int id;
        char title[40];
        float hours;
    };

typedef struct {
        int id;
        char title[40];
        float hours;
    } camera;

typedef struct {
        int x;
        int y;
    } point;

typedef struct {
    float radius;
    point center;
} circle;

typedef struct {
    int h;
    int w;
    int l;
} box;

union val {
    int intNum;
    float flNum;
    char str[20];
    };

typedef struct {
        char make[20];
        int modelYear;
        int idType;
        union {
            int idNum;
            char VIN[20];
        } id;
    }vehicle;
    
union id {
    int idNum;
    char name[20];
}

union type{
    int iVal;
    float fVal;
    char chVal;
}

void setId(union id *item){
    item->idNum = 42;    
}

void showId(union id item){
    printf("ID is %d\n", item.idNum);
}

int main(){
    printf("40. Structures\n");
    // keyword struct
    // members: vars inside struct
    // Structure: Also called composite or aggregate data type.
    // Also called as records
    // Declaration example
    // Structure can store anything including every datatype and pointers as well.
    struct student s1;
    struct student s2;
    // sizeof operator can be used to get the size of the structure.
    // Initialization
    struct student s3 = {19, 9, "John"};
    struct student s4 = {22, 10, "Batman"};
    // Initialization after declaration
    // Typecasting needed.
    struct student s5;
    s5 = (struct student) {19, 9, "John"};
    // Initialization using names
    struct student s6 = {.age = 19, .grade=9, .name = "John"};
    // Thus we can refer to corresponding members using the dot operation

    printf("41. Accessing Structure Members\n");
    // Access members using the (.dot operator)
    // Assigning values
    s1.age = 19;
    // We can also assign one structure to another of the same type
    s1 = s2;
    struct course cs1 = {341270, "Intro to C++", 12.5};
    struct course cs2;
    cs2.id = 341231;
    strcpy(cs2.title, "Advanced C++");
    cs2.hours = 15.25;
    // 4.2 is width and precision
    printf("%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);
    printf("%d\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);
    
    printf("42. Using typedef\n");
    // typedef keyword creates a type definition that simplifies the code and makes it easier to read
    // Usually used with struct
    camera c1;
    camera c2;
    // We can see that struct tag is no longer used.

    printf("43. Working with Structures\n");
    // Members of structures can also be structures
    // Nested curly brances are used to initialize the members that are struct.
    circle c = {4.5, {1,3}};
    printf("%3.1f %d, %d", c.radius, c.center.x, c.center.y);

    printf("44. Pointers to Structures\n");
    // Just like vars
    /*
    struct myStruct *struct_ptr;
    // defines a pointer to the myStruct structure

    struct_ptr = &struct_var;
    Store the address of the structure variable struct_var in the pointer struct_ptr.

    struct_ptr -> struct_mem;
    access the value of the structure member struct_mem.
    */
    struct student s7 = {.age = 21, .grade=15, .name="Krishna"};
    showStudentData(&s7);
    // (*st).age is same as st->age.
    // When typedef has been used to name the struct, then a pointer declared using only the typedef name 
    // along with * and the pointer name.

    printf("45. Structures as function Parameters.\n");
    // Accept arguments by value.
    // To change the actual values of the struct variable, pointer parameters are required.
    camera cs3;
    update_course(&cs3);
    display_course(cs3);

    printf("46. Array of Structures\n");
    box boxes[3] = {{2,6,8}, {4,6,6}, {2,6,9}};
    int k, volume;
    for(k=0; k<3; k++){
        volume = boxes[k].h*boxes[k].w*boxes[k].l;
        printf("Box %d volume %d\n", k, volume);
    }

    printf("47. Unions\n");
    // A Union allows to store different data types in the same memory location.
    // A lot like structure, but a union variable uses the same memory location
    // for all its member's and only one member at a time can occupy the memory location.
    union val u1;
    union val u2;
    u2 = u1;
    // Unions are used for memory management
    // The largest member data type is used to determine the size of the 
    // memory to share and then all members use this one location.
    // This process also helps limit memory fragmentation.

    printf("48. Accessing Union members\n");
    // .dot operator.
    // Trying to access a member that isn't occupying the memory location gives unexpected results.
    union val test;
    test.intNum = 123;
    test.flNum = 232.421;
    strcpy(test.str, "hello");
    printf("%d\n", test.intNum);
    printf("%f\n", test.flNum);
    printf("%s\n", test.str);
    // The last assignment overrides previous assignments,
    // Which is why str stores a value and accessing intNum and flNum is meaningless.

    printf("49. Structures with Unions\n");
    // Unions are often used within structures because a structure can have member to keep track
    // of which union member stores a value.
    vehicle car1;
    strcpy(car1.make, "Ford");
    car1.modelYear = 2017;
    car1.idType = 0;
    car1.id.idNum = 123098;
    // Here idType keeps track of which union member stores a value.
    printf("Make: %s\n", car1.make);
    printf("Model Year: %d\n", car1.modelYear);
    if(car1.idType == 0){
        printf("ID: %d\n", car1.id.idNum);
    }
    else{
        printf("ID: %s\n", car1.id.VIN);
    }
    // A union can also contain a structure.

    printf("50. Working with Unions\n");
    // Pointer to a union
    union val info;
    union val *ptr = NULL;
    ptr = &info;
    ptr->intNum = 10;
    printf("info.int_num is %d", info.intNum);
    // (*ptr).intNum is the same as ptr->intNum.

    printf("51. Unions as Function Parameters\n");
    union id item;
    setId(&item);
    showId(item);

    printf("52. Array of Unions\n");
    union val nums[10];
    int k;
    for(k=0; k<10; k++){
        nums[k].intNum = k;
    }
    for(k=0; k<10; k++){
        printf("%d ", nums[k].intNum);
    }
    // Array is a datastructure that stores collection values that are 
    // all the same type.
    // Array of unions allow storing values of different types.
    union type arr[3];
    arr[0].iVal = 42;
    arr[1].fVal = 3.14;
    arr[2].chVal = 'x';

    return 0;
}

void update_course(camera *class){
    strcpy(class->title, "C++ Fundamentals");
    class->id = 111;
    class->hours = 12.30;
}

void display_course(camera class){
    printf("%d\t%s\t%3.2f\n", class.id, class.title, class.hours);
}