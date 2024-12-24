#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
void xoaSinhVien(int id, struct SinhVien arr[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (arr[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*currentLength)--;
            printf("Sinh vien co id %d da duoc xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Sinh vien co id %d khong ton tai trong danh sach.\n", id);
    }
}
void printSinhVien(struct SinhVien arr[], int currentLength) {
    for (int i = 0; i < currentLength; i++) {
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
    int currentLength = 5;
    printf("Danh sach sinh vien truoc khi xoa:\n");
    printSinhVien(students, currentLength);
    int idToDelete;
    printf("\nNhap id sinh vien muon xoa: ");
    scanf("%d", &idToDelete);
    xoaSinhVien(idToDelete, students, &currentLength);
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printSinhVien(students, currentLength);
    return 0;
}

