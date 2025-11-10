#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h> // malloc, free, vs. için (Bu örnekte kullanýlmadý ama dinamik diziler için önemlidir)

// --- Yardýmcý Fonksiyon: Diziyi Ekrana Yazdýrýr ---
void print_array(int arr[], int size) {
    if (size == 0) {
        printf("[Dizi Boþ]\n");
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

// --- 1. Tersine Çevirme (Reverse) Ýþlemi ---
void array_reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end) {
        // start ve end pozisyonundaki elemanlarý yer deðiþtir (swap)
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Ýþaretçileri birbirine yaklaþtýr
        start++;
        end--;
    }
}

// --- 2. Ekleme (Insert) Ýþlemi ---
// *size'ý pointer olarak alýyoruz ki, fonksiyon içindeki boyut deðiþimi main'e yansýsýn.
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

    // 2. Kaydýrma: Ekleme pozisyonundan (index) baþlayarak son elemana kadar
    // tüm elemanlarý birer pozisyon saða kaydýr.
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // 3. Ekleme
    arr[index] = value;

    // 4. Boyutu güncelle
    (*size)++;
    printf("BAÞARILI: %d, %d. indekse eklendi.\n", value, index);
}

// --- 3. Çýkarma (Delete) Ýþlemi ---
// *size'ý pointer olarak alýyoruz ki, fonksiyon içindeki boyut deðiþimi main'e yansýsýn.
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

    // 2. Kaydýrma: Silme pozisyonundan (index) baþlayarak
    // tüm elemanlarý birer pozisyon sola kaydýr.
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // 3. Boyutu güncelle
    (*size)--;
    printf("BAÞARILI: %d, %d. indeksten silindi.\n", deleted_value, index);
}


// --- Ana Program ---
int main() {
    const int MAX_SIZE = 10; // Dizinin maksimum kapasitesi
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50}; // Baþlangýç verileri
    int current_size = 5; // Dizideki anlýk eleman sayýsý

    printf("--- Baþlangýç Durumu ---\n");
    printf("Dizi Boyutu: %d\n", current_size);
    print_array(arr, current_size);

    printf("\n--- 2. Ekleme (Insert) Ýþlemi ---\n");
    // 2. indekse 99 ekle (10, 20, 99, 30, 40, 50)
    array_insert(arr, &current_size, MAX_SIZE, 2, 99);
    print_array(arr, current_size);

    printf("\n--- 3. Çýkarma (Delete) Ýþlemi ---\n");
    // 1. indeksi sil (20) -> (10, 99, 30, 40, 50)
    array_delete(arr, &current_size, 1);
    print_array(arr, current_size);

    printf("\n--- 1. Tersine Çevirme (Reverse) Ýþlemi ---\n");
    // (50, 40, 30, 99, 10)
    array_reverse(arr, current_size);
    printf("Tersine Çevrilmiþ Dizi: ");
    print_array(arr, current_size);

    printf("\n--- Ek Test: Son Elemana Ekleme ---\n");
    array_insert(arr, &current_size, MAX_SIZE, current_size, 5);
    print_array(arr, current_size);
    
    return 0;
}
