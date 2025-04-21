/*************************************************************************
	> File Name: 666.ALL_SORT_TEST.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Apr 2025 06:03:44 PM CST
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TEST_SIZES {1000, 10000, 100000, 1000000, 10000000}
#define BAR_WIDTH 50
#define MIN_UPDATE_INTERVAL_MS 20
#define THRESHOLD 16

typedef void (*progress_cb_t)(const char* func_name, int current, int total);

typedef struct {
    int total_elements;
    int processed_elements;
    progress_cb_t cb;
    const char* func_name;
    clock_t last_update;
    int initialised;
} SortProgress;

SortProgress init_progress(int total, progress_cb_t cb, const char* func_name) {
    return (SortProgress){
        .total_elements = total,
        .processed_elements = 0,
        .cb = cb,
        .func_name = func_name,
        .last_update = 0,
        .initialised = 1
    };
}

void update_progress(SortProgress *progress, int newly_processed) {
    if (!progress || !progress->initialised || !progress->cb) return;

    progress->processed_elements += newly_processed;

    if (progress->processed_elements > progress->total_elements) {
        progress->processed_elements = progress->total_elements;
    }

    clock_t now = clock();
    if ((now - progress->last_update) * 1000 / CLOCKS_PER_SEC < MIN_UPDATE_INTERVAL_MS &&
        progress->processed_elements < progress->total_elements) {
        return;
    }

    if (progress->processed_elements == progress->total_elements) {
         progress->last_update = now;
         progress->cb(progress->func_name,
                      progress->processed_elements,
                      progress->total_elements);
         return;
    }

    progress->last_update = now;
    progress->cb(progress->func_name,
                 progress->processed_elements,
                 progress->total_elements);
}


void update_sort_progress(const char* func_name, int current, int total) {
    if (total <= 0) total = 1;
    if (current < 0) current = 0;
    if (current > total) current = total;


    int percent = (int)(((double)current / total) * 100);
    int bar_len = (int)(((double)current / total) * BAR_WIDTH);

    printf("\rTest %-20s : [", func_name);
    for (int i = 0; i < bar_len; ++i) printf("=");
    for (int i = 0; i < BAR_WIDTH - bar_len; ++i) printf(" ");
    printf(" ] %3d%%", percent);
    fflush(stdout);
}

__attribute__((constructor))
void __init_Rand__() {
    srand(time(0));
}

int check(int *arr, int l, int r) {
    for(int i = l + 1; i < r; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int *getRandomData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        perror("malloc failed in getRandomData");
        return NULL;
    }
    for(int i = 0; i < n; i++) arr[i] = rand();
    return arr;
}

void simple_insert_sort(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


#define swap(a, b) { __typeof(a) __c = a; a = b; b = __c; }

#define TEST(func, arr, n) { \
    printf("Test %-20s : ", #func); \
    fflush(stdout); \
    \
    int *temp = (int *)malloc(sizeof(int) * n); \
    if (temp == NULL) { \
        perror("malloc failed in TEST"); \
        exit(EXIT_FAILURE); \
    } \
    memcpy(temp, arr, sizeof(int) * n); \
    \
    clock_t b = clock(); \
    \
    func(temp, 0, n, update_sort_progress, #func); \
    \
    clock_t e = clock(); \
    \
    update_sort_progress(#func, n, n); \
    \
    if (check(temp, 0, n)) { \
        printf("\tOK"); \
    } else { \
        printf("\tFailed"); \
    } \
    printf(" %d items %lld ms\n", n, (long long)(e - b) * 1000 / CLOCKS_PER_SEC); \
    \
    free(temp); \
}

void selection_sort(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
    SortProgress progress = init_progress(r - l, cb, func_name);
    for (int i = l, I = r - 1; i < I; i++) {
        int ind = i;
        for (int j = i + 1; j < r; j++) {
            if(arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
        update_progress(&progress, 1);
    }
    update_progress(&progress, 0);
}

void bubble_sort(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
    SortProgress progress = init_progress(r - l, cb, func_name);
    int n = r - l;
    for (int i = r - 1; i > l; i--) {
        int swapped = 0;
        for (int j = l; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        update_progress(&progress, 1);
        if(!swapped) break;
    }
     update_progress(&progress, 0);
}

void insert_sort(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
     SortProgress progress = init_progress(r - l, cb, func_name);
     for (int i = l + 1; i < r; i++) {
         int key = arr[i];
         int j = i - 1;
         while (j >= l && arr[j] > key) {
             arr[j + 1] = arr[j];
             j--;
         }
         arr[j + 1] = key;
         update_progress(&progress, 1);
     }
      update_progress(&progress, 0);
}

void unguarded_insert_sort(int *arr, int l, int r, int step) {
    if (r - l <= step) return;

    int min_idx = l;
    for (int i = l + step; i < r; i += step) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    if (min_idx != l) {
         swap(arr[l], arr[min_idx]);
    }

    for (int i = l + step; i < r; i += step) {
        int key = arr[i];
        int j = i - step;
        while (arr[j] > key) {
            arr[j + step] = arr[j];
            j -= step;
        }
        arr[j + step] = key;
    }
}

void shell_sort(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
    int n = (r - l);
    if (n <= 1) return;
    
    int estimated_steps = 0;
     int k = 2;
     int current_step = n / k;
     while(current_step > 1) { estimated_steps++; k*=2; current_step = n/k; }
     estimated_steps++;

    SortProgress progress = init_progress(estimated_steps, cb, func_name);

    k = 2;
    int step;
    do {
        step = n / k == 0 ? 1 : n / k;
        if (step == 0) step = 1;
        
        for (int i = l; i < l + step && i < r; i++) {
             unguarded_insert_sort(arr, i, r, step);
        }
        update_progress(&progress, 1);
        k *= 2;
    } while(step != 1);

     update_progress(&progress, 0);
}

void shell_sort_hibbard(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
    int n = (r - l);
    if (n <= 1) return;
    
    int estimated_steps = 0;
    int step = 1;
    while (step <= n / 2) { estimated_steps++; step = step * 2 + 1; }
    if (estimated_steps == 0) estimated_steps = 1;


    SortProgress progress = init_progress(estimated_steps, cb, func_name);

    step = 1;
    while (step <= n / 2) step = step * 2 + 1;

    do {
        step /= 2;
        for (int i = l; i < l + step && i < r; i++) {
             unguarded_insert_sort(arr, i, r, step);
        }
        update_progress(&progress, 1);
    } while (step > 1);

    update_progress(&progress, 0);
}


int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}


void quick_sort_v1(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
     SortProgress progress = init_progress(r - l, cb, func_name);
     if (r - l <= 1) {
         update_progress(&progress, r - l);
         return;
     }

     void __quick_sort_v1_recursive(int *sub_arr, int sub_l, int sub_r, SortProgress *prog) {
          if (sub_r - sub_l <= THRESHOLD) {
              simple_insert_sort(sub_arr, sub_l, sub_r);
              update_progress(prog, sub_r - sub_l);
              return;
          }

          int x = sub_l, y = sub_r - 1, z = sub_arr[sub_l];
          do {
              while(sub_arr[x] < z) ++x;
              while(sub_arr[y] > z) --y;
              if(x <= y) {
                  swap(sub_arr[x], sub_arr[y]);
                  ++x; --y;
              }
          } while(x <= y);

           if (y - sub_l + 1 < sub_r - x) {
               __quick_sort_v1_recursive(sub_arr, sub_l, y + 1, prog);
               sub_l = x;
           } else {
               __quick_sort_v1_recursive(sub_arr, x, sub_r, prog);
               sub_r = y + 1;
           }
           if (sub_r - sub_l > THRESHOLD) {
              __quick_sort_v1_recursive(sub_arr, sub_l, sub_r, prog);
           } else {
               simple_insert_sort(sub_arr, sub_l, sub_r);
               update_progress(prog, sub_r - sub_l);
           }

     }

     __quick_sort_v1_recursive(arr, l, r, &progress);
     update_progress(&progress, 0);
}

void quick_sort_v2(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
     SortProgress progress = init_progress(r - l, cb, func_name);
     if (r - l <= 1) {
          update_progress(&progress, r - l);
          return;
     }

     void __quick_sort_v2_recursive(int *sub_arr, int sub_l, int sub_r, SortProgress *prog) {
          if (sub_r - sub_l <= THRESHOLD) {
              simple_insert_sort(sub_arr, sub_l, sub_r);
              update_progress(prog, sub_r - sub_l);
              return;
          }

          int x = sub_l, y = sub_r - 1, z = three_point_select(sub_arr[sub_l], sub_arr[sub_r - 1], sub_arr[(sub_l + sub_r) / 2]);
          do {
              while(sub_arr[x] < z) ++x;
              while(sub_arr[y] > z) --y;
              if(x <= y) {
                  swap(sub_arr[x], sub_arr[y]);
                  ++x; --y;
              }
          } while(x <= y);

           if (y - sub_l + 1 < sub_r - x) {
               __quick_sort_v2_recursive(sub_arr, sub_l, y + 1, prog);
               sub_l = x;
           } else {
               __quick_sort_v2_recursive(sub_arr, x, sub_r, prog);
               sub_r = y + 1;
           }
           if (sub_r - sub_l > THRESHOLD) {
              __quick_sort_v2_recursive(sub_arr, sub_l, sub_r, prog);
           } else {
               simple_insert_sort(sub_arr, sub_l, sub_r);
               update_progress(prog, sub_r - sub_l);
           }
     }

     __quick_sort_v2_recursive(arr, l, r, &progress);
     update_progress(&progress, 0);
}


void quick_sort_v3(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
     SortProgress progress = init_progress(r - l, cb, func_name);
     if (r - l <= 1) {
          update_progress(&progress, r - l);
          return;
     }

     void __quick_sort_v3_recursive(int *sub_arr, int sub_l, int sub_r, SortProgress *prog) {
         while(sub_r - sub_l > THRESHOLD) {
             int x = sub_l, y = sub_r - 1, z = three_point_select(sub_arr[sub_l], sub_arr[sub_r - 1], sub_arr[(sub_l + sub_r) / 2]);
             do {
                 while(sub_arr[x] < z) ++x;
                 while(sub_arr[y] > z) --y;
                 if(x <= y) {
                     swap(sub_arr[x], sub_arr[y]);
                     ++x; --y;
                 }
             } while(x <= y);

             if (y - sub_l + 1 < sub_r - x) {
                 __quick_sort_v3_recursive(sub_arr, sub_l, y + 1, prog);
                 sub_l = x;
             } else {
                 __quick_sort_v3_recursive(sub_arr, x, sub_r, prog);
                 sub_r = y + 1;
             }
         }
         simple_insert_sort(sub_arr, sub_l, sub_r);
         update_progress(prog, sub_r - sub_l);
     }

     __quick_sort_v3_recursive(arr, l, r, &progress);
     update_progress(&progress, 0);
}


void quick_sort_v4(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
    SortProgress progress = init_progress(r - l, cb, func_name);
     if (r - l <= 1) {
          update_progress(&progress, r - l);
          return;
     }

     void __quick_sort_v4_recursive(int *sub_arr, int sub_l, int sub_r, SortProgress *prog) {
         while(sub_r - sub_l > THRESHOLD) {
             int x = sub_l, y = sub_r - 1, z = three_point_select(sub_arr[sub_l], sub_arr[sub_r - 1], sub_arr[(sub_l + sub_r) / 2]);
             do {
                 while(sub_arr[x] < z) ++x;
                 while(sub_arr[y] > z) --y;
                 if(x <= y) {
                     swap(sub_arr[x], sub_arr[y]);
                     ++x; --y;
                 }
             } while(x <= y);

             if (y - sub_l + 1 < sub_r - x) {
                 __quick_sort_v4_recursive(sub_arr, sub_l, y + 1, prog);
                 sub_l = x;
             } else {
                 __quick_sort_v4_recursive(sub_arr, x, sub_r, prog);
                 sub_r = y + 1;
             }
         }
         simple_insert_sort(sub_arr, sub_l, sub_r);
         update_progress(prog, sub_r - sub_l);
     }

     __quick_sort_v4_recursive(arr, l, r, &progress);
     update_progress(&progress, 0);
}

void __merge_sort_recursive(int *arr, int l, int r, int *temp_buff, SortProgress *progress) {
    if(r - l <= 1) return;

    int mid = l + (r - l) / 2;

    __merge_sort_recursive(arr, l, mid, temp_buff, progress);
    __merge_sort_recursive(arr, mid, r, temp_buff, progress);

    int p1 = l, p2 = mid, k = 0;
    while(p1 < mid || p2 < r) {
        if(p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
            temp_buff[k++] = arr[p1++];
        } else {
            temp_buff[k++] = arr[p2++];
        }
    }
    for (int i = 0; i < r - l; i++) {
       arr[l + i] = temp_buff[i];
    }

    update_progress(progress, r - l);
}

void merge_sort(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
     SortProgress progress = init_progress(r - l, cb, func_name);
     if (r - l <= 1) {
          update_progress(&progress, r - l);
          return;
     }

     int size = r - l;
     int *temp_buff = (int *)malloc(sizeof(int) * size);
     if (!temp_buff) {
         perror("malloc failed in merge_sort");
         update_progress(&progress, 0);
         return;
     }

     __merge_sort_recursive(arr, l, r, temp_buff, &progress);

     free(temp_buff);

     update_progress(&progress, 0);
}

void radix_sort(int *arr, int l, int r, progress_cb_t cb, const char* func_name) {
    #define RADIX_BITS 16
    #define RADIX_BUCKETS (1 << RADIX_BITS)

    int n = r - l;
    if (n <= 1) return;

    SortProgress progress = init_progress(n, cb, func_name);

    int *cnt  = (int *)calloc(RADIX_BUCKETS, sizeof(int));
    int *temp = (int *)malloc(sizeof(int) * n);
    if (!cnt || !temp) {
         perror("malloc failed in radix_sort");
         free(cnt); free(temp);
         update_progress(&progress, 0);
         return;
    }

    int shift = 0;
    for (int pass = 0; pass < 2; ++pass) {
        memset(cnt, 0, sizeof(int) * RADIX_BUCKETS);

        for (int i = l; i < r; i++) {
            cnt[(arr[i] >> shift) & (RADIX_BUCKETS - 1)]++;
        }

        for (int i = 1; i < RADIX_BUCKETS; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = r - 1; i >= l; i--) {
            temp[--cnt[(arr[i] >> shift) & (RADIX_BUCKETS - 1)]] = arr[i];
        }

        memcpy(arr + l, temp, sizeof(int) * n);

        update_progress(&progress, n / 2);
    
        shift += RADIX_BITS;
    }

    free(cnt);
    free(temp);

    update_progress(&progress, 0);
    #undef RADIX_BITS
    #undef RADIX_BUCKETS
}


int main() {
    int test_sizes[] = TEST_SIZES;
    int num_sizes = sizeof(test_sizes) / sizeof(test_sizes[0]);

    printf("Starting sorting algorithm tests...\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = test_sizes[i];
        printf("\n--- Testing size: %d ---\n", n);
        int *arr = getRandomData(n);
        if (arr == NULL) {
            printf("Skipping tests for size %d due to memory allocation failure.\n", n);
            continue;
        }

        TEST(selection_sort, arr, n);
        TEST(bubble_sort, arr, n);
        TEST(insert_sort, arr, n);
        TEST(shell_sort, arr, n);
        TEST(shell_sort_hibbard, arr, n);

        TEST(quick_sort_v1, arr, n);
        TEST(quick_sort_v2, arr, n);
        TEST(quick_sort_v3, arr, n);
        TEST(quick_sort_v4, arr, n);

        TEST(merge_sort, arr, n);

        TEST(radix_sort, arr, n);

        free(arr);
    }

    printf("\nAll tests finished.\n");

    return 0;
}
