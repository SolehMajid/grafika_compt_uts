# Randomized Depth First Search (C)


# Struktur Maze

Maze berbentuk grid:

```
7 x 7 cell
```

Contoh hasil maze:

```
### ###
#     #
# ### #
# #   #
# ### #
#     #
### ###
```

Keterangan:

```
#  = dinding
   = jalan
```

Posisi pintu:

```
   masuk
     ↓
### ###
#     #
# ### #
# #   #
# ### #
#     #
### ###
     ↑
   keluar
```

---

# Struktur Data

Program menggunakan struktur berikut:

```c
typedef struct {
    int x1, x2;
    int y1, y2;
    int wall;
} Cell;
```

Penjelasan:

| Field | Fungsi          |
| ----- | --------------- |
| x1    | koordinat kiri  |
| x2    | koordinat kanan |
| y1    | koordinat atas  |
| y2    | koordinat bawah |
| wall  | status dinding  |

Maze disimpan dalam grid:

```c
typedef struct {
    Cell grid[HEIGHT][WIDTH];
} Maze;
```

---

# Inisialisasi Maze

Pada awal program seluruh grid dibuat sebagai **dinding**:

```c
m->grid[y][x].wall = 1;
```

Kemudian dibuka:

* titik awal `(1,1)`
* pintu masuk `(0, WIDTH/2)`
* pintu keluar `(HEIGHT-1, WIDTH/2)`

---

# Algoritma Maze

Program menggunakan **Randomized Depth First Search (DFS)**.

Langkah algoritma:

1. Mulai dari satu cell
2. Tandai cell sebagai **visited**
3. Pilih arah secara **acak**
4. Jika cell tujuan belum dikunjungi:

   * buka dinding di antaranya
   * pindah ke cell tersebut
5. Jika tidak ada arah yang bisa dipilih → **backtracking**
6. Ulangi sampai semua cell dikunjungi