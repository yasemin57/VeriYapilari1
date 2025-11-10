#include <stdio.h>
#include <stdlib.h>


void print_array(int arr[], int size) {
    if (size == 0) {
        printf("[Dizi Bos]\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

// (Reverse)  
void array_reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end) {
        //  (swap)
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

//  (Insert)  

void array_insert(int arr[], int *size, int max_size, int index, int value) {
    // 1. Kontroller
    if (*size >= max_size) {
        printf("HATA: Dizi dolu. Ekleme yapýlamadý.\n");
        return;
    }
    if (index < 0 || index > *size) {
        printf("HATA: Geçersiz indeks (%d). Ekleme yapýlamadý.\n", index);
        return;
    }

   
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
   
    arr[index] = value;


    (*size)++;
    printf("BAÞARILI: %d, %d. indekse eklendi.\n", value, index);
}


void array_delete(int arr[], int *size, int index) {
    // 1. Kontroller
    if (*size <= 0) {
        printf("HATA: Dizi boþ. Çýkarma yapýlamadý.\n");
        return;
    }
    if (index < 0 || index >= *size) {
        printf("HATA: Geçersiz indeks (%d). Çýkarma yapýlamadý.\n", index);
        return;
    }

    int deleted_value = arr[index];

  
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("BAÞARILI: %d, %d. indeksten silindi.\n", deleted_value, index);
}



int main() {
    const int MAX_SIZE = 10; 
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int current_size = 5; 

    printf("--------------\n");
    printf("Dizi Boyutu: %d\n", current_size);
    print_array(arr, current_size);

    printf("\n---  (Insert)  ---\n");
    // 2. indekse 99 ekle (10, 20, 99, 30, 40, 50)
    array_insert(arr, &current_size, MAX_SIZE, 2, 99);
    print_array(arr, current_size);

    printf("\n---  (Delete)  ---\n");
    // 1. indeksi sil (20) -> (10, 99, 30, 40, 50)
    array_delete(arr, &current_size, 1);
    print_array(arr, current_size);

    printf("\n---  (Reverse)  ---\n");
    // (50, 40, 30, 99, 10)
    array_reverse(arr, current_size);
    printf("Tersine Çevrilmiþ Dizi: ");
    print_array(arr, current_size);

    printf("\n--------------\n");
    array_insert(arr, &current_size, MAX_SIZE, current_size, 5);
    print_array(arr, current_size);
    
    return 0;
}

