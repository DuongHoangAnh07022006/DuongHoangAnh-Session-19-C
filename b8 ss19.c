#include <stdio.h>
#include <string.h>
struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
void sortSinhVienByName(struct SinhVien arr[], int n) {
    struct SinhVien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void printSinhVien(struct SinhVien arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
}
int main() {
    struct SinhVien students[5] = {
        {1, "John", 20, "0123456789"},
        {2, "Alice", 22, "0987654321"},
        {3, "Bob", 21, "0123984567"},
        {4, "David", 23, "0998765432"},
        {5, "Charlie", 20, "0987123456"}
    };
    int n = 5;
    printf("Danh sach sinh vien truoc khi sap xep:\n");
    printSinhVien(students, n);
    sortSinhVienByName(students, n);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printSinhVien(students, n);
    return 0;
}

