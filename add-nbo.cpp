#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main() {
    uint32_t value1;
    uint32_t value2;
    uint32_t sum;
    FILE *fp1, *fp2;
    char buffer[BUFFER_SIZE];

    fp1 = fopen("five-hundred.bin", "rb");
    fp2 = fopen("thousand.bin", "rb");

    // Read value1 from the first file
    fread(buffer, sizeof(uint32_t), 1, fp1);
    value1 = ntohl(*(uint32_t*)buffer);

    // Read value2 from the second file
    fread(buffer, sizeof(uint32_t), 1, fp2);
    value2 = ntohl(*(uint32_t*)buffer);

    sum = value1 + value2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", value1, value1, value2, value2, sum, sum);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
