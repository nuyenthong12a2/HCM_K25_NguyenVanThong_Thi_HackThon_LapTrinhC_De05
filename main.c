#include <stdio.h>
#define MAX_SIZE 50

int main() {
    int tickets[MAX_SIZE] = {85, 120, 60, 150, 95};
    int n = 5;
    int choice, isChanged, pos, value, newValue, target, count, i;

    do {
        isChanged = 0;
        printf("\n============================================");
        printf("\n    CHUONG TRINH QUAN LY BAN RA STARCINEMA");
        printf("\n============================================");
        printf("\n1. Them so ve ban ra");
        printf("\n2. Sua so ve ban ra");
        printf("\n3. Xoa so ve ban ra");
        printf("\n4. Tim kiem so ve ban ra");
        printf("\n0. Thoat chuong trinh");
        printf("\n============================================");
        printf("\nVui long nhap lua chon chuc nang (0 - 4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n >= MAX_SIZE) {
                    printf("\nMang da day, khong the them!\n");
                    break;
                }
                printf("\nNhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can chen: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("\nVi tri chen khong hop le!\n");
                    break;
                }
                for (i = n; i >= pos; i--) {
                    tickets[i] = tickets[i - 1];
                }
                tickets[pos - 1] = value;
                n++;
                isChanged = 1;
                break;

            case 2:
                printf("\nNhap vi tri can sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &newValue);
                if (pos < 1 || pos > n) {
                    printf("\nVi tri sua khong hop le!\n");
                } else if (newValue < 0) {
                    printf("\nSo ve ban ra khong hop le!\n");
                } else {
                    tickets[pos - 1] = newValue;
                    isChanged = 1;
                }
                break;

            case 3:
                if (n == 0) {
                    printf("\nMang rong, khong the xoa!\n");
                    break;
                }
                printf("\nNhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("\nVi tri xoa khong hop le!\n");
                    break;
                }
                for (i = pos - 1; i < n - 1; i++) {
                    tickets[i] = tickets[i + 1];
                }
                n--;
                isChanged = 1;
                break;

            case 4:
                printf("\nNhap gia tri can tim: ");
                scanf("%d", &target);
                count = 0;
                for (i = 0; i < n; i++) {
                    if (tickets[i] == target) {
                        if (count == 0) {
                            printf("\nTim thay tai vi tri:");
                        }
                        printf(" %d", i + 1);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("\nKhong tim thay gia tri trong mang!\n");
                } else {
                    printf("\nTong so lan xuat hien: %d\n", count);
                }
                break;

            case 0:
                printf("\nCam on ban da su dung chuong trinh. Hen gap lai!\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
                break;
        }

        if (isChanged == 1) {
            printf("Mang hien tai: [");
            for (i = 0; i < n; i++) {
                printf("%d", tickets[i]);
                if (i < n - 1) {
                    printf(", ");
                }
            }
            printf("]\n");
        }
    } while (choice != 0);

    return 0;
}
