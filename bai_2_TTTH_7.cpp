#include <stdio.h>
#include <stdlib.h>

struct DepTrai {
    char thangdeptrainhatthegian[50];
    char maso[10];
    float dodeptrai;
};

void ghiTenThangDepTraiVaoTep(const char* tenTep) {
    struct DepTrai depTrai;
    FILE* tep = fopen(tenTep, "wb");

    if (tep == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }

    printf("Nhap ten thang dep zai: ");
    scanf(" %[^\n]s", depTrai.thangdeptrainhatthegian);
    printf("Nhap ma so dep zai: ");
    scanf(" %[^\n]s", depTrai.maso);
    printf("Nhap do dep trai: ");
    scanf("%f", &(depTrai.dodeptrai));

    fwrite(&depTrai, sizeof(struct DepTrai), 1, tep);

    fclose(tep);
    printf("Da ghi ten no vao tep.\n");
}

void docThangDepTraiTuTep(const char* tenTep) {
    struct DepTrai depTrai;
    FILE* tep = fopen(tenTep, "rb");

    if (tep == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }

    fread(&depTrai, sizeof(struct DepTrai), 1, tep);

    printf("Thong tin thang dep zai:\n");
    printf("Ten: %s\n", depTrai.thangdeptrainhatthegian);
    printf("Ma so dep trai: %s\n", depTrai.maso);
    printf("Do dep zai: %.2f\n", depTrai.dodeptrai);

    fclose(tep);
}

int main() {
    const char* tenTep = "deptrai.bin";

	ghiTenThangDepTraiVaoTep(tenTep);
    docThangDepTraiTuTep(tenTep);

    return 0;
}
