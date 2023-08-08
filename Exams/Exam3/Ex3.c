#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Product {
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[50];
};

void printProduct(struct Product p) {
    printf("ID: %u\n", p.id);
    printf("Product Type: %c\n", p.product_type);
    printf("Product Name: %s\n", p.product_name);
    printf("Old Price: %.2lf\n", p.old_price);
    printf("New Price: %.2lf\n", p.new_price);
    printf("\n");
}

int compareProducts(const void *a, const void *b) {
    struct Product *productA = (struct Product *)a;
    struct Product *productB = (struct Product *)b;

    double diffPriceA = productA->new_price - productA->old_price;
    double diffPriceB = productB->new_price - productB->old_price;

    if (diffPriceA > diffPriceB) {
        return -1;
    } else if (diffPriceA < diffPriceB) {
        return 1;
    } else {
        int typeComparison = productA->product_type - productB->product_type;
        if (typeComparison != 0) {
            return typeComparison;
        } else {
            int nameComparison = strcmp(productA->product_name, productB->product_name);
            if (nameComparison != 0) {
                return nameComparison;
            } else {
                return productA->id - productB->id;
            }
        }
    }
}

void writeProductsToFile(struct Product products[], int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(products, sizeof(struct Product), count, file);
    fclose(file);
}

void readProductsFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Product product;
    while (fread(&product, sizeof(struct Product), 1, file) == 1) {
        printProduct(product);
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    struct Product products[40];
    char product_names[][50] = {
        "Product A", "Product B", "Product C", "Product D", "Product E",
        "Product F", "Product G", "Product H", "Product I", "Product J",
        "Product K", "Product L", "Product M", "Product N", "Product O",
        "Product P", "Product Q", "Product R", "Product S", "Product T",
        "Product U", "Product V", "Product W", "Product X", "Product Y", "Product Z"
    };

    for (int i = 0; i < 40; i++) {
        products[i].old_price = (rand() % 961 + 499) / 100.0;
        products[i].new_price = (rand() % 961 + 499) / 100.0;
        products[i].id = i + 1;
        products[i].product_type = 'A' + rand() % 4;
        strcpy(products[i].product_name, product_names[rand() % 26]);
    }

    printf("Initial Products:\n");
    for (int i = 0; i < 40; i++) {
        printProduct(products[i]);
    }

    qsort(products, 40, sizeof(struct Product), compareProducts);

    printf("Sorted Products:\n");
    for (int i = 0; i < 40; i++) {
        printProduct(products[i]);
    }

    writeProductsToFile(products, 40, "products.bin");

    printf("Products read from file:\n");
    readProductsFromFile("products.bin");

    return 0;
}
